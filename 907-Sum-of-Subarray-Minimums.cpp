class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
        int n=arr.size();
        vector<int>nse(n),psee(n);
        nse=findNse(arr);
        psee=findPsee(arr);
        long long total=0;
        long long mod=(int)(1e9+7);
        for(int i=0;i<n;i++)
        {
            long long left=i-psee[i];
            long long right=nse[i]-i;
            long long contribution=(arr[i]*left)%mod;
            contribution=(contribution*right)%mod;
            total=(total+contribution)%mod;
        }
        return (int)total;
        
    }
    vector<int> findNse(vector<int>& arr)
    {
        stack<int>st;
        int n=arr.size();
        vector<int>nse(n);
        for(int i=n-1;i>=0;i--)
        {
        while(!st.empty() && arr[st.top()]>=arr[i])
        {
            st.pop();
        }
        nse[i]=st.empty()?n:st.top();
        st.push(i);
        }
        return nse;


    }
     vector<int> findPsee(vector<int>& arr)
    {
        stack<int>st;
        int n=arr.size();
        vector<int>psee(n);
        for(int i=0;i<n;i++)
        {
        while(!st.empty() && arr[st.top()]>arr[i])
        {
            st.pop();
        }
        psee[i]=st.empty()?-1:st.top();
        st.push(i);
        }
        return psee;


    }
};