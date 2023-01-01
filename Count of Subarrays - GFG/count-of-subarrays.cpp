//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

#define ll long long


// } Driver Code Ends
//User function template for C++
class Solution{
public:
	// #define ll long long

	ll countSubarray(int arr[], int n, int k) {
	    // code heres
	    stack<int>st;
	    vector<int>lefts(n,1),rights(n,1);
	    for(int i=n-1; i>=0; i--)
	    {
	        while(!st.empty() && arr[st.top()]<=arr[i])
	        st.pop();
	        int top=st.empty()?-1:st.top();
	      
	        if(st.size())
	        {
	            rights[i]=top-i;
	        }
	        else
	        {
	            rights[i]=n-i;
	        }
	          st.push(i);
	    }
	    while(!st.empty())
	    st.pop();
	    for(int i=0; i<n; i++)
	    {
	        while(!st.empty() && arr[st.top()]<arr[i])
	        st.pop();
	        int top=st.empty()?-1:st.top();
	        st.push(i);
	       lefts[i]=i-top;
	    }
	   // for(auto i:lefts)
	   // {
	   //     cout<<i<<" ";
	        
	   // }
	   // cout<<endl;
	   // for(auto i:rights)
	   // {
	   //     cout<<i<<" ";
	        
	   // }
	   // cout<<endl;
	   long long int ans=0;
	   for(int i=0; i<n; i++)
	   {
	       if(arr[i]>k)
	       {
	           ans+=lefts[i]*rights[i];
	       }
	   }
	    return ans;
	}
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k, i;
        cin >> n >> k;
        int arr[n];
        for (i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.countSubarray(arr, n, k);
        cout << ans << "\n";
    }
    return 0;
}
// } Driver Code Ends