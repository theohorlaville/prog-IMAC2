#include "includes/menu.hpp"
#include <iostream>
#include "includes/get_input_from_user.hpp"
#include "includes/guess_the_number.hpp"
#include "includes/hangman.hpp"

void display_menu()
{
    display_menu_options();
    start_game();
}

void display_menu_options()
{
    std::cout << "Hey, which game do you want to play today ?" << std::endl;
    std::cout << "q: Close" << std::endl;
    std::cout << "1: play Guess the Number" << std::endl;
    std::cout << "2: play Hangman" << std::endl;
}

void start_game()
{
    char user_choice = get_input_from_user<char>();

    switch (user_choice) {
    case 'q':
        break;
    case '1':
        play_guess_the_number();
        break;

    case '2':
        play_hangman();
        break;

    default:
        std::cout << "Oups, wrong command, try something else !" << std::endl;
        start_game();
    }
}