#pragma once
#include "../../TexturedSprite/Public/TexturedSprite.h"

class AnimatedTexturedSpriteComponent : public TexturedSpriteComponent
{
    public:
        using TexturedSpriteComponent::TexturedSpriteComponent;
        AnimatedTexturedSpriteComponent();
        ~AnimatedTexturedSpriteComponent();

};