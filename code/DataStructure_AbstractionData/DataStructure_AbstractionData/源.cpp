#include<stdio.h>

typedef struct {
	float realpart;
	float imagpart;
}Complex;

void assign(Complex a, float real, float image);
void add(Complex a, Complex A, Complex B);

void assign(Complex A, float real, float image) {
	A.realpart = real;
	A.imagpart = image;
};

void add(Complex c, Complex A, Complex B) {
	c.realpart = A.realpart + B.realpart;
	c.imagpart = A.imagpart + B.imagpart;
}

//void main() {
//	Complex A, B, C;
//	assign(A, 2.88, 4.99);
//	assign(B, 2.88, 4.99);
//	add(C,A,B);
//	printf("imagpart of c",C.imagpart);
//	printf("realpart of c", C.realpart);
//}