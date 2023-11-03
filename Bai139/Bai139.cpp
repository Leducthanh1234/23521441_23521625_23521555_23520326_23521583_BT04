#include<iostream>
#include<iomanip>
#include<cmath>
using namespace std;
void Nhap(float[][100], int&, int&);
void SapXep(float[][100], int, int);
void Xuat(float[][100], int, int);
int main()
{
	float a[100][100];
	int m, n;
	Nhap(a, m, n);
	SapXep(a, m, n);
	Xuat(a, m, n);
	return 0;
}
void Nhap(float a[][100], int& m, int& n)
{
	cout << "Nhap m:";
	cin >> m;
	cout << "Nhap n:";
	cin >> n;
	cout << "Nhap cac phan tu cua ma tran:" << endl;
	for (int i = 0;i < m;i++)
		for (int j = 0;j < n;j++)
		{
			cout << "A[" << i << "," << j << "] = ";
			cin >> a[i][j];
		}
}
void SapXep(float a[][100], int m, int n)
{
	int dong = m, cot = n, k = 1, p = 0, i, j;
	while (k <= m * n)
	{
		for (i = p; i < cot; i++)
			a[p][i] = k++;
		for (i = p + 1; i < dong; i++)
			a[i][cot - 1] = k++;
		if (p != dong - 1)
		{
			for (i = cot - 2; i >= p; i--) 
				a[dong - 1][i] = k++;
		}
		if (p != cot - 1)
		{
			for (i = dong - 2; i > p; i--)
				a[i][p] = k++;
		}
		p++;dong--; cot--;
	}
}
void Xuat(float a[][100], int m, int n)
{
	cout << "Ma tran sau khi sap xep la:" << endl;
	for (int i = 0;i < m;i++)
	{
		for (int j = 0;j < n;j++)
			cout << setw(4) << a[i][j];
		cout << endl;
	}
}