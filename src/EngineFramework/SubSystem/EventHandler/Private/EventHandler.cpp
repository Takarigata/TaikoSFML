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
            if(event.key.code == KaInput)
            {
                SendKaInput();
            }
            if(event.key.code == DonInput)
            {
                SendDonInput();
            }
        }
    }
    
}

void EventHandler::SendKaInput()
{
    //AudioComponent Ka(AudioComponentSettings("Assets/SFX/ka.ogg", false, 100, 0, 1));
    printf("KA \n");
    Ka.PlaySound();

}

void EventHandler::SendDonInput()
{
    //AudioComponent Don(AudioComponentSettings("Assets/SFX/don.ogg", false, 100, 0, 1));
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
        Listnener->method1();
    }
}