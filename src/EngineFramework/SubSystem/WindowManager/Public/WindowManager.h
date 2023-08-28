#pragma once
#include "../../Public/BaseSubsystem.h"
#include <SFML/Graphics.hpp>

class WindowManager  : public BaseEngineSubSystem<WindowManager>
{
public:
    WindowManager(token) { std::cout << "constructed Test" << std::endl; }
    ~WindowManager() {  std::cout << "destructed Test" << std::endl; }

    void use() const { std::cout << "in use Test" << std::endl; };

    void SetWindowRef(sf::RenderWindow* in_window);
    
    sf::RenderWindow* m_window;

};