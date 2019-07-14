#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>

using std::cin;using std::cout;using std::cerr;using std::endl;
struct game{
    int scoreA,scoreB;
}can[500000];
int m,n;
int main()
{

    cin.tie(0);
    std::ios::sync_with_stdio(false);

    char c;
    int i=1;
    bool b=1;
    while(cin>>c&&c!='E'){
        b=0;
        if(c=='\n') continue;

        if(c=='W'){
            m++;
            can[i].scoreA++;
        }
        else{
            n++;
            can[i].scoreB++;
        }
        if((m>=11||n>=11)&&abs(m-n)>=2){
            cout<<m<<':'<<n<<endl;
            m=n=0;
        }
        if(abs(can[i].scoreA-can[i].scoreB)>=2&&(can[i].scoreA>=21||can[i].scoreB>=21)){
            i++;
        }
    }

    cout<<m<<':'<<n<<endl;
    
    cout<<endl;

    for(int j=1;j<=i;j++){
        cout<<can[j].scoreA<<':'<<can[j].scoreB<<endl;
    }
    return 0;
}
