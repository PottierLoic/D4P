#pragma once

#include <string>
#include <map>
#include <iostream>
#include <vector>

#include "class.hpp"
#include "item.hpp"

class Build {
public:
  std::string name;

  Build(std::string name, Class cl);

  void setClass(const Class cl);
  Class getClass() const;
  void setStatistic(const std::string& key, const float value);
  float getStatistic(const std::string& key) const;

  void setPlayerAilment(const std::string& key, const bool value);
  std::map<std::string, bool>& getPlayerAilments();
  void setEnemyAilment(const std::string& key, const bool value);
  std::map<std::string, bool>& getEnemyAilments();
private:
  Class buildClass;

  std::map<std::string, float> statistics; /** full stats list of the build */
  std::map<std::string, bool> playerAilments; /** Ailments applied to the player */
  std::map<std::string, bool> enemyAilments; /** Ailments applied to the enemy*/

  void setBaseStats(); // called in setClass only
  void initAilments(); // called in constructor only
};
