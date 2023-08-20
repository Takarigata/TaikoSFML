#include "../Public/MathLib.h"


float MathLib::Lerp(float a, float b, float f)
{
    return a * (1.0 - f) + (b * f);
}

float MathLib::MapRangeClamp(float in_value, float min_in_range, float max_in_range, float min_out_range, float max_out_range)
{
    float x = (in_value - min_in_range) / (max_in_range - min_in_range);
    return min_out_range + (max_out_range - min_out_range) * x;
}

MathLib::MathLib(){};

