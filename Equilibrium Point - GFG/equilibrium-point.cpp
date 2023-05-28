//{ Driver Code Starts
#include <iostream>
using namespace std;


// } Driver Code Ends

class Solution{
    public:
    // Function to find equilibrium point in the array.
    // a: input array
    // n: size of array
    #define ll long long
    int equilibriumPoint(ll a[], int n) {
        ll sum1 = 0, sum2 = 0;
        for(int i = 0; i < n; i++){
            sum1 += a[i];
        }
        for(int i = 0; i < n; i++){
            sum1 -= a[i];
            if(sum1 == sum2) return i + 1;
            sum2 += a[i];
        }
        return -1;
    }

};

//{ Driver Code Starts.


int main() {

    long long t;
    
    //taking testcases
    cin >> t;

    while (t--) {
        long long n;
        
        //taking input n
        cin >> n;
        long long a[n];

        //adding elements to the array
        for (long long i = 0; i < n; i++) {
            cin >> a[i];
        }
        
        Solution ob;

        //calling equilibriumPoint() function
        cout << ob.equilibriumPoint(a, n) << endl;
    }
    return 0;
}

// } Driver Code Ends