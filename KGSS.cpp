//kgss
#include<iostream>
#include<algorithm>
#include<vector>
#define mp make_pair
using namespace std;
typedef pair<int,int> pi;
typedef vector<pi> vpi;
pi merger(pi & a,pi &b){


int aa[4];
aa[0]=a.first;
aa[1]=a.second;
aa[2]=b.first;
aa[3]=b.second;
sort(aa,aa+4);

return mp(aa[3],aa[2]);

}

void builder(int node,int l,int r,int *a,vpi &tree){

    if(l==r){
        tree[node]= mp(a[l],0);

        return;
    }
    builder(2*node,l,(l+r)/2,a,tree);
    builder(2*node+1,(l+r)/2 +1,r,a,tree);
    tree[node]=merger(tree[2*node +1],tree[2*node ]);

}
void update(int node,int l,int r,int value,int point,vpi &tree){
    if(l==r){
        tree[node]=mp(value,0);
        return;

    }
        int p =(l+r)/2;
        if(point<=p)
            update(2*node ,l,p,value,point,tree);
        else
            update(2*node +1,p+1,r,value,point ,tree);
        tree[node]=merger(tree[2*node +1],tree[2*node ]);

}
pi query(int node,int l,int r,int ql,int qr,vpi &tree){

    if(l>r || l>qr || r< ql)
        return mp(-8,-8);
    if(ql<=l && r<=qr)
        return tree[node];

    int p=(l+r)/2;
    //cout<<p<<endl;
    pi a=query(2*node ,l,p,ql,qr,tree);
    pi b=query(2*node +1,p+1,r,ql,qr,tree);
   // cout<<"hello"<<a.first<<" "<<a.second<<" "<<b.first<<" "<<b.second;
    return merger(a,b);

}
int main(){
int n;
cin>>n;
int a[n];
vpi tree(4*n);
for(int i=0;i<(4*n);i++){
    tree[i]=mp(0,0);
    //cout<<tree[i].first<<tree[i].second<<"  ";
}

for(int i=0;i<n;i++)
cin>>a[i];
builder(1,0,n-1,a,tree);
int q;
cin>>q;
while(q--){
    char a;int b,c;
    cin>>a>>b>>c;
    if(a=='Q'){

    pi q=query(1,0,n-1,b-1,c-1,tree);

        cout<<q.first+q.second<<"\n";
    }

    else if(a=='U')
        update(1,0,n-1,c,b-1,tree);



}




}
