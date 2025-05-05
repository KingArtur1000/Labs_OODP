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


// ������� ��� �������������� ������ � ������� �������
string to_lowercase(const string& input) {
    string result;
    transform(input.begin(), input.end(), back_inserter(result), ::tolower);
    return result;
}


// ������� ��� ��������� ����� ���������
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

    // �������� �������� �����
    vector<string> input = { "KingArtur1000", "RoSTICK", "���������������", "����-����" };
    vector<string> output(input.size());


    size_t num_threads = std::thread::hardware_concurrency(); // �������� ���������� ��������� �������
    if (num_threads == 0) num_threads = 1; // � ������, ���� �� �� ������������� ��� ����������
    cout << "���-�� ��������� �������: " << num_threads << "\n\n";


    size_t chunk_size = input.size() / num_threads;
    // ���������� ������� ������ "�����" ������ ��� ��������� � ������ ������.
    // ����� ����� ���������� ��������� �� ����� �������.


    vector<thread> threads;
    // ������ ��� �������� �������� �������. ������ ������� ����� ������������ ��������� �����.


    mutex output_mutex;
    // ������� ��� ������������� ������� � ��������� ������� "output" ����� ��������.
    // �����������, ��� ��������� ������� �� ���������� ������������ �������� ���� � �� �� ������.


    for (size_t i = 0; i < num_threads; ++i) {
        size_t start = i * chunk_size;
        // ������ ������ "�����", ������� ����� �������������� ������� �������.

        size_t end = (i == num_threads - 1) ? input.size() : start + chunk_size;
        // ������ ����� "�����". ��������� ����� ����� �������� ������ ������,
        // ���� ����� ����� ��������� �� ������� ������ �� ����� �������.

        threads.emplace_back(process_chunk, ref(input), ref(output), start, end, ref(output_mutex));
        // �������� ������ ������ � �������� process_chunk.
        // ���������� ������ (ref) �� ������� � �������� �������, ������� ������ � ����� ���������,
        // � ����� ������� ��� �������������. ����� ����� ����������� � ������ threads.
    }


    for (auto& t : threads) {
        t.join();
        // �������� ���������� ���� �������.
        // ������� join() ��������� ���������� ��������� ������, ���� �� ���������� ������� ����� t.
    }


    // ����� ����������
    for (const auto& str : output) {
        std::cout << str << '\n';
    }


    return 0;
}
