class Solution {
public:
    int partition(vector<int>& nums,int l,int r){
        int pivot=nums[r];
        int i=l;
        for (int j=l;j<r;j++){
            if (nums[j]>pivot){
                swap(nums[i],nums[j]);
                i++;
            }
        }
        swap(nums[i],nums[r]);
        return i;
    }
    int quickSelect(vector<int>& nums,int l,int r,int k){
        if (l==r) return nums[l];
        int p=partition(nums,l,r);
        if (k==p) return nums[p];
        else if (k>p) return quickSelect(nums,p+1,r,k);
        return quickSelect(nums,l,p-1,k);
    }
    int findKthLargest(vector<int>& nums, int k) {
        return quickSelect(nums,0,nums.size()-1,k-1);
    }
};