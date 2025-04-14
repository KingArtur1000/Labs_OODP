#include "Task_1.h"
#include "Task_2.h"
#include "Task_3.h"


int main() {
    setlocale(0, "");
    std::cout << "Вариант 5, Дмитриев Артур Александрович:\n\n";


    std::cout << "Задание 1: Обратный порядок элементов вектора\n";
    std::vector<int> A = { 1, 2, 3 };
    reverseVector(A);
    std::cout << "\n\n";


    std::cout << "Задание 2: Потоки с итератором\n";
    createThreadsWithIterator();
    std::cout << "\n\n";


    std::cout << "Задание 3: Перемножение элементов векторов\n";
    std::vector<int> vec1 = { 1, 2, 3, 4 };
    std::vector<int> vec2 = { 5, 6, 7, 8 };
    multiplyVectorsInIntervals(vec1, vec2);
    std::cout << "\n\n";


    return 0;
}
