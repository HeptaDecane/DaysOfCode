#include <bits/stdc++.h>
using namespace std;

class Solution{
public:
    static bool comparator(string a, string b){
        return a+b > b+a;
    }

    string printLargest(vector<string> &arr) {
        // TODO
        sort(arr.begin(), arr.end(), comparator);

        string res;
        for(string s : arr)
            res += s;

        return res;
    }
};

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, i;
        cin >> n;
        vector<string> arr(n);
        for (i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.printLargest(arr);
        cout << ans << "\n";
    }
    return 0;
}
