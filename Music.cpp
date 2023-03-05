//
// Created by Edward Eckelberry on 12/5/22.
//

#include "Music.h"

Music::Music()
{

}

Music::Music(const TracksEnum &track)
{
    song.setBuffer(Tracks::getTrack(track));
}

void Music::playAudio()
{
    song.play();
}

void Music::pauseAudio()
{
    song.pause();
}

void Music::setAudioVolume(const float& volume_value)
{
    song.setVolume(volume_value);
}

void Music::setLoopOn(const bool &toggle)
{
    song.setLoop(toggle);
}
