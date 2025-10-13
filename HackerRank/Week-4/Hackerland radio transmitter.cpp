#include <bits/stdc++.h>
using namespace std;

int hackerlandRadioTransmitters(vector<int>& x, int k) {
    sort(x.begin(), x.end());
    int n = x.size();
    int count = 0;
    int i = 0;

    while (i < n) {
        count++; 
        int loc = x[i] + k;  

        while (i < n && x[i] <= loc) i++;

     
        int transmitter = x[i-1] + k;

     
        while (i < n && x[i] <= transmitter) i++;
    }

    return count;
}

int main() {
    int n, k;
    cin >> n >> k;
    vector<int> x(n);
    for (int i = 0; i < n; i++) cin >> x[i];
    cout << hackerlandRadioTransmitters(x, k) << endl;
    return 0;
}