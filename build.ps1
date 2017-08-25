#mkdir -Force build_debug
#cd build_debug
#cmake .. -G "Visual Studio 15" "-DCMAKE_TOOLCHAIN_FILE=$env:WORKSPACE\vcpkg\scripts\buildsystems\vcpkg.cmake" "-DVCPKG_TARGET_TRIPLET=x86-windows-static"
#cmake --build . --config Debug
#cd ..
mkdir -Force build
cd build
cmake .. -G "Visual Studio 15" "-DCMAKE_TOOLCHAIN_FILE=$env:WORKSPACE\vcpkg\scripts\buildsystems\vcpkg.cmake" "-DVCPKG_TARGET_TRIPLET=x86-windows-static" "-DCMAKE_BUILD_TYPE=Release"
cmake --build . --target install --config Release
cd ..
