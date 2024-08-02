# ResolveConverter

ResolveConverter is a C++ program that converts video files in a directory to DaVinci Resolve-compatible `.mov` format using FFmpeg. It preserves the original quality and resolution, creating a new directory named `[inputdirectory name] Resolve Format` for the converted files.

## Features
- Converts all video files in the specified directory.
- Creates a new directory for the converted files.
- Utilizes FFmpeg to ensure compatibility with DaVinci Resolve.
- Maintains original video quality and resolution.

## Requirements
- C++17 or later
- FFmpeg installed and accessible in the system's PATH

## Usage
1. Clone the repository:
   ```sh
   git clone https://github.com/yourusername/ResolveConverter.git
   ```
2. Navigate to the repository directory:
   ```sh
   cd ResolveConverter
   ```
3. Compile the program:
   ```sh
   g++ -std=c++17 -o formatter formatter.cpp
   ```
4. Run the program with the input directory as an argument:
   ```sh
   ./formatter /path/to/your/input_directory
   ```

## Contributions
Contributions are welcome! Open an issue or submit a pull request for improvements or new features.
