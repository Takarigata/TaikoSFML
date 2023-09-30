#include "../Public/FadeComponent.h"

FadeComponent::FadeComponent(){}

FadeComponent::~FadeComponent(){}

FadeComponent::FadeComponent(bool in_fade_in, float in_fade_time, bool in_hold_fade)
{
    fade_in = in_fade_in;
    fade_time = in_fade_time;
    hold_fade = in_hold_fade;
    ConstructSprite();
}

void FadeComponent::ConstructSprite()
{
    fade_clock = sf::Clock();
    fade_sprite = sf::RectangleShape();
    fade_sprite.setFillColor(sf::Color::Black);
    sf::RenderWindow* window_ref = WindowManager::instance().m_window;
    sf::Vector2f targetSize(window_ref->getView().getSize().x, window_ref->getView().getSize().y);
    sf::FloatRect SpriteBound = fade_sprite.getLocalBounds();
    fade_sprite.setSize(sf::Vector2f(window_ref->getView().getSize().x, window_ref->getView().getSize().y));
}

void FadeComponent::Fade()
{
    fade_clock.restart();
    is_fading = true;
    
}

void FadeComponent::StopFade()
{
    is_fading = false;
    
    if(!hold_fade)
    {
        fade_sprite.setFillColor(sf::Color(0, 0, 0, fade_in ? 255 : 0));
    }
    else
    {
        fade_sprite.setFillColor(sf::Color(0, 0, 0, fade_in ? 255 : 0));
    }
}

bool FadeComponent::UpdateFade()
{
    float time = fade_clock.getElapsedTime().asSeconds();
    float alpha_value = MathLib::MapRangeClamp(time, 0, fade_time, 0, 1);
    float target_value = fade_in ? 255 : 0;
    float start_value = fade_in ? 0 : 255;

    if(alpha_value >= 1)
    {
        StopFade();
        return true;
    }
    fade_sprite.setFillColor(sf::Color(0, 0, 0, MathLib::Lerp(start_value, target_value, alpha_value)));
    return false;
}

void FadeComponent::tick(float elapsed_time)
{
    
}