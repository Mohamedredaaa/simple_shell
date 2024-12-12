# Simple Shell

## Overview
The **Simple Shell** project is a custom implementation of a Unix shell created in C. It serves as a foundational project for understanding system programming concepts, including process creation, file descriptors, and handling user input.

---

## Features
- **Interactive Mode**: Allows users to type commands and receive immediate feedback.
- **Non-Interactive Mode**: Executes commands passed as input in a script or pipeline.
- **Builtin Commands**: Includes a set of builtin commands like `exit`, `cd`, and more.
- **Error Handling**: Handles invalid commands and errors gracefully.
- **Custom Utilities**: Implements helper functions for command parsing and execution.

---

## Project Structure
```
simple_shell
├── builtin_functions.c          # Implementation of shell builtin commands
├── helper.c                     # General helper functions
├── helper_1.c                   # Additional helper functions
├── helper_2.c                   # Supplementary helper functions
├── initializer_function.c       # Functions for initializing shell components
├── non_interactive_function.c   # Functions for handling non-interactive mode
├── shell.h                      # Header file with function prototypes and macros
├── shell_main.c                 # Main shell loop and entry point
├── shell_utils.c                # Utility functions for shell operations
├── README.md                    # Documentation for the project
```

---

## How to Compile
To compile the shell, use the `gcc` compiler with the following command:
```bash
gcc -Wall -Werror -Wextra -pedantic *.c -o simple_shell
```

This will generate an executable file named `simple_shell`.

---

## How to Run
### Interactive Mode
Run the shell by executing the compiled file:
```bash
./simple_shell
```
The shell will wait for user input, execute commands, and display the results.

### Non-Interactive Mode
Pipe a file or set of commands into the shell:
```bash
echo "ls -l" | ./simple_shell
```

---

## Builtin Commands
- **`exit`**: Exits the shell.
  ```bash
  exit
  ```
- **`cd`**: Changes the current working directory.
  ```bash
  cd /path/to/directory
  ```
- Additional builtins can be found in `builtin_functions.c`.

---

## External Commands
The shell supports execution of external commands by searching for them in the system's `PATH` environment variable.
For example:
```bash
ls -la
```

---

## Error Handling
The shell gracefully handles errors, including:
- Invalid commands.
- Missing files or directories.
- Syntax errors.

---

## Requirements
- GCC compiler.
- A Unix-like operating system.

---

## Contributing
Contributions are welcome! Feel free to fork the repository, make changes, and submit a pull request.

---

## License
This project is for educational purposes and is not licensed for commercial use. Please refer to the project's documentation for further details.

