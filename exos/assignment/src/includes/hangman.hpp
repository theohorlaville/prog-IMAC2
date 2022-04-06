#pragma once
#include <iostream>
#include <vector>

const std::string rand_word();

bool player_alive(const int& number_of_lives);
bool player_won(const std::vector<bool>& letters_guessed);
void show_number_lives(const int& number_of_lives);
void show_word_to_guess_with_missing_letters(const std::string& word_to_guess, const std::vector<bool>& letters_guessed);
void show_congrats_message(const std::string word_to_guess);
void show_grosloozer_message(const std::string word_to_guess);
void remove_one_life(int& number_of_lives);
bool word_to_guess_contains(const char& letter, const std::string& word_to_guess);
void marks_as_guessed(const char& guess, std::vector<bool>& letters_guessed, const std::string& word_to_guess);
void play_hangman();
