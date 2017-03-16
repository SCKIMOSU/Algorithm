#include <stdio.h>
#include <algorithm>

int n, A[101][101], cnt, Size[101];

bool safe(int a, int b)
{
    int dec;
    dec = (0<=a && a<n) && (0<=b && b<n);
    return (dec);
}

bool cmp(int a, int b)
{
    int dec1;
    dec1= a>b;
    return dec1;
}


void dfs(int a, int b, int c)
{

    A[a][b]=c;
    printf("%d ", A[a][b]);

    if (safe(a+1, b) && A[a+1][b]==1)
        dfs(a+1, b, c);

    if(safe(a-1, b) && A[a-1][b]==1)
        dfs(a-1, b, c);

    if(safe(a, b+1) && A[a][b+1]==1)
        dfs(a, b+1, c);

    if(safe(a, b-1) && A[a][b-1]==1)
        dfs(a, b-1, c);


}


void solve()
{

    for (int i=0; i<n; i++)
        for (int j=0; j<n; j++)
            if(A[i][j]==1)
            {
                cnt++;
                printf("%d ", cnt);
                 dfs(i, j, cnt+1);
            }

    for (int i=0; i<n; i++)
        for(int j=0; j<n; j++)
            if (A[i][j])
                Size[A[i][j]-2]++;

    std::sort(Size, Size+cnt, cmp);


}


void input()
{

    scanf("%d", &n);

    for (int i=0; i<n; i++)
        for (int j=0; j<n; j++)
        scanf("%d", &A[i][j]);
}


void output()
{
    printf("%d\n", cnt);

    for(int i=0; i<cnt; i++)
        printf("%d\n", Size[i]);
}


int main()
{

    input();
    solve();
    output();

}

