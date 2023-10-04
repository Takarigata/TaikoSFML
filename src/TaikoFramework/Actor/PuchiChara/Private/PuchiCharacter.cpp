#include "../Public/PuchiCharacter.h"

BasePuchiCharacter::BasePuchiCharacter()
{

}

BasePuchiCharacter::~BasePuchiCharacter()
{

}

void BasePuchiCharacter::tick(float elapsed_time)
{
    bpm_comp.TickBPMComp();

    sf::Vector2f levitating_pos = SFMLTransformLib::CalculateScreenPos(start_pos.x, (MathLib::Lerp(start_pos.y - offset_y, start_pos.y + offset_y, sine_wave_generator.GetSineValue())));
    puchi_sprite_comp->GetSpriteRef_ptr()->setPosition(levitating_pos);

}

void BasePuchiCharacter::bpm_tick(float elapsed_time)
{
    update_puchi_char_anim();
}

void BasePuchiCharacter::setup_character(PuchiCharacterSettings in_settings)
{
    puchi_settings = in_settings;
    puchi_sprite_comp = new TexturedSpriteComponent(puchi_settings.puch_scale, "Assets/5_Game/18_PuchiChara/0.png", puchi_settings.puchi_actor_name);
    bpm_comp = BPMSignalComponent(puchi_settings.anim_speed);
    bpm_comp.add_bpm_actor_listener(this);
    sf::IntRect rect = SFMLSpriteUtility::get_sprite_inrect_by_xypos(puchi_settings.puchi_start_row, puchi_settings.puchi_start_collums, 256, 265);
    puchi_sprite_comp->GetSpriteRef_ptr()->setTextureRect(rect);
    puchi_sprite_comp->GetSpriteRef_ptr()->setPosition(in_settings.start_pos);
    max_sprite = 2;
    sine_wave_generator = SineWaveGenerator(5);
    start_pos = SFMLTransformLib::WorldPosToScreenPos(puchi_sprite_comp->GetSpriteRef_ptr()->getPosition());

}

void BasePuchiCharacter::update_puchi_char_anim()
{
    if(current_sprite_sheet_pos < max_sprite)
    {
        sf::IntRect rect = SFMLSpriteUtility::get_sprite_inrect_by_xypos(puchi_settings.puchi_start_row + (current_sprite_sheet_pos), puchi_settings.puchi_start_collums, 256, 265);
        puchi_sprite_comp->GetSpriteRef_ptr()->setTextureRect(rect);
        current_sprite_sheet_pos++;
    }
    else
    {
        current_sprite_sheet_pos = 0;
        update_puchi_char_anim();
    }
}
