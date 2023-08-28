#include "../Public/EventHandler.h"

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

void EventHandler::SendPressed()
{
    // printf(" PRESSING  Listen count = %d \n", ListenedObject.size());
    // for(auto & Listnener : ListenedObject)
    // {
    //     Listnener->method1();
    // }
}