#include <bits/stdc++.h>
using namespace std;

class item
{
public:
    int value, weight;
    item(int value, int weight)
    {
        this->value = value;
        this->weight = weight;
    }
};

bool compare(item a, item b)
{
    double val1 = double(a.value) / double(a.weight);
    double val2 = double(b.value) / double(b.weight);
    return val1 > val2;
}

double fraction_knapsack(int w, vector<item> arr, int n, vector<item> &knapsack)
{
    sort(arr.begin(), arr.end(), compare);
    // for (int i = 0; i < arr.size(); i++)
    // {
    //     cout << arr[i].weight << "\t" << arr[i].value << "\n";
    // }

    double ans = 0;

    for (int i = 0; i < arr.size(); i++)
    {
        if (arr[i].weight < w)
        {
            w -= arr[i].weight;
            ans += arr[i].value;
            item obj(arr[i].value, arr[i].weight);
            knapsack.push_back(obj);
        }

        else
        {
            ans += (double(arr[i].value) / double(arr[i].weight)) * double(w);
            item obj((double(arr[i].value) / double(arr[i].weight)) * double(w), w);
            knapsack.push_back(obj);
            w = 0;
            break;
        }
    }
    return ans;
}

int main()
{
    int w = 50;
    vector<item> arr = {{120, 30}, {60, 10}, {100, 20}};
    vector<item> knapsack;
    int n = arr.size();
    cout << "The total value is => " << fraction_knapsack(w, arr, n, knapsack);
    cout << "The values and corresponding weights are: \n";
    cout << "Weight"
         << "  "
         << "Value\n";
    for (int i = 0; i < knapsack.size(); i++)
    {
        cout << knapsack[i].weight << "\t" << knapsack[i].value << "\n";
    }
}