#include <iostream>

#include <SFML/Graphics.hpp>
#include <SFML/System/Clock.hpp>
#include <SFML/Window/Event.hpp>
#include <imgui-SFML.h>
#include <imgui.h>

#include "gui.hpp"
#include "class.hpp"
#include "build.hpp"
#include "skill.hpp"

int main () {
  sf::ContextSettings settings;
  settings.antialiasingLevel = 8;
  sf::RenderWindow window(sf::VideoMode(1280, 720), "D4P", sf::Style::Default, settings);
  window.setFramerateLimit(120);

  if(!ImGui::SFML::Init(window)) {
    std::cerr << "ImGui initialization failed!" << std::endl;
  }

  ImGuiIO& io = ImGui::GetIO(); (void)io;
  io.ConfigFlags |= ImGuiConfigFlags_DockingEnable;
  io.ConfigFlags |= ImGuiConfigFlags_ViewportsEnable;

  Build testBuild("test", Class::BARBARIAN);
  Gui gui(std::make_unique<Build>(testBuild));

  sf::Clock deltaClock;
  while(window.isOpen()) {
    sf::Event event;
    while (window.pollEvent(event)) {
      ImGui::SFML::ProcessEvent(window, event);

      if (event.type == sf::Event::Resized) {
        sf::FloatRect visibleArea(0, 0, event.size.width, event.size.height);
        window.setView(sf::View(visibleArea));
      } else if (event.type == sf::Event::Closed) {
        window.close();
      }
    }
    ImGui::SFML::Update(window, deltaClock.restart());
    ImGui::DockSpaceOverViewport();
    window.clear(sf::Color(51, 51, 51, 255));
    gui.display();
    // TODO: display everything from the main window here
    ImGui::SFML::Render(window);
    window.display();
  }
  ImGui::SFML::Shutdown();
  return 0;
}
