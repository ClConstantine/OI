#include<cstdio>
#include<cstring>
char s[5010];
int T,L,x,y;
int main()
{
	freopen("robot.in","r",stdin);
	freopen("robot.out","w",stdout);
	scanf("%s%d",s,&T);
	L=strlen(s);
	for(int i=0;i<L;i++){
		switch (s[i])
		{
			case 'E': x++;break;
			case 'S': y--;break;
			case 'W': x--;break;
			case 'N': y++;break;
		}
	}
	x=x*(T/L);
	y=y*(T/L);
	for(int i=0;i<T%L;i++)
		switch (s[i])
		{
			case 'E': x++;break;
			case 'S': y--;break;
			case 'W': x--;break;
			case 'N': y++;break;
		}
	printf("%d %d",x,y);
	return 0;
}
