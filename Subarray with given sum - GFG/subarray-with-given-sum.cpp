//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
    #define ll long long
    //Function to find a continuous sub-array which adds up to a given number.
    vector<int> subarraySum(vector<int>arr, int n, ll s)
    {
        // Your code here
        if(s == 0) return {-1};
        ll sum = 0;
        int j = 0;
        bool flag = false;
        set<int> s1;
        for(int i = 0; i < n; i++){
            sum += (ll)arr[i];
            s1.insert(i);
            while(sum > s){
                sum -= (ll)arr[j];
                s1.erase(j);
                j++;
            }
            if(sum == s){
                flag = true;
                break;
            }
        }
        vector<int> v(s1.begin(), s1.end());
        if(flag){
            return {v.front() + 1, v.back() + 1};
        }
        return {-1};
    }
};

//{ Driver Code Starts.

int main()
 {
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        long long s;
        cin>>n>>s;
        vector<int>arr(n);
        // int arr[n];
        const int mx = 1e9;
        for(int i=0;i<n;i++)
        {
            cin>>arr[i];
        }
        Solution ob;
        vector<int>res;
        res = ob.subarraySum(arr, n, s);
        
        for(int i = 0;i<res.size();i++)
            cout<<res[i]<<" ";
        cout<<endl;
        
    }
	return 0;
}
// } Driver Code Ends