#include "audiomanager.h"

AudioManager::AudioManager()
{
    playlist = new QMediaPlaylist();
    playlist->setPlaybackMode(QMediaPlaylist::Loop);
    player = new QMediaPlayer;
    player->setPlaylist(playlist);
    PlayMusic("kitchen");
}

void AudioManager::PlayMusic(string name)
{
    // TODO: Fade previous music out and fade new music in.
    string path = "qrc:/sfx/music/"+name+".mp3";
    QString pathString = QString::fromLocal8Bit(path.c_str());
    playlist->addMedia(QUrl(pathString));
    player->setVolume(50);
    player->play();
}

void AudioManager::PlayOneShot(string audioString)
{
    string path = "qrc:/sfx/"+audioString+".wav";
    QString pathString = QString::fromLocal8Bit(path.c_str());
    effect.setSource(QUrl(pathString));
    effect.setVolume(0.6f);
    effect.play();
}
