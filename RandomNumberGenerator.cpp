//
// Created by Slowikus on 29.04.2021.
//

#include "RandomNumberGenerator.h"
RandomNumberGenerator::RandomNumberGenerator(long seedValue, int size) {
    this->size = size;
    this->seed = seedValue;
}

RandomNumberGenerator::RandomNumberGenerator() {};

int RandomNumberGenerator::nextInt(int low, int high) {
    long k;
    double value_0_1;
    long m = 2147483647l, a = 16807l, b = 127773l, c = 2836l;

    k = seed / b;
    seed = a * (seed % b) - k * c;
    if (seed < 0)
        seed = seed + m;
    value_0_1 = seed;
    value_0_1 /= m;
    return low + (int) floor(value_0_1 * (high - low + 1));
}

float RandomNumberGenerator::nextFloat(int low, int high) {
    low *= 100000;
    high *= 100000;
    float val = nextInt(low, high) / 100000.0;
    return val;
}

void RandomNumberGenerator::setSeedAndSize() {
    std::cout << "Podaj seed: ";
    std::cin >> seed;
    std::cout << std::endl;
    std::cout << "Podaj rozmiar danych: ";
    std::cin >> size;
    std::cout << std::endl;
}

void RandomNumberGenerator::create() {
    long sum = 0;

    for (int i = 0; i < size; ++i) {
        data.push_back(Data());
        data[i].j = i+1;
    }
    for (int i = 0; i < size; ++i) {
        data[i].p = nextInt(1,29);
        sum += data[i].p;
    }
    for (int i = 0; i < size; ++i) {
        data[i].w = nextInt(1,9);
    }
    for (int i = 0; i < size; ++i) {
        data[i].d = nextInt(1,29);
    }
}

void RandomNumberGenerator::print() {
    std::cout << "----------------------------" <<std::endl;
    std::cout << " J          P     W     D" <<std::endl;
    std::cout << "----------------------------" <<std::endl;
    for (int i = 0; i < size; ++i) {
        std::cout << " " << data[i].j;
        for (int j = 0; j < 11-countDigit(data[i].j); ++j) {
            std::cout << " ";
        }
        std::cout << data[i].p;
        for (int j = 0; j < 6-countDigit(data[i].p); ++j) {
            std::cout << " ";
        }
        std::cout << data[i].w;
        for (int j = 0; j < 6-countDigit(data[i].w); ++j) {
            std::cout << " ";
        }
        std::cout << data[i].d << std::endl;
    }
    std::cout << "----------------------------" <<std::endl;

}

int RandomNumberGenerator::countDigit(int n) {
    int count = 0;
    while (n != 0)
    {
        n = n / 10;
        ++count;
    }
    return count;
}

void RandomNumberGenerator::print(std::vector<Data> data) {
    std::cout << "----------------------------" <<std::endl;
    std::cout << " J          P     W     D" <<std::endl;
    std::cout << "----------------------------" <<std::endl;
    for (int i = 0; i < data.size(); ++i) {
        std::cout << " " << data[i].j;
        for (int j = 0; j < 11-countDigit(data[i].j); ++j) {
            std::cout << " ";
        }
        std::cout << data[i].p;
        for (int j = 0; j < 6-countDigit(data[i].p); ++j) {
            std::cout << " ";
        }
        std::cout << data[i].w;
        for (int j = 0; j < 6-countDigit(data[i].w); ++j) {
            std::cout << " ";
        }
        std::cout << data[i].d << std::endl;
    }
    std::cout << "----------------------------" <<std::endl;
}

std::vector<Data> RandomNumberGenerator::get() {
    return data;
}


