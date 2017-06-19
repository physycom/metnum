mkdir -Force build
cd build
cmake .. -G "Visual Studio 15" "-DCMAKE_TOOLCHAIN_FILE=$env:WORKSPACE\vcpkg\scripts\buildsystems\vcpkg.cmake" "-DVCPKG_TARGET_TRIPLET=x86-windows-static"
cmake --build . --target install --config Release
#cmake --build . --target install --config Debug
cd ..
