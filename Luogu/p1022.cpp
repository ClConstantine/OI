#include <iostream>
#include <cstdio>

using std::cin;using std::cout;using std::endl;
int l,a;
char c,m;
double anss=0,ansx=0,ans=0;

int main(){
    l=1,a=1;
    while(cin>>c&&c!='\n'){

        if(c=='=') {
            if(a==1){
                    anss+=ans;
                    ans=0;
                }
            else {
                    anss-=ans;
                    ans=0;
                }
            l=-1;a=-1;
            }
        
        if(l==1){
            if(c=='+'||c=='-') {
                if(a==1){
                    anss+=ans;
                    ans=0;
                }
                else {
                    anss-=ans;
                    ans=0;
                }
                a=(c=='+'?1:-1);
            }
            else {
                if(c<='9'&&c>='0'){
                    (ans*=10)+=c-'0';
                }
                else if(c>='a'&&c<='z'){
                    m=c;
                    if(a==1){
                        if(ans==0){
                            ansx++;
                        }
                        else ansx+=ans;
                        ans=0;
                    }
                    else {
                        if(ans==0){
                            ansx--;
                        }
                        else ansx-=ans;
                        ans=0;
                    }
                }
            }
        }
        else if(l==-1){
            if(c=='+'||c=='-') {
                if(a==1){
                    anss+=ans;
                    ans=0;
                }
                else {
                    anss-=ans;
                    ans=0;
                }
                a=(c=='+'?-1:1);
            }
            else {
                if(c<='9'&&c>='0'){
                    (ans*=10)+=c-'0';
                }
                else if(c>='a'&&c<='z'){
                    m=c;
                    if(a==1){
                        if(ans==0){
                            ansx++;
                        }
                        else ansx+=ans;
                        ans=0;
                    }
                    else {
                        if(ans==0){
                            ansx--;
                        }
                        else ansx-=ans;
                        ans=0;
                    }
                }
            }
        }
    }
    if(a==1){
        anss+=ans;
        ans=0;
    }
    else {
        anss-=ans;
        ans=0;
    }
    if(anss==0) printf("%c=%.3f",m,0);
    else printf("%c=%.3f",m,-anss/ansx);
    return 0;
}
