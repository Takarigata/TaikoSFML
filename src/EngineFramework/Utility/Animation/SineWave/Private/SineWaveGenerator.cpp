#include "../Public/SineWaveGenerator.h"

SineWaveGenerator::SineWaveGenerator(float in_amplitude)
{   
    sine_clock = sf::Clock();
    amplitude = in_amplitude;
}

SineWaveGenerator::~SineWaveGenerator(){}

void SineWaveGenerator::StartClock()
{
    sine_clock.restart();
}

void SineWaveGenerator::StopClock()
{

}

float SineWaveGenerator::GetSineValue()
{
    float out_value = (sin(sine_clock.getElapsedTime().asSeconds() * amplitude) + 1) / 2;
    return out_value;
}

float SineWaveGenerator::GetLinearValue()
{
    float out_value;
    float time = sine_clock.getElapsedTime().asSeconds();
    float period = amplitude;
    out_value = fmod(time, period) / period;
    if (out_value < 0.5f)
        out_value *= 2.0f;
    else
        out_value = 2.0 * (1.0f - out_value);
    return out_value;
}