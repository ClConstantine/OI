#include<iostream>
#include<cstring>
using namespace std;
int shu[10];
void Vs(int a){
    if(a<10) shu[a]++;
    else {
        shu[a%10]++;
        Vs(a/10);
    }
}
int main()
{
    int a,b,c,i,j,p;
    for(i=1;i<10;i++){
        for(j=1;j<10;j++){
            for(p=1;p<10;p++){
                memset(shu,0,sizeof(shu));
                a=100*i+10*j+p;
                b=2*a;
                c=3*a;
                Vs(a);
                Vs(b);
                Vs(c);
                if(shu[1]==1&&shu[2]==1&&shu[3]==1&&shu[4]==1&&shu[5]==1&&shu[6]==1&&shu[7]==1&&shu[8]==1&&shu[9]==1)
                    cout<<a<<" "<<b<<" "<<c<<endl;
            }
        }
    }
    return 0;
}
