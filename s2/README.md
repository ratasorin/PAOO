# Laboratory equipment inventory

A C++17 application stores measurement readings for laboratory devices and
reports their averages. `lib/` contains the `Device` and `Inventory` classes;
`app/` demonstrates them. The root CMake project builds the library and app.

`Device` encapsulates a dynamically allocated array, initializes its members
in the constructor initializer list, and releases the array in its destructor.
Its copy constructor allocates independent storage; its move constructor takes
ownership and leaves the source empty. Copy and move assignment handle ownership
as well. A default shallow copy would make two devices point to the same array:
changing one would affect the other, and both destructors would try to free it.
The app changes a copied reading and prints both values, then moves the copy and
prints the source and destination sizes. Constructor and destructor messages
make object lifetimes visible. `Inventory` holds devices and accepts copies or
moves; it checks access through `std::vector::at`.

Requires CMake 3.16 or newer and a C++17 compiler. From `s2/`:

```sh
cmake -S . -B build
cmake --build build
./build/app/app
```

For a multi-configuration generator, select a configuration with
`cmake --build build --config Debug` and run `build/app/Debug/app` (or the
corresponding `.exe` on Windows).
