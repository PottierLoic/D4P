#pragma once

#include <iostream>
#include <string>

#include <imgui-SFML.h>
#include <imgui.h>
#include <imgui_stdlib.h>

extern const char* worldTiers[];

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
  void displayNotes();
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
  bool showNotes = true;

  // TODO: remove once there are real stats to use (build class)
  int tmp1 = 0;
  int tmp2 = 0;
  bool tmp3 = false;
  int worldTierIndex = 0;
  const char* worldTierValue = worldTiers[worldTierIndex];
  float stats = 100.0;
  char notesText[1024 * 32] = "Example text";


  std::string saveName; // buffer for build name in save as menu
};
