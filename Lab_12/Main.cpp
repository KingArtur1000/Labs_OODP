#include <iostream>
#include <vector>
#include <string>
#include <thread>
#include <algorithm>
#include <cctype>
#include <mutex>


using std::string;
using std::vector;
using std::lock_guard;
using std::mutex;
using std::thread;

using std::cout;


// Функция для преобразования строки в верхний регистр
string to_lowercase(const string& input) {
    string result;
    transform(input.begin(), input.end(), back_inserter(result), ::tolower);
    return result;
}


// Функция для обработки части диапазона
void process_chunk(const vector<string>& input, vector<string>& output,
    size_t start, size_t end, mutex& output_mutex) {
    for (size_t i = start; i < end; ++i) {
        string transformed = to_lowercase(input[i]);
        lock_guard<mutex> lock(output_mutex);
        output[i] = transformed;
    }
}


int main() {
    setlocale(0, "");

    // Исходный диапазон строк
    vector<string> input = { "KingArtur1000", "RoSTICK", "Многопоточность", "Техн-Мехн" };
    vector<string> output(input.size());


    size_t num_threads = std::thread::hardware_concurrency(); // Получить количество доступных потоков
    if (num_threads == 0) num_threads = 1; // В случае, если ОС не предоставляет эту информацию
    cout << "Кол-во доступных потоков: " << num_threads << "\n\n";


    size_t chunk_size = input.size() / num_threads;
    // Вычисление размера одного "куска" данных для обработки в каждом потоке.
    // Делим общее количество элементов на число потоков.


    vector<thread> threads;
    // Вектор для хранения объектов потоков. Каждый элемент будет представлять отдельный поток.


    mutex output_mutex;
    // Мьютекс для синхронизации доступа к выходному массиву "output" между потоками.
    // Гарантирует, что несколько потоков не попытаются одновременно изменить одни и те же данные.


    for (size_t i = 0; i < num_threads; ++i) {
        size_t start = i * chunk_size;
        // Индекс начала "куска", который будет обрабатываться текущим потоком.

        size_t end = (i == num_threads - 1) ? input.size() : start + chunk_size;
        // Индекс конца "куска". Последний поток может получить больше данных,
        // если общее число элементов не делится нацело на число потоков.

        threads.emplace_back(process_chunk, ref(input), ref(output), start, end, ref(output_mutex));
        // Создание нового потока с функцией process_chunk.
        // Передаются ссылки (ref) на входной и выходной массивы, индексы начала и конца диапазона,
        // а также мьютекс для синхронизации. Новый поток добавляется в вектор threads.
    }


    for (auto& t : threads) {
        t.join();
        // Ожидание завершения всех потоков.
        // Функция join() блокирует выполнение основного потока, пока не завершится текущий поток t.
    }


    // Вывод результата
    for (const auto& str : output) {
        std::cout << str << '\n';
    }


    return 0;
}
