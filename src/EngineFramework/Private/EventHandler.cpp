#include "../Public/EventHandler.h"
#include "Game.h"

EventHandler::EventHandler()
{
    printf(" START  Listen count = %d \n", ListenedObject.size());
};

void EventHandler::UpdateInputEvent(GameSFML* InGame)
{
    if(InGame)
    {
        //printf("UPDATING INPUT \n");
        sf::Event event;
        sf::RenderWindow* m_window = static_cast<WindowManagerSubSystem*>(WindowManagerSubSystem::GetInstance())->GetWindowRef();
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


bool EventHandler::AddObjectToListenner(InputComponent* ObjToAdd)
{
   
    printf("ADDED OBJ TO LISTENER \n");
    ListenedObject.push_back(ObjToAdd);
    return true;
}

void EventHandler::SendPressed()
{
    printf(" PRESSING  Listen count = %d \n", ListenedObject.size());
    for(auto & Listnener : ListenedObject)
    {
        Listnener->method1();
    }
}
