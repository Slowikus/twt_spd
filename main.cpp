#include "RandomNumberGenerator.h"
#include "Algorithms.h"

int main() {
    RandomNumberGenerator data(1,8);
    data.create();
    std::cout << "Wygenerowane Dane: " << std::endl;
    data.print();
    std::cout << "wiTi sum: " << Algorithms::delay(data.get()) << std::endl;

    std::cout << "Bruteforce: " << std::endl;
    std::vector<Data> brut;
    brut = Algorithms::bruteforce(data.get());
    RandomNumberGenerator::print(brut);
    std::cout << "wiTi sum: " << Algorithms::delay(brut) << std::endl;

    std::cout << "Greedy: " << std::endl;
    std::vector<Data> greed;
    greed = Algorithms::greedy(data.get());
    RandomNumberGenerator::print(greed);
    std::cout << "wiTi sum: " << Algorithms::delay(greed) << std::endl;
    return 0;
}
