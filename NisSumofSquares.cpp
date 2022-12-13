// PROBLEM : Given a positive integer n, determine is n can be written as the sum of the squares of two integers,
// i.e. is n^2 = a^2 + b^2 for some pair of integers a and b?

#include <cstdlib>
#include <math.h>
#include <iostream>

bool is_sum_of_squares(int n)
{

    for (size_t i = 0; i*i < n; i++)
    {
        size_t squared = i*i;

        if (sqrt(n - squared) == int(sqrt(n-squared)))
        {
            std::cout << "n is the sum of the squares of " << int(sqrt(n-squared)) << " and " << i;
            return true;
        }
    }

    std::cout << "n is not the sum of the squares of two integers";

    return false;
}

int main()
{
    int n = 25 + 64;
    bool ans = is_sum_of_squares(n);

    return 0;
}
