#include "guess_the_number.hpp"
#include <iostream>
#include <random>

/// Returns a random int between min (included) and max (included)
int rand(int min, int max)
{
    static std::default_random_engine  generator{std::random_device{}()};
    std::uniform_int_distribution<int> distribution{min, max};
    return distribution(generator);
}

int get_int_from_user()
{
    int user_try = 0;
    std::cin >> user_try;
    return user_try;
}

void play_guess_the_number()
{
    int number_to_guess = rand(0, 100);
    std::cout << "Donner un chiffre" << std::endl;
    int user_try = get_int_from_user();
    //std::cout << "Valeur à trouver : " << number_to_guess << std::endl;
    while (number_to_guess != user_try) {
        if (user_try < number_to_guess) {
            std::cout << "Greater" << std::endl;
        }

        else {
            std::cout << "Smaller" << std::endl;
        }
        user_try = get_int_from_user();
    }
    std::cout << "Félicitation : vous avez trouvé la valeur";
}
