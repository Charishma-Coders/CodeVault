class Solution {
public:
    long long maximumMedianSum(vector<int>& nums) {
        int n=nums.size();
        if (n==0) return 0;
        long long sum=0;
        sort(nums.begin(),nums.end());
        int i=n/3;
        while (i>0){
            sum+=nums[n-2];
            n=n-2;
            i--;
        }
        return sum;
    }
};