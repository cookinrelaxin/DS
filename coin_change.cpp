#include <limits>
#include <climits>
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
		
int main() {
	int total = 5;
	int coins[3] = {1,2,3};
	cout<<numberOfSolutions(total,coins,3)<<endl;
	return 0;
}

