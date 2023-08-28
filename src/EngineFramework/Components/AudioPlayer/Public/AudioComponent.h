#pragma once
#include "../Public/BaseComponent.h"
#include <SFML/Audio.hpp>
#include <SFML/Audio/Music.hpp>

struct AudioComponentSettings
{
    std::string file_path;
    bool is_looping = false;
    float volume = 100;
    float offset = 0;
    float pitch = 1;
};


class AudioComponent : public BaseComponent
{
    public:
        AudioComponent();
        ~AudioComponent();

};
