#include<iostream>
#include<cstdio>
#include<set>
using namespace std;
int a[110];
set<int> can;
int main()
{
    int n;
    int ans=0;
    cin>>n;
    int temp;
    for(int i=0;i<n;i++){
        cin>>temp;
        can.insert(temp);
    }
    int In=can.size();
    int i=0;
    for(set<int>::iterator it=can.begin();it!=can.end();it++){
        a[i++]=*it;
    }
    for(int i=0;i<In;i++){
        for(int j=i+1;j<In;j++){
            if(can.find(a[i]+a[j])!=can.end()){
                ans++;
                can.erase(a[i]+a[j]);
            }
        }
    }
    cout<<ans;
    return 0;
}
