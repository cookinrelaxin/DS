#include <iostream>
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

void insertion_sort(int a[], int N) {
	for (int i = 0; i < N; i ++) {
	}
}

int main() {
	
	int a[100];
	for (int i = 0; i < 100; i ++) {
		a[i] = rand()%100;
	}
	print_array(a,100);
	cout<<"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"<<endl;
	bubble_sort(a,100);
	print_array(a,100);
	return 0;
}
