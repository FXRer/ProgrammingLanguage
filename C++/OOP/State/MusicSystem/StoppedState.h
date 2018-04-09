class StoppedState: public State {
public:
    bool playMusic(MusicSystem * pMusicSys);
 
};
bool StoppedState::playMusic(MusicSystem * pMusicSys) {
    pMusicSys->setCurrentState(new PlayingState());
    std::cout << "Started Playing the music\n";
    return true;
}
