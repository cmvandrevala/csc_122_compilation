# CSC 122 - Compilation Demo

## Background

Let's start by checking out the `.gitignore` file. What are all of those file extensions used for?

## Steps to Compile C++ Code

1. Preprocessing
    * Copy the contents of header files into the source code
    * Generate macros
    * Replace symbolic constants defined using `#define`
2. Compilation
    * Turn source code into assembler code
3. Assembly
    * Turn assembler code into object code for the platform
4. Linking
    * Combine different object files into one executable program

## Compilation Commands

### Stop at Preprocessing

```bash
g++ -Wall -Werror -ansi -pedantic -std=c++14 -E main.cpp source.cpp
```

### Stop at Compilation

```bash
g++ -Wall -Werror -ansi -pedantic -std=c++14 -S main.cpp source.cpp
```

### Stop at Assembly

```bash
g++ -Wall -Werror -ansi -pedantic -std=c++14 -c main.cpp source.cpp
```

View the dump of the object file:

```bash
objdump -d main.o
```

### Link Together Object Files

```bash
g++ -o prog main.o source.o
```

## Statically Linked Libraries

A static library in C++ is an archive of object files that can be linked with other object files to create an executable.

```bash
ar -crs my_static_library.a source.o
```

```bash
g++ -Wall -Werror -ansi -pedantic -std=c++14 main.cpp my_static_library.a -o prog
```

## Dynamically Linked / Shared Object Libraries

```bash
gcc -shared -o source.so source.o
```

```bash
gcc -L<path to .SO file> -Wall -o code main.c -l<library name>
```

This line should compile and link the code... but I am not sure what is going on with my MacBook 😖

```bash
g++ main.cpp -L/Users/cyrus/Projects/harper/122/csc_122_compilation_demo/source -Wall -o prog -L /Users/cyrus/Projects/harper/122/csc_122_compilation_demo
```

An example with [SFML](https://www.sfml-dev.org/):

```bash
g++ sfml.cpp --std=c++14 -I/opt/homebrew/Cellar/sfml/2.6.1/include -o prog -L /opt/homebrew/Cellar/sfml/2.6.1/lib -lsfml-window -lsfml-system -lsfml-graphics
```
