#include <cstdlib> //20137126048 김재원
#include <iostream>
#include "MyDoubleVector.h"
using namespace std;

MyDoubleVector::MyDoubleVector() : used(0), capa(10) { //precondition: 없음
	data = new double[capa];
} //postcondition: 10의 공간을 가진 벡터 생성

MyDoubleVector::MyDoubleVector(const MyDoubleVector& v) : used(v.size()), capa(v.capacity()) { //precondition: v의 존재
	data = new double[capa];
	for (size_t i = 0; i < size(); i++)
		data[i] = v.data[i];
} //postcondition: v와 같은 크기, 같은 값들을 가진 벡터 생성

MyDoubleVector::~MyDoubleVector() { //precondition: 벡터의 존재
	delete [] data;
} //postcondition: 동적 할당 해제

MyDoubleVector& MyDoubleVector::operator = (const MyDoubleVector& v) { //precondition: 두 벡터의 존재
	delete [] data;
	data = new double[v.capacity()];
	for (size_t i = 0; i < v.size(); i++)
		data[i] = v.data[i];
	used = v.size();
	capa = v.capacity();
	return *this;
} //postcondition: LHS를 RHS와 같게 만들고 LHS를 반환

MyDoubleVector& MyDoubleVector::operator += (MyDoubleVector& v) { //precondition: 두 벡터의 존재
	reserve(v.size());
	for (size_t i = 0; i < v.size(); i++)
		data[i + size()] = v.data[i];
	used = size() + v.size();
	return *this;
} //postcondition: LHS에 RHS의 값들을 추가하고 LHS를 반환

double& MyDoubleVector::operator [] (size_t index) { //precondition: index가 0~used 사이일 것
	if (index < 0 || index > size()) {
		cout << "error! it's not effective index" << endl;
		exit(0);
	}		
	else
		return data[index];
} //postcondition: index에 맞는 벡터의 값 반환

MyDoubleVector& MyDoubleVector::operator + (MyDoubleVector& v) { //precondition: 두 벡터의 size가 같을것
	if (size() != v.size()) {
		cout << "error! the sizes of two operands is not same.";
	}
	else {
		for (size_t i = 0; i < size(); i++)
			data[i] = data[i] + v.data[i];
		return *this;
	}
} //postcondition: 두 벡터의 값들을 각각 합치고 합쳐진 값을 저장한 벡터 반환

MyDoubleVector& MyDoubleVector::operator - (MyDoubleVector& v) { //precondition: 두 벡터의 size가 같을것
	if (size() != v.size()) {
		cout << "error! the sizes of two operands is not same.";
	}
	else {
		for (size_t i = 0; i < size(); i++)
			data[i] = data[i] - v.data[i];
		return *this;
	}
} //postcondition: 두 벡터의 값들을 각각 빼고 빼진 값을 저장한 벡터 반환

MyDoubleVector& MyDoubleVector::operator * (MyDoubleVector& v) { //precondition: 두 벡터의 size가 같을것
	if (size() != v.size()) {
		cout << "error! the sizes of two operands is not same." << endl;
	}
	else {
		for (size_t i = 0; i < size(); i++)
			data[i] = data[i] * v.data[i];
		return *this;
	}
} //postcondition: 두 벡터의 값들을 각각 곱하고 곱해진 값을 저장한 벡터 반환

MyDoubleVector& MyDoubleVector::operator - () { //precondition: 벡터의 존재
	for (size_t i = 0; i < size(); i++)
		data[i] = -data[i];
	return *this;
} //postcondition: 벡터의 모든 값들을 부호를 반대로 함

bool MyDoubleVector::operator == (MyDoubleVector& v) { //precondition: 두 벡터의 존재
	if (size() == v.size() && capacity() == v.capacity()) {
		size_t count = 0;
		for (size_t i = 1; i < size() + 1; i++)
			if (data[i] == v.data[i])
				count++;
		if (count == size())
			return true;
	}
	else
		return false;
} //postcondition: 두 벡터가 size, capa, 값들이 모두 같은지 확인후 bool로 반환

void MyDoubleVector::operator () (double& operand) { //precondition: 벡터의 존재
	for (size_t i = 0; i < capacity(); i++)
		this->push_back(operand);
} //postcondition: 벡터의 값들을 모두 입력받은 값으로 바꿈

void MyDoubleVector::pop_back() { //precondition: 벡터에 하나 이상의 값이 존재할 것
	if (empty() == true)
		cout << "error! vector is empty." << endl;
	else
		used--;
} //postcondition: 마지막에 입력된 값을 없애고, 없앨 값이 없는 경우 error 출력

void MyDoubleVector::push_back(double x) { //precondition: 벡터에 여유 공간이 있을 것
	if (size() >= capacity())
		reserve(10);
	data[size()] = x;
	used++;
} //postcondition: 벡터에 여유 공간이 없다면 공간을 10만큼 늘리고 입력받은 값을 저장

size_t MyDoubleVector::capacity() const{ //precondition: 없음
	return capa;
} //postcondition: capa 반환

size_t MyDoubleVector::size() const { //precondition: 없음
	return used;
} //postcondition: used 반환

void MyDoubleVector::reserve(size_t n) { //precondition: 벡터에 여유 공간이 n보다 작을 것
	if (capacity() - size() < n) {
		double *tmp;
		tmp = new double[size() + (2 * n)];
		for (size_t i = 0; i < size(); i++)
			tmp[i] = data[i];
		delete[] data;
		data = tmp;
		capa = size() + (2 * n);
	}
} //postcondition: 2n만큼 공간을 늘림

bool MyDoubleVector::empty() const { //precondition: 없음
	return size() == 0;
} //postcondition: size가 0인지 확인후 bool로 출력

void MyDoubleVector::clear() { //precondition: 없음
	delete[] data;
	data = new double [0];
	capa = 0;
	used = 0;
} //postcondition: data를 delete하고 capa와 used를 모두 0으로 만듬