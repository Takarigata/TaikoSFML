#pragma once
#include "../../../../EngineFramework/Actor/Public/BaseActor.h"
#include "../../../../TJAParser/Public/TJAUtility.h"
#include "../../../EngineFramework/Components/AnimatedTexturedSprite/Public/AnimatedTexturedSprite.h"
#include "../../../EngineFramework/SubSystem/WindowManager/Public/WindowManager.h"
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include "imconfig-SFML.h"
#include "imgui-SFML.h"
#include "imgui.h"


class TaikoNote : public BaseActor
{
    public:
        TaikoNote();
        TaikoNote(note_type in_note_type, bool debug_window = false);
        ~TaikoNote(){};

        AnimatedTexturedSpriteComponent* animated_textured_sprite_comp;

        void bpm_tick(float elapsed_time) override;

        void tick(float elapsed_time) override;

        bool mouth_open = false;

        note_type current_note_type;

        sf::IntRect get_note_rec_value();

        sf::Clock m_deltaClock;
        bool debug_imgui = false;
        float sprite_pos[2] = {0,0};





};