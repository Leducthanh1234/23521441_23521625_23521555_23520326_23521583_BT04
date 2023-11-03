#include <iostream>
#include <iomanip>
void Nhap(float[][500], int&, int&);
bool ktTangDan(float[][500], int, int);
void LietKe(float[][500], int, int);
using namespace std;

int main()
{
	float a[500][500];
	int m, n;
	Nhap(a, m, n);
	LietKe(a, m, n);
	return 0;
}

void Nhap(float a[][500], int& m, int& n)
{
	cout << "Nhap so hang:";
	cin >> m;
	cout << "Nhap so cot:";
	cin >> n;
	for (int i = 0; i < m; i++)
		for (int j = 0; j < n; j++)
		{
			cout << "a[" << i << "][" << j << "]:";
			cin >> a[i][j];
		}
}

bool ktTangDan(float a[][500], int m, int n)
{
	float lc = a[0][n];
	for (int i = 1; i < m; i++)
		if (a[i][n] <= lc)
			return false;
	return true;
}

void LietKe(float a[][500], int m, int n)
{
	int flag = 1;
	for (int j = 0; j < n; j++)
		if (ktTangDan(a, m, j))
			flag = 0;
	if (flag == 1)
		cout << "khong co cot nao tang dan";
	else
	{
		cout << "cac cot tang dan la:" << endl;
		for (int j = 0; j < n; j++)
			if (ktTangDan(a, m, j))
				cout << "cot thu " << j + 1 << endl;
	}
}