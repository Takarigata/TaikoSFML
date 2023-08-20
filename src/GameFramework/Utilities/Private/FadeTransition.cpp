#include "../Public/FadeTransition.h"

FadeTransition::FadeTransition(bool in_fade_out, float in_fade_time)
{
    fade_out = in_fade_out;
    fade_time = in_fade_time;
    StartFadeTransition();
}

FadeTransition::~FadeTransition(){};

void FadeTransition::StartFadeTransition()
{
    sf::Clock FadeClock;
    sf::RectangleShape FadeBox;
    FadeBox.setSize(sf::Vector2f(120, 50));
    FadeBox.setFillColor(sf::Color::Black);

    sf::RenderWindow* window_ref;
    window_ref = static_cast<WindowManagerSubSystem*>(WindowManagerSubSystem::GetInstance())->GetWindowRef();
    sf::Vector2f targetSize(window_ref->getView().getSize().x, window_ref->getView().getSize().y);
    FadeBox.setScale(targetSize.x / FadeBox.getLocalBounds().width, targetSize.y / FadeBox.getLocalBounds().height);
    int alpha_value = fade_out ? 255 : 0;
    int target_value = fade_out ? 0 : 255;
    printf("FADE VALUE = %d \n", alpha_value);
    printf("progess = %d Target = %d Alpha = %d \n", abs(alpha_value - target_value), target_value, alpha_value);
    while(abs(target_value - alpha_value) > 1)
    {
        alpha_value = MathLib::MapRangeClamp(FadeClock.getElapsedTime().asSeconds(), 0, fade_time, fade_out ? 255 : 0, fade_out ? 0 : 255);
        printf("FADE VALUE = %d \n", alpha_value);
        printf("progess = %d Target = %d Alpha = %d \n", abs(alpha_value - target_value), target_value, alpha_value);
        FadeBox.setFillColor(sf::Color(0, 0, 0, alpha_value));
        window_ref->draw(FadeBox);
    }

    
    
}