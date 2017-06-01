#include <stdio.h>

int n;

int solve()
{
    int cnt=0;
    scanf("%d", &n);

    int count=0;

    for (int a=1; a<=n; a++)
        for (int b=a; b<=n; b++)
            for (int c=b; c<=n; c++)
            {
                if(count%5==0) puts("");
                    count++;
                printf("[%d %d %d]\t", a,b, c);



            }

   puts("");
   puts("");

    for(int a=1; a<=n; a++)
        for(int b=a; b<=n; b++)
            for(int c=b; c<=n; c++)
                if(a+b+c==n && a+b>c)
                    {

                        cnt++;
                        printf(" result=[%d %d %d]\n", a,b, c);
                    }
    return cnt;


}

int main()
{
    printf("\n answer(cnt)= %d\n", solve());
}

