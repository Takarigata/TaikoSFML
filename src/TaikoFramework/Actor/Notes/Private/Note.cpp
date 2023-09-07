#include "../Public/Note.h"

TaikoNote::TaikoNote()
{
    ActorName = "TaikoNote";

    animated_textured_sprite_comp = new AnimatedTexturedSpriteComponent(sf::Vector2f(1, 1), "Assets/Game/Notes.png");
    animated_textured_sprite_comp->GetSpriteRef_ptr()->setScale(1.5f, 1.5f);
    current_note_type = note_type::ka;
}

TaikoNote::TaikoNote(note_type in_note_type)
{
    ActorName = "TaikoNote";

    animated_textured_sprite_comp = new AnimatedTexturedSpriteComponent(sf::Vector2f(1, 1), "Assets/Game/Notes.png");
    animated_textured_sprite_comp->GetSpriteRef_ptr()->setScale(1.5f, 1.5f);
    current_note_type = in_note_type;
}

void TaikoNote::tick(float elapsed_time)
{
    printf("TICK NOTE \n");
    animated_textured_sprite_comp->GetSpriteRef_ptr()->setTextureRect(get_note_rec_value());
    animated_textured_sprite_comp->SetSpriteOriginToCenter();
    // if(mouth_open)
    // {
    //     animated_textured_sprite_comp->GetSpriteRef_ptr()->setTextureRect(get_note_rec_value());
    //     mouth_open = false;
    // }
    // else
    // {
    //     animated_textured_sprite_comp->GetSpriteRef_ptr()->setTextureRect(get_note_rec_value());
    //     mouth_open = true;
    // }
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
    
}