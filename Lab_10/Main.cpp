#include "Task_1.h"
#include "Task_2.h"
#include "Task_3.h"


int main() {
    setlocale(0, "");
    cout << "Вариант 5, Дмитриев Артур Александрович:\n\n";


    cout << "Задание 1: Обратный порядок элементов вектора\n";
    vector<int> A = { 1, 2, 3 };
    thread task1(reverseVector, A);
    task1.join();
    cout << "\n\n";


    cout << "Задание 2: Потоки с итератором\n";
    createThreadsWithIterator();
    cout << "\n\n";


    cout << "Задание 3: Перемножение элементов векторов\n";
    vector<int> vec1 = { 1, 2, 3, 4 };
    vector<int> vec2 = { 5, 6, 7, 8 };
    multiplyVectorsInIntervals(vec1, vec2);
    cout << "\n\n";


    return 0;
}
