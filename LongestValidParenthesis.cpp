// PROBLEM : Given a string containing only '(' and ')' characters, find the length of the longest
// substring that uses the parenthesis correctly.


#include <string>
#include <iostream>

using namespace std;
int count_longest(string& str)
{
    int left = 0; int right = 0; int count = 0;

    for (char i : str)
    {
        i == '(' ? left +=1 : right +=1;

        if (left - right <  0)
        {
            if (left + right - 1 >  count) { count = left + right - 1;}
            left = 0; right = 0;
        }
    }

    return max(count, left+right - (left - right));
}

int main()
{

    string str("(()(((()()))())");

    int count = count_longest(str);

    cout << "The longest valid parenthesis substring has length " << count << " characters.";

    return 0;
}