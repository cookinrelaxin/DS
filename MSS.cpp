#include <limits>
#include <climits>
#include <iostream>
using namespace std;

void print_array(int A[], int N) {
	for(int i=0;i<N;i++) cout<<A[i]<<" ";
	cout<<endl;
}

int MSS_brute_force(int a[], int N) {
	int max_sum = numeric_limits<int>::min();
	for (int size = 1; size <= N; size++) {
		for (int i = 0; i+size-1 < N; i++) {
			int sum = 0;
			for (int j = i; j < size; j++)
				sum+=a[j];
			max_sum = max(sum,max_sum);
		}
	}
	return max_sum;
}

int MSS_less_brute(int a[], int N) {
	int max_sum=numeric_limits<int>::min();
	for (int i = 0; i < N; i++) {
		int sum = 0;
		for (int size = 1; i+size <= N; size++) {
			sum += a[i+size-1];
			max_sum = max(sum,max_sum);
		}
	}
	return max_sum;
}

int MSS_DC(int a[],int N) {
	if (N==1) return a[0];
	int m = N/2;
	int left_MSS = MSS_DC(a,m);
	int right_MSS = MSS_DC(a+m,N-m);
	int left_sum = INT_MIN, right_sum = INT_MIN, sum = 0;
	for (int i = m-1; i >= 0; i--) {
		sum += a[i];
		left_sum = max(left_sum,sum);
	}
	sum = 0;
	for (int i = m; i < N; i++) {
		sum += a[i];
		right_sum = max(right_sum,sum);
	}
	return max(max(left_MSS,right_MSS),left_sum+right_sum);
}
int main() {
	int N = 1000;
	int *A = new int[N]; 
	for (int i = 0; i < N; i ++) 
		A[i] = rand()%N - N/2;
	print_array(A,N);
	cout<<"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"<<endl;
	clock_t start,elapsed;
	start = clock();
	//cout<<"MSS: "<<MSS_less_brute(A,N)<<endl;
	cout<<"MSS: "<<MSS_DC(A,N)<<endl;
	elapsed = clock() - start;
	printf("time elapsed: %ldms\n",elapsed);
	return 0;
}
