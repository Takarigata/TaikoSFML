#pragma once
#include <stdio.h>
#include <SFML/Graphics.hpp>
#include "BaseEngineSubsystem.h"


class WindowManagerSubSystem : public BaseEngineSubsystem
{
    public:
        WindowManagerSubSystem();
        ~WindowManagerSubSystem();


        sf::RenderWindow* GetWindowRef();

        void SetWindowRef(sf::RenderWindow* InWindow);

    protected:

        static WindowManagerSubSystem* m_instance_window;

        //GameSFML* GameRefl;
        sf::RenderWindow* WindowRef;
};

//Init Singleton
inline WindowManagerSubSystem* WindowManagerSubSystem::m_instance_window = nullptr;

inline void WindowManagerSubSystem::SetWindowRef(sf::RenderWindow* InWindow)
{
    WindowRef = InWindow;
}

inline sf::RenderWindow* WindowManagerSubSystem::GetWindowRef()
{
    return WindowRef;
}


inline WindowManagerSubSystem::WindowManagerSubSystem(){}

inline WindowManagerSubSystem::~WindowManagerSubSystem(){}
