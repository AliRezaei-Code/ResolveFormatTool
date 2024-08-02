#include <iostream>
#include <filesystem>
#include <cstdlib>
#include <vector>
#include <map>
#include <string>
#include <stdexcept>

namespace fs = std::filesystem;

// Function to detect the operating system
std::string detectOS() {
#ifdef _WIN32
    return "Windows";
#elif __APPLE__
    return "macOS";
#elif __linux__
    return "Linux";
#else
    return "Unknown";
#endif
}

// Function to get the supported formats based on the OS
std::vector<std::pair<std::string, std::string>> getSupportedFormats(const std::string& os) {
    std::vector<std::pair<std::string, std::string>> formats;
    if (os == "Windows") {
        formats.push_back({"ProRes", "mov"});
        formats.push_back({"DNxHD", "mov"});
        formats.push_back({"DNxHR", "mov"});
    } else if (os == "macOS") {
        formats.push_back({"ProRes", "mov"});
        formats.push_back({"DNxHD", "mov"});
        formats.push_back({"DNxHR", "mov"});
    } else if (os == "Linux") {
        formats.push_back({"DNxHR", "mov"});
    }
    return formats;
}

void convertToResolveFormat(const fs::path& inputDir, const std::string& format, const std::string& extension, const std::string& os) {
    // Create the output directory
    fs::path outputDir = inputDir.string() + " Resolve Format";
    if (!fs::exists(outputDir)) {
        fs::create_directory(outputDir);
    }

    // Iterate through all files in the input directory
    for (const auto& entry : fs::directory_iterator(inputDir)) {
        if (entry.is_regular_file()) {
            fs::path inputFile = entry.path();
            fs::path outputFile = outputDir / inputFile.filename();
            outputFile.replace_extension(extension);

            std::string command;

            if (os == "Windows" || os == "macOS") {
                if (format == "ProRes") {
                    command = "ffmpeg -i \"" + inputFile.string() + "\" -c:v prores_ks -profile:v 3 -vendor apl0 -c:a pcm_s16le \"" + outputFile.string() + "\"";
                } else if (format == "DNxHD" || format == "DNxHR") {
                    command = "ffmpeg -i \"" + inputFile.string() + "\" -c:v dnxhd -profile:v dnxhr_hq -pix_fmt yuv422p -c:a pcm_s16le \"" + outputFile.string() + "\"";
                }
            } else if (os == "Linux" && format == "DNxHR") {
                command = "ffmpeg -i \"" + inputFile.string() + "\" -c:v dnxhd -profile:v dnxhr_hq -pix_fmt yuv422p -c:a pcm_s16le \"" + outputFile.string() + "\"";
            }

            std::cout << "Executing: " << command << std::endl;

            int result = std::system(command.c_str());
            if (result != 0) {
                std::cerr << "Error converting file: " << inputFile << std::endl;
            } else {
                std::cout << "Successfully converted: " << inputFile << " to " << outputFile << std::endl;
            }
        }
    }
}

int main(int argc, char* argv[]) {
    try {
        if (argc != 2) {
            throw std::invalid_argument("Usage: " + std::string(argv[0]) + " <input_directory>");
        }

        fs::path inputDir = argv[1];
        if (!fs::exists(inputDir)) {
            throw std::invalid_argument("Directory does not exist: " + inputDir.string());
        }
        if (!fs::is_directory(inputDir)) {
            throw std::invalid_argument("Path is not a directory: " + inputDir.string());
        }

        std::string os = detectOS();
        if (os == "Unknown") {
            throw std::runtime_error("Unsupported operating system.");
        }
        std::cout << "Detected OS: " << os << std::endl;

        std::vector<std::pair<std::string, std::string>> supportedFormats = getSupportedFormats(os);
        if (supportedFormats.empty()) {
            throw std::runtime_error("No supported formats available for the detected OS.");
        }
        
        std::cout << "Supported formats:" << std::endl;
        for (size_t i = 0; i < supportedFormats.size(); ++i) {
            std::cout << i + 1 << ". " << supportedFormats[i].first << " (" << supportedFormats[i].second << ")" << std::endl;
        }

        int selectedIndex;
        std::cout << "Enter the number of the desired format: ";
        std::cin >> selectedIndex;

        if (selectedIndex < 1 || selectedIndex > supportedFormats.size()) {
            throw std::invalid_argument("Invalid format selection.");
        }

        std::string selectedFormat = supportedFormats[selectedIndex - 1].first;
        std::string selectedExtension = supportedFormats[selectedIndex - 1].second;

        convertToResolveFormat(inputDir, selectedFormat, selectedExtension, os);

    } catch (const std::invalid_argument& e) {
        std::cerr << "Invalid argument: " << e.what() << std::endl;
        return 1;
    } catch (const std::runtime_error& e) {
        std::cerr << "Runtime error: " << e.what() << std::endl;
        return 1;
    } catch (const std::exception& e) {
        std::cerr << "An error occurred: " << e.what() << std::endl;
        return 1;
    }

    return 0;
}
