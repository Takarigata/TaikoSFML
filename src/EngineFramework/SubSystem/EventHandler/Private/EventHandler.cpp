#include "../Public/EventHandler.h"
#include "../../../../GameFramework/Public/Game.h"


EventHandler::EventHandler(token) : BaseEngineSubSystem<EventHandler>()
{
    KaSettings = AudioComponentSettings(KaSoundPath, false, 100, 0 , 1);
    DonSettings = AudioComponentSettings(DonSoundPath, false, 100, 0 , 1);
    Ka = AudioComponent(KaSettings);
    Don = AudioComponent(DonSettings);
}

void EventHandler::UpdateInputEvent(GameSFML* InGame)
{
    if(InGame)
    {
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
            if(event.type == sf::Event::KeyPressed)
            {
                if(event.key.code == DonInput)
                {
                    SendDonInput();
                }
                if(event.key.code == KaInput)
                {
                    SendKaInput();
                }
            }
            
            
        }
    }
    
}

void EventHandler::SendKaInput()
{
    printf("KA \n");
    Ka.PlaySound();

}

void EventHandler::SendDonInput()
{
    printf("Don \n");
    Don.PlaySound();
}

void EventHandler::AddToListening(InputComponent* in_obj)
{
    ListeningInputComponent.push_back(in_obj);
}

void EventHandler::SendPressed()
{
    for(auto & Listnener : ListeningInputComponent)
    {
        Listnener->drum_hit();
    }
}