#pragma once

#include <map>

enum Class {
  BARBARIAN,
  NECROMANCER,
  DRUID,
  SORCERER,
  ROGUE,
};

struct BaseStats {
  int strength;
  int dexterity;
  int intelligence;
  int willpower;
};

extern std::map<Class, BaseStats> classStats;
