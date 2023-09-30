#include "../Public/AudioComponent.h"


AudioComponent::AudioComponent(AudioComponentSettings in_settings)
{
    ACS = in_settings;
}

AudioComponent::~AudioComponent()
{
    printf("DESTOYED \n");
}

void AudioComponent::SetAudioComponentSettings(AudioComponentSettings in_settings)
{
    ACS = in_settings;
}


bool AudioComponent::PlaySound()
{
    if (!buffer.loadFromFile(ACS.file_path))
    {
        return false;
    }
    sound.setBuffer(buffer);
    sound.setVolume(ACS.volume);
    sound.setPitch(ACS.pitch);
    sound.setPlayingOffset(sf::seconds(ACS.offset));
    sound.setLoop(ACS.is_looping);
    sound.play();

    return true;
}

void  AudioComponent::StopSound()
{
    sound.stop();
    delete this;
}

void AudioComponent::tick(float elapsed_time)
{
    
}