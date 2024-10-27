#include <fstream>
#include "nlohmann/json.hpp"
#include <iostream>
#include <boost/algorithm/string/case_conv.hpp>
using json = nlohmann::json;
int main() {
    std::ifstream f("files/example.json");
    json data = json::parse(f);
    std::string strData = data["title"];
    boost::algorithm::to_lower(strData);
    std::cout << strData << "\n";
    return 0;
}
