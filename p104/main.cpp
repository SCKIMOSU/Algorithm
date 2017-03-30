#include <stdio.h>
#include <queue>

struct VERTEX{int a, b;}; //꼭지점
int h,w,Sa, Sb, Ga, Gb, visited[101][101];
int dx[4]={1,0,-1,0}, dy[4]={0,1,0,-1};
char M[101][101];

bool safe(int a, int b)
{
    return (0<=a && a<h) && (0<=b && b<w);
}
void input(void)
{
    scanf("%d %d", &h, &w);

    for (int i=0; i<h; i++)
    {
        scanf("%s", M[i]);
        for (int j=0; j<w; j++)
        {
            if (M[i][j]=='S')
                Sa=i, Sb=j;
            else if (M[i][j]=='G')
                Ga=i, Gb=j;
           // else M[i][j]='.'
           //
        }

    }
}


int solve(void)
{
   std::queue<VERTEX> Q; // / 템플릿에 사용할 클래스의 형을 정의해준다.
    //  Q의 형태는 vertex형 queue 이다  VERTEX{int a, b;}는 두 개의 좌표 a,b를 가지는 꼭지점이다

    Q.push((VERTEX){Sa, Sb}), visited[Sa][Sb]=0;
     // Q는 vertex형 queue인 데, Sa와 Sb는 Start의 a,b 좌표이다


    while (!Q.empty())
    {
        VERTEX cur=Q.front(); // 첫 번째 원소에 접근한다. 접근하면 vertex타입의 {0,1}이 있다.
        Q.pop(); //첫 번째 원소를 제거한다

        if(cur.a==Ga && cur.b==Gb)
            break;

            for (int i=0; i<4; i++) // [0,1 위치에서 4개의 방향을 검토하여 나아갈 방향 선택
            {
                int a=cur.a+dx[i], b=cur.b+dy[i];
                 // int dx[4]={1,0,-1,0}, dy[4]={0,1,0,-1};
                 // a=cur.a+1, b=cur.b+0  /a,b=[0,1] --> [1,1]

                if(safe(a,b) && !visited[a][b] && M[a][b]=='.')
                {
                    visited[a][b]=visited[cur.a][cur.b]+1;
                    Q.push((VERTEX){a,b});
                }
            }
    }

    return visited[Ga][Gb];

}

int main()
{
    input();
    printf("%d\n", solve());
}
