
# Resolve Format Tool

This tool converts all video files in a specified directory into a format that can be imported into DaVinci Resolve. It creates a new directory named `[inputdirectory name] Resolve Format` and places the converted videos in that directory.

## Features
- Auto-detects the operating system (Windows, macOS, Linux) and adjusts supported formats accordingly.
- Allows users to select the desired output format by entering an index number.
- Ensures compatibility with DaVinci Resolve by using appropriate codecs.
- Handles filenames with spaces properly by quoting paths in the FFmpeg command.

## Prerequisites
- FFmpeg must be installed on your system and accessible in your system's PATH.
- The program must be compiled with support for filesystem operations (C++17 or later).

## Compilation and Execution

1. **Ensure FFmpeg is installed** and accessible in your system's PATH.
2. **Save the program** to a file, e.g., `formatter.cpp`.
3. **Compile the program** with a C++17 compatible compiler:
   ```sh
   g++ -std=c++17 -o formatter formatter.cpp
   ```
4. **Run the program** with the input directory as an argument:
   ```sh
   ./formatter "/path/to/your/input_directory"
   ```

## Important Notes

- **Program Filename:** Make sure there are no spaces in the name of the program executable. Spaces in the program name can cause the C++ runtime to misinterpret the inline arguments as more than one argument.
- **Directory Names:** If there are any spaces in the folder name, replace them with dashes before running the program.

## Example

Given a directory named `b-roll agile planning video` with spaces:

1. Rename the directory:
   ```sh
   mv "b-roll agile planning video" b-roll-agile-planning-video
   ```
2. Run the program:
   ```sh
   ./formatter "/path/to/b-roll-agile-planning-video"
   ```

By following these instructions, you can ensure that the program runs correctly and efficiently converts your video files for use in DaVinci Resolve.

## Contribution

Feel free to fork this repository, create a new branch, and submit a pull request. For significant changes, please open an issue first to discuss what you would like to change.

## License

This project is licensed under the MIT License - see the [LICENSE](LICENSE) file for details.
