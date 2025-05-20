// User function template for C++

class Solution {
  public:
    int fibo(int n,vector<int>& result){
        if (n==0) return result[0]=0;
        if (n==1) return result[1]=1;
        int value=fibo(n-1,result)+fibo(n-2,result);
        if (result[n]==-1) result[n]=value;
        return value;
    }
    vector<int> fibonacciNumbers(int n) {
        vector<int> result(n,-1);
        if (n<=1) return {0};
        fibo(n,result);
        return result;
    }
};