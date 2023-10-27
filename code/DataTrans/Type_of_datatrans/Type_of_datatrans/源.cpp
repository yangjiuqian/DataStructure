#include<stdio.h>
#include<string.h>
#include<iostream>
using namespace std;

void ValueSwap(float m, float n) {
	float temp;
	temp = m;
	m = n;
	n = temp;
};

void AdddressSwap(float *m, float *n) {
	float temp;
	temp = *m;
	*m = *n;
	*n = temp;
};

void Swap(float* m, float* n) {
	float *temp;
	temp = m;
	m = n;
	n = temp;
};

void Noneffect() {
	float a, b;
	cin >> a >> b;
	ValueSwap(a, b);
	cout << a << endl << b << endl;
};

void Noneffect2() {
	float a, b, * p1, * p2;
	cin >> a >> b;
	p1 = &a;
	p2 = &b;
	Swap(p1, p2);
	cout << a << endl << b << endl;
}

void Effect() {
	float a, b, * p1, * p2;
	cin >> a >> b;
	p1 = &a;
	p2 = &b;
	AdddressSwap(p1, p2);
	cout << a << endl << b << endl;
};


void main() {
	Noneffect2();
}