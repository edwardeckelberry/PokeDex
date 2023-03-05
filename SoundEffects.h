//
// Created by Edward Eckelberry on 12/6/22.
//

#ifndef DROPDOWNMENU_SOUNDEFFECTS_H
#define DROPDOWNMENU_SOUNDEFFECTS_H
#include "TracksEnum.h"
#include "Tracks.h"
#include "SFML/Audio.hpp"

class SoundEffects
{
private:
    sf::Sound soundEffect;
public:
    SoundEffects();
    SoundEffects(const TracksEnum& track);

    void playAudio();
    void pauseAudio();
    void setAudioVolume(const float& volume_value);
    void setLoopOn(const bool& toggle);
};


#endif //DROPDOWNMENU_SOUNDEFFECTS_H
