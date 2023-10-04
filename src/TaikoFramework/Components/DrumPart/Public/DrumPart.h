#pragma once
#include "../../../../EngineFramework/Components/TexturedSprite/Public/TexturedSprite.h"
#include "../../../../EngineFramework/Lib/Math/Public/SFMLTransformUtility.h"
#include "../../../../EngineFramework/Lib/Math/Public/MathLib.h"
#include <SFML/System.hpp>

class DrumPart : public TexturedSpriteComponent
{
    public:
        using TexturedSpriteComponent::TexturedSpriteComponent;
        DrumPart();
        ~DrumPart();

        void setup_drum(bool left_side);

        void tick(float elapsed_time) override;

        void DrumPressed();

        void DebugValue();

        sf::Clock drum_clock;

        bool anim_in_progress = false;
};