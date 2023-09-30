#include "../Public/DrumPart.h"

DrumPart::DrumPart()
{

}

DrumPart::~DrumPart()
{

}

void DrumPart::setup_drum(bool left_side)
{

    if(left_side)
    {
        GetSpriteRef_ptr()->setTextureRect(sf::IntRect(0, 0, 60, 133));
    }
    else
    {
        GetSpriteRef_ptr()->setTextureRect(sf::IntRect(60, 0, 60, 133));
    }
    
    GetSpriteRef_ptr()->setColor(sf::Color(255, 255, 255, 0));

    drum_clock = sf::Clock();
    
}

void DrumPart::DrumPressed()
{
    drum_clock.restart();
    anim_in_progress = true;
}

void DrumPart::tick(float elapsed_time)
{
    if(anim_in_progress)
    {
        int new_alpha = MathLib::Lerp(255, 0, MathLib::MapRangeClamp(drum_clock.getElapsedTime().asSeconds(), 0, 0.5f, 0, 1));
        GetSpriteRef_ptr()->setColor(sf::Color(255, 255, 255, new_alpha));
        anim_in_progress = new_alpha > 0;
    }
    else
        GetSpriteRef_ptr()->setColor(sf::Color(255, 255, 255, 0));
}