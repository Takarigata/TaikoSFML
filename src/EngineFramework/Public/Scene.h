#pragma once
#include <stdio.h>
#include <string>
#include <iostream>
#include <map>
#include <vector>
#include "../../SubSystem/WindowManager/Public/WindowManager.h"
#include "../../EngineFramework/Actor/Public/BaseActor.h"
#include "SFMLTransformUtility.h"
#include <SFML/Graphics.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <SFML/System/Clock.hpp>

class Scene
{
    public:
        Scene();
        ~Scene();

        bool IsSceneLoaded = true;

        int cnt = 0;

        virtual void InitScene();
        virtual void UpdateScene();
        virtual void CloseScene();
        virtual void UnloadScene();
        virtual void RenderScene();

        std::string SceneName = "BaseScene";

        std::vector<sf::Sprite*> background_layer;

        std::vector<sf::Sprite*> game_layer;

        std::vector<sf::Sprite*> foreground_layer;

        std::vector<sf::Sprite*> ui_layer;

        std::vector<BaseActor*> tickable_actor;


    protected:

        sf::RenderWindow* window_ref;
};