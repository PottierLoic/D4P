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
    //TODO: use real variables located in build class instead of tmp1/tmp2
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
    if (ImGui::Button("All##check-all-altar-bonuses")) {
      tmp1 = 68;
      tmp2 = 4;
    }
    ImGui::SameLine();
    if (ImGui::Button("None##check-all-altar-bonuses")) {
      tmp1 = 0;
      tmp2 = 0;
    }
    ImGui::SeparatorText("Renown Bonuses");
    // TODO: use real variables located in build class instead of tmp3
    if (ImGui::BeginTable("##renown-bonuses", 5)) {
      // Table head
      ImGui::TableNextRow();
      ImGui::TableSetColumnIndex(0);
      ImGui::Text("Fractured Peaks");
      ImGui::TableSetColumnIndex(1);
      ImGui::Text("Scoglen");
      ImGui::TableSetColumnIndex(2);
      ImGui::Text("Dry Steppes");
      ImGui::TableSetColumnIndex(3);
      ImGui::Text("Kehjistan");
      ImGui::TableSetColumnIndex(4);
      ImGui::Text("Hawezar");
      // +1 skill point row
      ImGui::TableNextRow();
      ImGui::TableSetColumnIndex(0);
      ImGui::Checkbox("+1 Skill Point##fractured-peak-+1-skill-point", &tmp3);
      ImGui::TableSetColumnIndex(1);
      ImGui::Checkbox("+1 Skill Point##scoglen-+1-skill-point", &tmp3);
      ImGui::TableSetColumnIndex(2);
      ImGui::Checkbox("+1 Skill Point##dry-steppes-+1-skill-point", &tmp3);
      ImGui::TableSetColumnIndex(3);
      ImGui::Checkbox("+1 Skill Point##kehjistan-+1-skill-point", &tmp3);
      ImGui::TableSetColumnIndex(4);
      ImGui::Checkbox("+1 Skill Point##hawezar-+1-skill-point", &tmp3);
      // +1 potion capacity row
      ImGui::TableNextRow();
      ImGui::TableSetColumnIndex(0);
      ImGui::Checkbox("+1 Potion Capacity##fractured-peak-+1-potion-capacity", &tmp3);
      ImGui::TableSetColumnIndex(1);
      ImGui::Checkbox("+1 Potion Capacity##scoglen-+1-potion-capacity", &tmp3);
      ImGui::TableSetColumnIndex(2);
      ImGui::Checkbox("+1 Potion Capacity##dry-steppes-+1-potion-capacity", &tmp3);
      ImGui::TableSetColumnIndex(3);
      ImGui::Checkbox("+1 Potion Capacity##kehjistan-+1-potion-capacity", &tmp3);
      ImGui::TableSetColumnIndex(4);
      ImGui::Checkbox("+1 Potion Capacity##hawezar-+1-potion-capacity", &tmp3);
      // +1 skill point row
      ImGui::TableNextRow();
      ImGui::TableSetColumnIndex(0);
      ImGui::Checkbox("+1 Skill Point##fractured-peak-+1-skill-point", &tmp3);
      ImGui::TableSetColumnIndex(1);
      ImGui::Checkbox("+1 Skill Point##scoglen-+1-skill-point", &tmp3);
      ImGui::TableSetColumnIndex(2);
      ImGui::Checkbox("+1 Skill Point##dry-steppes-+1-skill-point", &tmp3);
      ImGui::TableSetColumnIndex(3);
      ImGui::Checkbox("+1 Skill Point##kehjistan-+1-skill-point", &tmp3);
      ImGui::TableSetColumnIndex(4);
      ImGui::Checkbox("+1 Skill Point##hawezar-+1-skill-point", &tmp3);
      // +4 paragon points row
      ImGui::TableNextRow();
      ImGui::TableSetColumnIndex(0);
      ImGui::Checkbox("+4 Paragon Points##fractured-peak-+4-paragon-points", &tmp3);
      ImGui::TableSetColumnIndex(1);
      ImGui::Checkbox("+4 Paragon Points##scoglen-+4-paragon-points", &tmp3);
      ImGui::TableSetColumnIndex(2);
      ImGui::Checkbox("+4 Paragon Points##dry-steppes-+4-paragon-points", &tmp3);
      ImGui::TableSetColumnIndex(3);
      ImGui::Checkbox("+4 Paragon Points##kehjistan-+4-paragon-points", &tmp3);
      ImGui::TableSetColumnIndex(4);
      ImGui::Checkbox("+4 Paragon Points##hawezar-+4-paragon-points", &tmp3);
      ImGui::EndTable();
    }
    if (ImGui::Button("All##check-all-renown-bonuses")) {
      tmp3 = true;
    }
    ImGui::SameLine();
    if (ImGui::Button("None##uncheck-all-renown-bonuses")) {
      tmp3 = false;
    }
  }
  ImGui::End();
}

void Gui::displayCalculations() {
  if (ImGui::Begin("Calculations")) {
    // TODO
  }
  ImGui::End();
}
