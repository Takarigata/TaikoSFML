#pragma once
#include <algorithm>
#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>


class MathLib
{

public:
    MathLib();
    ~MathLib();

    static float Lerp(float a, float b, float f);

    static float Interp(float a, float b, float f);

    static sf::Vector2f LerpVector2(sf::Vector2f a, sf::Vector2f b, float f);

    static sf::Vector2f InterpVector2(sf::Vector2f a, sf::Vector2f b, float f);

    static float MapRangeClamp(float in_value, float min_in_range, float max_in_range, float min_out_range, float max_out_range);

    static float Clamp(float n, float lower = 0, float upper = 1);

};

