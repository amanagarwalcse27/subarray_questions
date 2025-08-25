#include<bits/stdc++.h>
using namespace std;

void printsubarray(vector<int> &arr)
{
    int n = arr.size();
    for(int i = 0; i < n;i++)
    {
        for(int j = i ; j < n;j++)
        {
            for(int k = i ; k <= j;k++)
            {
                cout<<arr[k]<<" ";
            }
            cout<<endl;
        }
    }
}

int main()
{
    vector<int> arr = {2,4,6,8,10};
    printsubarray(arr);
    return 0;
}