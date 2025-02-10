#include <iostream>
#include <vector>
using namespace std;

void two_sum(vector<int> &a, int target)
{
    int flag = 0;
    for (int i = 0; i < a.size() - 1; i++)
    {
        for (int j = i + 1; j < a.size(); j++)
        { 
            if (a[i] + a[j] == target)
            { 
                flag = 1;
                cout << "(" << i << "," << j << ")" << endl;
            }
            
        }
    }
    if(flag ==0)
    {
    cout << "No Such Pair is Found";
    }
}

int main()
{
    int target;
    cout << "Enter a number: ";
    cin >> target;

    vector<int> v = {1, 5, 9, 6, 2};

    two_sum(v, target);
    return 0;
}