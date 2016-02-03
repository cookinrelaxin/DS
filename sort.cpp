#include <iostream>
#include <ctime>
using namespace std;

void print_array(int a[], int N) {
	for (int i = 0; i < N; i ++) {
		cout<<a[i]<<" ";
	}
	cout<<endl;
}

void selection_sort(int a[], int N) {
	for (int i = 0; i < N; i++) {
		int smallest = a[i];
		int smallest_index = i;
		for (int j = i; j < N; j++) {
			if (a[j] < smallest) {
				smallest = a[j];
				smallest_index = j;
			}
		}
		swap(a[i],a[smallest_index]);
	}
}

void bubble_sort(int a[], int N) {
	for (int i = 0; i < N; i ++) {
		for (int j = 0; j < N-1-i; j ++) {
			if (a[j] > a[j+1])
				swap(a[j],a[j+1]);
		}
	}
}

void insertion_sort(int a[], int N, bool (*predicate)(int v1, int v2)) {
	if (N == 1) return;
	for (int i = 1; i < N; i++) {
		for (int j = i; j >= 1; j--) {
			if (predicate(a[j],a[j-1]))
				swap(a[j],a[j-1]);
			else break;
		}
	}
}

void merge(int A[], int N, int a[], int a_n, int b[], int b_n) {
	int i = 0, j = 0, k = 0;
	while (i < a_n && j < b_n) {
		if (a[i] < b[j]) {
			A[k] = a[i];
			i++;
		}
		else {
			A[k] = b[j];
			j++;
		}
		k++;
	}
	while (i < a_n) {
		A[k] = a[i];
		i ++;
		k ++;
	}
	while (j < b_n) {
		A[k] = b[j];
		j ++;
		k ++;
	}
}

void merge_sort(int A[], int N) {
	if (N<2) return;
	int *a = new int[N/2];
	int *b = new int[N/2];
	int a_n = N/2;
	int b_n = (N%2 == 0) ? N/2 : N/2 + 1; 
	for (int i = 0; i < a_n; i ++) {
		a[i] = A[i];
	} 
	for (int i = 0; i < b_n; i ++) {
		b[i] = A[i+N/2];
	} 
	merge_sort(a,a_n);
	merge_sort(b,b_n);
	merge(A,N,a,a_n,b,b_n);
	delete a;
	delete b;
}

bool greater_than(int v1, int v2) {
	return v1>v2;
}
bool less_than(int v1, int v2) {
	return v1<v2;
}

int partition(int a[], int start, int end) {
	int pivot = a[end];
	int p_index = start;
	for (int i=start;i<end;i++)
		if (a[i]<pivot) {
			swap(a[i],a[p_index]);
			p_index++;
		}
	swap(a[p_index],a[end]);
	return p_index;
}
void quick_sort_helper(int a[], int start, int end){
	if (start<end) {
		int p_index = partition(a,start,end);
		quick_sort_helper(a,start,p_index-1);
		quick_sort_helper(a,p_index+1,end);
	}
}
void quick_sort(int a[], int N) {return quick_sort_helper(a,0,N-1);}

void counting_sort(int a[], int N) {
	int maximum = INT_MIN;
	for (int i = 0; i < N; i++)
		maximum = max(maximum,a[i]);
	int *b = new int[maximum+1]();
	for (int i = 0; i < N; i++)
		b[a[i]]++;
	int k = 0;
	for (int i = 0; i < maximum+1; i++) {
		int count = b[i];
		int start_index = k;
		while(k < start_index+count) {
			a[k] = i;
			k++;
		}
	}
	delete [] b;
}

int main() {
	
	int N = 1e8;
	int *a = new int[N];
	for (int i = 0; i < N; i ++) {
		a[i] = rand()%N;
 	}
	//print_array(a,N);
	cout<<"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"<<endl;
	clock_t start,elapsed;
	start = clock();
	quick_sort(a,N);
	//counting_sort(a,N);
	elapsed = clock() - start;
	//print_array(a,N);
	printf("time elapsed: %ldms\n",elapsed);
	return 0;
}
