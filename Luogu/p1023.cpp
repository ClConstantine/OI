#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>

using std::cin;using std::cout;using std::cerr;using std::endl;

int accept,price,num,last,di;
int can[100001];

int main()
{

    cin.tie(0);
	std::ios::sync_with_stdio(false);

    cin>>accept;

    cin>>price>>num;
    can[price]=num;
    di=last=price;

    while(cin>>price>>num&&price!=-1&&num!=-1){
        can[price]=num;
        if(price-last>1){
            int cha=(can[last]-can[price])/(price-last);
            for(int i=last+1;i<price;i++){
                can[i]=can[i-1]-cha;
            }
        }
        last=price;
    }
    int cha;
    cin>>cha;
    for(int i=last+1;can[i-1]-cha>0;i++){
        can[i]=can[i-1]-cha;
    }
    int i;
    for(i=0;i<=100000;i++){
        if((accept-di+i)*can[accept]>=(accept+1-di+i)*can[accept+1]&&(accept-di+i)*can[accept]>=(accept-1-di+i)*can[accept-1])
        {
            cout<<i;
            return 0;
        }
        else if(accept-di-i<=0) continue;
        else if((accept-di-i)*can[accept]>=(accept+1-di-i)*can[accept+1]&&(accept-di-i)*can[accept]>=(accept-1-di-i)*can[accept-1]){
            cout<<'-'<<i;
            return 0;
        }
    }
    cout<<"NO SOLUTION";
    return 0;
}
