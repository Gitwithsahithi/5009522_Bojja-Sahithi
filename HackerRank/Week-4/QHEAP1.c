#include <iostream>
#include <set>
using namespace std;

int main() {
    int Q;
    cin >> Q;
    set<long long> heap;

    while (Q--) {
        int type;
        long long v;
        cin >> type;
        if (type == 1) {
            cin >> v;
            heap.insert(v);
        } else if (type == 2) {
            cin >> v;
            heap.erase(v);
        } else if (type == 3) {
            cout << *heap.begin() << endl;  // smallest element
        }
    }
    return 0;
}
