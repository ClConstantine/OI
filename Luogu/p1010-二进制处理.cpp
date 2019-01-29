#include <iostream>
#include <cstdio>

using std::cin;using std::cout;using std::endl;using std::cerr;

int a[100]={1,2,4,8,16,32,64,128,256,512,1024,2048,4096,8192,16384};
void dfs(int x,bool f){
	if(x==0) {
		return;
	}
	for(int i=14;i>=0;i--){
		if(a[i]==x){
			if(f==0) f=1;
			else cout<<'+';
			
			if(a[i]==2){
				cout<<2;
				x-=2;
			}
			else if(a[i]==1){
				cout<<"2(0)";
				x--;
			}
			else {
				cout<<"2(";
				dfs(i,0);
				cout<<")";
				x-=a[i];
			}
		} 
		else if(a[i]<x){
			if(f==0) f=1;
			else cout<<'+';
		
			if(a[i]==2){
				cout<<2;
				x-=2;
			}
			
			else {
				cout<<"2(";
				dfs(i,0);
				cout<<')';
				x-=a[i];
			}
		}
	}
	return ; 
}
int main(){
	int n;
	cin>>n;
	dfs(n,0);
	return 0;
}  
