#pragma once

#include "affix.hpp"

class Stat : public IAffix {
  std::string statName;
  float value;
};