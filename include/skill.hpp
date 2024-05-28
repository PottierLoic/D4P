#pragma once

#include <string>
#include <vector>
#include <fstream>
#include <stdexcept>
#include <iostream>

#include <nlohmann/json.hpp>

using json = nlohmann::json;

enum SkillType {
  Basic,
  Core,
  Defensive,
  Brawling,
  WeaponMastery,
  Ultimate,
  KeyPassive,
};

class Skill {
public:
  static void loadSkillTypes(const std::string& filePath);
  static std::vector<std::string> skillTypeList;

  std::string name;
  std::string type;
  std::vector<std::string> tags;
  Skill(std::string name, SkillType type, std::vector<std::string> tags);
};
