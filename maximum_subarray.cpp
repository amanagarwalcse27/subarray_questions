#include<bits/stdc++.h>
using namespace std;

int max_sum_subarray(vector<int> &a)
{
    int n = a.size();
    int ans = INT_MIN;

     // Outer loop for starting point of subarray
    for(int i = 0; i < n;i++)
    {
        int current_sum = 0;
        // Inner loop for ending point of subarray
        for(int j = i;j<n;j++)
        {
            current_sum = current_sum + a[j];
          //  Update ans if currSum is greater than ans
            ans = max(ans,current_sum);
        }
    }
    return ans;
}

//optimal approach using kadane's algorithm
int maxSubarraySum(vector<int> &a)
{
    int n = a.size();

    int ans = INT_MIN;  //maximum store krega 

    int sum = 0;

    for(int i = 0;i<n;i++)
    {
        sum = sum + a[i];

        ans = max(ans,sum);
        
        if(sum < 0)  //agr sum  -ve bne toh reset krdo sum ko 0 again
        {
            sum = 0;
        }
    }
    return ans;
}   

int main()
{
    vector<int> a= {2,3,-8,7,-1,2,3};

    int result = max_sum_subarray(a);
    cout<<result<<endl;

    return 0;
    
}