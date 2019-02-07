#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
char T1[1000010],T2[1000010];
int next[1000010];
int main (){
    scanf("%s%s",T1+1,T2+1);
    int l1=strlen(T1+1),l2=strlen(T2+1);
    next[0]=next[1]=0;
    int j=0;
    for(int i=2;i<=l2;i++){
        while(j&&T2[i]!=T2[j+1]) j=next[j];
        if(T2[j+1]==T2[i]) j++;
        next[i]=j;
    }
    j=0;
    for(int i=1;i<=l1;i++){
    	while(j&&T1[i]!=T2[j+1]) j=next[j];
    	if(T1[i]==T2[j+1]) j++;
    	if(j==l2){
    		cout<<i-l2+1<<endl;
    		j=next[j];
        }
    }
    for(int i=1;i<=l2;i++){
        cout<<next[i]<<" ";
    }
    return 0;
}
