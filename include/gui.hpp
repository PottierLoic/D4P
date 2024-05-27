#pragma once

#include <iostream>
#include <string>

#include <imgui-SFML.h>
#include <imgui.h>
#include <imgui_stdlib.h>

class Gui {
public:
  void display();
  void displayBar();
  void displaySaveAs();
  void displayStats();
  void displayImportExport();
  void displaySkillTree();
  void displayParagonTree();
  void displayItems();
  void displayConfiguration();
  void displayCalculations();
private:
  // Determine if usefull
  bool showSaveAs = false;
  bool showStats = true;
  bool showImportExport = true;
  bool showSkillTree = true;
  bool showParagonTree = true;
  bool showItems = true;
  bool showConfiguration = true;
  bool showCalculations = true;

  std::string saveName; // buffer for build name in save as menu
};
