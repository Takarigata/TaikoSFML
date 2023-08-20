#pragma once
#include <stdio.h>
#include <string>
#include <iostream>
#include <map>
#include "WindowManager.h"
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

        // std::map<sf::Drawable, sf::RenderStates> ObjectsToDraw;
        // sf::CircleShape* shape;
        // sf::Font* font;

    protected:

        sf::RenderWindow* window_ref;
};