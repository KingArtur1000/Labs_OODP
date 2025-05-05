#pragma once

#include <iostream>
#include <vector>
#include <thread>
#include <mutex>


std::mutex mtx; // Мьютекс для синхронизации доступа к общей переменной
int scalarSum = 0; // Скалярная переменная для результата


// Функция для выполнения умножения в интервале
void multiplyIntervals(const std::vector<int>& vec1, const std::vector<int>& vec2, int start, int end) {
    int localSum = 0; // Локальная переменная результата
    for (int i = start; i < end; ++i) {
        localSum += vec1[i] * vec2[i];
    }

    // Синхронизированный доступ к общей переменной
    std::lock_guard<std::mutex> lock(mtx);
    scalarSum += localSum;

    /*
        • Гарантирует, что только один поток в любой момент времени сможет обновить scalarSum.
        • Снижает вероятность ошибок и конфликтов при доступе к общему ресурсу.
        • Упрощает управление мьютексом за счёт использования std::lock_guard,
          который автоматически разблокирует мьютекс при выходе из области видимости.
    */
}


// Функция для перемножения элементов двух векторов
void multiplyVectorsInIntervals(const std::vector<int>& vec1, const std::vector<int>& vec2) {
    int numIntervals = 2; // Количество интервалов
    int intervalSize = vec1.size() / numIntervals;

    vector<thread> threads;

    // Запускаем потоки для обработки интервалов
    for (int i = 0; i < numIntervals; ++i) {
        int start = i * intervalSize;
        int end = (i + 1) * intervalSize;
        threads.emplace_back(multiplyIntervals, std::ref(vec1), std::ref(vec2), start, end);
    }

    // Ждём завершения всех потоков
    for (thread& t : threads) {
        t.join();
    }

    // Выводим итоговый результат
    cout << "Результирующее значение: " << scalarSum << std::endl;
}
