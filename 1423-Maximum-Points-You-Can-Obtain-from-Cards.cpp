class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int lsum=0,rsum=0,maxSum;
        int n=cardPoints.size();
        for(int i=0;i<=k-1;i++)
        lsum+=cardPoints[i];

        maxSum=lsum;
        int j=n-1;
        for(int i=k-1;i>=0;i--)
        {
            lsum-=cardPoints[i];
            rsum+=cardPoints[j];
            maxSum=max(maxSum,lsum+rsum);
            j--;

        }
        
        return maxSum;
    }
};