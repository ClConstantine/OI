#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;

vector<int> s;

int main()
{
    int n,t;
    cin>>n>>t;
    s.push_back(t);
    cout<<t<<endl;
    
    for(int i=2;i<=n;i++){
        cin>>t;
        s.insert(lower_bound(s.begin(),s.end(),t),t);
        if(i&1) cout<<s[i/2]<<endl;
    }
    
    return 0;
}
