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
        //bpm_spind_comp.PlaySound();
        for(auto listener : listening_actor)
        {
            listener->tick(1);
        }
        bpm_clock.restart();
    }

}

bool BPMSignalComponent::add_bpm_actor_listener(BaseActor* in_actor)
{
    if(in_actor)
    {
        listening_actor.push_back(in_actor);
        return true;
    }
    return false;
    
}