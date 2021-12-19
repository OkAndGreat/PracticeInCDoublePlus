/**
 * Created by OkAndGreat on 2021/12/19.
 *
 */

#ifndef PRACTICEINCDOUBLEPLUS_MUSICPLAYER_H
#define PRACTICEINCDOUBLEPLUS_MUSICPLAYER_H

using namespace std;
#include <iostream>

class MusicPlayer{
public:
    MusicPlayer();
    MusicPlayer(int time);
    void start();
    void stop();
    int getTime(){
        return time;
    }

private:
    int time;
    void doSthMySelf();
};


#endif //PRACTICEINCDOUBLEPLUS_MUSICPLAYER_H
