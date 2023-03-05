//
// Created by Edward Eckelberry on 12/5/22.
//

#ifndef DROPDOWNMENU_MUSIC_H
#define DROPDOWNMENU_MUSIC_H
#include "SFML/Audio.hpp"
#include "TracksEnum.h"
#include "Tracks.h"
class Music
{
private:
    sf::Sound song;
public:
    Music();
    Music(const TracksEnum& track);

    void playAudio();
    void pauseAudio();
    void setAudioVolume(const float& volume_value);
    void setLoopOn(const bool& toggle);
};


#endif //DROPDOWNMENU_MUSIC_H
