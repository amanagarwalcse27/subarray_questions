//hme btana h ki koi subarray exist krta h ya nhi 

#include<bits/stdc++.h>
using namespace std;
bool subArrayExists(vector<int>& a) 
{
    
    int n = a.size();
    for(int i=0;i<n;i++)
    {
        int sum = 0;

        for(int j=i;j<n;j++)
        {
            sum = sum + a[j];

             if(sum == 0)
            {
               return true;
            }
        }
    }
        
    return false;
}  

//using hashset  
bool isSubarry(vector<int> &a)
{
    int n = a.size();

    unordered_set<int> s;

    int prefix_sum = 0;
    
    for(int i=0;i<n;i++)
    {
        prefix_sum = prefix_sum + a[i];

        if(prefix_sum == 0)  //agr prefix sum  hi mil jaaye zero sum ka
        return true;
            
        if(s.find(prefix_sum) != s.end())  //we have to find that sum already exists or not 
        return true;
            
        s.insert(prefix_sum);  //insert that sum 
    }
    return false;
}

//count of subarray with zero sum
int findSubarray(vector<int> &a) 
{
    int n = a.size();
    int total = 0;  //total return krna h answer yh btayega number of subarrays with zero sum
    unordered_map<int,int> mp;   //map me key prefixsum hogi,value uska count
    int prefix_sum = 0;
    
    mp[0] = 1;  //intialize with 0 hashmap intially

    for(int i = 0; i < n;i++)
    {
        prefix_sum += a[i];

        if(mp.find(prefix_sum) != mp.end())
        {
            total = total + mp[prefix_sum];
        } 

            mp[prefix_sum]++;
        
    }
    return total;
} 

 int main()
 {
    vector<int> a = {};
    cout<<isSubarry(a)<<endl;

    return 0;
 }       