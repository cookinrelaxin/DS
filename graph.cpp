#include <iostream>
#include <map>
#include <set>
#include <stack>
#include <string>

using namespace std;

void DFS_recursive(set<char> &V, char N, map<char,set<char>> &A) {
	for (const char &n : A[N]) {
		if (V.find(n) == V.end()) {
			cout<<n<<endl;
			V.insert(n);
			DFS_recursive(V,n,A);
		}
	}
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

int main() {
	map<char,set<char>> A;
	A['A'].insert('B');
	A['A'].insert('D');
	A['A'].insert('G');

	A['B'].insert('A');
	A['B'].insert('E');
	A['B'].insert('F');

	A['C'].insert('F');
	A['C'].insert('H');

	A['D'].insert('A');
	A['D'].insert('F');

	A['E'].insert('B');
	A['E'].insert('G');

	A['F'].insert('B');
	A['F'].insert('C');
	A['F'].insert('D');

	A['G'].insert('A');
	A['G'].insert('E');

	A['H'].insert('C');

	set<char> V;
	V.insert('A');
	//DFS_recursive(V,'A',A);
	DFS_iterative(A,'A');
	return 0;
}
