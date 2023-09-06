#include "../Public/Note.h"

TaikoNote::TaikoNote()
{
    ActorName = "TaikoNote";

    animated_textured_sprite_comp = new AnimatedTexturedSpriteComponent(sf::Vector2f(1, 1), "Assets/Game/Notes.png");
    animated_textured_sprite_comp->GetSpriteRef_ptr()->setScale(1.5f, 1.5f);
}

void TaikoNote::tick(float elapsed_time)
{
    printf("TICK NOTE \n");
    if(mouth_open)
    {
        animated_textured_sprite_comp->GetSpriteRef_ptr()->setTextureRect(sf::IntRect(130, 0, 130, 130));
        mouth_open = false;
    }
    else
    {
        animated_textured_sprite_comp->GetSpriteRef_ptr()->setTextureRect(sf::IntRect(130, 130, 130, 130));
        mouth_open = true;
    }
    

}