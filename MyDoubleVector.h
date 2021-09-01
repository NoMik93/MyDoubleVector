#ifndef MYDOUBLEVECTOR_H //20137126048 ±èÀç¿ø
#define MYDOUBLEVECTOR_H

class MyDoubleVector
{
public:
	MyDoubleVector();
	MyDoubleVector(const MyDoubleVector& v);
	~MyDoubleVector();
	MyDoubleVector& operator = (const MyDoubleVector& v);
	MyDoubleVector& operator += (MyDoubleVector& v);
	double& operator [] (size_t index);
	MyDoubleVector& operator + (MyDoubleVector& v);
	MyDoubleVector& operator - (MyDoubleVector& v);
	MyDoubleVector& operator * (MyDoubleVector& v);
	MyDoubleVector& operator - ();
	bool operator == (MyDoubleVector& v);
	void operator () (double& operand);
	void pop_back();
	void push_back(double x);
	size_t capacity() const;
	size_t size() const;
	void reserve(size_t n);
	bool empty() const;
	void clear();
private:
	double *data;
	size_t used;
	size_t capa;
};

#endif // !MYDOUBLEVECTOR_H
#pragma once
