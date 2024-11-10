#include <fstream>
#include "nlohmann/json.hpp"
#include <iostream>
#include <boost/algorithm/string/case_conv.hpp>
using json = nlohmann::json;
#include <boost/log/trivial.hpp>

int main() {
    std::ifstream f("files/example.json");
    json data;

    try {
        data = json::parse(f);
        std::string strData = data["title"];
        boost::algorithm::to_lower(strData);
        std::cout << strData << "\n";
        std::vector<int> x;
        int h = 12;
        x.push_back(h);
    }

    catch (json::exception) {
        BOOST_LOG_TRIVIAL(error) << "Something went wrong parsing the JSON file";
    }

    return 0;
}
