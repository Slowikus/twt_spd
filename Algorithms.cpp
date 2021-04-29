//
// Created by Slowikus on 29.04.2021.
//

#include "Algorithms.h"

int Algorithms::delay(std::vector<Data> data) {
    int delay =0;
    int sum = 0;

    for (int i = 0; i < data.size(); ++i) {
        sum += data[i].p;
        if (data[i].d < sum) {
            delay += (sum - data[i].d)*data[i].w;
        }
    }

    return delay;
}

std::vector<Data> Algorithms::bruteforce(std::vector<Data> data) {
    int minDelay = INT_MAX;
    std::vector<Data> result;
    do
    {

        if(delay(data) < minDelay) {
            result = data;
            minDelay = delay(result);
        }

    } while (std::next_permutation(data.begin(), data.end(),
                                   [](const auto & lhs, const auto & rhs)
                                   { return lhs.j < rhs.j; }));

    return result;
}

std::vector<Data> Algorithms::greedy(std::vector<Data> data) {
    std::sort(data.begin(), data.end(), compareD);
    return data;
}
