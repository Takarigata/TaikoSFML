#include "../Public/EventHandler.h"

EventHandler::EventHandler(){};

EventHandler::~EventHandler(){};

void EventHandler::UpdateInputEvent(GameSFML* InGame)
{
    if(InGame)
    {
        printf("UPDATING INPUT \n");
        sf::Event event;
        sf::RenderWindow* m_window = static_cast<WindowManagerSubSystem*>(WindowManagerSubSystem::GetInstance())->GetWindowRef();
        if(m_window->pollEvent(event))
        {
            ImGui::SFML::ProcessEvent(*m_window, event);
            
            if(event.type == sf::Event::Closed || event.key.code == sf::Keyboard::Escape)
            {
                InGame->SetGameRunningState(false);
            }
        }
    }
    
}

void EventHandler::SetGameRef(GameSFML* InGame)
{
    game = InGame;
}