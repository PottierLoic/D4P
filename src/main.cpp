#include <iostream>

#include <SFML/Graphics.hpp>
#include <SFML/System/Clock.hpp>
#include <SFML/Window/Event.hpp>
#include <imgui-SFML.h>
#include <imgui.h>

int main () {
  sf::ContextSettings settings;
  settings.antialiasingLevel = 8;
  sf::RenderWindow window(sf::VideoMode(1920, 1080), "D4P", sf::Style::Default, settings);
  window.setFramerateLimit(120);

  if(!ImGui::SFML::Init(window)) {
    std::cerr << "ImGui initialization failed!" << std::endl;
  }

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
    window.clear(sf::Color(51, 51, 51, 255));
    // TODO: call menu display here
    // TODO: display everything in the main window here
    ImGui::SFML::Render(window);
    window.display();
  }
  ImGui::SFML::Shutdown();
  return 0;
}
