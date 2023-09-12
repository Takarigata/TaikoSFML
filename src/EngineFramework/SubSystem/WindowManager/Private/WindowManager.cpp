#include "../Public/WindowManager.h"

void WindowManager::SetWindowRef(sf::RenderWindow* in_window)
{
    m_window = in_window;
}

void WindowManager::SetGameClock(sf::Clock* in_clock)
{
    _clock = in_clock;
}