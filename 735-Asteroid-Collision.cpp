class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {

        int n=asteroids.size();
        vector<int>ans;
        stack<int>st;
        for(int i=n-1;i>=0;i--)
        {
            if(asteroids[i]<0)
            st.push(asteroids[i]);
            else{
                
            while(!st.empty() && st.top()<0 && abs(st.top())<asteroids[i])
            st.pop();

            if(!st.empty() && st.top()<0 && abs(st.top())==asteroids[i])
            st.pop();

            else if(st.empty() || st.top()>0)
            st.push(asteroids[i]);
            }
        }
        while(!st.empty())
        {
            int ele=st.top();
            st.pop();
            ans.push_back(ele);
        }
        return ans;

        
    }
};