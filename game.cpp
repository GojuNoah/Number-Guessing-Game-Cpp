#include <iostream>
#include <random>
#include <limits>


int main() {
    int player = 0;
    int computer = 0;

    //Get random number from device for the initial seed
    std::random_device rd;

    //Feed the Mersenne twister engine with the seed
    std::mt19937 engine(rd());
    
    //Set distribution and the range
    std::uniform_int_distribution<int> distribution(1,10);

    computer = distribution(engine);
    std::cout << "Welcome to the number guess game!" << std::endl;
    std::cout << "Guess a number between 1 and 10: "; std::cin >> player;

    while (player != computer) {
        std::cout << "Guess Again: ";
        if (!(std::cin >> player)) {
            std::cout << "Invalid input. Please enter a number between 1 and 10. ";
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        } else {
            if (player < 1 || player > 10) {
                std::cout << "Invalid number. Please enter a number between 1 and 10. ";
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            }
        }
    }

    std::cout << "Congrats! You guessed the number correctly." << std::endl;
    return 0;
}
