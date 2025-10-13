#include <bits/stdc++.h>
using namespace std;

int cookies(int k, vector<int>& A) {
    priority_queue<int, vector<int>, greater<int>> pq(A.begin(), A.end());
    int operations = 0;

    while (pq.size() > 1 && pq.top() < k) {
        int first = pq.top(); pq.pop();
        int second = pq.top(); pq.pop();
        int new_cookie = first + 2 * second;
        pq.push(new_cookie);
        operations++;
    }

    if (pq.top() < k) return -1;
    return operations;
}

int main() {
    int n, k;
    cin >> n >> k;
    vector<int> A(n);
    for (int i = 0; i < n; i++) cin >> A[i];
    cout << cookies(k, A) << endl;
    return 0;
}