#pragma once
#include "RandomNumberGenerator.h"
#include <algorithm>
class Algorithms {
    //nest_permutation - użyć
private:

public:

    //sortuje od najmniejszego do najwiekszego po d
    static bool compareD(const Data &a, const Data &b){
        return a.d < b.d;
    }
    //wylicza koszt*delay zadań
    static int delay(std::vector<Data> data);
    //przegląd zupełny
    static std::vector<Data> bruteforce(std::vector<Data> data);
    //metoda zachłanna
    static std::vector<Data> greedy(std::vector<Data> data);
};

