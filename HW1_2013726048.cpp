#include <iostream> //20137126048 �����
#include "MyDoubleVector.h"
using namespace std;

void printAll(MyDoubleVector v) {
	for (size_t i = 0; i < v.size(); i++) {
		cout << v[i] << " ";
	}
	cout << endl;
}

int main() {
	MyDoubleVector a, b;

	while (true) {
		int work;
		int select;
		cout << "������ �����ϼ���." << endl
			<< "1.���߰� 2.������������ 3.������ġ�� 4.���Ͱ�����ġ�� 5.���Ͱ��黩�� 6.���Ͱ�����ϱ�" << endl
			<< "7.���鿡- 8.���ͺ� 9.���Ͱ����� 10.���Ϳ뷮�ø��� 11.��������� 12.���Ͱ���� 13.����" << endl;
		cin >> work;
		switch (work)
		{
		case 1:
			double x;
			cout << "���͸� �����ϼ���. 1.A 2.B" << endl;
			cin >> select;
			cout << "���� �Է��ϼ���. ";
			cin >> x;
			if (select == 1)
				a.push_back(x);
			else if (select == 2)
				b.push_back(x);
			else {
				cout << "�߸��� �Է��Դϴ�.\n";
				break;
			}
			cout << endl;
			break;
		case 2:
			cout << "���͸� �����ϼ���. 1.A 2.B" << endl;
			cin >> select;
			if (select == 1)
				a.pop_back();
			else if (select == 2)
				b.pop_back();
			else {
				cout << "�߸��� �Է��Դϴ�.\n";
				break;
			}
			cout << endl;
			break;
		case 3:
			a += b;
			cout << "B�� ������ A�� ���������ϴ�." << endl;
			cout << endl;
			break;
		case 4:
			a + b;
			cout << endl;
			break;
		case 5:
			a - b;
			cout << endl;
			break;
		case 6:
			a * b;
			cout << endl;
			break;
		case 7:
			cout << "���͸� �����ϼ���. 1.A 2.B" << endl;
			cin >> select;
			if (select == 1)
				- a;
			else if (select == 2)
				- b;
			else {
				cout << "�߸��� �Է��Դϴ�.\n";
				break;
			}
			cout << endl;
			break;
		case 8:
			if (a == b)
				cout << "A�� B�� �����ϴ�. " << endl;
			else if (!(a == b))
				cout << "A�� B�� �ٸ��ϴ�. " << endl;
			cout << endl;
			break;
		case 9:
			cout << "���͸� �����ϼ���. 1.A 2.B" << endl;
			cin >> select;
			cout << "���� �Է��ϼ���. ";
			cin >> x;
			if (select == 1)
				a(x);
			else if (select == 2)
				b(x);
			else {
				cout << "�߸��� �Է��Դϴ�.\n";
				break;
			}
			cout << endl;
			break;
		case 10:
			int n;
			cout << "���͸� �����ϼ���. 1.A 2.B" << endl;
			cin >> select;
			cout << "���� �Է��ϼ���. ";
			cin >> n;
			if (select == 1)
				a.reserve(n);
			else if (select == 2)
				b.reserve(n);
			else {
				cout << "�߸��� �Է��Դϴ�.\n";
				break;
			}
			cout << endl;
			break;
		case 11:
			cout << "���͸� �����ϼ���. 1.A 2.B" << endl;
			cin >> select;
			if (select == 1)
				a.clear();
			else if (select == 2)
				b.clear();
			else {
				cout << "�߸��� �Է��Դϴ�.\n";
				break;
			}
			cout << endl;
			break;
		case 12:
			cout << "���͸� �����ϼ���. 1.A 2.B" << endl;
			cin >> select;
			if (select == 1)
				printAll(a);
			else if (select == 2)
				printAll(b);
			else {
				cout << "�߸��� �Է��Դϴ�.\n";
				break;
			}
			cout << endl;
			break;
		default:
			cout << "�߸��� �Է��Դϴ�.\n";
			break;
		}
		if (work == 13) {
			cout << "���α׷��� �����մϴ�.\n";
			break;
		}
	}
}