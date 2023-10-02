#pragma once
#include "../../../EngineFramework/Actor/Public/BaseActor.h"
#include "../../../EngineFramework/Components/TexturedSprite/Public/TexturedSprite.h"
#include "../../../EngineFramework/Components/BPMSignalComponent/Public/BPMSignalComponent.h"
#include "../../../EngineFramework/Lib/Math/Public/SFMLTransformUtility.h"
#include "../../../EngineFramework/Lib/Math/Public/SFMLSpriteUtility.h"
#include "../../../EngineFramework/Lib/Math/Public/MathLib.h"
#include "../../../EngineFramework/Utility/Animation/SineWave/Public/SineWaveGenerator.h"


struct PuchiCharacterSettings
{
    int anim_speed = 60;
    int levitating_anim_speed = 25;
    int puchi_start_row = 0;
    int puchi_start_collums = 0;
    sf::Vector2f puch_scale = sf::Vector2f(1, 1);
    sf::Vector2f start_pos;
    std::string puchi_actor_name = "BasePuchiActor";

};
class BasePuchiCharacter : public BaseActor
{
    public:
        BasePuchiCharacter();
        ~BasePuchiCharacter();

        void tick(float elapsed_time) override;

        void bpm_tick(float elapsed_time) override;

        void setup_character(PuchiCharacterSettings in_settings);

        void update_puchi_char_anim();

        PuchiCharacterSettings puchi_settings;

        TexturedSpriteComponent* puchi_sprite_comp;

        BPMSignalComponent bpm_comp;

        SineWaveGenerator sine_wave_generator;

        sf::Vector2f start_pos;

        float offset_y = 0.03f;

        int max_sprite = 1;

        int current_sprite_sheet_pos = 0;


    

};
