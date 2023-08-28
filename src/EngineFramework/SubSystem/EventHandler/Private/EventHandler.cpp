#include "../Public/EventHandler.h"
#include "../../../../GameFramework/Public/Game.h"

void EventHandler::UpdateInputEvent(GameSFML* InGame)
{
    if(InGame)
    {
        //printf("UPDATING INPUT \n");
        sf::Event event;
        //TODO: REPLACE WITH NEW SUB
        sf::RenderWindow* m_window = WindowManager::instance().m_window;
        if(m_window->pollEvent(event))
        {
            ImGui::SFML::ProcessEvent(*m_window, event);
            
            if(event.type == sf::Event::Closed || event.key.code == sf::Keyboard::Escape)
            {
                InGame->SetGameRunningState(false);
            }
            if(event.key.code == sf::Keyboard::J)
            {
                SendPressed();
            }
        }
    }
    
}

void EventHandler::AddToListening(InputComponent* in_obj)
{
    ListeningInputComponent.push_back(in_obj);
}

void EventHandler::SendPressed()
{
    for(auto & Listnener : ListeningInputComponent)
    {
        Listnener->method1();
    }
}