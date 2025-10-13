#include <stdio.h>
#include <stdint.h>

#define MOD 1000000007
#define MAX 1001

int64_t row[MAX];
int64_t solid[MAX];

int64_t mod_pow(int64_t a, int64_t b) {
    int64_t res = 1;
    while (b) {
        if (b % 2) res = (res * a) % MOD;
        a = (a * a) % MOD;
        b /= 2;
    }
    return res;
}

int legoBlocks(int n, int m) {
    row[0] = 1;
    for (int i = 1; i <= m; i++) {
        row[i] = row[i-1];
        if (i >= 2) row[i] = (row[i] + row[i-2]) % MOD;
        if (i >= 3) row[i] = (row[i] + row[i-3]) % MOD;
        if (i >= 4) row[i] = (row[i] + row[i-4]) % MOD;
    }

    int64_t wall[MAX];
    for (int i = 1; i <= m; i++) {
        wall[i] = mod_pow(row[i], n);
    }

    solid[0] = 0;
    for (int i = 1; i <= m; i++) {
        solid[i] = wall[i];
        for (int j = 1; j < i; j++) {
            solid[i] = (solid[i] - (solid[j] * wall[i-j]) % MOD + MOD) % MOD;
        }
    }

    return solid[m];
}

int main() {
    int t;
    scanf("%d", &t);
    while (t--) {
        int n, m;
        scanf("%d %d", &n, &m);
        printf("%d\n", legoBlocks(n, m));
    }
    return 0;
}
