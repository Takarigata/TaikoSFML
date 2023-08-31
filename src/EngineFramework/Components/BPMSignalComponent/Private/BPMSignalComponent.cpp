#include "../Public/BPMSignalComponent.h"

BPMSignalComponent::BPMSignalComponent()
{
    bpm_clock = sf::Clock();
    bpm_spind_comp = AudioComponent(AudioComponentSettings("Assets/SFX/BPM_Hit.ogg", false, 100, 0 ,1));
    StartBPMClock();
}

BPMSignalComponent::~BPMSignalComponent(){}

void BPMSignalComponent::StartBPMClock()
{
    bpm_time = 60000 / bpm;
    printf("BPM IME  = %d \n", bpm_time);
    bpm_clock.restart();
}

void BPMSignalComponent::TickBPMComp()
{
    //printf("clock time = %d \n", bpm_clock.getElapsedTime().asMilliseconds());
    if(bpm_clock.getElapsedTime().asMilliseconds() >= bpm_time)
    {
        printf("tick \n");
        bpm_spind_comp.PlaySound();
        bpm_clock.restart();
    }

}