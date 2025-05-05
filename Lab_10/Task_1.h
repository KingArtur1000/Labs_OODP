#pragma once

#include <iostream>
#include <vector>


// Функция для обратного порядка вектора
void reverseVector(const std::vector<int>& A) {
    std::vector<int> B(A.rbegin(), A.rend()); // Создаём обратный порядок

    std::cout << "Обратный порядок вектора: ";
    for (const int& num : B) {
        std::cout << num << " ";
    }

    std::cout << std::endl;
}

