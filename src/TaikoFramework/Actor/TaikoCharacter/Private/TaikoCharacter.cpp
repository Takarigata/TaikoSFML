#include "../Public/TaikoCharacter.h"

BaseTaikoCharacter::BaseTaikoCharacter()
{
    setup_character();
}

BaseTaikoCharacter::~BaseTaikoCharacter()
{

}

void BaseTaikoCharacter::tick(float elapsed_time)
{
    bpm_comp.TickBPMComp();
}

void BaseTaikoCharacter::bpm_tick(float elapsed_time)
{
    update_taiko_char_anim();
}

void BaseTaikoCharacter::setup_character()
{
    taiko_sprite_comp = new TexturedSpriteComponent(sf::Vector2f(1.3f, 1.3f), "Assets/Game/Characters/TaikoBaseChar.png", "taiko_char");
    sf::Vector2f pos =  SFMLTransformLib::CalculateScreenPos(-0.025f, 0.275f);
    taiko_sprite_comp->GetSpriteRef_ptr()->setPosition(pos);
    bpm_comp = BPMSignalComponent(1800);
    bpm_comp.add_bpm_actor_listener(this);

}

void BaseTaikoCharacter::update_taiko_char_anim()
{
    if(current_sprite_sheet_pos < 118)
    {
        taiko_sprite_comp->GetSpriteTexture()->loadFromFile("Assets/Game/Characters/0/Normal/" + std::to_string(current_sprite_sheet_pos) + ".png");
        current_sprite_sheet_pos++;
    }
    else
    {
        current_sprite_sheet_pos = 0;
        update_taiko_char_anim();
    }
}