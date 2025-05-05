#pragma once

#include <iostream>
#include <thread>
#include <vector>


// Функция для вывода информации о потоке
void printIteratorInfo(int iterator) {
    std::cout << "Итератор: " << iterator << ", ID потока: " << std::this_thread::get_id() << std::endl;
}


// Функция для создания потоков в цикле
void createThreadsWithIterator() {
    const int numThreads = 5; // Количество потоков
    std::vector<std::thread> threads;

    // Создаем потоки в цикле
    for (int i = 0; i < numThreads; ++i) {
        threads.emplace_back(printIteratorInfo, i); // Передаём номер итератора
    }

    // Ждём завершения всех потоков
    for (std::thread& t : threads) {
        t.join();
    }
}

