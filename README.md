# D4P - Diablo 4 Planner

D4P is a WIP build planner for the game Diablo 4.  
It is heavily inspired by Path of Building.

Please note that this is a solo project and is currently a work in progress. It will take a long time before a fully usable version is released, if any.

## Building from source

### Requirements

- [CMake](https://cmake.org/).
- Make
- a C++ compiler (MSVC, g++, Clang, ...)

### Building

First, get the repository on your computer.
```bash
git clone https://github.com/PottierLoic/D4P.git
cd D4P
```

Get the submodules too
```bash
git submodule init
git submodule update
```

Then simply run the build script
```bash
sh build.sh
```

The executable is created in the `build` folder.

## License

This project is licensed under the [MIT License](LICENSE).

