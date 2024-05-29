#pragma once

#include <string>
#include <map>
#include <iostream>

#include "class.hpp"

class Build {
public:
  Build(std::string name, Class cl);

  void setName(const std::string name);
  std::string getName();

  void setStatistic(const std::string& key, const float value);
  float getStatistic(const std::string& key) const;

  void setPlayerAilment(const std::string& key, const bool value);
  std::map<std::string, bool>& getPlayerAilments(); // TODO: remove this bullshit function erk

  void setEnemyAilment(const std::string& key, const bool value);
  std::map<std::string, bool>& getEnemyAilments(); // TODO: remove this bullshit function erk

  void setClass(const Class cl);
  Class getClass() const;

private:
  std::string name;
  Class buildClass;
  std::map<std::string, float> statistics;
  std::map<std::string, bool> playerAilments;
  std::map<std::string, bool> enemyAilments;

  void setBaseStats(); // called in setClass only
  void initAilments(); // called in constructor only
};
