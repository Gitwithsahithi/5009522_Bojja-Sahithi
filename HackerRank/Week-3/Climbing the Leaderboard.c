#include <stdio.h>

#define MAX 200005
typedef long long ll;

int main() {
    ll n, m;
    ll arrN[MAX], arrM[MAX], result[MAX];
    
    
    scanf("%lld", &n);
    for (ll i = 0; i < n; i++) {
        scanf("%lld", &arrN[i]);
    }

   
    result[0] = 1;
    for (ll i = 1; i < n; i++) {
        if (arrN[i] == arrN[i - 1])
            result[i] = result[i - 1];
        else
            result[i] = result[i - 1] + 1;
    }
    result[n] = result[n - 1] + 1; 
    scanf("%lld", &m);
    for (ll i = 0; i < m; i++) {
        scanf("%lld", &arrM[i]);
    }

    ll i = n - 1; 
    for (ll j = 0; j < m; j++) {
       
        while (i > 0 && arrN[i] < arrM[j]) {
            i--;
        }

        if (arrN[i] == arrM[j]) {
            printf("%lld\n", result[i]);
        }
        else if (arrN[i] > arrM[j]) {
            printf("%lld\n", result[i] + 1);
        }
        else { // arrN[i] < arrM[j]
            if (result[i] == 1)
                printf("1\n");
            else
                printf("%lld\n", result[i] - 1);
        }
    }

    return 0;
}
