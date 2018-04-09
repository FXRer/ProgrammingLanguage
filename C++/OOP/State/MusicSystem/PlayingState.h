class PlayingState: public State {
public:
    bool stopMusic(MusicSystem * pMusicSys) {
        pMusicSys->setCurrentState(new StoppedState());
        std::cout << "Stopped Playing the music\n";
        return true;
    }
    bool previousSong(MusicSystem * pMusicSys) {
        std::cout << "Playing the previous song\n";
        return true;
    }
    bool nextSong(MusicSystem * pMusicSys) {
        std::cout << "Playing the next song\n";
        return true;
    }
};
