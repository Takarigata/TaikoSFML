#include "../Public/Note.h"

TaikoNote::TaikoNote()
{
    ActorName = "TaikoNote";

    animated_textured_sprite_comp = new AnimatedTexturedSpriteComponent(sf::Vector2f(1, 1), "Assets/Game/Notes.png");
    animated_textured_sprite_comp->GetSpriteRef_ptr()->setScale(1.0f, 1.0f);
    current_note_type = note_type::ka;
    note_clock = SineWaveGenerator(10);
}

TaikoNote::TaikoNote(note_type in_note_type, sf::Vector2f in_start_pos, sf::Vector2f in_end_pos, float in_note_time)
{
    ActorName = "TaikoNote";

    note_clock = SineWaveGenerator(in_note_time);

    animated_textured_sprite_comp = new AnimatedTexturedSpriteComponent(sf::Vector2f(1, 1), "Assets/Game/Notes.png");
    animated_textured_sprite_comp->GetSpriteRef_ptr()->setScale(1.0f, 1.0f);
    current_note_type = in_note_type;
    start_position = in_start_pos;
    end_position = in_end_pos;
    note_time = in_note_time;
    m_deltaClock = sf::Clock();
    m_deltaClock.restart();
}

void TaikoNote::bpm_tick(float elapsed_time)
{
    animated_textured_sprite_comp->GetSpriteRef_ptr()->setTextureRect(get_note_rec_value());
    animated_textured_sprite_comp->SetSpriteOriginToCenter();

}

void TaikoNote::tick(float elapsed_time)
{
    if(current_note_type != note_type::blank && current_note_type != note_type::hit && note_time - m_deltaClock.getElapsedTime().asSeconds() >= 0.00001f)
    {
        sf::Vector2f new_pos = MathLib::InterpVector2(start_position, end_position, MathLib::MapRangeClamp(m_deltaClock.getElapsedTime().asSeconds(), 0, note_time, 0, 1));
        animated_textured_sprite_comp->GetSpriteRef_ptr()->setPosition(new_pos);
    }
    else
    {
        //delete this;
    }
}

sf::IntRect TaikoNote::get_note_rec_value()
{
    mouth_open = !mouth_open;
    switch (current_note_type)
    {
    case note_type::ka:
        if(mouth_open)
            return sf::IntRect(260, 0, 130, 130);
        else
            return sf::IntRect(260, 130, 130, 130);
    case note_type::don:
        if(mouth_open)
            return sf::IntRect(130, 0, 130, 130);
        else
            return sf::IntRect(130, 130, 130, 130);
    case note_type::hit:
        return sf::IntRect(0, 0, 130, 130);
        break;
    
    default:
        break;
    }
    return sf::IntRect(0, 0, 130, 130);
}