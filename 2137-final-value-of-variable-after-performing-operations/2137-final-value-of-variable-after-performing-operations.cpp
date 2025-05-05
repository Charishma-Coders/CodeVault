class Solution {
public:
    int finalValueAfterOperations(vector<string>& operations) {
        int x=0;
        for (auto each:operations){
            if (each=="++X") ++x;
            else if (each=="X++") x++;
            else if (each=="--X") --x;
            else if (each=="X--") x--;
        }
        return x;
    }
};