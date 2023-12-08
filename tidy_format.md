`clang-tidy` and `clang-format` are tools provided by the Clang project, which is a compiler front end for the C, C++, and Objective-C programming languages. These tools help improve code quality and maintain consistent coding styles.

- They are part of LLVM: https://github.com/llvm/llvm-project/releases/tag/llvmorg-17.0.1
- For Windows it is recommented to install this version: https://github.com/llvm/llvm-project/releases/download/llvmorg-17.0.1/LLVM-17.0.1-win64.exe

### `clang-tidy`

`clang-tidy` is a tool that analyzes C++ code and suggests improvements based on a set of predefined or user-defined rules. Here's a basic example of how to use `clang-tidy`:

1. **Install Clang:**
   Ensure you have Clang installed on your system. You can install it using your package manager or download it from the official Clang website.

2. **Run `clang-tidy`:**
   Open a terminal and navigate to the directory containing your C++ source code. Run the following command:

   ```bash
   clang-tidy your_file.cpp
   ```

   Replace `your_file.cpp` with the actual name of your C++ source file.

   `clang-tidy` will analyze the code and provide suggestions for improvements based on its rules.

3. **Use a Configuration File:**
   You can create a configuration file (e.g., `.clang-tidy`) to customize the checks and their options. Here's a simple example:

   ```yaml
   Checks: '-*,modernize-*'
   WarningsAsErrors: '*'
   HeaderFilterRegex: '.*'
   ```

   This configuration file, when placed in the project directory, tells `clang-tidy` to enable all modernization checks and treat all warnings as errors.

### `clang-format`

`clang-format` is a tool that automatically formats C, C++, and Objective-C code according to a specified coding style. Here's an example of how to use `clang-format`:

1. **Install Clang:**
   Ensure you have Clang installed on your system.

2. **Create a Style Configuration File:**
   Create a `.clang-format` file in your project directory or specify the style options directly in the command line. Here's an example configuration:

   ```yaml
   BasedOnStyle: LLVM
   IndentWidth: 4
   UseTab: Never
   ```

   This configuration sets the style based on the LLVM style, uses 4 spaces for indentation, and specifies not to use tabs.

3. **Run `clang-format`:**
   Open a terminal and navigate to the directory containing your C++ source code. Run the following command:

   ```bash
   clang-format -i your_file.cpp
   ```

   Replace `your_file.cpp` with the actual name of your C++ source file.

   The `-i` option modifies the file in place.
