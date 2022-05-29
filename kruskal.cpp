#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int fathers[100];

int find(int x){
	if(fathers[x] == x){
		return x;
	}
	return find(fathers[x]);
}

void unite(int x, int y){
	int fx = find(x);
	int fy = find(y);
	fathers[fx] = fy;
}

int main(){
	for(int i=0;i<100;i++){
		fathers[i]=i;
	}
	int number_of_nodes,number_of_edges;
	int a,b,weight;

	vector < pair < int, pair < int, int > > > edges;
	cin>>number_of_nodes>>number_of_edges;

	for(int i=0; i<number_of_edges; i++){
		cin>>a>>b>>weight;
		edges.push_back(make_pair(weight,make_pair(a,b)));
	}

	cout<<endl;

	int mst_weight = 0, mst_edges = 0;
	int	mst_next_index = 0;

	sort(edges.begin(),edges.end());

	while(( mst_edges < number_of_nodes-1) || (mst_next_index < number_of_edges)){

		a = edges[mst_next_index].second.first;
		b = edges[mst_next_index].second.second;
		weight = edges[mst_next_index].first;

		if(find(a) != find(b)) {
			unite(a,b);
			mst_weight += weight;
			cout<<a<<" "<<b<<" "<<weight<<endl;
			mst_edges++;
		}
		mst_next_index++;
	}
	cout<<"\nWeight of the MST is "<<mst_weight<<endl;
}

/*	The example's input:
7 9
1 2 4
7 2 2
6 2 3
6 5 1
5 3 20
4 3 6
1 4 7
2 5 2
2 3 1

/*	The example's output:
2 3 1
6 5 1
2 5 2
7 2 2
1 2 4
4 3 6

Weight of the MST is 16
*/

