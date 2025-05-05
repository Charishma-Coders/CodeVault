//{ Driver Code Starts
// Initial function template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

// User function template for C++

class Solution {
  public:
    int partition(vector<int>& nums,int l,int r){
        while (l<r){
            if (nums[l+1]<=nums[l]){
                swap(nums[l+1],nums[l]);
                l++;
            }
            else if (nums[r]>nums[l]) r--;
            else{
                swap(nums[r],nums[l+1]);
            }
        }
        return l;
    }
    int quickSelect(vector<int>& nums,int l,int r,int k){
        if (l==r) return nums[l];
        int p=partition(nums,l,r);
        if (k==p) return nums[p];
        else if (k>p) return quickSelect(nums,p+1,r,k);
        return quickSelect(nums,l,p-1,k);
    }
    int kthSmallest(vector<int> &nums, int k) {
        return quickSelect(nums,0,nums.size()-1,k-1);
    }
};


//{ Driver Code Starts.

int main() {
    int test_case;
    cin >> test_case;
    cin.ignore();
    while (test_case--) {

        int k;
        vector<int> arr, brr, crr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        getline(cin, input);
        ss.clear();
        ss.str(input);
        while (ss >> number) {
            crr.push_back(number);
        }
        k = crr[0];
        int n = arr.size();
        Solution ob;
        cout << ob.kthSmallest(arr, k) << endl << "~\n";
    }
    return 0;
}

// } Driver Code Ends