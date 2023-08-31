#pragma once
#include <SFML/System.hpp>
#include <cmath>

class SineWaveGenerator
{
    public:

        SineWaveGenerator(float in_amplitude = 1);
        ~SineWaveGenerator();

        sf::Clock sine_clock;

        float amplitude = 1;

        void StartClock();

        void StopClock();

        float GetSineValue();

};