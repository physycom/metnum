mkdir -Force build
cd build
cmake .. -G "Visual Studio 15" "-DCMAKE_TOOLCHAIN_FILE=$env:WORKSPACE\vcpkg\scripts\buildsystems\vcpkg.cmake"
cmake --build . --target install
cd ..
