#include "Classes.h"

int main() {
    setlocale(0, "");


    OldMediaPlayer* oldPlayer = new OldMediaPlayer();


    NewMediaPlayer* adapter = new MediaPlayerAdapter(oldPlayer);


    // ��������������� ������ ����� �������
    adapter->play("song.mp3");   // �������������� ������
    std::cout << '\n';

    adapter->play("audio.wav"); // �������������� ������
    std::cout << '\n';

    adapter->play("video.mp4"); // ���������������� ������
    std::cout << '\n';


    delete adapter;
    delete oldPlayer;

    return 0;
}
