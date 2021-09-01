#include <cstdlib> //20137126048 �����
#include <iostream>
#include "MyDoubleVector.h"
using namespace std;

MyDoubleVector::MyDoubleVector() : used(0), capa(10) { //precondition: ����
	data = new double[capa];
} //postcondition: 10�� ������ ���� ���� ����

MyDoubleVector::MyDoubleVector(const MyDoubleVector& v) : used(v.size()), capa(v.capacity()) { //precondition: v�� ����
	data = new double[capa];
	for (size_t i = 0; i < size(); i++)
		data[i] = v.data[i];
} //postcondition: v�� ���� ũ��, ���� ������ ���� ���� ����

MyDoubleVector::~MyDoubleVector() { //precondition: ������ ����
	delete [] data;
} //postcondition: ���� �Ҵ� ����

MyDoubleVector& MyDoubleVector::operator = (const MyDoubleVector& v) { //precondition: �� ������ ����
	delete [] data;
	data = new double[v.capacity()];
	for (size_t i = 0; i < v.size(); i++)
		data[i] = v.data[i];
	used = v.size();
	capa = v.capacity();
	return *this;
} //postcondition: LHS�� RHS�� ���� ����� LHS�� ��ȯ

MyDoubleVector& MyDoubleVector::operator += (MyDoubleVector& v) { //precondition: �� ������ ����
	reserve(v.size());
	for (size_t i = 0; i < v.size(); i++)
		data[i + size()] = v.data[i];
	used = size() + v.size();
	return *this;
} //postcondition: LHS�� RHS�� ������ �߰��ϰ� LHS�� ��ȯ

double& MyDoubleVector::operator [] (size_t index) { //precondition: index�� 0~used ������ ��
	if (index < 0 || index > size()) {
		cout << "error! it's not effective index" << endl;
		exit(0);
	}		
	else
		return data[index];
} //postcondition: index�� �´� ������ �� ��ȯ

MyDoubleVector& MyDoubleVector::operator + (MyDoubleVector& v) { //precondition: �� ������ size�� ������
	if (size() != v.size()) {
		cout << "error! the sizes of two operands is not same.";
	}
	else {
		for (size_t i = 0; i < size(); i++)
			data[i] = data[i] + v.data[i];
		return *this;
	}
} //postcondition: �� ������ ������ ���� ��ġ�� ������ ���� ������ ���� ��ȯ

MyDoubleVector& MyDoubleVector::operator - (MyDoubleVector& v) { //precondition: �� ������ size�� ������
	if (size() != v.size()) {
		cout << "error! the sizes of two operands is not same.";
	}
	else {
		for (size_t i = 0; i < size(); i++)
			data[i] = data[i] - v.data[i];
		return *this;
	}
} //postcondition: �� ������ ������ ���� ���� ���� ���� ������ ���� ��ȯ

MyDoubleVector& MyDoubleVector::operator * (MyDoubleVector& v) { //precondition: �� ������ size�� ������
	if (size() != v.size()) {
		cout << "error! the sizes of two operands is not same." << endl;
	}
	else {
		for (size_t i = 0; i < size(); i++)
			data[i] = data[i] * v.data[i];
		return *this;
	}
} //postcondition: �� ������ ������ ���� ���ϰ� ������ ���� ������ ���� ��ȯ

MyDoubleVector& MyDoubleVector::operator - () { //precondition: ������ ����
	for (size_t i = 0; i < size(); i++)
		data[i] = -data[i];
	return *this;
} //postcondition: ������ ��� ������ ��ȣ�� �ݴ�� ��

bool MyDoubleVector::operator == (MyDoubleVector& v) { //precondition: �� ������ ����
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
} //postcondition: �� ���Ͱ� size, capa, ������ ��� ������ Ȯ���� bool�� ��ȯ

void MyDoubleVector::operator () (double& operand) { //precondition: ������ ����
	for (size_t i = 0; i < capacity(); i++)
		this->push_back(operand);
} //postcondition: ������ ������ ��� �Է¹��� ������ �ٲ�

void MyDoubleVector::pop_back() { //precondition: ���Ϳ� �ϳ� �̻��� ���� ������ ��
	if (empty() == true)
		cout << "error! vector is empty." << endl;
	else
		used--;
} //postcondition: �������� �Էµ� ���� ���ְ�, ���� ���� ���� ��� error ���

void MyDoubleVector::push_back(double x) { //precondition: ���Ϳ� ���� ������ ���� ��
	if (size() >= capacity())
		reserve(10);
	data[size()] = x;
	used++;
} //postcondition: ���Ϳ� ���� ������ ���ٸ� ������ 10��ŭ �ø��� �Է¹��� ���� ����

size_t MyDoubleVector::capacity() const{ //precondition: ����
	return capa;
} //postcondition: capa ��ȯ

size_t MyDoubleVector::size() const { //precondition: ����
	return used;
} //postcondition: used ��ȯ

void MyDoubleVector::reserve(size_t n) { //precondition: ���Ϳ� ���� ������ n���� ���� ��
	if (capacity() - size() < n) {
		double *tmp;
		tmp = new double[size() + (2 * n)];
		for (size_t i = 0; i < size(); i++)
			tmp[i] = data[i];
		delete[] data;
		data = tmp;
		capa = size() + (2 * n);
	}
} //postcondition: 2n��ŭ ������ �ø�

bool MyDoubleVector::empty() const { //precondition: ����
	return size() == 0;
} //postcondition: size�� 0���� Ȯ���� bool�� ���

void MyDoubleVector::clear() { //precondition: ����
	delete[] data;
	data = new double [0];
	capa = 0;
	used = 0;
} //postcondition: data�� delete�ϰ� capa�� used�� ��� 0���� ����