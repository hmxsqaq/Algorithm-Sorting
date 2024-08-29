#ifndef TEST_H
#define TEST_H

#include <functional>
#include <random>
#include "log.h"


class Numbers {
public:
    static int GenerateRandomNumber(const int min_value, const int max_value) {
        const unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
        std::mt19937 generator(seed);
        std::uniform_int_distribution distribution(min_value, max_value);
        return distribution(generator);
    }

    static void GenerateRandomNumbers(const size_t size, const int min_value, const int max_value, std::vector<int> &ref_nums) {
        ref_nums.resize(size);
        for (int i = 0; i < size; i++) {
            ref_nums[i] = GenerateRandomNumber(min_value, max_value);
        }
    }

    static void GetNumbersFromData(const std::string& filename, std::vector<int> &ref_nums) {
        std::ifstream in;
        in.open(std::string(DATA_PATH) + filename);
        if (!in.is_open()) {
            LOG_ERROR("failed to open file: " + filename);
            return;
        }
        std::string line;
        std::getline(in, line);
        const size_t size = std::stoi(line);
        ref_nums.resize(size);
        for (int i = 0; i < size; i++) {
            std::getline(in, line);
            ref_nums[i] = std::stoi(line);
        }
        in.close();
    }

    static void GenerateSortedNumbers(const int size, const bool ascend, std::vector<int> &ref_nums) {
        ref_nums.resize(size);
        if (ascend) {
            for (int i = 0; i < size; i++) ref_nums[i] = i;
        } else {
            for (int i = size - 1; i >= 0; i--) ref_nums[i] = i;
        }
    }
};



#endif //TEST_H
