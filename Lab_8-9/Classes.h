#pragma once

#include <iostream>
#include <string>



class OldMediaPlayer {
public:
    void play(const std::string& audioType, const std::string& fileName) {
        if (audioType == "mp3" || audioType == "wav") {
            std::cout << "��������������� �����: " << fileName << " (���: " << audioType << ")\n";
        }
        else {
            std::cout << "������: ������ ����� " << audioType << " �� ��������������.\n";
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
    OldMediaPlayer* oldMediaPlayer; // ��������� �� ������ �����


public:
    MediaPlayerAdapter(OldMediaPlayer* player) : oldMediaPlayer(player) {}


    void play(const std::string& fileName) override {
        // ���������� ��� ����� �� ��� ����������
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


        std::cout << "�������: �������� ���� - " << fileName << "\n";

        // ������� ��������� ������� ������
        oldMediaPlayer->play(audioType, fileName);


        std::cout << "�������: �������� ��������� ����� - " << fileName << "\n";
    }
};
