#include "Lab_7.h"


int main() {
    setlocale(0, "");


    // ������� #1 ������� 5
    // 5.	���������: ���� ��������� ��������. ���������: ������ ���������� �������.

    string original_text = "������ ������";
    thread thr(threadFunction, original_text);
    thr.join();


    // ������� #2
    const int SIZE = 3;
    for (int i = 0; i < SIZE; i++) {
        thread thr(threadFunction2, i);
        cout << thr.get_id() << "\n";
        thr.join();
    }


    // ������� #3
    const int size = 10; // ������ ��������
    vector<int> vec1(size), vec2(size);


    // ��������� ������� �������
    for (int i = 0; i < size; ++i) {
        vec1[i] = i + 1;       // 1, 2, 3, ...
        vec2[i] = (i + 1) * 2; // 2, 4, 6, ...
    }


    // ��������� ������� �� 2 �����
    int mid = size / 2;
    int result1 = 0, result2 = 0;


    // ������� ��� ������
    thread t1(multiply_intervals, std::ref(vec1), std::ref(vec2), 0, mid, std::ref(result1));
    thread t2(multiply_intervals, std::ref(vec1), std::ref(vec2), mid, size, std::ref(result2));

    // ���� ���������� �������
    t1.join();
    t2.join();

    int result = result1 + result2;
    cout << "��������� ���������: " << result << std::endl;



    // ������� #3

    return 0;
}