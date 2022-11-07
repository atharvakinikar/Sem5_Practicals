#include <bits/stdc++.h>
using namespace std;

int available[3] = {2, 1, 0};
bool finish[5] = {false, false, false, false, false};
int allocation[5][3] = {{1, 1, 2}, {2, 1, 2}, {4, 0, 1}, {0, 2, 0}, {1, 1, 2}};
int max_need[5][3] = {{4, 3, 3}, {3, 2, 2}, {9, 0, 2}, {7, 5, 3}, {1, 1, 2}};
int need[5][3];

int main()
{
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            need[i][j] = max_need[i][j] - allocation[i][j];
        }
    }
    /**
    need[5][3] = {
       3 2 1,
       1 1 0,
       5 0 1,
       7 3 3,
       0 0 0,
    }
    */

    int isSafeState, isStarving;
    cout << "Process sequence: ";
    while (true)
    {
        isSafeState = 0;
        bool check_process;
        for (int process = 0; process < 5; process++)
        {
            check_process = true;
            if (!finish[process])
            {
                for (int resource = 0; resource < 3; resource++)
                {
                    if (need[process][resource] > available[resource])
                    {
                        check_process = false;
                        break;
                    }
                }
                if (!check_process)
                    continue;
                for (int resource = 0; resource < 3; resource++)
                {
                    available[resource] += allocation[process][resource];
                    need[process][resource] = 0;
                }
                finish[process] = true;
                cout << "P" << process + 1 << " ";
            }
        }
        isStarving = 0;
        for (int process = 0; process < 5; process++)
        {
            if (finish[process])
            {
                isStarving++;
            }
            else
            {
                if (isSafeState)
                {
                    cout << "Deadlock condition!" << endl;
                    return 0;
                }
            }
        }
        if (isStarving >= 5)
        {
            cout << "\nAll process finished CPU in idle state..." << endl;
            return 0;
        }
    }
};