#pragma once

#include <iostream>
#include <vector>
#include <thread>
#include <mutex>


std::mutex mtx; // ������� ��� ������������� ������� � ����� ����������
int scalarSum = 0; // ��������� ���������� ��� ����������


// ������� ��� ���������� ��������� � ���������
void multiplyIntervals(const std::vector<int>& vec1, const std::vector<int>& vec2, int start, int end) {
    int localSum = 0; // ��������� ���������� ����������
    for (int i = start; i < end; ++i) {
        localSum += vec1[i] * vec2[i];
    }

    // ������������������ ������ � ����� ����������
    std::lock_guard<std::mutex> lock(mtx);
    scalarSum += localSum;

    /*
        � �����������, ��� ������ ���� ����� � ����� ������ ������� ������ �������� scalarSum.
        � ������� ����������� ������ � ���������� ��� ������� � ������ �������.
        � �������� ���������� ��������� �� ���� ������������� std::lock_guard,
          ������� ������������� ������������ ������� ��� ������ �� ������� ���������.
    */
}


// ������� ��� ������������ ��������� ���� ��������
void multiplyVectorsInIntervals(const std::vector<int>& vec1, const std::vector<int>& vec2) {
    int numIntervals = 2; // ���������� ����������
    int intervalSize = vec1.size() / numIntervals;

    std::vector<std::thread> threads;

    // ��������� ������ ��� ��������� ����������
    for (int i = 0; i < numIntervals; ++i) {
        int start = i * intervalSize;
        int end = (i + 1) * intervalSize;
        threads.emplace_back(multiplyIntervals, std::ref(vec1), std::ref(vec2), start, end);
    }

    // ��� ���������� ���� �������
    for (std::thread& t : threads) {
        t.join();
    }

    // ������� �������� ���������
    std::cout << "�������������� ��������: " << scalarSum << std::endl;
}
