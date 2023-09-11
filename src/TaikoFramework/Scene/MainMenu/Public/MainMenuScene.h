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
#include "SFMLTransformUtility.h"
#include "../../../EngineFramework/SubSystem/EventHandler/Public/EventHandler.h"
#include "../../../EngineFramework/Components/AudioPlayer/Public/AudioComponent.h"
#include "../../../EngineFramework/Components/BPMSignalComponent/Public/BPMSignalComponent.h"
#include "../../../EngineFramework/Components/TexturedSprite/Public/TexturedSprite.h"
#include "../../../EngineFramework/Components/AnimatedTexturedSprite/Public/AnimatedTexturedSprite.h"
#include "../../../EngineFramework/Components/FadeComponent/Public/FadeComponent.h"
#include "../../../EngineFramework/Utility/Animation/SineWave/Public/SineWaveGenerator.h"
#include "../../GameFramework/Input/Public/InputComponent.h"
#include "../../TaikoFramework/Actor/Notes/Public/Note.h"



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

        sf::Clock linear_clock;

        sf::RectangleShape FadeBox;

        void StartTransition();

        InputComponent* input_component;
        AudioComponent test;

    protected : 

        TexturedSpriteComponent* entry_bar_sprite;

        TexturedSpriteComponent* background_sprite_comp;

        AnimatedTexturedSpriteComponent* animated_sprite_comp;

        TaikoNote* test_note;

        TaikoNote* hit_placement;

        FadeComponent* fade_component;

        BPMSignalComponent bpm_test;

        SineWaveGenerator sine_wave;



        
};