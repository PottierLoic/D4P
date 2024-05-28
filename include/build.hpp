#pragma once

#include <string>
#include <map>
#include <iostream>

#include "class.hpp"

class Build {
public:
  Build(Class cl);
  void setProperty(const std::string& key, const float value);
  float getProperty(const std::string& key) const;
  void printProperties() const;

  void setBaseStats();
private:
  Class buildClass;
  std::map<std::string, float> properties;
};
