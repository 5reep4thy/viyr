#include <fstream>
#include "nlohmann/json.hpp"
#include <iostream>
using json = nlohmann::json;
int main() {
    std::ifstream f("files/example.json");
    json data = json::parse(f);
    std::cout << data["title"] << "\n";
    return 0;
}
