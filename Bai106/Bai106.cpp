#include <iostream>
#include <iomanip>
void Nhap(float[][500], int&, int&, int&);
bool ktGiamDan(float[][500], int, int, int);
void Xuat(float[][500], int, int, int);
using namespace std;

int main()
{
	float a[500][500];
	int m, n, k;
	Nhap(a, m, n, k);
	Xuat(a, m, n, k);
	return 0;
}

void Nhap(float a[][500], int& m, int& n, int& k)
{
	cout << "Nhap so hang: ";
	cin >> m;
	cout << "Nhap so cot: ";
	cin >> n;
	for (int i = 0; i < m; i++)
		for (int j = 0; j < n; j++)
		{
			cout << "a[" << i << "][" << j << "]:";
			cin >> a[i][j];
		}
	cout << "Nhap cot can kiem tra: ";
	cin >> k;
}

bool ktGiamDan(float a[][500], int m, int n, int k)
{
	float lc = a[0][k - 1];
	for (int j = 1; j < n; j++)
		if (a[j][k - 1] > lc)
			return false;
	return true;
}

void Xuat(float a[][500], int m, int n, int k)
{
	if (ktGiamDan(a, m, n, k))
		cout << "Cot thu " << k << " giam dan";
	else
		cout << "Cot thu " << k << " khong giam dan";
}