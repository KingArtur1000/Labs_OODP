#pragma once

#include <iostream>
#include <thread>
#include <vector>


using std::vector;
using std::cout;
using std::thread;



void printIteratorInfo(int iterator) {
    cout << "Итератор: " << iterator << ", ID потока: " << std::this_thread::get_id() << std::endl;
}


void createThreadsWithIterator() {
    const int numThreads = 10; 
    vector<thread> threads;

    // Создаем потоки в цикле
    for (int i = 0; i < numThreads; ++i) {
        threads.emplace_back(printIteratorInfo, i); // Передаём номер итератора
    }

    // Ждём завершения всех потоков
    for (thread& t : threads) {
        t.join();
    }
}

