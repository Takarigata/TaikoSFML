#pragma once
#include "../../../EngineFramework/Actor/Public/BaseActor.h"
#include "../../../EngineFramework/Components/TexturedSprite/Public/TexturedSprite.h"
#include "../../../EngineFramework/Components/BPMSignalComponent/Public/BPMSignalComponent.h"
#include "../../../EngineFramework/Lib/Math/Public/SFMLTransformUtility.h"

class BaseTaikoCharacter : public BaseActor
{
    public:
        using BaseActor::BaseActor;
        BaseTaikoCharacter();
        ~BaseTaikoCharacter();

        void tick(float elapsed_time) override;

        void bpm_tick(float elapsed_time) override;

        void setup_character();

        void update_taiko_char_anim();

        std::string character_sprite_seq_path;

        TexturedSpriteComponent* taiko_sprite_comp;

        BPMSignalComponent bpm_comp;

        int current_sprite_sheet_pos = 0;

};