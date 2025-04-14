#pragma once

#include <iostream>
#include <thread>
#include <vector>


// ������� ��� ������ ���������� � ������
void printIteratorInfo(int iterator) {
    std::cout << "��������: " << iterator << ", ID ������: " << std::this_thread::get_id() << std::endl;
}


// ������� ��� �������� ������� � �����
void createThreadsWithIterator() {
    const int numThreads = 5; // ���������� �������
    std::vector<std::thread> threads;

    // ������� ������ � �����
    for (int i = 0; i < numThreads; ++i) {
        threads.emplace_back(printIteratorInfo, i); // ������� ����� ���������
    }

    // ��� ���������� ���� �������
    for (std::thread& t : threads) {
        t.join();
    }
}

