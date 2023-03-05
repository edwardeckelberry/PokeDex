//
// Created by Edward Eckelberry on 12/6/22.
//

#include "SoundEffects.h"

SoundEffects::SoundEffects()
{

}

SoundEffects::SoundEffects(const TracksEnum &track)
{
    soundEffect.setBuffer(Tracks::getTrack(track));
}

void SoundEffects::playAudio()
{
    soundEffect.play();
}

void SoundEffects::pauseAudio()
{
    soundEffect.pause();
}

void SoundEffects::setAudioVolume(const float &volume_value)
{
    soundEffect.setVolume(volume_value);
}

void SoundEffects::setLoopOn(const bool &toggle)
{
    soundEffect.setLoop(toggle);
}
