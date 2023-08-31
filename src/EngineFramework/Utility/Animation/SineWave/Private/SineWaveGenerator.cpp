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