//longest subarray with sum 0 btana h

#include<bits/stdc++.h>
using  namespace std;

int longestsubarray(vector<int> &a)
{
    int n = a.size();
    int ans = 0;
    for(int i =0; i<n;i++)
    {
        int sum = 0;
        for(int j =0;j<n;j++)
        {
            sum = sum + a[j];
            if(sum == 0)
            {
                ans = max(ans,j-i+1);
            }
        }
    }
    return ans;
}

int longest_subarray(vector<int> &a)
{
    // Map to store the previous sums
    unordered_map<int, int> mp;

    int sum = 0;
    int max_len = 0;

    // Traverse through the given array
    for (int i = 0; i < a.size(); i++) {

        // Add current element to sum
        sum += a[i];

        if (sum == 0) 
        {
            max_len = i + 1;
        }

        // Look for this sum in Hash table
        if (mp.find(sum) != mp.end())
        {
            // If this sum is seen before, then update max_len
            max_len = max(max_len, i - mp[sum]);
        }
         else 
        {
            // Else insert this sum with index in hash table
            mp[sum] = i;
        }
    }

    return max_len;
}

int main() 
{
    vector<int> a = {15, -2, 2, -8, 1, 7, 10, 23};
    cout << longest_subarray(a)<<endl;
    return 0;
}