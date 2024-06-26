// PROBLEM : GIVEN N Queens and an N x N chess-board, find all configurations of the board where no queen is attacking
// any other queen.

#include <cstdlib>
#include <iostream>


using namespace std;

class Solution
{
public:
    explicit Solution(int N)
            :N(N),
             board(new int*[N]){

                 for (int i = 0 ; i < N; i++)
                    { board[i] = new int[N]();}

                    recurse(0);
                 }

    ~Solution()
    {
        for (int i = 0 ; i < N; i ++) {delete[] board[i];}
        delete[] board;
    }
private:


    bool place_queen(int i, int j)
    {

        if (board[i][j] != 0) {return false;}

        for (int k = 0 ; k < N ; k++)
        {
            board[i][k] ++;
            board[k][j] ++;
        }

        board[i][j] = -1;


        // southeast diagonal
        int incr = 1;
        while ( i + incr < N && j + incr < N)
        {
            board[i+incr][j+incr] ++;
            incr++;
        }

        // northeast diagonal
        incr = 1;
        while (i - incr >= 0 && j + incr < N)
        {
            board[i - incr][j + incr] ++;
            incr++;
        }

        // southwest diagoanal
        incr = 1;
        while (i + incr < N && j - incr >= 0)
        {
            board[i+incr][j - incr] ++;
            incr++;
        }

        // northwest diagonal
        incr = 1;
        while( i - incr >=0 && j - incr >= 0)
        {
            board[i - incr][j - incr] ++;
            incr++;
        }

        return true;
    }

    void rem_queen(int i, int j)
    {
        if (board[i][j] != -1) {exit(-1);}

        for (int k = 0 ; k < N ; k++)
        {
            board[i][k] --;
            board[k][j] --;
        }

        board[i][j] = 0;

        // southeast diagonal
        int incr = 1;
        while ( i + incr < N && j + incr < N)
        {
            board[i+incr][j+incr] --;
            incr++;
        }

        // northeast diagonal
        incr = 1;
        while (i - incr >= 0 && j + incr < N)
        {
            board[i - incr][j + incr] --;
            incr++;
        }

        // southwest diagoanal
        incr = 1;
        while (i + incr < N && j - incr >= 0)
        {
            board[i+incr][j - incr] --;
            incr++;
        }

        // northwest diagonal
        incr = 1;
        while( i - incr >=0 && j - incr >= 0)
        {
            board[i - incr][j - incr] --;
            incr++;
        }
    }

    void recurse(int row)
    {
        if (row == N-1)
        {
            for (int j = 0 ; j < N; j++)
            {
                if (place_queen( row, j))
                {
                    cout << "Solution Found: \n\n";

                    for (int x = 0 ; x < N; x ++)
                    {
                        for (int y = 0; y < N; y ++)
                        {
                            if (board[x][y] == -1) { cout << "Q, ";}
                            else {cout << "., ";}
                        }

                        cout << "\n";
                    }

                    rem_queen(row, j);

                }
            }
        }

        else
        {
            for (int j = 0 ; j < N; j++)
            {
                if (place_queen(row, j))
                {
                    recurse(row + 1);
                    rem_queen( row, j);
                }
            }
        }
    }

    int N;
    int** board;
};


int main()
{
    auto sol = Solution(4);
    return 0;
}
