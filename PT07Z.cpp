#include<iostream>
#include<list>
using namespace std;
 int v,count=0;
 int cmaxx=-1,chosen;
void DFSUtil( bool*visited,int n,list <int>  *adj,int counts)
{

    visited[n] = true;
    counts++;
    //cout << n<< " ";


    list<int>::iterator i;
    for(i = adj[n].begin(); i != adj[n].end(); ++i)
        if(!visited[*i]){



            DFSUtil(visited,*i,adj,counts);

            }




             if(counts>cmaxx){
                chosen =n;
                cmaxx=counts;
                }

}

int main(){

    cin>>v;
    list<int> edar[v];

    for(int i=0;i<v-1;i++){
        int a,b;
        cin>>a>>b;

        edar[a-1].push_back(b-1);
        edar[b-1].push_back(a-1);

    }
    bool visited[v];
    for(int i = 0; i < v; i++)
        visited[i] = false;


    DFSUtil( visited,0,edar,0);

    for(int i = 0; i < v; i++)
        visited[i] = false;

    DFSUtil(visited,chosen,edar,0);

        cout<<cmaxx-1<<"\n";


}
