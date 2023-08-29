#pragma once
#include "../../Public/BaseSubsystem.h"
#include "../../WindowManager/Public/WindowManager.h"

#include <vector>
#include <memory>
#include <string>
#include <SFML/Graphics.hpp>
#include "imgui.h"
#include "imconfig-SFML.h"
#include "imgui-SFML.h"
#include "../../GameFramework/Input/Public/InputComponent.h"
#include "../../Components/AudioPlayer/Public/AudioComponent.h"

class GameSFML;
class EventHandler  : public BaseEngineSubSystem<EventHandler>
{
public:
    
    EventHandler::EventHandler(token);
    ~EventHandler() {}

    void use() const {};

    void AddToListening(InputComponent* in_obj);

    void UpdateInputEvent(GameSFML* InGame);

    void SendPressed();

    std::vector<InputComponent*> ListeningInputComponent;

    sf::Keyboard::Key KaInput = sf::Keyboard::J;
    sf::Keyboard::Key DonInput = sf::Keyboard::K;

    void SendKaInput();

    void SendDonInput();

    std::string KaSoundPath = "Assets/SFX/ka.ogg";
    std::string DonSoundPath = "Assets/SFX/don.ogg"; 

    AudioComponent Ka;
    AudioComponentSettings KaSettings;

    AudioComponent Don;
    AudioComponentSettings DonSettings;
};


