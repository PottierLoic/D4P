#include "gui.hpp"

void Gui::display() {
  displayMenuBar();
  if (showSaveAsMenu) { displaySaveAsMenu(); }
}

void Gui::displayMenuBar() {
  if (ImGui::BeginMainMenuBar()) {
    if (ImGui::MenuItem("Back")) {}
    ImGui::MenuItem("Current build: TODO INSERT NAME", NULL, false, false);
    if (ImGui::MenuItem("Save")) {
      // TODO: Implement save function
      std::cout<< "Save button pressed" <<std::endl;
    }
    if (ImGui::MenuItem("Save As")) {
      showSaveAsMenu = true;
    }
    ImGui::EndMainMenuBar();
  }
}


void Gui::displaySaveAsMenu() {
  if (ImGui::Begin("Save build")) {
    ImGui::Text("Build name: ");
    ImGui::SameLine(100);
    ImGui::InputText("##save-name", &saveName);
    if (ImGui::Button("Cancel")) { showSaveAsMenu = false; }
    ImGui::SameLine();
    if (ImGui::Button("Save")) {
      // TODO: Implement save as function
      std::cout << "Save as button pressed" << std::endl; 
    }
  }
  ImGui::End();
}
