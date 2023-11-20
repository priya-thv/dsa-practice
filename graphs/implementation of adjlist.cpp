#include <bits//stdc++.h>
using namespace std;

class graph{
	public:
	
	unordered_map<int,list<int>>adj;
	
	void adjedge(int u,int v,bool direction){
		//direction=0 undirected
		//direction=1 directed
		
		//create edge tw them
		
		adj[u].push_back(v);
		
		if(direction==0){
			adj[v].push_back(u);
		}
	}
	
	void print(){
		for(auto i:adj){
			cout<<i.first<<"->";
			for(auto j:i.second){
				cout<<j<<",";
			}
			cout<<endl;
		}
	}
};

int main() {
	int n;
	cin>>n;
	int m;
	cin>>m;
	graph g;
	for(int i=0;i<n;i++){
		int u,v;
		cin>>u>>v;
		g.adjedge(u,v,0);
	}
	
	g.print();
	return 0;
}
