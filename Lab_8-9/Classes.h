#pragma once

#include <iostream>
#include <string>



class OldMediaPlayer {
public:
    void play(const std::string& audioType, const std::string& fileName) {
        if (audioType == "mp3" || audioType == "wav") {
            std::cout << "Воспроизведение файла: " << fileName << " (Тип: " << audioType << ")\n";
        }
        else {
            std::cout << "Ошибка: формат файла " << audioType << " не поддерживается.\n";
        }
    }
};



class NewMediaPlayer {
public:
    virtual void play(const std::string& fileName) = 0;
    virtual ~NewMediaPlayer() = default;
};



class MediaPlayerAdapter : public NewMediaPlayer {
private:
    OldMediaPlayer* oldMediaPlayer; // Указатель на старый плеер


public:
    MediaPlayerAdapter(OldMediaPlayer* player) : oldMediaPlayer(player) {}


    void play(const std::string& fileName) override {
        // Определяем тип файла по его расширению
        std::string audioType;
        if (fileName.substr(fileName.find_last_of('.') + 1) == "mp3") {
            audioType = "mp3";
        }
        else if (fileName.substr(fileName.find_last_of('.') + 1) == "wav") {
            audioType = "wav";
        }
        else {
            audioType = "unknown";
        }


        std::cout << "Адаптер: входящий файл - " << fileName << "\n";

        // Передаём обработку старому плееру
        oldMediaPlayer->play(audioType, fileName);


        std::cout << "Адаптер: завершил обработку файла - " << fileName << "\n";
    }
};
