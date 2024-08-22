#ifndef TEST_H
#define TEST_H

#include <functional>
#include <random>
#include "utility/log.h"


class Numbers {
public:
    static void GenerateRandomNumbers(const size_t size, const int min_value, const int max_value, std::vector<int> &ref_nums) {
        ref_nums.reserve(size);
        const unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
        std::mt19937 generator(seed);
        std::uniform_int_distribution<int> distribution(min_value, max_value);
        for (int i = 0; i < size; i++) {
            ref_nums[i] = distribution(generator);
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
        ref_nums.reserve(size);
        for (int i = 0; i < size; i++) {
            std::getline(in, line);
            ref_nums.emplace_back(std::stoi(line));
        }
        in.close();
    }
};



#endif //TEST_H
