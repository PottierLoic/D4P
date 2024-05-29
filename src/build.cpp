#include "build.hpp"

Build::Build(std::string name, Class cl) {
  this->name = name;
  this->setClass(cl);
  this->initAilments();
  setStatistic("level", 1);
}

void Build::setStatistic(const std::string& key, const float value) {
  statistics[key] = value;
}

float Build::getStatistic(const std::string& key) const {
  auto it = statistics.find(key);
  if (it != statistics.end()) {
    return it->second;
  }
  return 0.0f;
}

void Build::setPlayerAilment(const std::string& key, const bool value) {
  playerAilments[key] = value;
}

std::map<std::string, bool>& Build::getPlayerAilments() {
  return playerAilments;
}

void Build::setEnemyAilment(const std::string& key, const bool value) {
  enemyAilments[key] = value;
}

std::map<std::string, bool>& Build::getEnemyAilments() {
  return enemyAilments;
}

void Build::setClass(const Class cl) {
  this->buildClass = cl;
  this->setBaseStats();
}

Class Build::getClass() const {
  return this->buildClass;
}

void Build::setBaseStats() {
  BaseStats stats = classStats[buildClass];
  setStatistic("base-strength", stats.strength);
  setStatistic("base-dexterity", stats.dexterity);
  setStatistic("base-intelligence", stats.intelligence);
  setStatistic("base-willpower", stats.willpower);
}

void Build::initAilments() {
  std::map<std::string, bool> tmp = {
    {"chilled", false},
    {"frozen", false},
    {"immune", false},
    {"unstoppable", false},
    {"vulnerable", false},
    {"fortified", false},
    {"berserking", false},
    {"barrier", false},
    {"blood orb", false},
    {"crackling energy", false},
    {"dazed", false},
    {"healthy", false},
    {"injured", false},
    {"overpower", false},
    {"stealth", false}
  };
  playerAilments = tmp;
  enemyAilments = tmp;
};
