#pragma once
#include <SFML/System.hpp>
#include "../Public/BaseComponent.h"
#include "../AudioPlayer/Public/AudioComponent.h"

class BPMSignalComponent : BaseComponent
{
    public:

        BPMSignalComponent();
        ~BPMSignalComponent();

        AudioComponent AP;

        sf::Clock bpm_clock;

        AudioComponent bpm_spind_comp;


        int bpm = 180;

        int bpm_time;

        void StartBPMClock();

        void TickBPMComp();

        void BPMHit();

};