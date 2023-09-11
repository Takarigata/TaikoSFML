#include "../Public/MathLib.h"


float MathLib::Lerp(float a, float b, float f)
{
    return a * (1.0 - f) + (b * f);
}

float MathLib::Interp(float a, float b, float f)
{
    return a + ( b - a ) * f;
}

float MathLib::MapRangeClamp(float in_value, float min_in_range, float max_in_range, float min_out_range, float max_out_range)
{
    float x = (in_value - min_in_range) / (max_in_range - min_in_range);
    return min_out_range + (max_out_range - min_out_range) * x;
}

float MathLib::Clamp(float n, float lower, float upper)
{
    return std::clamp(n, lower, upper);
}

sf::Vector2f MathLib::LerpVector2(sf::Vector2f a, sf::Vector2f b, float f)
{
    sf::Vector2f out_vector;
    out_vector.x = Lerp(a.x, b.x, f);
    out_vector.y = Lerp(a.y, b.y, f);
    return out_vector;
}

sf::Vector2f MathLib::InterpVector2(sf::Vector2f a, sf::Vector2f b, float f)
{
    sf::Vector2f out_vector;
    out_vector.x = Interp(a.x, b.x, f);
    out_vector.y = Interp(a.y, b.y, f);
    return out_vector;
}

MathLib::MathLib(){};

