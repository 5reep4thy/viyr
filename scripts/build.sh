conan install . --output-folder=build --build=missing
cd build
cmake .. -DCMAKE_CXX_COMPILER_LAUNCHER=ccache -DCMAKE_TOOLCHAIN_FILE="build/build/Debug/generators/conan_toolchain.cmake"  -DCMAKE_CXX_COMPILER=/usr/bin/clang++ -DCMAKE_C_COMPILER=/usr/bin/clang -DCMAKE_MAKE_PROGRAM=/usr/bin/make -DCMAKE_BUILD_TYPE=Debug
cmake --build . --config Debug