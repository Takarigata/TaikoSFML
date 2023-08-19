#pragma once
#include <stdio.h>
#include <SFML/Graphics.hpp>


class WindowManagerSubSystem
{
    public:
        WindowManagerSubSystem();
        ~WindowManagerSubSystem();

        static WindowManagerSubSystem* GetInstance();

        static void DestroyWindowManager();

        //RenderWindow Getter and Setter

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

inline WindowManagerSubSystem* WindowManagerSubSystem::GetInstance()
{
    if(!m_instance_window)
    {
        m_instance_window = new WindowManagerSubSystem();
    }

    return m_instance_window;
}

inline void WindowManagerSubSystem::DestroyWindowManager()
{
    delete m_instance_window;
    m_instance_window = 0;
}

inline WindowManagerSubSystem::WindowManagerSubSystem(){}

inline WindowManagerSubSystem::~WindowManagerSubSystem(){}
