//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Geeks {
  public:
    void insert(stack<int>& st, int x) {
        st.push(x);
    }

    void remove(stack<int>& st) {
        if (!st.empty()) st.pop();
    }

    void headOf_Stack(stack<int>& st) {
        if (!st.empty()) cout<<st.top()<<endl;
    }

    void find(stack<int>& st, int val) {
        stack<int> temp;
        bool found = false;

        while (!st.empty()) {
            if (st.top() == val) {
                found = true;
                break;
            }
            temp.push(st.top());
            st.pop();
        }

        // Restore the original stack
        while (!temp.empty()) {
            st.push(temp.top());
            temp.pop();
        }

        if (found) cout << "Yes" << endl;
        else cout << "No" << endl;
    }
};



//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;

    while (t--) {
        // Declaring stack of integers
        stack<int> st;

        int q;
        cin >> q;

        // Working with queries
        while (q--) {
            char ch;
            cin >> ch;
            Geeks obj;
            if (ch == 'i') {
                int x;
                cin >> x;
                obj.insert(st, x);
            }

            if (ch == 'r') {
                obj.remove(st);
            }

            if (ch == 'h') {
                obj.headOf_Stack(st);
            }
            if (ch == 'f') {
                int x;
                cin >> x;
                obj.find(st, x);
            }
        }
    }
}
// } Driver Code Ends