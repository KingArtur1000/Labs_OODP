#pragma once

#include <algorithm>
#include <iostream>
#include <thread>
#include <string>


using std::thread;
using std::string;
using std::cout;
using std::this_thread::get_id;


// Функция для перемножения частей векторов
void multiply_intervals(const std::vector<int>& vec1, const std::vector<int>& vec2,
    int start, int end, int& local_result) {
    local_result = 0;
    for (int i = start; i < end; ++i) {
        local_result += vec1[i] * vec2[i];
    }
}





