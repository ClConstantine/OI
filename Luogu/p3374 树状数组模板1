#include <iostream>
using std::cin;using std::cerr;using std::cout;using std::endl;
struct BIT{
    int C[500010];
    int N;
    int lowbitF(int x){
        return x&(-x);
    }
    void addF(int x,int y){
        for(int i=y;i<=N;i+=lowbitF(i)) 
            C[i]+=x;
    }
    long long sumF(int x){
        long long temp=0;
        for(int i=x;i>0;i-=lowbitF(i)){
            temp+=C[i];
        }
        return temp;
    }
}A;
int main(){
    std::ios::sync_with_stdio(false);
    cin.tie(0);
    int T;
    cin>>A.N>>T;
    for(int i=1;i<=A.N;i++){
        int temp;
        cin>>temp;
        A.addF(temp,i);
    }
    while (T--){
        int temp;
        cin>>temp;
        if(temp==1){
            int x,y;
            cin>>x>>y;
            A.addF(y,x);
        }
        else{
            int x,y;
            cin>>x>>y;
            cout<<A.sumF(y)-A.sumF(x-1)<<endl;
        }
    }
    return 0;
}
