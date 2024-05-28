#include "gui.hpp"

const char* worldTiers[] = { "World Tier 1", "World Tier 2", "World Tier 3", "World Tier 4" };

Gui::Gui(std::unique_ptr<Build> build) {
  this->currentBuild = std::move(build);
}

void Gui::display() {
  displayBar();
  if (showSaveAs) { displaySaveAs(); }
  displayStats();
  displaySkillTree();
  displayParagonTree();
  displayItems();
  displayConfiguration();
  displayCalculations();
  displayNotes();
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
    // TODO: Replace with real values from actual build
    ImGui::SeparatorText("Core Stats");
    ImGui::Text("Level");
    ImGui::SameLine(240);
    ImGui::Text("%d", static_cast<int>(stats));
    ImGui::PushStyleColor(ImGuiCol_Text, IM_COL32(255, 80, 80, 255));
    ImGui::Text("Strength");
    ImGui::SameLine(240);
    ImGui::Text("%d", static_cast<int>(stats));
    ImGui::PopStyleColor();
    ImGui::PushStyleColor(ImGuiCol_Text, IM_COL32(51, 253, 255, 255));
    ImGui::Text("Intelligence");
    ImGui::SameLine(240);
    ImGui::Text("%d", static_cast<int>(stats));
    ImGui::PopStyleColor();
    ImGui::PushStyleColor(ImGuiCol_Text, IM_COL32(255, 255, 102, 255));
    ImGui::Text("Willpower");
    ImGui::SameLine(240);
    ImGui::Text("%d", static_cast<int>(stats));
    ImGui::PopStyleColor();
    ImGui::PushStyleColor(ImGuiCol_Text, IM_COL32(102, 255, 102, 255));
    ImGui::Text("Dexterity");
    ImGui::SameLine(240);
    ImGui::Text("%d", static_cast<int>(stats));
    ImGui::PopStyleColor();

    ImGui::SeparatorText("Resistances");
    ImGui::PushStyleColor(ImGuiCol_Text, IM_COL32(255, 80, 80, 255));
    ImGui::Text("Fire Resistance");
    ImGui::SameLine(240);
    ImGui::Text("%d%%", static_cast<int>(stats));
    ImGui::PopStyleColor();
    ImGui::PushStyleColor(ImGuiCol_Text, IM_COL32(255, 255, 102, 255));
    ImGui::Text("Lightning Resistance");
    ImGui::SameLine(240);
    ImGui::Text("%d%%", static_cast<int>(stats));
    ImGui::PopStyleColor();
    ImGui::PushStyleColor(ImGuiCol_Text, IM_COL32(51, 253, 255, 255));
    ImGui::Text("Cold Resistance");
    ImGui::SameLine(240);
    ImGui::Text("%d%%", static_cast<int>(stats));
    ImGui::PopStyleColor();
    ImGui::PushStyleColor(ImGuiCol_Text, IM_COL32(102, 255, 102, 255));
    ImGui::Text("Poison Resistance");
    ImGui::SameLine(240);
    ImGui::Text("%d%%", static_cast<int>(stats));
    ImGui::PopStyleColor();
    ImGui::PushStyleColor(ImGuiCol_Text, IM_COL32(204, 153, 255, 255));
    ImGui::Text("Shadow Resistance");
    ImGui::SameLine(240);
    ImGui::Text("%d%%", static_cast<int>(stats));
    ImGui::PopStyleColor();

    ImGui::SeparatorText("Offensive");
    ImGui::Text("Ranged Weapon Damage");
    ImGui::SameLine(240);
    ImGui::Text("%d", static_cast<int>(stats));
    ImGui::Text("Dual Wielded Weapon Damage");
    ImGui::SameLine(240);
    ImGui::Text("%d", static_cast<int>(stats));
    ImGui::Text("Weapon Speed");
    ImGui::SameLine(240);
    ImGui::Text("%.2f", static_cast<float>(stats));
    ImGui::Text("Attack Speed Bonus");
    ImGui::SameLine(240);
    ImGui::Text("%.1f%%", static_cast<float>(stats));
    ImGui::Text("Attack Speed from Dodging");
    ImGui::SameLine(240);
    ImGui::Text("%.1f%%", static_cast<float>(stats));
    ImGui::Text("Critical Strike Chance");
    ImGui::SameLine(240);
    ImGui::Text("%.1f%%", static_cast<float>(stats));
    ImGui::Text("Critical Strike Damage");
    ImGui::SameLine(240);
    ImGui::Text("%.1f%%", static_cast<float>(stats));
    ImGui::Text("Overpower Chance");
    ImGui::SameLine(240);
    ImGui::Text("%.1f%%", static_cast<float>(stats));
    ImGui::Text("Overpower Damage");
    ImGui::SameLine(240);
    ImGui::Text("%.1f%%", static_cast<float>(stats));
    ImGui::Text("Vulnerable Damage");
    ImGui::SameLine(240);
    ImGui::Text("%.1f%%", static_cast<float>(stats));
    ImGui::Text("All Damage");
    ImGui::SameLine(240);
    ImGui::Text("%.1f%%", static_cast<float>(stats));
    ImGui::Text("Damage with Physical");
    ImGui::SameLine(240);
    ImGui::Text("%.1f%%", static_cast<float>(stats));
    ImGui::Text("Damage with Marksman");
    ImGui::SameLine(240);
    ImGui::Text("%.1f%%", static_cast<float>(stats));
    ImGui::Text("Damage vs Close");
    ImGui::SameLine(240);
    ImGui::Text("%.1f%%", static_cast<float>(stats));
    ImGui::Text("Damage vs Distant");
    ImGui::SameLine(240);
    ImGui::Text("%.1f%%", static_cast<float>(stats));
    ImGui::Text("Damage vs Elites");
    ImGui::SameLine(240);
    ImGui::Text("%.1f%%", static_cast<float>(stats));
    ImGui::Text("Damage vs Crowd Controlled");
    ImGui::SameLine(240);
    ImGui::Text("%.1f%%", static_cast<float>(stats));
    ImGui::Text("Damage vs Healthy");
    ImGui::SameLine(240);
    ImGui::Text("%.1f%%", static_cast<float>(stats));
    ImGui::Text("Thorns");
    ImGui::SameLine(240);
    ImGui::Text("%d", static_cast<int>(stats));

    ImGui::SeparatorText("Defensive");
    ImGui::PushStyleColor(ImGuiCol_Text, IM_COL32(255, 80, 80, 255));
    ImGui::Text("Maximum Life");
    ImGui::SameLine(240);
    ImGui::Text("%d", static_cast<int>(stats));
    ImGui::PopStyleColor();
    ImGui::Text("Potion Capacity");
    ImGui::SameLine(240);
    ImGui::Text("%d", static_cast<int>(stats));
    ImGui::Text("Healing from Potions");
    ImGui::SameLine(240);
    ImGui::Text("%.1f%%", static_cast<float>(stats));
    ImGui::PushStyleColor(ImGuiCol_Text, IM_COL32(255, 255, 204, 255));
    ImGui::Text("Armor");
    ImGui::SameLine(240);
    ImGui::Text("%d", static_cast<int>(stats));
    ImGui::PopStyleColor();
    ImGui::Text("All Damage Reduction");
    ImGui::SameLine(240);
    ImGui::Text("%.1f%%", static_cast<float>(stats));
    ImGui::Text("Damage Reduction from Elites");
    ImGui::SameLine(240);
    ImGui::Text("%.1f%%", static_cast<float>(stats));
    ImGui::Text("Damage Reduction from Vulnerable");
    ImGui::SameLine(240);
    ImGui::Text("%.1f%%", static_cast<float>(stats));
    ImGui::Text("Damage Reduction from Slowed");
    ImGui::SameLine(240);
    ImGui::Text("%.1f%%", static_cast<float>(stats));
    ImGui::Text("Damage Reduction from Close");
    ImGui::SameLine(240);
    ImGui::Text("%.1f%%", static_cast<float>(stats));
    ImGui::Text("Damage Reduction from Distant");
    ImGui::SameLine(240);
    ImGui::Text("%.1f%%", static_cast<float>(stats));
    ImGui::Text("Dodge Chance");
    ImGui::SameLine(240);
    ImGui::Text("%.1f%%", static_cast<float>(stats));

    ImGui::SeparatorText("Utility");
    ImGui::Text("Maximum Energy");
    ImGui::SameLine(240);
    ImGui::Text("%d", static_cast<int>(stats));
    ImGui::Text("Energy Regeneration");
    ImGui::SameLine(240);
    ImGui::Text("%d", static_cast<int>(stats));
    ImGui::Text("Energy Generation");
    ImGui::SameLine(240);
    ImGui::Text("%.1f%%", static_cast<float>(stats));
    ImGui::Text("Movement Speed");
    ImGui::SameLine(240);
    ImGui::Text("%.1f%%", static_cast<float>(stats));
    ImGui::Text("Elite Kill Movement Speed");
    ImGui::SameLine(240);
    ImGui::Text("%.1f%%", static_cast<float>(stats));
    ImGui::Text("Cooldown Reduction");
    ImGui::SameLine(240);
    ImGui::Text("%.1f%%", static_cast<float>(stats));
    ImGui::Text("Imbuement Cooldown Reduction");
    ImGui::SameLine(240);
    ImGui::Text("%.1f%%", static_cast<float>(stats));
    ImGui::Text("Lucky Hit Chance Bonus");
    ImGui::SameLine(240);
    ImGui::Text("%.1f%%", static_cast<float>(stats));
    ImGui::Text("Lucky Hit Freeze");
    ImGui::SameLine(240);
    ImGui::Text("%.1f%%", static_cast<float>(stats));
    ImGui::Text("Experience Bonus");
    ImGui::SameLine(240);
    ImGui::Text("%.1f%%", static_cast<float>(stats));

    ImGui::SeparatorText("PVP");
    ImGui::Text("Damage Reduction");
    ImGui::SameLine(240);
    ImGui::Text("%.1f%%", static_cast<float>(stats));
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
    ImGui::Text("World Effects:");
    ImGui::PushStyleColor(ImGuiCol_Text, IM_COL32(0, 255, 0, 255));
    ImGui::SeparatorText("Altar Bonuses");
    ImGui::PopStyleColor();
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
    ImGui::PushStyleColor(ImGuiCol_Text, IM_COL32(255, 0, 0, 255));
    ImGui::SeparatorText("Renown Bonuses");
    ImGui::PopStyleColor();
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
    ImGui::PushStyleColor(ImGuiCol_Text, IM_COL32(255, 255, 0, 255));
    ImGui::SeparatorText("World Difficulty");
    ImGui::PopStyleColor();
    const char* worldTierPreviewValue = worldTiers[worldTierIndex];
    if (ImGui::BeginCombo("##world-tier-list", worldTierPreviewValue)) {
      for (int n = 0; n < IM_ARRAYSIZE(worldTiers); n++) {
        const bool selected = (worldTierIndex == n);
        if (ImGui::Selectable(worldTiers[n], selected)) {
          worldTierIndex = n;
        }
        if (selected) {
          ImGui::SetItemDefaultFocus();
        }
      }
      ImGui::EndCombo();
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

void Gui::displayNotes() {
  if (ImGui::Begin("Notes")) {
    ImGui::InputTextMultiline("##note-input", notesText, IM_ARRAYSIZE(notesText), ImVec2(-FLT_MIN, ImGui::GetTextLineHeight() * 32));
  }
  ImGui::End();
}
