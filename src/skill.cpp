#include "skill.hpp"

std::vector<std::string> Skill::skillTypeList;

void Skill::loadSkillTypes(const std::string& filePath) {
  std::ifstream file(filePath);
  if (!file.is_open()) {
    throw std::runtime_error("Cannot open JSON file");
  }

  json jsonData;
  file >> jsonData;
  file.close();

  for (const auto& skillType : jsonData["skillTypes"]) {
    skillTypeList.push_back(skillType);
  }
}

Skill::Skill(std::string name, SkillType type, std::vector<std::string> tags) {
  name = name;
  type = type;
  tags = tags;
}

