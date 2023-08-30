#pragma once
#include "../Public/BaseComponent.h"
#include "../../../EngineFramework/SubSystem/WindowManager/Public/WindowManager.h"
#include "../../Lib/Math/Public/MathLib.h"
#include <string>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <SFML/System.hpp>


class FadeComponent : BaseComponent
{
    public:
        FadeComponent(bool in_fade_in = false, float in_fade_time = 1, bool in_hold_fade = false);
        FadeComponent();
        ~FadeComponent();

        sf::RectangleShape* GetSpriteRef_ptr() { return &fade_sprite; };

        void ConstructSprite();

        void Fade();

        void StopFade();

        bool UpdateFade();

        bool fade_in;
        float fade_time;
        bool hold_fade;
        bool is_fading;

        
        sf::Clock fade_clock;

        sf::RectangleShape fade_sprite;

};