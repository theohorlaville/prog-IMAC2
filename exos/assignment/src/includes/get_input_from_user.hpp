#include <iostream>

template<typename T>
T get_input_from_user()
{
    T user_try;
    std::cin >> user_try;
    return user_try;
}