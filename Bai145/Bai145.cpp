#include<iostream>
#include<cmath>
#include<iomanip>
using namespace std;

void Nhap(int[][100], int&, int&);
void Xuat(int[][100], int, int);

int ktDong(int[][100], int, int, int);
void XoaDong(int[][100], int&, int, int);
void XoaDong(int[][100], int&, int);

int main()
{
	int b[100][100];
	int k, l;
	cout << "Ma tran: \n";
	Nhap(b, k, l);

	cout << "\nMa tran ban dau:\n";
	Xuat(b, k, l);

	XoaDong(b, k, l);
	cout << "\nMa tran sau khi xoa: \n";
	Xuat(b, k, l);

	cout << "\n\n\nKet Thuc!!!";
	return 0;
}

void Nhap(int a[][100], int& m, int& n)
{
	cout << "Nhap so dong: ";
	cin >> m;
	cout << "Nhap so cot: ";
	cin >> n;
	srand(time(NULL));
	for (int i = 0; i < m; i++)
		for (int j = 0; j < n; j++)
			a[i][j] = rand() % (200 + 1) - 100;
}

void Xuat(int a[][100], int m, int n)
{
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
			cout << setw(10) << a[i][j];
		cout << endl;
	}
}

int ktDong(int a[][100], int m, int n, int d)
{
	int flag = 1;
	for (int j = 0; j < n; j++)
		if (a[d][j] % 2 != 0)
			flag = 0;
	return flag;
}

void XoaDong(int a[][100], int& m, int n, int d)
{
	for (int j = 0; j < n; j++)
	{
		for (int i = d; i <= m - 2; i++)
			a[i][j] = a[i + 1][j];
	}
	m--;
}

void XoaDong(int a[][100], int& m, int n)
{
	for (int i = m - 1; i >= 0; i--)
		if (ktDong(a, m, n, i))
			XoaDong(a, m, n, i);
}