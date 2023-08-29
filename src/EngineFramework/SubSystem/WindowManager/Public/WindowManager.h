#pragma once
#include "../../Public/BaseSubsystem.h"
#include <SFML/Graphics.hpp>

class WindowManager  : public BaseEngineSubSystem<WindowManager>
{
public:
    WindowManager(token) {}
    ~WindowManager() {}

    void use() const {};

    void SetWindowRef(sf::RenderWindow* in_window);
    
    sf::RenderWindow* m_window;

};