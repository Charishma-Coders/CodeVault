class Solution {
public:
    long long maxArrayValue(vector<int>& nums) {
        int n=nums.size();
        long long ans=nums[n-1];
        long long nextEle=nums[n-1];
        for (int i=n-2;i>=0;i--){
            if (nums[i]<=nextEle) nextEle+=nums[i];
            else nextEle=nums[i];
            ans=max(ans,nextEle);
        }
        return ans;
    }
};