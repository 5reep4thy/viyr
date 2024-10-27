from conan import ConanFile
from conan.tools.cmake import cmake_layout, CMakeToolchain


class ExampleRecipe(ConanFile):
    settings = "os", "compiler", "build_type", "arch"
    generators = "CMakeDeps", "CMakeToolchain"

    def requirements(self):
        self.requires("nlohmann_json/3.11.3")
        self.requires("boost/1.86.0")

    def layout(self):
        cmake_layout(self)

