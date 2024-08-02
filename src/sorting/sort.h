#ifndef SORT_H
#define SORT_H

#include <sstream>
#include <functional>
#include <random>
#include <string>
#include <vector>
#include "utility/log.h"
#include "utility/timer.h"

template <typename T>
bool IsSorted(const T *array, const size_t size) {
    for (int i = 0; i < size - 1; i++) {
        if (array[i] > array[i + 1]) {
            return false;
        }
    }
    return true;
}

template <typename T>
void Swap(T &a, T &b) {
    T temp = a;
    a = b;
    b = temp;
}

template <typename T>
void Show(const T *array, const size_t size) {
    std::ostringstream oss;
    for (int i = 0; i < size; i++)
        oss << " " << array[i];
    LOG_INFO("[" + oss.str() + " ]");
}

class Test {
public:
    static void Sorting(const std::function<void(int*, size_t)> &sort, const size_t size, const int min_value, const int max_value, const bool show = false) {
        int* array = GenerateRandomArray(size, min_value, max_value);
        Sorting(sort, array, size, show);
    }

    static void Sorting(const std::function<void(int*, size_t)> &sort, const std::string& filename, const bool show = false) {
        size_t size;
        int* array = GetArrayFromData(filename, size);
        if (array == nullptr) return;
        Sorting(sort, array, size, show);
    }

    static void Sorting(const std::function<void(int*, size_t)> &sort, int* array, const size_t size, const bool show = false) {
        LOG_INFO("Test - Start: " + std::to_string(size) + " elements");
        if (show) Show(array, size);
        sort(array, size);
        if (show) Show(array, size);
        LOG_INFO(IsSorted(array, size) ? "PASS\n" : "FAIL\n");
        delete[] array;
    }

private:
    static int* GenerateRandomArray(const size_t size, const int min_value, const int max_value) {
        const auto array = new int[size];
        const unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
        std::mt19937 generator(seed);
        std::uniform_int_distribution<int> distribution(min_value, max_value);
        for (int i = 0; i < size; i++) {
            array[i] = distribution(generator);
        }
        return array;
    }

    static int* GetArrayFromData(const std::string& filename, size_t& ref_size) {
        std::ifstream in;
        in.open(std::string(DATA_PATH) + filename);
        if (!in.is_open()) {
            LOG_ERROR("failed to open file: " + filename);
            return nullptr;
        }
        std::string line;
        std::getline(in, line);
        ref_size = std::stoi(line);
        const auto numbers = new int[ref_size];
        for (int i = 0; i < ref_size; i++) {
            std::getline(in, line);
            numbers[i] = std::stoi(line);
        }
        in.close();
        return numbers;
    }
};



#endif //SORT_H
