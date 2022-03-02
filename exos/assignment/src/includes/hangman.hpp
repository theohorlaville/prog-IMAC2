#pragma once
#include <iostream>

const std::string rand_word();
bool              player_won();
bool              player_alive(const int number_of_lives);
void              play_hangman();

void show_number_lives(int& number_of_lives);
void show_word_to_guess_with_missing_letters();