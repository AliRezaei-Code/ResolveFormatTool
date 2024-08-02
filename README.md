### Repository Description

**ResolveConverter** is a C++ tool that converts all video files in a directory to DaVinci Resolve-compatible `.mov` format using FFmpeg. It maintains original video quality and resolution, creating a new output directory with the suffix "Resolve Format."

### README.md

```markdown
# ResolveConverter

ResolveConverter is a C++ tool that converts all video files in a directory to DaVinci Resolve-compatible `.mov` format using FFmpeg. It maintains original video quality and resolution, creating a new output directory with the suffix "Resolve Format."

## Features
- Converts videos to DaVinci Resolve-compatible `.mov` format
- Maintains original video quality and resolution
- Creates a new directory for converted files

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
   g++ -std=c++17 -o convert_to_resolve convert_to_resolve.cpp
   ```
4. Run the program with the input directory as an argument:
   ```sh
   ./convert_to_resolve /path/to/your/input_directory
   ```

## Contributions
Contributions are welcome! Open an issue or submit a pull request for improvements or new features.
