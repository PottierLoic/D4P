#include "gui.hpp"

void Gui::display() {
  displayBar();
  if (showSaveAs) { displaySaveAs(); }
  if (showStats) { displayStats(); }
  if (showSkillTree) { displaySkillTree(); }
  if (showParagonTree) { displayParagonTree(); }
  if (showItems) { displayItems(); }
  if (showConfiguration) { displayConfiguration(); }
  if (showCalculations) { displayCalculations(); }
}

void Gui::displayBar() {
  if (ImGui::BeginMainMenuBar()) {
    if (ImGui::MenuItem("Back")) {}
    ImGui::MenuItem("Current build: TODO INSERT NAME", NULL, false, false);
    if (ImGui::MenuItem("Save")) {
      // TODO: Implement save function
      std::cout<< "Save button pressed" <<std::endl;
    }
    if (ImGui::MenuItem("Save As")) {
      showSaveAs = true;
    }
    ImGui::EndMainMenuBar();
  }
}

void Gui::displaySaveAs() {
  if (ImGui::Begin("Save build")) {
    ImGui::Text("Build name: ");
    ImGui::SameLine(100);
    ImGui::InputText("##save-name", &saveName);
    if (ImGui::Button("Cancel")) { showSaveAs = false; }
    ImGui::SameLine();
    if (ImGui::Button("Save")) {
      // TODO: Implement save as function
      std::cout << "Save as button pressed" << std::endl; 
    }
  }
  ImGui::End();
}

void Gui::displayStats() {
  if (ImGui::Begin("Statistics")) {
    // TODO
    ImGui::Text("Health");
    ImGui::Text("Cheese");
  }
  ImGui::End();
}

void Gui::displaySkillTree() {
  if (ImGui::Begin("Skill Tree")) {
    // TODO
  }
  ImGui::End();
}


void Gui::displayParagonTree() {
  if (ImGui::Begin("Paragon Tree")) {
    // TODO
  }
  ImGui::End();
}

void Gui::displayItems() {
  if (ImGui::Begin("Items")) {
    // TODO
  }
  ImGui::End();
}

void Gui::displayConfiguration() {
  if (ImGui::Begin("Configuration")) {
    ImGui::PushStyleColor(ImGuiCol_Text, IM_COL32(0,255,0,255));
    ImGui::Text("World Effects:");
    ImGui::PopStyleColor();
    ImGui::SeparatorText("Altar Bonuses");
    //TODO: use a real variable located in build class
    ImGui::Text("Strength");
    ImGui::SameLine(100);
    ImGui::SliderInt("##altar-strength", &tmp1, 0, 68);
    ImGui::Text("Intelligence");
    ImGui::SameLine(100);
    ImGui::SliderInt("##altar-intelligence", &tmp1, 0, 68);
    ImGui::Text("Willpower");
    ImGui::SameLine(100);
    ImGui::SliderInt("##altar-willpower", &tmp1, 0, 68);
    ImGui::Text("Dexterity");
    ImGui::SameLine(100);
    ImGui::SliderInt("##altar-dexterity", &tmp1, 0, 68);
    ImGui::Text("Paragon points");
    ImGui::SameLine(120);
    ImGui::SliderInt("##altar-paragon", &tmp2, 0, 4);
  }
  ImGui::End();
}

void Gui::displayCalculations() {
  if (ImGui::Begin("Calculations")) {
    // TODO
  }
  ImGui::End();
}
