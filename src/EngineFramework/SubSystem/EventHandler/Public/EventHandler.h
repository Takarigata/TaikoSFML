#pragma once
#include "../../Public/BaseSubsystem.h"
#include "../../WindowManager/Public/WindowManager.h"
#include "../../../../GameFramework/Public/Game.h"
#include <vector>
#include <memory>
#include <SFML/Graphics.hpp>
#include "imgui.h"
#include "imconfig-SFML.h"
#include "imgui-SFML.h"
#include "../../GameFramework/Input/Public/InputComponent.h"


class EventHandler  : public BaseEngineSubSystem<EventHandler>
{
public:
    EventHandler(token) { std::cout << "constructed Test" << std::endl; }
    ~EventHandler() {  std::cout << "destructed Test" << std::endl; }

    void use() const { std::cout << "in use Test" << std::endl; };

    void UpdateInputEvent(GameSFML* InGame);

    void SendPressed();
};