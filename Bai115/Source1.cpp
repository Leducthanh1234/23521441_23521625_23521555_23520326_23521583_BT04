#include <iostream>
#include <iomanip>
void Nhap(float[][500], int&, int&);
bool ktGiamDan(float[][500], int, int);
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

bool ktGiamDan(float a[][500], int m, int n)
{
	float lc = a[m][0];
	for (int j = 1; j < n; j++)
		if (a[m][j] >= lc)
			return false;
	return true;
}

void LietKe(float a[][500], int m, int n)
{
	int flag = 1;
	for (int i = 0; i < m; i++)
		if (ktGiamDan(a, i, m))
			flag = 0;
	if (flag == 1)
		cout << "khong co dong nao tang dan";
	else
	{
		cout << "cac dong tang dan la:" << endl;
		for (int i = 0; i < n; i++)
			if (ktGiamDan(a, i, n))
				cout << "Dong thu " << i + 1 << endl;
	}
}