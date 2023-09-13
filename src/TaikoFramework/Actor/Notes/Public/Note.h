#pragma once
#include "../../../../EngineFramework/Actor/Public/BaseActor.h"
#include "../../../../TJAParser/Public/TJAUtility.h"
#include "../../../EngineFramework/Components/AnimatedTexturedSprite/Public/AnimatedTexturedSprite.h"
#include "../../../EngineFramework/SubSystem/WindowManager/Public/WindowManager.h"
#include "../../../EngineFramework/Utility/Animation/SineWave/Public/SineWaveGenerator.h"
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include  <math.h>
#include "imconfig-SFML.h"
#include "MathLib.h"
#include "SFMLTransformUtility.h"
#include "imgui-SFML.h"
#include "imgui.h"


class TaikoNote : public BaseActor
{
    public:
        TaikoNote();
        TaikoNote(note_type in_note_type, sf::Vector2f in_start_pos = sf::Vector2f(), sf::Vector2f in_end_pos = sf::Vector2f(), float in_note_time = 1);
        ~TaikoNote(){};

        AnimatedTexturedSpriteComponent* animated_textured_sprite_comp;

        void bpm_tick(float elapsed_time) override;

        void tick(float elapsed_time) override;

        bool mouth_open = false;

        note_type current_note_type;

        sf::IntRect get_note_rec_value();

        sf::Clock m_deltaClock;

        sf::Vector2f start_position;

        sf::Vector2f end_position;

        float note_time;

        SineWaveGenerator note_clock;

};