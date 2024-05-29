#pragma once

#include <iostream>
#include <string>
#include <memory>

#include <imgui-SFML.h>
#include <imgui.h>
#include <imgui_stdlib.h>

#include "build.hpp"

extern const char* worldTiers[];

class Gui {
public:
  void display();

  /**
  * @brief Initialize the gui.
  * @param &build: Reference to actual build.
  */
  Gui(std::unique_ptr<Build> build);

private:
  bool showSaveAs = false;
  std::unique_ptr<Build> currentBuild;

  /* Display functions splitted by window */
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

  // TODO: remove once there are real stats to use (build class)
  int tmp1 = 0;
  int tmp2 = 0;
  bool tmp3 = false;
  int worldTierIndex = 0;
  const char* worldTierValue = worldTiers[worldTierIndex];
  float stats = 100.0;
  char notesText[1024 * 32] = "Example text";
  bool tmp4 = false;

  std::string saveName; // buffer for build name in save as menu
};
