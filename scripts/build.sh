usage() {
    echo "Usage: $0 --build_type <type> [Debug / Release]"
    exit 1
}

# Initialize variables
BUILD_TYPE="Debug"

# Parse command-line arguments
while [[ $# -gt 0 ]]; do
    case "$1" in
        --build_type)
            BUILD_TYPE="$2"
            if [[ "$BUILD_TYPE" != "Debug" && "$BUILD_TYPE" != "Release" ]]; then
                echo "Error: build_type must be either 'Debug' or 'Release'."
                exit 1
            fi
            shift 2
            ;;
        *)
            echo "Unknown option: $1"
            usage
            ;;
    esac
done
# Output the parsed options
echo "Build Type: $BUILD_TYPE"

conan install . --output-folder=build --build=missing -s build_type="$BUILD_TYPE"
cd build
cmake .. -DCMAKE_CXX_COMPILER_LAUNCHER=ccache -DCMAKE_TOOLCHAIN_FILE="build/build/$BUILD_TYPE/generators/conan_toolchain.cmake"  -DCMAKE_CXX_COMPILER=/usr/bin/clang++ -DCMAKE_C_COMPILER=/usr/bin/clang -DCMAKE_MAKE_PROGRAM=/usr/bin/make -DCMAKE_BUILD_TYPE="$BUILD_TYPE"
cmake --build . --config "$BUILD_TYPE"