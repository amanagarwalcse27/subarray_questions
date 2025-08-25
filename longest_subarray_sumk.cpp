//longest subarray nikalna h with sum k 
//here sliding window not valid as array contains negative also so slide the window from left can increase and decrease the sum
//also increrase the window can increase or decrease the sum 

#include<bits/stdc++.h>
using  namespace std;

int longestSubarray(vector<int>& a, int k) 
    {
        int n = a.size();
        vector<int> pf(n,0);
        
        //making prefix sum array 
        pf[0] = a[0];
        
        for(int i = 1; i < n;i++)
        {
            pf[i] = pf[i-1] + a[i];
        }
        
        unordered_map<int,int> mp;  //store first indices of each prefix sum 
        int maxlen = 0;
        
        for(int i = 0 ; i < n;i++)
        {
            
            if(pf[i] == k) maxlen = i+1;
            
            //find in map it's complemnt exist
            if(mp.find(pf[i]-k) != mp.end())
            {
                int len = i - mp[pf[i]-k];
                maxlen = max(len,maxlen);
            }
            
            //only store first occurence index only
            if(mp.find(pf[i]) == mp.end())  //first occurennce of prefix sum
            {
                mp[pf[i]] = i;
            }
            
        }
        return maxlen;
    }
        
        