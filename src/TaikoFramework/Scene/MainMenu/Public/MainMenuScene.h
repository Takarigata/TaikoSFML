#pragma once
#include "Scene.h"
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Drawable.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Audio/Music.hpp>
#include <SFML/Audio/SoundStream.hpp>
#include <SFML/System.hpp>
#include <memory>
#include <SFML/System/Clock.hpp>
// #include "../../GameFramework/Utilities/Public/FadeTransition.h"
#include <cmath>
#include "MathLib.h"
#include "../../../EngineFramework/SubSystem/EventHandler/Public/EventHandler.h"
#include "../../../EngineFramework/Components/AudioPlayer/Public/AudioComponent.h"
#include "../../../EngineFramework/Components/TexturedSprite/Public/TexturedSprite.h"
#include "../../../EngineFramework/Components/FadeComponent/Public/FadeComponent.h"
#include "../../GameFramework/Input/Public/InputComponent.h"



class MainMenuScene : public Scene
{
    public:
        MainMenuScene();
        
        void InitScene() override;

        void SetupMenuGFX();

        void RenderScene() override;

        void SetupInput();

        void SetupMusic();

        

        sf::Music TitleMusic;

        sf::Clock clock;

        sf::RectangleShape FadeBox;

        

        // FadeTransition* FadeOut;

        void StartTransition();

        InputComponent* input_component;
        AudioComponent test;

    protected : 

        TexturedSpriteComponent* entry_bar_sprite;

        TexturedSpriteComponent* background_sprite_comp;

        FadeComponent* fade_component;



        
};