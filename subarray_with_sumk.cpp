#include<bits/stdc++.h>
using namespace std;

//method1 using two for loops
int countSubarrays(vector<int>& arr, int k) 
{
     
        int n = arr.size();
    int count = 0;

    for (int i = 0; i < n; i++) 
    {
        int sum = 0;  // fresh sum for every i
        for (int j = i; j < n; j++) 
        {
            sum += arr[j];

            if (sum == K) 
            {
                count++;
            }
        }
    }

    return count;
    */
}
//method2 using prefix sum array and hashmap
/*
     int n = arr.size();
    vector<int> prefix(n);
    unordered_map<int, int> freq;
    int count = 0;

    // Build prefix sum array
    prefix[0] = arr[0];
    for (int i = 1; i < n; i++) 
    {
        prefix[i] = prefix[i - 1] + arr[i];
    }

    for (int i = 0; i < n; i++) 
    {
        // If entire subarray from 0 to i sums to K
        if (prefix[i] == K) count++;

        // If prefix[i] - K exists in map, add its frequency
        count += freq[prefix[i] - K];

        // Store current prefix sum frequency
        freq[prefix[i]]++;
    }

    return count;
    */

//optimal approach using hashmap
int count_Subarrays(vector<int> &a, int k) 
{
        int n = a.size();
        int total = 0;
        unordered_map<int,int> mp;  //store the frequencies for each hashmap
        int prefix_sum = 0;
        
        for(int i = 0; i <n;i++)
        {
            //1. find prefix sum on elemnt
            prefix_sum = prefix_sum + a[i];

            if(prefix_sum == k) count++;


            //2. check the complemnt of prefix sum exists or not in map 
            //if it exists in answer increase its value 
            //for subarray sum = 0 make k = 0
            if(mp.find(prefix_sum - k) != mp.end())
            {
                total = total + mp[prefix_sum - k];
            }

            //3.put current prefix sum in map
            mp[prefix_sum]++;
            
        }
        return total;
}

int main()
{
    vector<int> arr = {10, 2, -2, -20, 10};
    int k = -10;
    cout << count_Subarrays(arr, k);
    return 0;
}
