#include <stdio.h>
#include <limits.h>

int main() {
    char str[100000];
    int count[26] = {0};
    scanf("%s", str);

 
    for (int i = 0; str[i] != '\0'; i++) {
        count[str[i] - 'a']++;
    }

    int max = INT_MIN, secondMax = 0;
    int min = INT_MAX, secondMin = 0;
    int maxCount = 0, minCount = 0;


    for (int i = 0; i < 26; i++) {
        if (count[i] == 0)
            continue;

    
        if (count[i] > max) {
            secondMax = max;
            max = count[i];
            maxCount = 1;
        } else if (count[i] == max) {
            maxCount++;
        } else if (count[i] > secondMax) {
            secondMax = count[i];
        }

        
        if (count[i] < min) {
            secondMin = min;
            min = count[i];
            minCount = 1;
        } else if (count[i] == min) {
            minCount++;
        }
    }

    
    if (max == min)
        printf("YES");
    else if ((max - min == 1 && maxCount == 1))
        printf("YES");
    else if (min == 1 && minCount == 1 && secondMin == max)
        printf("YES");
    else
        printf("NO");

    return 0;
}
