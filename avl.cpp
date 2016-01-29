#include <iostream>
using namespace std;

struct node {
	int key;
	unsigned char height;
	node *left;
	node *right;
	node(int k) {key = k; left = right = 0; height = 1;}
};

unsigned char height(node *p) {
	return p ? p->height : 0;
}

int bfactor(node *p) {
	return height(p->right) - height(p->left);
}

void fixheight(node *p) {
	unsigned char hl = height(p->left);
	unsigned char hr = height(p->right);
	p->height = (hl>hr ? hl : hr) + 1;
}

node* rotateright(node* p) {
	node *q = p->left;
	p->left = q->right;
	q->right = p;
	fixheight(p);
	fixheight(q);
	return q;
}

node* rotateleft(node* q) {
	node *p = q->right;
	q->right = p->left;
	p->left = q;
	fixheight(q);
	fixheight(p);
	return p;
}

node* balance(node *p) {
	fixheight(p);
	if (bfactor(p) == 2) {
		if (bfactor(p->right) < 0)
			p->right = rotateright(p->right);
		return rotateleft(p);
	}
	else if (bfactor(p) == -2) {
		if (bfactor(p->left) > 0)
			p->left = rotateleft(p->left);
		return rotateright(p);
	}
	return p;
}

node* insert(node *p, int k) {
	if (!p) return new node(k);
	else if (k < p->key)
		p->left = insert(p->left,k);
	else
		p-right = insert(p->right,k);
	return balance(p);
}

int main() {
	return 0;
}
