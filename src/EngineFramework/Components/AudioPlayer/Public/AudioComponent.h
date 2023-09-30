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
    AudioComponentSettings()
    {

    }
    AudioComponentSettings(std::string in_file_path, bool in_is_looping, float in_volume, float in_offset, float in_pitch)
    {
        file_path = in_file_path;
        is_looping = in_is_looping;
        volume = in_volume;
        offset = in_offset;
        pitch = in_pitch;

    }
};


class AudioComponent : public BaseComponent
{
    public:
        AudioComponent(){}
        AudioComponent(AudioComponentSettings in_settings);
        ~AudioComponent();

        void tick(float elapsed_time) override;

        AudioComponentSettings ACS;

        void SetAudioComponentSettings(AudioComponentSettings in_settings);

        bool PlaySound();

        void StopSound();

        sf::SoundBuffer get_buffer() { return buffer; };

        sf::Sound get_soundplayer() { return sound; };

    protected:

        sf::SoundBuffer buffer;

        sf::Sound sound;

};
