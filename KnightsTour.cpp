// See LEETCODE problem "Knight Probability"

#include <utility>
#include <vector>
#include <iostream>

using namespace std;
using Posn = pair<int,int>;

using Posns = vector<Posn>;


class Solution{
public:
    Solution(int n, int k)
    :N(n),
    K(k),
    directions({{2,1}, {2,-1}, {-2, 1}, {-2,-1}, {1, 2}, {-1, 2}, {1,-2}, {-1, -2}}),
    fprev(new double * [n]),
    f(new double * [n])
    {
        for (int i = 0 ; i < N; i++)
        {
            fprev[i] = new double [n]{0};
            f[i] = new double [n]{0};
        }
    }

    ~Solution()
    {
        for (int i = 0 ; i < N; i++)
        {
            delete[] fprev[i];
            delete[] f[i];
        }

        delete[] fprev;
        delete[] f;
    }

    void iterate()
    {
        for (int i = 0; i < N; i++){
            for (int j = 0; j < N; j++)
            {
                f[i][j] = 0;
                for (auto pos : directions)
                {
                    if (i + pos.first < N && i + pos.first > -1 && j+pos.second<N && j+pos.second>-1)
                    {
                        f[i][j] += 0.125*fprev[i+pos.first][j+pos.second];
                    }
                }
            }
        }
    }

    double solve(Posn position)
    {
        if (K==0) {return 1.0;}

        // initialize first board
        for (auto pos : directions)
        {
            if (position.first + pos.first < N && position.first + pos.first > -1 && position.second+pos.second<N && position.second+pos.second>-1)
            {
                fprev[position.first + pos.first][position.second + pos.second] = 0.125;
            }
        }

        // iterate the board until we reach K;
        for (int i = 1 ; i < K; i++)
        {
            iterate();
            swap(fprev, f);
        }

        // return the answer
        double ans = 0;
        for (int i = 0 ; i < N; i ++)
        {
            for (int j =0 ; j <N ; j ++)
            {
                ans += fprev[i][j];
            }
        }

        return ans;
    }

private:
    int N;
    int K;
    Posns directions;
    double** fprev;
    double** f;
};

int main()
{
    int N = 8;
    int K = 1;

    double probability = Solution(N, K).solve({4,4});

    cout << "The probability the knight stays on a " << N << "x" << N <<" board after " << K << " moves is: " << probability;
    return 0;
}
