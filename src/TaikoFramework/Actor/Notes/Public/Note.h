#pragma once
#include "../../../../EngineFramework/Actor/Public/BaseActor.h"
#include "../../../EngineFramework/Components/AnimatedTexturedSprite/Public/AnimatedTexturedSprite.h"


class TaikoNote : public BaseActor
{
    public:
        TaikoNote();
        ~TaikoNote(){};

        AnimatedTexturedSpriteComponent* animated_textured_sprite_comp;

        void tick(float elapsed_time) override;

        bool mouth_open = false;





};