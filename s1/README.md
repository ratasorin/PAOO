# Rectangle calculator

A C++17 application calculates the area and perimeter of a rectangle. The
static library in `lib/` provides `Calculator::rectangleArea` and
`Calculator::rectanglePerimeter`; `app/` calls these functions for an example
rectangle. Both functions require positive dimensions and throw
`std::invalid_argument` otherwise.

## Build and run

Requires CMake 3.16 or newer and a C++17 compiler. From `s1/`:

```sh
cmake -S . -B build
cmake --build build
./build/app/app
```

For the example dimensions 6 and 3, the area is 18 and the perimeter is 18.
With a multi-configuration generator, the executable may be under
`build/app/Debug/` or `build/app/Release/`.

## Install the library

```sh
cmake -S lib -B build/lib -DCMAKE_INSTALL_PREFIX="$PWD/install"
cmake --build build/lib
cmake --install build/lib
```

Another CMake project can set `CMAKE_PREFIX_PATH` to that install prefix and
call `find_package(Calculator 1 CONFIG REQUIRED)`. The exported target is
`Lib::calculator`.
