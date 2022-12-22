// See LEETCODE problem "Divide Two Integers"

#include <iostream>

int divide(int dividend, int divisor)
{
    if (dividend == INT_MIN)
    {
        if (divisor == -1) {return INT_MAX;}
        if (divisor == INT_MIN) {return 1;}
        if (divisor < 0){return 1 + divide(dividend - divisor, divisor);}
        else return -1 + divide(dividend + divisor, divisor);
    }

    if (divisor == INT_MIN) {return 0;}

    bool neg_dividend_flag = false;
    bool neg_divisor_flag = false;

    if (dividend < 0){dividend = -dividend; neg_dividend_flag = true;}
    if (divisor < 0){divisor = -divisor; neg_divisor_flag = true;}

    int cand = divisor;
    int rem = dividend;
    int multiplier;
    int ans = 0;

    while (rem >= divisor)
    {
        multiplier = 1;

        while(cand<<1 < rem && cand<<1 > 0)
        {
            cand <<= 1;
            multiplier <<= 1;
        }


        rem -= cand;
        cand = divisor;
        ans += multiplier;
    }

    if (neg_dividend_flag){ans = -ans;}
    if (neg_divisor_flag){ans = -ans;}

    return ans;
}

int main()
{
    std::cout << divide(INT_MIN, -1);
    return 0;
}
