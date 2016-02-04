#include <limits>
#include <climits>
#include <vector>
#include <iostream>
using namespace std;

void print_array(int A[], int N) {
	for(int i=0;i<N;i++) cout<<A[i]<<" ";
	cout<<endl;
}

int numberOfSolutions(int total, int coins[], int num_coins) {
	int **temp = new int *[num_coins+1];
	for (int i = 0; i < num_coins+1; i++)
		temp[i] = new int[total+1];
	for (int i = 0; i < num_coins; i++ )
		temp[i][0] = 1;
	for (int i = 1; i <= num_coins; i++) {
		for (int j = 1; j <= total; j++) {
			if (coins[i-1] > j)
				temp[i][j] = temp[i-1][j];
			else
				temp[i][j] = temp[i][j-coins[i-1]] + temp[i-1][j];
		}
	}
	for (int i = 0; i < num_coins+1; i++)
		delete [] temp[i];
	delete [] temp;
	return temp[num_coins][total];
}

unsigned long long int make_change(int n, vector<int> M) {
	int num_coins = M.size();
	vector<vector<unsigned long long int>> S (num_coins+1,vector<unsigned long long int> (n+1));
	for (int i=1; i <= num_coins; i++) {
		for (int a=0; a <= n; a++) {
			int m = M[i-1];
			if (a == 0)
				S[i][a] = 1;
			else if (a >= m)
				S[i][a] = S[i-1][a] + S[i][a-m];
			else
				S[i][a] = S[i-1][a];
		}
	}
	return S[num_coins][n];
}

string vec_to_string(vector<int> vec) {
	string s;
	for (int &x : vec)
		s += to_string(x) + " ";
	return s;
}
		
int main() {
	int n = 250;
	vector<int> M = {41,34,46,9,37,32,42,21,7,13,1,24,3,43,2,23,8,45,19,30,29,18,35,11};
	printf("# of ways to make change for %d with %s: %llu\n", n,vec_to_string(M).data(), make_change(n,M));
	return 0;
}
