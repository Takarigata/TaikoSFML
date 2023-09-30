#pragma once
#include <SFML/System.hpp>
#include <vector>
#include "../Public/BaseComponent.h"
#include "../AudioPlayer/Public/AudioComponent.h"
#include "../../../Actor/Public/BaseActor.h"


class BPMSignalComponent : BaseComponent
{
    public:

        BPMSignalComponent();
        BPMSignalComponent(int in_bpm);
        ~BPMSignalComponent();

        AudioComponent AP;

        sf::Clock bpm_clock;

        AudioComponent bpm_spind_comp;

        bool add_bpm_actor_listener(BaseActor* in_actor);

        std::vector<BaseActor*> listening_actor;

        int bpm = 160;

        int bpm_time;

        void StartBPMClock();

        void TickBPMComp();

        void BPMHit();

        void tick(float elapsed_time) override;

};