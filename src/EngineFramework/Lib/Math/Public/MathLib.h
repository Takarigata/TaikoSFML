#pragma once


class MathLib
{

public:
    MathLib();
    ~MathLib();

    static float Lerp(float a, float b, float f);

    static float MapRangeClamp(float in_value, float min_in_range, float max_in_range, float min_out_range, float max_out_range);
};
