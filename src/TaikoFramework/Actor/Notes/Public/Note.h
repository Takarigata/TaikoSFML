#pragma once
#include "../../../../EngineFramework/Actor/Public/BaseActor.h"
#include "../../../../TJAParser/Public/TJAUtility.h"
#include "../../../EngineFramework/Components/AnimatedTexturedSprite/Public/AnimatedTexturedSprite.h"


class TaikoNote : public BaseActor
{
    public:
        TaikoNote();
        TaikoNote(note_type in_note_type);
        ~TaikoNote(){};

        AnimatedTexturedSpriteComponent* animated_textured_sprite_comp;

        void tick(float elapsed_time) override;

        bool mouth_open = false;

        note_type current_note_type;

        sf::IntRect get_note_rec_value();





};