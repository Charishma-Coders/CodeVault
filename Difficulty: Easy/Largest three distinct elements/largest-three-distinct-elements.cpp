//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    vector<int> getThreeLargest(vector<int>& arr) {
        int n=arr.size();
        int first=INT_MIN,second=INT_MIN,third=INT_MIN;
        for (int i=0;i<n;i++){
            if (arr[i]>first){
                third=second;
                second=first;
                first=arr[i];
            }
            else if (arr[i]>second && arr[i]<first){
                third=second;
                second=arr[i];
            }
            else if (arr[i]>third && arr[i]<second){
                third=arr[i];
            }
        }
        if (first==INT_MIN) return {};
        else if (second==INT_MIN) return {first};
        else if (third==INT_MIN) return {first,second};
        return {first,second,third};
    }
};



//{ Driver Code Starts.

int main() {
    int tc;
    cin >> tc;
    cin.ignore(); // To ignore the newline after the number of test cases

    while (tc-- > 0) {
        string input;
        getline(cin, input);

        vector<int> arr;
        stringstream ss(input);
        int num;

        while (ss >> num) {
            arr.push_back(num);
        }

        Solution obj;
        vector<int> ans = obj.getThreeLargest(arr);

        for (int i : ans) {
            cout << i << " ";
        }
        cout << endl;
        cout << "~" << endl;
    }

    return 0;
}

// } Driver Code Ends