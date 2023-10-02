#include "../Public/TaikoCharacter.h"

BaseTaikoCharacter::BaseTaikoCharacter()
{
    //setup_character();
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

void BaseTaikoCharacter::setup_character(int in_bpm, std::string in_file_path, sf::Vector2f in_scale, std::string in_char_name)
{
    char_name = in_char_name;
    taiko_sprite_comp = new TexturedSpriteComponent(in_scale, "Assets/Game/Characters/TaikoBaseChar.png", char_name.c_str());
    character_sprite_seq_path = in_file_path;
    bpm_comp = BPMSignalComponent(in_bpm);
    bpm_comp.add_bpm_actor_listener(this);

}

void BaseTaikoCharacter::update_taiko_char_anim()
{
    if(current_sprite_sheet_pos < max_sprite)
    {
        taiko_sprite_comp->GetSpriteTexture()->loadFromFile(character_sprite_seq_path + std::to_string(current_sprite_sheet_pos) + ".png");
        taiko_sprite_comp->GetSpriteRef_ptr()->setTexture(*taiko_sprite_comp->GetSpriteTexture());
        taiko_sprite_comp->GetSpriteRef_ptr()->setTextureRect(sf::IntRect(0, 0, taiko_sprite_comp->GetSpriteTexture()->getSize().x, taiko_sprite_comp->GetSpriteTexture()->getSize().y));
        current_sprite_sheet_pos++;
    }
    else
    {
        current_sprite_sheet_pos = 0;
        update_taiko_char_anim();
    }
}