class Solution {
public:
    long long subArrayRanges(vector<int>& nums) {
        long long ans=findSubArrayMaximumsSum(nums)-findSubArrayMinimumsSum(nums);
        return ans;
        
    }
    long long findSubArrayMinimumsSum(vector<int>& nums)
    {
        long long total=0;
        int n=nums.size();
        vector<int>nse(n),psee(n);
        nse=findNse(nums);
        psee=findPsee(nums);
        for(int i=0;i<n;i++)
        {
            long long left=i-psee[i];
            long long right=nse[i]-i;
            long long contribution=nums[i]*left*right;
            total+=contribution;

        }
        return total;
    }
    vector<int>findNse(vector<int>& nums)
    {
        stack<int>st;
        int n=nums.size();
        vector<int>nse(n);
        for(int i=n-1;i>=0;i--)
        {
            while(!st.empty() && nums[st.top()]>=nums[i])
            st.pop();

            nse[i]=st.empty()?n:st.top();
            st.push(i);
        }
        return nse;
    }
    vector<int>findPsee(vector<int>& nums)
    {
        stack<int>st;
        int n=nums.size();
        vector<int>psee(n);
        for(int i=0;i<n;i++)
        {
            while(!st.empty() && nums[st.top()]>nums[i])
            st.pop();

            psee[i]=st.empty()?-1:st.top();
            st.push(i);
        }
        return psee;
    }
    long long findSubArrayMaximumsSum(vector<int>& nums)
    {
        long long totalMax=0;
        int n=nums.size();
        vector<int>nge(n),pgee(n);
        nge=findNge(nums);
        pgee=findPgee(nums);
        for(int i=0;i<n;i++)
        {
            long long left=i-pgee[i];
            long long right=nge[i]-i;
            long long contribution=nums[i]*left*right;
            totalMax+=contribution;

        }
        return totalMax;
    }
    vector<int>findNge(vector<int>& nums)
    {
        stack<int>st;
        int n=nums.size();
        vector<int>nge(n);
        for(int i=n-1;i>=0;i--)
        {
            while(!st.empty() && nums[st.top()]<=nums[i])
            st.pop();

            nge[i]=st.empty()?n:st.top();
            st.push(i);
        }
        return nge;
    }
    vector<int>findPgee(vector<int>& nums)
    {
        stack<int>st;
        int n=nums.size();
        vector<int>pgee(n);
        for(int i=0;i<n;i++)
        {
            while(!st.empty() && nums[st.top()]<nums[i])
            st.pop();

            pgee[i]=st.empty()?-1:st.top();
            st.push(i);
        }
        return pgee;
    }


};