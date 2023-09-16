#pragma once
#include <algorithm>
#include <math.h> 
#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>
#include <limits>
#include "../../SubSystem/WindowManager/Public/WindowManager.h"

class SFMLTransformLib
{
    public:
        SFMLTransformLib();
        ~SFMLTransformLib();

        static sf::Vector2f CalculateScreenPos(float width_percent, float height_percent);

        static sf::Vector2f WorldPosToScreenPos(sf::Vector2f in_position);

        static bool IsVectorEqual(sf::Vector2f a, sf::Vector2f b, float epsilon = 1.0f);

};