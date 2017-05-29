#include <stdio.h>

int data[101], N, W, ans=0;

int main()
{
    scanf("%d%d", &N, &W);

    for(int i=0; i<N; i++)
        scanf("%d", data+i);


    for(int i=0; i<N+W-1; i++)
    {
        int sum=0;
        for(int j=0; j<W; j++)
            sum+=data[i+j];
        if(sum>ans) ans=sum;
    }
    printf("%d", ans);
}


