#include "BossMusic.h"
#include <windows.h>
#include <mmsystem.h>
#include <iostream>
#include <string>

#pragma comment(lib, "winmm.lib")

void playBossMusic(const char* filename)
{
    PlaySoundA(filename, NULL, SND_FILENAME | SND_ASYNC | SND_LOOP | SND_NODEFAULT);
}

void stopBossMusic()
{
    PlaySoundA(NULL, NULL, 0);
}

void playVoiceLine(const char* filename)
{
    static int voiceID = 0;

    std::string alias = "voice" + std::to_string(voiceID++);

    std::string command = "open \"" + std::string(filename) + "\" type waveaudio alias " + alias;

    mciSendStringA(command.c_str(), NULL, 0, NULL);

    command = "play " + alias + " notify";

    mciSendStringA(command.c_str(), NULL, 0, NULL);
}