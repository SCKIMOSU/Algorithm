#include <stdio.h>

#define MAXN 9

int main()
{
    int i, ans, index, A[MAXN+1];
    ans=0;
    index=0;

    for (i=1; i<MAXN+1; i++)
    {
        scanf("%d", &A[i]);
    }

    for(i=1; i<MAXN+1; i++)
        if(ans < A[i])
        {
            ans=A[i];
            index=i;
        }

    printf("%d\n%d\n", ans, index);
    return 0;
}
