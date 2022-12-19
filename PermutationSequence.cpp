// Given n and k, return the kth permutation sequence. We do this by listing out all the permutations possible and
// sorting them. The kth smallest permutation of n = the kth permutation sequence.
#include <vector>
#include <iostream>

using namespace std;

class Solution
{
public:

    explicit Solution(int n, int k)
    :N(n)
    {
        vector<int> buckets = find_buckets(k);

        vector<int> digits = find_digits(buckets);
        cout << "The " << k << "th "<<  "permutation of " << N << " is: ";

        for (int digit : digits)
        {
            cout << digit;
        }
    }


private:

    int factorial(int n)
    {
        int ans = 1;
        while (n > 0) {ans *= n; n--;}
        return ans;
    }

    vector<int> find_buckets(int k)
    {
        vector<int> buckets(N);

        int c = factorial(N - 1);
        for (int i = 0; i < N-1; i++)
        {
            // if k == 0 this corresponds to the last bucket, otherwise it corresponds to ceil(k/c) bucket
            buckets[i] = k == 0 ? N - i : int(k/c + (k % c != 0));
            k = k % c;
            c = c / (N - i - 1);
        }

        // for the last bucket we only have one choice, set it equal to one
        buckets[N-1] = 1;

        return buckets;
    }

    vector<int> find_digits(vector<int> buckets)
    {

        vector<int> nums(N);
        for (int i = 0; i < N; i++) {nums[i] = i+1;}

        vector<int> digits(N);
        for (int i = 0; i < N; i++)
        {
            digits[i] = nums[buckets[i]-1];

            // this happens in O(n) time, can be optimized with a data structure offering O(1) removal time
            nums.erase(nums.begin()+buckets[i]-1);
        }

        return digits;
    }

private:
    int N;
};


int main()
{

    Solution(4,3);
    return 0;
}
