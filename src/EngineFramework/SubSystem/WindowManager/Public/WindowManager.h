#pragma once
#include "../../Public/BaseSubsystem.h"
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>

class WindowManager  : public BaseEngineSubSystem<WindowManager>
{
public:
    WindowManager(token) {}
    ~WindowManager() {}

    void use() const {};

    void SetWindowRef(sf::RenderWindow* in_window);

    void SetGameClock(sf::Clock* in_clock);
    
    sf::RenderWindow* m_window;

    sf::Clock* _clock;

};