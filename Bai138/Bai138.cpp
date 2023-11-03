#include <iostream>
#include <iomanip>
void Nhap(float[][100], int&, int&);
void BienMaTran(float[][100], int, int, float[], int&);
void HoanVi(float&, float&);
void SapXep(float[], int);
void SapXepBienMaTran(float[][100], int, int, float[], int);
void Xuat(float[][100], int, int);
using namespace std;

int main()
{
	float a[100][100];
	float b[100];
	int m, n,k;
	Nhap(a, m, n);
	BienMaTran(a, m, n, b, k);
	SapXep(b, k);
	SapXepBienMaTran(a, m, n, b, k);
	Xuat(a, m, n);
	return 0;
}

void Nhap(float a[][100], int& m, int& n)
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

void HoanVi(float& a, float& b)
{
	a = a + b;
	b = a - b;
	a = a - b;
}

void BienMaTran(float a[][100], int m, int n, float b[], int& k)
{
	int h = 0;
	for (int j = 0; j < n; j++)
		if (a[0][j]>0)
		{
			b[h] =a[0][j];
			h++;
		}
	for (int i = 1; i < m; i++)
		if (a[i][n-1] > 0)
		{
			b[h] = a[i][n - 1];
			h++;
		}
	for (int j = n - 2; j >= 0; j--)
		if (a[m-1][j] > 0)
		{
			b[h] = a[m - 1][j];
			h++;
		}
	for (int i = m - 2; i > 0; i--)
		if (a[i][0] > 0)
		{
			b[h] = a[i][0];
			h++;
		}
	k = h;
}

void SapXep(float b[], int k)
{
	for (int i = 0; i < k - 1; i++)
		for (int j = i+1; j < k; j++)
			if (b[i] > b[j])
				HoanVi(b[i], b[j]);
}

void SapXepBienMaTran(float a[][100], int m, int n , float b[], int k)
{
	int h = 0;
	for (int j = 0; j < n; j++)
		if (a[0][j] > 0)
		{
			a[0][j] = b[h];
			h++;
		}
	for (int i = 1; i < m; i++)
		if (a[i][n - 1] > 0)
		{
			a[i][n-1] = b[h];
			h++;
		}
	for (int j = n - 2; j >= 0; j--)
		if (a[m - 1][j] > 0)
		{
			a[m-1][j] = b[h];
			h++;
		}
	for (int i = m - 2; i > 0; i--)
		if (a[i][0] > 0)
		{
			a[i][0] = b[h];
			h++;
		}
}

void Xuat(float a[][100], int m, int n)
{
	cout << "ma tran sau hoan vi la:";
	cout << endl;
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
			cout << setw(4) << a[i][j];
		cout << endl;
	}
}