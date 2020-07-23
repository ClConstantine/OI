#include <iostream>
#include <cstdio>
#include <cmath>
#include <string>
#include <sstream>

using std::cin;using std::cout;using std::endl;using std::cerr;using std::string;

const int mmax = 100;

std::pair< char , int > st[mmax + 10];

int T;
int n,tot;
string O,opt,c,x,y;

int getn(string s){
    int qaq = 0;
    int len = s.size();
    for(int i = 0;i < len;++i){
        (qaq *= 10) += s[i] - '0';
    }
    //cout<<qaq<<endl;
    return qaq;
}

int gett(string s){
    if(s == "O(1)") return 0;
    int pos = s.find('^');
    //cout<<"pos:"<<pos<<endl;
    string sub = s.substr(pos + 1,s.size() - pos - 2);
    //<<"gett:"<<sub<<endl;
    return getn(sub);
}

bool charih(char c){
    for(int i = 1;i <= tot;++i){
        if(c == st[i].first){
            return 1;
        }
    }
    return 0;
}

int getfor(string x,string y){
    if(x == "n"){
        if(y == "n") return 0;
        return -1;
    }
    
    if(y == "n") return 1;
    
    int a = getn(x),b = getn(y);
    
    if(a>b) return -1;
    return 0;
}

int main(){

    cin>>T;
    
    while(T--){
        string str;
        cin>>n>>O;
        //cout<<"n:"<<n<<" "<<"O:"<<O<<endl;
        int om = gett(O);
        
        //cout<<om<<endl;
        getchar();
        //cout<<temp1<<endl;
        //cout<<str;
        tot = 0;
        int maxn = 0;
        bool f=0;

        while(n--){
            getline(cin,str);

            //cout<<str<<endl;

            if(f) continue;
            if(str[0] == 'E'){
                if(tot) tot--;
                else f = 1;
                //cout<<"1f "<<f<<endl;
            }
            else{
                std::stringstream sin(str);
                
                sin>>opt>>c>>x>>y;

                //cout<<opt<<" "<<c<<" "<<x<<" "<<y<<endl;
                if(charih(c[0])){
                    f = 1;
                    //cout<<"2f "<<f<<" "<<n<<' '<<c[0]<<endl;
                }
                
                else{
                    int tm = getfor(x,y);
                    if(tm >= 0 && st[tot].second >= 0) tm += st[tot].second;
                    else tm = -1;
                    st[++ tot] = std::make_pair(c[0],tm);
                    maxn = std::max(maxn,tm);
                }
            }
        }
        if(tot) f = 1;
        if(f) cout<<"ERR"<<endl;
        else if(maxn == om) cout<<"Yes"<<endl;
        else cout<<"No"<<endl;
        //cout<<str<<endl;
    }

    return 0;
}