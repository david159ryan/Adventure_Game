#ifndef AUDIOMANAGER_H
#define AUDIOMANAGER_H
#include <QSoundEffect>
#include <QMediaPlayer>
#include <QMediaPlaylist>
#include <QApplication>
#include <QDesktopWidget>

using namespace std;

class AudioManager
{
private:
    QMediaPlayer * player;
    QMediaPlaylist * playlist;
    QSoundEffect effect;
public:
    AudioManager();
    void PlayMusic(string name);
    void PlayOneShot(string audioString);
};

#endif // AUDIOMANAGER_H
