#include "Classes.h"

int main() {
    setlocale(0, "");


    OldMediaPlayer* oldPlayer = new OldMediaPlayer();


    NewMediaPlayer* adapter = new MediaPlayerAdapter(oldPlayer);


    // Воспроизведение файлов через адаптер
    adapter->play("song.mp3");   // Поддерживаемый формат
    std::cout << '\n';

    adapter->play("audio.wav"); // Поддерживаемый формат
    std::cout << '\n';

    adapter->play("video.mp4"); // Неподдерживаемый формат
    std::cout << '\n';


    delete adapter;
    delete oldPlayer;

    return 0;
}
