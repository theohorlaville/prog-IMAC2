#include "includes/hangman.hpp"
#include <array>
#include <iostream>
#include <random>
#include <string>
#include "includes/get_input_from_user.hpp"
#include "includes/rand_int.hpp"
const std::string rand_word()
{
    static constexpr std::array words_list = {
        "code",
        "crous",
        "imac",
        "opengl",
        "gaetan",
        "sylvain",
        "sonia",
        "jules"};

    std::string word_to_guess = words_list[rand_int(0, words_list.size() - 1)];

    return word_to_guess;
}

bool player_alive(const int number_of_lives)
{
    if (number_of_lives == 0)
        return false;
    else
        return true;
}

bool player_won()
{
    return true;
}

void show_number_lives(int& number_of_lives)
{
    std::cout << "Il vous reste " << number_of_lives << " vies" << std::endl;
}
void show_word_to_guess_with_missing_letters() {}

void play_hangman()
{
    const std::string word_to_guess   = rand_word();
    int               number_of_lives = 5;

    while (player_alive(number_of_lives) && !player_won()) {
        show_number_lives(number_of_lives);
        show_word_to_guess_with_missing_letters();
        char guess = get_input_from_user<char>();
    }
}