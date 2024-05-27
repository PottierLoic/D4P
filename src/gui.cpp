#include "gui.hpp"

void Gui::display() {
  displayMenuBar();
  displayTestWindow();
}

void Gui::displayMenuBar() {
  if (ImGui::BeginMainMenuBar()) {
    if (ImGui::BeginMenu("File")) {
      if (ImGui::MenuItem("New build")) {}
      if (ImGui::MenuItem("Open build")) {}
      ImGui::EndMenu();
    }
    ImGui::EndMainMenuBar();
  }
}

void Gui::displayTestWindow() {
  if (ImGui::Begin("test window")) {
    if (ImGui::Button("test button")) {
      std::cout << "test button clicked" << std::endl; 
    }
  }
  ImGui::End();
}
