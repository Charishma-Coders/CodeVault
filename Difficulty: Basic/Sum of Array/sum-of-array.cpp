// User function template for C++
class Solution {
  public:
    int arrSum(vector<int>& arr,int idx){
        if (idx==arr.size()) return 0;
        return arr[idx]+arrSum(arr,idx+1);
    }
    int arraySum(vector<int>& arr) {
        return arrSum(arr,0);
    }
};