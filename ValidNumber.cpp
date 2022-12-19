// See Leetcode description for "Valid Number" Problem

#include<string>
#include <iostream>

using namespace std;

class Solution
{
public:

    Solution()
    :e(nullptr),
     dot(nullptr),
     plusminus(nullptr),
     digit(nullptr)
    {}

    bool isnumber(const string& candidate)
    {
        const char* cand = candidate.c_str();
        const char* start = cand;

        // fringe case
        if (*start == '.' && (*(start+1) == 'e' || *(start + 1) == 'E')) {return false;}
        if (*start == 'e') {return false;}

        while (*cand)
        {
            if (47 < *cand && *cand < 58) {digit = cand; cand++; continue;}

            if (*cand == 'e' || *cand == 'E')
            {
                // cannot have plusminus before an exponent
                if (plusminus == cand - 1) {return false;}

                // if an exponent already exists in the string, we cant have another one
                if (e) {return false;}
                e = cand; cand ++; continue;
            }

            if (*cand == '.')
            {
                // cannot have two decimals in string || cannot have decimal exponent
                if (dot || e) {return false;}
                dot = cand; cand ++; continue;
            }

            if (*cand == '+' || *cand == '-')
            {

                // if no exponent and a previous plus minus...
                if (!e && plusminus) {return false;}

                // if no exponent and no previous plusminus...
                if (!e && !plusminus)
                {
                    if (cand == start) {plusminus = cand; cand++; continue;}
                    return false;
                }

                if (e == cand - 1) {plusminus = cand; cand ++; continue;}

                return false;

            }

            return false;
        }

        // last character cannot be exponent or plusminus
        if (cand-1 == e || cand-1 == plusminus) {return false;}

        // last character can be decimal accompanied by digit
        if (cand-1 == dot) {return digit;}

        return true;
    }

private:
    const char* e;
    const char* dot;
    const char* plusminus;
    const char* digit;
};


int main()
{
    string candidate("5.");

    cout << "The candidate: " << candidate << " is a number : " << Solution().isnumber(candidate);

    return 0;
}
