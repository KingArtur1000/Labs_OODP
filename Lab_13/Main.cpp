#include <iostream>
#include <thread>
#include <vector>
#include <chrono>
#include <mutex>


using std::cout;
using std::thread;
using std::vector;


// Функция для выполнения потока в первом задании
void threadTask1(int index) {
    cout << "Поток " << index << " начался. ID: " << std::this_thread::get_id() << '\n';
    cout << "Поток " << index << " завершен. ID: " << std::this_thread::get_id() << '\n';
}


// Задание 1: Запуск нескольких потоков без ожидания
void task1() {
    cout << "\n--- ЗАДАНИЕ 1 ---\n";
    vector<thread> threads;
    for (int i = 0; i < 5; ++i) {
        threads.emplace_back(threadTask1, i);
    }
    // Ожидание завершения всех потоков
    for (auto& t : threads) t.join();
}


// Функция для выполнения потока со сном
void threadTask2(int index) {
    cout << "Поток " << index << " стартует. ID: " << std::this_thread::get_id() << '\n';
    cout << "Поток " << index << " спит 1 сек. ID: " << std::this_thread::get_id() << '\n';
    std::this_thread::sleep_for(std::chrono::seconds(1)); // Сон на 1 секунду
    cout << "Поток " << index << " проснулся. ID: " << std::this_thread::get_id() << '\n';
}

// Задание 2: Потоки со временем ожидания
void task2() {
    cout << "\n--- ЗАДАНИЕ 2 ---\n";
    vector<thread> threads;
    for (int i = 0; i < 5; ++i) {
        threads.emplace_back(threadTask2, i);
    }
    for (auto& t : threads) t.join();
}


std::mutex mtx; // Создание глобального мьютекса


// Функция для выполнения потока с использованием мьютекса
void threadTask3(int index) {
    mtx.lock();
    cout << "Поток " << index << " стартует (mutex). ID: " << std::this_thread::get_id() << '\n';
    std::this_thread::sleep_for(std::chrono::milliseconds(500)); // Сон на 500 мс
    cout << "Поток " << index << " завершает (mutex). ID: " << std::this_thread::get_id() << '\n';
    mtx.unlock();
}


// Задание 3: Потоки с синхронизацией через мьютекс
void task3() {
    cout << "\n--- ЗАДАНИЕ 3 (mutex) ---\n";
    vector<thread> threads;
    for (int i = 0; i < 5; ++i) {
        threads.emplace_back(threadTask3, i);
    }
    for (auto& t : threads) t.join();
}


// Функция выполнения потока без мьютекса
void threadTask4_noMutex(int index) {
    cout << "Поток " << index << " cтартует (без mutex). ID: " << std::this_thread::get_id() << '\n';
    std::this_thread::sleep_for(std::chrono::milliseconds(200)); // Сон на 200 мс
    cout << "Поток " << index << " завершает (без mutex). ID: " << std::this_thread::get_id() << '\n';
}


// Задание 4: Сравнение работы потоков с мьютексом и без
void task4() {
    cout << "\n--- ЗАДАНИЕ 4 (Сравнение mutex / без mutex) ---\n";

    cout << "\n--- Без mutex ---\n";
    auto start_no_mutex = std::chrono::high_resolution_clock::now();

    vector<thread> threads1;
    for (int i = 0; i < 5; ++i) {
        threads1.emplace_back(threadTask4_noMutex, i);
    }
    for (auto& t : threads1) t.join();

    auto end_no_mutex = std::chrono::high_resolution_clock::now();
    auto duration_no_mutex = std::chrono::duration_cast<std::chrono::milliseconds>(end_no_mutex - start_no_mutex);

    cout << "\n--- С mutex ---\n";
    auto start_with_mutex = std::chrono::high_resolution_clock::now();

    vector<thread> threads2;
    for (int i = 0; i < 5; ++i) {
        threads2.emplace_back(threadTask3, i); // Повторное использование с mtx
    }
    for (auto& t : threads2) t.join();

    auto end_with_mutex = std::chrono::high_resolution_clock::now();
    auto duration_with_mutex = std::chrono::duration_cast<std::chrono::milliseconds>(end_with_mutex - start_with_mutex);

    // Вывод результатов сравнения
    cout << "\n--- Результаты измерения времени ---\n";
    cout << "Время выполнения без mutex: " << duration_no_mutex.count() << " миллисекунд\n";
    cout << "Время выполнения с mutex: " << duration_with_mutex.count() << " миллисекунд\n";
    cout << "Разница: " << (duration_with_mutex.count() - duration_no_mutex.count()) << " миллисекунд\n";
}


// Главная функция программы
int main() {
    setlocale(0, "");

    task1();
    task2();
    task3();
    task4();

    return 0;
}
