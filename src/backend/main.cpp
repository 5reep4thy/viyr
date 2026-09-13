#include "nlohmann/json.hpp"
#include <boost/algorithm/string/case_conv.hpp>
#include <fstream>
#include <iostream>
using json = nlohmann::json;
#include <boost/log/trivial.hpp>

class MainConfig {
  uint32_t m_version;
  std::string m_tag;

public:
  static constexpr const char *const TagString = "Tag";
  static constexpr const char *const VersionString = "Version";
  MainConfig(uint32_t _version, std::string _tag)
      : m_version(_version), m_tag(_tag) {}
  uint32_t getVersion() { return m_version; }
  std::string getTag() { return m_tag; }
};

int main() {
  std::ifstream f("files/config.json");
  json data;

  try {
    data = json::parse(f);
  } catch (json::exception &exc) {
    BOOST_LOG_TRIVIAL(error)
        << "Something went wrong parsing the JSON file: " << exc.what();
  }
  uint32_t version = data["version"];
  std::string tag = data["tag"];
  MainConfig mainConfig(version, tag);
  std::cout << MainConfig::TagString << ": " << mainConfig.getTag() << "\n";
  std::cout << MainConfig::VersionString << ": " << mainConfig.getVersion()
            << "\n";

  return 0;
}
