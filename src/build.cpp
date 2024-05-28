#include "build.hpp"

Build::Build(Class cl) {
  this->buildClass = cl;
  setBaseStats();
  setProperty("level", 1);
}

void Build::setProperty(const std::string& key, const float value) {
  properties[key] = value;
}

float Build::getProperty(const std::string& key) const {
  auto it = properties.find(key);
  if (it != properties.end()) {
    return it->second;
  }
  return 0.0f;
}

void Build::printProperties() const {
  for (const auto& pair : properties) {
    std::cout << pair.first << ": " << pair.second << std::endl;
  }
}

void Build::setBaseStats() {
  BaseStats stats = classStats[buildClass];
  setProperty("base-strength", stats.strength);
  setProperty("base-dexterity", stats.dexterity);
  setProperty("base-intelligence", stats.intelligence);
  setProperty("base-willpower", stats.willpower);
}