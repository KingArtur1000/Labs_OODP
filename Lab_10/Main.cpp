#include "Task_1.h"
#include "Task_2.h"
#include "Task_3.h"


int main() {
    setlocale(0, "");
    std::cout << "������� 5, �������� ����� �������������:\n\n";


    std::cout << "������� 1: �������� ������� ��������� �������\n";
    std::vector<int> A = { 1, 2, 3 };
    reverseVector(A);
    std::cout << "\n\n";


    std::cout << "������� 2: ������ � ����������\n";
    createThreadsWithIterator();
    std::cout << "\n\n";


    std::cout << "������� 3: ������������ ��������� ��������\n";
    std::vector<int> vec1 = { 1, 2, 3, 4 };
    std::vector<int> vec2 = { 5, 6, 7, 8 };
    multiplyVectorsInIntervals(vec1, vec2);
    std::cout << "\n\n";


    return 0;
}
