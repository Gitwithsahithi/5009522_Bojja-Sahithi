#include <stdio.h>
#include <stdlib.h>

#define MAX 100000

int main() {
    int q;
    scanf("%d", &q);

    int stack1[MAX];  
    int stack2[MAX];  
    int top1 = -1, top2 = -1;

    while (q--) {
        int type;
        scanf("%d", &type);

        if (type == 1) {
          
            int x;
            scanf("%d", &x);
            stack1[++top1] = x;
        } 
        else if (type == 2) {
        
            if (top2 == -1) {
         
                while (top1 != -1) {
                    stack2[++top2] = stack1[top1--];
                }
            }
        
            if (top2 != -1) {
                top2--;
            }
        } 
        else if (type == 3) {
           
            if (top2 == -1) {
            
                while (top1 != -1) {
                    stack2[++top2] = stack1[top1--];
                }
            }
            if (top2 != -1) {
                printf("%d\n", stack2[top2]);
            }
        }
    }

    return 0;
}
