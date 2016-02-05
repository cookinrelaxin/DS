#include <iostream>
#include <map>
#include <set>
#include <stack>
#include <queue>
#include <string>

using namespace std;

void DFS_recursive(map<char,set<char>> &adjacency_list, char initial_node) {
	set<char> visted;
	visted.insert(initial_node);
	cout<<initial_node<<endl;
	function<void (map<char,set<char>>&,set<char>&,char)> loop = [&loop](map<char,set<char>> &A, set<char> &V, char N) {
		for (const char &n : A[N]) {
			if (V.find(n) == V.end()) {
				V.insert(n);
				cout<<n<<endl;
				loop(A,V,n);
			}
		}
	};
	loop(adjacency_list,visted,initial_node);
}

void DFS_iterative(map<char,set<char>> &A, char v) {
	set<char> V;
	stack<char> S;
	S.push(v);
	while (!(S.empty())) {
		v = S.top();
		S.pop();
		if (V.find(v) == V.end()) {
			cout<<v<<endl;
			V.insert(v);
			for (const char &w : A[v]) {
				S.push(w);
			}
		}
	}
}

void BFS(map<char,set<char>> &A, char n) {
	queue<char> Q;
	set<char> V;
	Q.push(n);
	while(!(Q.empty())) {
		n = Q.front();
		Q.pop();
		if (V.find(n) == V.end()) {
			V.insert(n);
			cout<<n<<endl;
			for (const char &w : A[n])
				Q.push(w);
		}
	}
}

struct node {
	int id;
	int distance;
	bool visited;
	vector<int> neighbors;
};

void BFS_shortest_reach(map<int,node*> A, int n) {
	queue<int> Q;
	Q.push(n);
	A[n]->visited = true;
	A[n]->distance = 0;
	int initial_node = n;
	while (!Q.empty()) {
		n = Q.front();
		Q.pop();
		for (int &w : A[n]->neighbors) {
			if (!A[w]->visited) {
				A[w]->visited = true;
				A[w]->distance = A[n]->distance + 1;
				Q.push(w);
			}
		}
	}
	for (auto const &w : A)
		printf("node %d's distance from %d: %d\n",w.first,initial_node,w.second->distance);
}

int main() {
	// map<char,set<char>> A;
	// A['A'].insert('B');
	// A['A'].insert('D');
	// A['A'].insert('G');

	// A['B'].insert('A');
	// A['B'].insert('E');
	// A['B'].insert('F');

	// A['C'].insert('F');
	// A['C'].insert('H');

	// A['D'].insert('A');
	// A['D'].insert('F');

	// A['E'].insert('B');
	// A['E'].insert('G');

	// A['F'].insert('B');
	// A['F'].insert('C');
	// A['F'].insert('D');

	// A['G'].insert('A');
	// A['G'].insert('E');

	// A['H'].insert('C');

	//DFS_recursive(A,'A');
	//DFS_iterative(A,'A');
	//BFS(A,'A');

	// map<int,node*> A;
	// A[1] = new node{1,0,false,vector<int>()};
	// A[1]->neighbors.push_back(2);
	// A[1]->neighbors.push_back(4);
	// A[1]->neighbors.push_back(6);

	// A[2] = new node{2,0,false,vector<int>()};
	// A[2]->neighbors.push_back(1);
	// A[2]->neighbors.push_back(3);
	// A[2]->neighbors.push_back(5);

	// A[3] = new node{3,0,false,vector<int>()};
	// A[3]->neighbors.push_back(2);
	// A[3]->neighbors.push_back(4);

	// A[4] = new node{4,0,false,vector<int>()};
	// A[4]->neighbors.push_back(1);
	// A[4]->neighbors.push_back(3);
	// A[4]->neighbors.push_back(9);

	// A[5] = new node{5,0,false,vector<int>()};
	// A[5]->neighbors.push_back(2);
	// A[5]->neighbors.push_back(6);
	// A[5]->neighbors.push_back(7);

	// A[6] = new node{6,0,false,vector<int>()};
	// A[6]->neighbors.push_back(1);
	// A[6]->neighbors.push_back(5);
	// A[6]->neighbors.push_back(9);

	// A[7] = new node{7,0,false,vector<int>()};
	// A[7]->neighbors.push_back(5);
	// A[7]->neighbors.push_back(8);

	// A[8] = new node{8,0,false,vector<int>()};
	// A[8]->neighbors.push_back(7);

	// A[9] = new node{9,0,false,vector<int>()};
	// A[9]->neighbors.push_back(4);
	// A[9]->neighbors.push_back(6);
	// BFS_shortest_reach(A,1);

	id a = 5;

	return 0;
}
