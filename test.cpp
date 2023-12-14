#include <iostream>
#include <random>

int main() {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<int> distribution(1, 5000000);
    int random_number = distribution(gen);

    std::cout << "Random number: " << random_number << std::endl;

    return 0;
}
