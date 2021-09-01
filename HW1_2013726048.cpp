#include <iostream> //20137126048 김재원
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
		cout << "할일을 선택하세요." << endl
			<< "1.값추가 2.마지막값삭제 3.벡터합치기 4.벡터값들합치기 5.벡터값들빼기 6.벡터값들곱하기" << endl
			<< "7.값들에- 8.벡터비교 9.벡터값통일 10.벡터용량늘리기 11.벡터지우기 12.벡터값출력 13.종료" << endl;
		cin >> work;
		switch (work)
		{
		case 1:
			double x;
			cout << "벡터를 선택하세요. 1.A 2.B" << endl;
			cin >> select;
			cout << "값을 입력하세요. ";
			cin >> x;
			if (select == 1)
				a.push_back(x);
			else if (select == 2)
				b.push_back(x);
			else {
				cout << "잘못된 입력입니다.\n";
				break;
			}
			cout << endl;
			break;
		case 2:
			cout << "벡터를 선택하세요. 1.A 2.B" << endl;
			cin >> select;
			if (select == 1)
				a.pop_back();
			else if (select == 2)
				b.pop_back();
			else {
				cout << "잘못된 입력입니다.\n";
				break;
			}
			cout << endl;
			break;
		case 3:
			a += b;
			cout << "B의 값들이 A에 합쳐졌습니다." << endl;
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
			cout << "벡터를 선택하세요. 1.A 2.B" << endl;
			cin >> select;
			if (select == 1)
				- a;
			else if (select == 2)
				- b;
			else {
				cout << "잘못된 입력입니다.\n";
				break;
			}
			cout << endl;
			break;
		case 8:
			if (a == b)
				cout << "A와 B는 같습니다. " << endl;
			else if (!(a == b))
				cout << "A와 B는 다릅니다. " << endl;
			cout << endl;
			break;
		case 9:
			cout << "벡터를 선택하세요. 1.A 2.B" << endl;
			cin >> select;
			cout << "값을 입력하세요. ";
			cin >> x;
			if (select == 1)
				a(x);
			else if (select == 2)
				b(x);
			else {
				cout << "잘못된 입력입니다.\n";
				break;
			}
			cout << endl;
			break;
		case 10:
			int n;
			cout << "벡터를 선택하세요. 1.A 2.B" << endl;
			cin >> select;
			cout << "값을 입력하세요. ";
			cin >> n;
			if (select == 1)
				a.reserve(n);
			else if (select == 2)
				b.reserve(n);
			else {
				cout << "잘못된 입력입니다.\n";
				break;
			}
			cout << endl;
			break;
		case 11:
			cout << "벡터를 선택하세요. 1.A 2.B" << endl;
			cin >> select;
			if (select == 1)
				a.clear();
			else if (select == 2)
				b.clear();
			else {
				cout << "잘못된 입력입니다.\n";
				break;
			}
			cout << endl;
			break;
		case 12:
			cout << "벡터를 선택하세요. 1.A 2.B" << endl;
			cin >> select;
			if (select == 1)
				printAll(a);
			else if (select == 2)
				printAll(b);
			else {
				cout << "잘못된 입력입니다.\n";
				break;
			}
			cout << endl;
			break;
		default:
			cout << "잘못된 입력입니다.\n";
			break;
		}
		if (work == 13) {
			cout << "프로그램을 종료합니다.\n";
			break;
		}
	}
}