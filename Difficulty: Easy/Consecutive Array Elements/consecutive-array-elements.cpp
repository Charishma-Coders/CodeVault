//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends


class Solution {

  public:
    bool areConsecutives(vector<int>& arr) {
        int n=arr.size();
        int smallEle=*min_element(arr.begin(),arr.end());
        int indexSum=0;
        int overallSum=0;
        for (int i=0;i<n;i++){
            indexSum+=i;
            overallSum+=(arr[i]-smallEle);
        }
        return overallSum==indexSum;
    }
};



//{ Driver Code Starts.

int main() {
    string ts;
    getline(cin, ts);
    int t = stoi(ts);
    while (t--) {
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        Solution obj;
        bool res = obj.areConsecutives(arr);
        if (res)
            cout << "true" << endl;
        else
            cout << "false" << endl;
        // cout << res << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends