#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* isBalanced(char* s) {
    static char yes[] = "YES";
    static char no[] = "NO";
    char stack[1000];
    int top = -1;

    for (int i = 0; s[i] != '\0'; i++) {
        char ch = s[i];

       
        if (ch == '(' || ch == '{' || ch == '[') {
            stack[++top] = ch;
        } 
        else {
            
            if (top == -1)
                return no;

            char last = stack[top--];
            if ((ch == ')' && last != '(') ||
                (ch == '}' && last != '{') ||
                (ch == ']' && last != '[')) {
                return no;
            }
        }
    }

    if (top == -1)
        return yes;
    else
        return no;
}

int main() {
    int t;
    scanf("%d", &t);
    getchar(); 
    while (t--) {
        char s[1000];
        scanf("%s", s);
        printf("%s\n", isBalanced(s));
    }

    return 0;
}