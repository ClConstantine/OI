#include <iostream>
#include <cstdio>
#include <cstring>
using std::cin;using std::cout;using std::endl;using std::cerr;
char art[1000010],ch[15];
int next[20],first=-1,ans;
bool bo=0;
int main(){
    std::ios::sync_with_stdio(false);
    cin.tie(0);
    cin.getline(ch+1,11);
    cin.getline(art+1,1000001);
    int j=0,len1=strlen(ch+1),len2=strlen(art+1);
    for(int i=1;i<=len1;i++){
        if(ch[i]<'a')ch[i]=char(ch[i]+32);
    }
//    cerr<<ch+1<<endl<<art+1;
    for(int i=1;i<=len2;i++){
        if(art[i]<'a'&&art[i]!=32) art[i]=char(art[i]+32); 
    }
    for(int i=2;i<=len1;i++){
        while(j&&ch[i]!=ch[j+1]) j=next[j];
        if(ch[i]==ch[j+1]) j++;
        next[i]=j;
    }
    j=0;
    /*for(int i=1;i<=len1;i++){
    	cerr<<next[i];
	}*/
    for(int i=1;i<=len2;i++){
		while(j&&ch[j+1]!=art[i]){
            j=next[j];
        }
        if(ch[j+1]==art[i]) j++;
        if(j==len1) {
            if((i-j==0&&art[i+1]==' ')||(art[i-j]==' '&&art[i+1]==' ')||(art[i-j]==' '&&i==len2)){
                ans++;
                if(!bo) {
                    first=i-j;
                    bo=1;
                }
            }
            j=next[j];
        }
    }
    if(bo) cout<<ans<<" "<<first;
    else cout<<-1;
    return 0; 
}
