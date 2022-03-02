#include "includes/guess_the_number.hpp"
#include <iostream>
#include "includes/get_input_from_user.hpp"
#include "includes/hangman.hpp"
#include "includes/rand_int.hpp"

void play_guess_the_number()
{
    int number_to_guess = rand_int(0, 100);
    std::cout << "Donner un chiffre" << std::endl;
    int user_try = get_input_from_user<int>();

    //std::cout << "Valeur à trouver : " << number_to_guess << std::endl;
    while (number_to_guess != user_try) {
        if (user_try < number_to_guess) {
            std::cout << "Greater" << std::endl;
        }

        else {
            std::cout << "Smaller" << std::endl;
        }
        user_try = get_input_from_user<int>();
    }
    std::cout << "Félicitation : vous avez trouvé la valeur" << std::endl;
}
