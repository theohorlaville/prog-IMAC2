#pragma once
#include <iostream>
#include <vector>

const std::string rand_word();

bool player_won(const std::vector<bool>& letters_guessed);
bool player_alive(const int number_of_lives);
void play_hangman();

void remove_one_life(int& number_of_lives);
void word_to_guess_contains(std::string word_with_guess, char guess);
void marks_as_guessed(char guess, std::string& word_to_guess);

void show_number_lives(int& number_of_lives);
void show_word_to_guess_with_missing_letters();
void show_congrats_message(const std::string word_to_guess);
void show_grosloozer_message(const std::string word_to_guess);
