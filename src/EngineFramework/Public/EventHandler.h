#pragma once
#include "BaseEngineSubsystem.h"
#include "WindowManager.h"
#include <SFML/Graphics.hpp>
#include "imgui.h"
#include "imconfig-SFML.h"
#include "imgui-SFML.h"
#include "../../GameFramework/Public/Game.h"


class EventHandler : public BaseEngineSubsystem
{
    public:

        EventHandler();
        ~EventHandler();

        void UpdateInputEvent(GameSFML* InGame);

        void SetGameRef(GameSFML* InGame);

        GameSFML* GetGameRef() { return game; };

        GameSFML* game;

    protected:

        




};