#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main()
{
    int n,q;
    scanf("%d",&n);
    char strings[n][101];
    for(int i=0;i<n;i++){
        scanf("%s",strings[i]);
     }
     scanf("%d",&q);
     char queries[101];
      for(int i=0;i<q;i++){
        int count=0;
        scanf("%s",queries);
        for (int j=0;j<n;j++) {
            if(strcmp(strings[j],queries)==0){
                count++;
            }
        }
        printf("%d\n",count);
    }
    return 0;
}