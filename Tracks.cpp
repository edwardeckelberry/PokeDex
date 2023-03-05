//
// Created by Edward Eckelberry on 12/5/22.
//

#include "Tracks.h"

std::map<TracksEnum, sf::SoundBuffer> Tracks::musica;

void Tracks::loadTrack(const TracksEnum &track)
{
    musica[track].loadFromFile(getTrackPath(track));
}

std::string Tracks::getTrackPath(const TracksEnum &track)
{
    switch (track)
    {
        case MUSIC       :  return "music/sound_1.wav";
        case MENU   : return "music/12-Hurry-Along-1.wav";
        case CLICK       :  return "soundEffects/click.wav";
        case LAST_ONE           :  return "";
    }
}

sf::SoundBuffer& Tracks::getTrack(const TracksEnum &track)
{
    loadTrack(track);

    return musica[track];
}
