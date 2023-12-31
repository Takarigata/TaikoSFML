#pragma once
#include <string>

class BaseActor
{
    public:
        BaseActor(){};
        ~BaseActor(){};

        std::string ActorName;

        virtual void tick(float elapsed_time);

        virtual void bpm_tick(float elapsed_time);
};

