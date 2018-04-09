class State {
public:
    virtual bool playMusic(MusicSystem * pMusicSys);
    virtual bool stopMusic(MusicSystem * pMusicSys);
    virtual bool previousSong(MusicSystem * pMusicSys);
    virtual bool nextSong(MusicSystem * pMusicSys);
 
};
bool State::playMusic(MusicSystem * pMusicSys) {
    std::cout << "Sorry Music Cannot be played\n";
    return false;
}
bool State::stopMusic(MusicSystem * pMusicSys) {
    std::cout << "Sorry Music Cannot be played as Music is already stopped\n";
    return false;
}
bool State::previousSong(MusicSystem * pMusicSys) {
    std::cout << "Sorry previous song Cannot be played\n";
    return false;
}
bool State::nextSong(MusicSystem * pMusicSys) {
    std::cout << "Sorry previous song Cannot be played\n";
    return false;
}

