#pragma once

#include <iostream>
#include <vector>
#include <thread>


// ������� ��� ��������� ������� �������
void reverseVector(const std::vector<int>& A) {
    std::vector<int> B(A.rbegin(), A.rend()); // ������ �������� �������

    std::cout << "�������� ������� �������: ";
    for (const int& num : B) {
        std::cout << num << " ";
    }

    std::cout << std::endl;
}

