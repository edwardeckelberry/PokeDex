//
// Created by Edward Eckelberry on 12/5/22.
//

#ifndef DROPDOWNMENU_TRACKS_H
#define DROPDOWNMENU_TRACKS_H
#include "TracksEnum.h"

#include "SFML/Audio.hpp"
#include <map>
#include <string>

class Tracks
{
private:
    static std::map<TracksEnum, sf::SoundBuffer> musica;
    static void loadTrack(const TracksEnum& track);
    static std::string getTrackPath(const TracksEnum& track);

public:
    static sf::SoundBuffer& getTrack(const TracksEnum& track);
};


#endif //DROPDOWNMENU_TRACKS_H
