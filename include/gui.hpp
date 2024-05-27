#pragma once

#include <iostream>
#include <string>

#include <imgui-SFML.h>
#include <imgui.h>
#include <imgui_stdlib.h>

class Gui {
public:
  void display();
  void displayMenuBar();
  void displaySaveAsMenu();
private:
  bool showSaveMenu = false;
  bool showSaveAsMenu = false;

  std::string saveName;
};
