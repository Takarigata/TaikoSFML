#pragma once
#include <algorithm>
#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>
#include "../../SubSystem/WindowManager/Public/WindowManager.h"

class SFMLTransformLib
{
    public:
        SFMLTransformLib();
        ~SFMLTransformLib();

        static sf::Vector2f CalculateScreenPos(float width_percent, float height_percent);

};