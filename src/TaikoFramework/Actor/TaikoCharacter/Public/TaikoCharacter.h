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

        void setup_character(int in_bpm = 1800, std::string in_file_path = "", sf::Vector2f in_scale = sf::Vector2f(1.0f, 1.0f), std::string in_char_name = "Taiko Char");

        void update_taiko_char_anim();

        std::string char_name = "TaikoChar";

        std::string character_sprite_seq_path;

        TexturedSpriteComponent* taiko_sprite_comp;

        BPMSignalComponent bpm_comp;

        int max_sprite = 118;

        int current_sprite_sheet_pos = 0;

};