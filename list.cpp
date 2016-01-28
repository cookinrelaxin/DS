#include <iostream>
#include <cassert>
using namespace std;

struct Node {
	int data;
	Node *next;
};

Node* insert(Node *head, int data, int position);
Node* append(Node *head, int data);
Node* remove(Node *head, int position);
Node* reverse(Node *head);
bool compare(Node *headA, Node *headB);
bool empty(Node *head);
Node* from_array(Node *head);
Node* merge(Node *head);
Node* dedupe(Node *head);
Node* merge_point(Node *headA, Node *headB);
int node_value(Node *head, int position);
int detect_cycle(Node *head);
void print_list(Node *head);
void print_reverse_list(Node *head);
int size(Node *head);

void print_list(Node *head) {
	while (head) {
		cout<<head->data<<" --> ";
		head = head->next;
	}
	cout<<"NULL"<<endl;
	return;
}

void test_passed(string test_name) {
	cout<<"\033[1;32m"<<test_name<<" passed"<<endl;
	cout<<"\033[0;30m";
}

void test_failed(string test_name) {
	cout<<"\033[1;31m"<<test_name<<" failed"<<endl;
	cout<<"\033[0;30m";
}

Node* from_array(int *a, int N) {
	if (N == 1) {
		return new Node{*a,NULL};
	}
	return new Node{*a,from_array(++a,--N)};
}

bool test_from_array() {
	int arr0[3] = {5,6,7};
	Node* n0 = from_array(arr0,3);
	assert(n0->data == 5);
	assert(n0->next->data == 6);
	assert(n0->next->next->data == 7);
	test_passed("from_array");
	return true;
}

Node* insert(Node *head, int data, int position) {
	if (!head)
		return new Node{data,NULL};
	if (!position) {
		return new Node{data,head};
	}
	head->next = insert(head->next, data, --position);
	return head;
}

bool test_insert() {
	int arr0[3] = {1,2,3};
	Node* n0 = from_array(arr0,3);
	assert(n0->data == 1);

	Node* n1 = insert(n0,7,0);
	assert(n1->data == 7);

	int arr1[2] = {5,6};
	Node *n2 = from_array(arr1,2);
	assert(n2->data == 5);

	Node *n3 = insert(n2, 7, 2);
	assert(n3->data == 5);
	assert(n3->next->data == 6);
	assert(n3->next->next->data == 7);

	int arr2[3] = {5,6,8};
	Node *n4 = from_array(arr2,3);
	assert(n4->data == 5);

	Node *n5 = insert(n4, 7, 2);
	assert(n5->data == 5);
	assert(n5->next->data == 6);
	assert(n5->next->next->data == 7);
	assert(n5->next->next->next->data == 8);

	test_passed("test_insert");
	return true;
}

Node* append(Node *head, int data) {
	if (!head) return new Node{data,NULL};
	head->next = append(head->next,data);
	return head;
}

bool test_append() {
	int arr0[1] = {1};
	Node* n0 = from_array(arr0,1);
	assert(n0->data == 1);

	Node *n1 = append(n0,2);
	assert(n0->data == 1);
	assert(n0->next->data == 2);

	Node *n2 = append(NULL,2);
	assert(n2->data == 2);

	test_passed("test_append");
	return true;
}

Node* remove(Node *head, int position) {
	return head;
}

bool test_remove() {
	int arr0[1] = {1};
	Node *n0 = from_array(arr0,1);
	assert(n0->data == 1);

	Node *n1 = remove(n0,0);
	assert(n1 == NULL);

	int arr1[3] = {1,2,3};
	Node *n2 = from_array(arr1,3);
	assert(n2->next->data == 2);

	Node *n3 = remove(n2,1);
	assert(n3->next == 3);

	return true;
}

int main() {
	test_from_array();
	test_insert();
	test_append();
	test_remove();
	return 0;
}
