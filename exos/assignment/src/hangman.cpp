#include "includes/hangman.hpp"
#include <algorithm>
#include <array>
#include <iostream>
#include <random>
#include <string>
#include <vector>
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

bool player_alive(const int& number_of_lives)
{
    if (number_of_lives == 0)
        return false;
    else
        return true;
}

bool player_won(const std::vector<bool>& letters_guessed)
{
    return std::all_of(letters_guessed.begin(), letters_guessed.end(), [](bool state) { return state; });
}

void show_number_lives(const int& number_of_lives)
{
    std::cout << "Il vous reste " << number_of_lives << " vies" << std::endl;
}
void show_word_to_guess_with_missing_letters(const std::string& word_to_guess, const std::vector<bool>& letters_guessed)
{
    for (size_t i = 0; i < word_to_guess.size(); i++) {
        if (letters_guessed[i] == true) {
            std::cout << word_to_guess[i];
        }
        else
            std::cout << "-";
    }
    std::cout << std::endl;
}
void show_congrats_message(const std::string& word_to_guess)
{
    std::cout << " Félicitation vous avez trouvé le mot qui est : " << word_to_guess << std::endl;
}

void show_grosloozer_message(const std::string& word_to_guess)
{
    std::cout << " Oups vous avez perdu, le mot à trouver était : " << word_to_guess << std::endl;
}

void remove_one_life(int& number_of_lives)
{
    number_of_lives -= 1;
}

bool word_to_guess_contains(const char& letter, const std::string& word_to_guess)
{
    if (word_to_guess.find(letter) > word_to_guess.size() - 1)
        return false;
    else
        return true;
}

void marks_as_guessed(const char& guess, std::vector<bool>& letters_guessed, const std::string& word_to_guess)
{
    for (size_t i = 0; i < letters_guessed.size(); i++) {
        if (word_to_guess[i] == guess) {
            letters_guessed[i] = true;
        }
    }
}

void play_hangman()
{
    const std::string word_to_guess   = rand_word();
    int               number_of_lives = 5;
    std::vector<bool> letters_guessed;
    letters_guessed.resize(word_to_guess.size(), false);

    while (player_alive(number_of_lives) && !player_won(letters_guessed)) {
        show_number_lives(number_of_lives);
        show_word_to_guess_with_missing_letters(word_to_guess, letters_guessed);
        char guess = get_input_from_user<char>();

        if (word_to_guess_contains(guess, word_to_guess)) {
            marks_as_guessed(guess, letters_guessed, word_to_guess);
        }
        else {
            remove_one_life(number_of_lives);
        }
    }

    if (player_won(letters_guessed)) {
        show_congrats_message(word_to_guess);
    }
    else {
        show_grosloozer_message(word_to_guess);
    }
}
