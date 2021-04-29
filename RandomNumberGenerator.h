#pragma once
#include <cmath>
#include <iostream>
#include <vector>
#include "Data.h"

class RandomNumberGenerator {
private:
    int size = 6;
    long seed = 1;
    std::vector<Data> data;

public:

    RandomNumberGenerator(long seedValue, int size);
    RandomNumberGenerator();
    int nextInt(int low, int high);
    float nextFloat(int low, int high);
    void setSeedAndSize();
    void create();
    void print();
    static void print(std::vector<Data> data);
    static int countDigit(int n);
    std::vector<Data> get ();

};