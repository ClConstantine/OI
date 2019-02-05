#include<cstdio>
using namespace std;
char a[2010][2010];
int main()
{
    int l,q,x,y,min0,ans,m,n;
    scanf("%d%d",&l,&q);
    for(int i=0;i<l;i++){
        scanf("%s",a[i]);
    }
    for(int i=0;i<q;i++){
        scanf("%d%d",&x,&y);
        n=m=x-1;
        ans=min0=1;
        while(++m<l&&--n>=0){
            if(a[m][y-1]==a[n][y-1]) ans+=2;
            else break;
        }
        n=m=y-1;
        while(++m<l&&--n>=0){
            if(a[x-1][m]==a[x-1][n]) min0+=2;
            else break;
        }
        printf("%d\n",ans>min0?ans:min0);
    }
    return 0;
}
