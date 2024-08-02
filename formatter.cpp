#include <iostream>
#include <filesystem>
#include <cstdlib>

namespace fs = std::filesystem;

void convertToResolveFormat(const fs::path& inputDir) {
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
            outputFile.replace_extension(".mov"); // Using .mov for DaVinci Resolve compatibility

            std::string command = "ffmpeg -i \"" + inputFile.string() + "\" -c:v copy -c:a copy \"" + outputFile.string() + "\"";
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
    if (argc != 2) {
        std::cerr << "Usage: " << argv[0] << " <input_directory>" << std::endl;
        return 1;
    }

    fs::path inputDir = argv[1];
    if (!fs::exists(inputDir) || !fs::is_directory(inputDir)) {
        std::cerr << "Invalid directory: " << inputDir << std::endl;
        return 1;
    }

    convertToResolveFormat(inputDir);

    return 0;
}
