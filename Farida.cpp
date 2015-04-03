#include<iostream>
using namespace std;
long long int max(long long int  a,long long int b){
return (a>b)?a:b;
}
int main(){
int t;
cin>>t;
for(int i=0;i<t;i++){
     long long int n;
    cin>>n;
    if(n==0){
        cout<<"Case "<<i+1<<": "<<"0\n";
        continue;
            }
        long long int a[n];
    for(int i=0;i<n;i++)
        cin>>a[i];
    long long int p[n];
    p[0]=a[0];
    p[1]=max(a[0],a[1]);
    for(int i=2;i<n;i++){
        p[i]=max(a[i]+p[i-2],p[i-1]);

    }

    cout<<"Case "<<i+1<<": "<<p[n-1]<<"\n";

}


}
