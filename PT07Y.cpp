#include<iostream>
#include<vector>
#include<string.h>
using namespace std;
//union by rank or path compression
typedef vector< pair<int,int> > vi;
int find(vi &a,int target){
	//cout<<target<<" \n";
	if(a[target].first!=target)
		a[target].first=find(a,a[target].first);
	return a[target].first;
		
	}
	
void uniona(vi &a,int tar1,int tar2){
		if(a[tar1].second<a[tar2].second)
			a[tar1].first=tar2;
		else if(a[tar1].second>a[tar2].second)
				a[tar2].first=tar1;
		else{
			a[tar2].first=tar1;
			a[tar1].second++;
		}
		
	}
int main(){
	int v,e;
	cin>>v>>e;
	vi lst, parank(v);
	for(int i=0;i<v;++i){
		parank[i].first=i;
		parank[i].second=1;
	}
	bool flag=false;
	
	for(int i=0;i<e;++i){
		
		int a,b;
		cin>>a>>b;
		lst.push_back(make_pair(a,b));
		
		
	}
	
	for(int i=0;i<e;++i){
		int p1=find(parank,lst[i].first-1);
		int p2=find(parank,lst[i].second-1);
		
		if(p1==p2){
			flag=true;
			break;
		}
		uniona(parank,p1,p2);
		
	}
	if(flag)
		cout<<"NO\n";
	else
		cout<<"YES\n";
	}
