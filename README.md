#### Steps:

1. conan profile detect --force
2. conan install . --output-folder=build --build=missing
3. cd build
4. cmake .. -DCMAKE_TOOLCHAIN_FILE="build/build/Release/generators/conan_toolchain.cmake"  -DCMAKE_CXX_COMPILER=/usr/bin/clang++ -DCMAKE_C_COMPILER=/usr/bin/clang -DCMAKE_MAKE_PROGRAM=/usr/bin/make -DCMAKE_BUILD_TYPE=Release
5. cmake --build . --config Release
