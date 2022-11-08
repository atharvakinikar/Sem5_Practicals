#include <bits/stdc++.h>
using namespace std;
int n;

bool safeSquare(vector<vector<int>> &board, int row, int col)
{
    int i, j;
    for (i = 0; i < col; i++)
    {
        if (board[row][i])
        {
            return false;
        }
    }

    for (i = row, j = col; i >= 0 && j >= 0; i--, j--)
    {
        if (board[i][j])
        {
            return false;
        }
    }

    for (i = row, j = col; j >= 0 && i < n; i++, j--)
    {
        if (board[i][j])
        {
            return false;
        }
    }

    return true;
}

bool traverseColumn(vector<vector<int>> &board, int column)
{
    if (column >= n)
    {
        return true;
    }

    for (int i = 0; i < n; i++)
    {
        if (safeSquare(board, i, column))
        {
            board[i][column] = 1;

            if (traverseColumn(board, column + 1))
            {
                return true;
            }

            board[i][column] = 0;
        }
    }
    return false;
}

void solve()
{
    cout << "Enter size of the board : ";
    cin >> n;
    vector<vector<int>> board(n, vector<int>(n, 0));
    if (traverseColumn(board, 0))
    {
        for (int i = 0; i < board.size(); i++)
        {
            for (int j = 0; j < board[0].size(); j++)
            {
                cout << " " << board[i][j] << " ";
            }
            cout << endl;
        }
        return;
    }
    else
    {
        cout << "\nSOLUTION DOES NOT EXIST!";
        return;
    }
}

// main function
int main()
{
    solve();
    return 0;
}