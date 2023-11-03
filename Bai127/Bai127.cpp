#include <iostream>
#include <iomanip>
void Nhap(float[][500], int&, int&);
void SapCotTang(float[][500], int, int);
void SapCotGiam(float[][500], int, int);
void SapXep(float[][500], int, int);
void Xuat(float[][500], int, int);
void HoanVi(float&, float&);
using namespace std;

int main()
{
	float a[500][500];
	int m, n;
	Nhap(a, m, n);
	SapXep(a, m, n);
	Xuat(a, m, n);
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

void SapXep(float a[][500], int m, int n)
{
	for (int j = 0; j < n; j++)
	{
		if (j % 2 == 0)
			SapCotGiam(a,m,j);
		else
			SapCotTang(a,m,j);
	}
}

void HoanVi(float& a, float& b)
{
	a = a + b;
	b = a - b;
	a = a - b;
}

void SapCotGiam(float a[][500], int m, int n)
{
	for (int i = 0; i < m - 1; i++)
		for (int j = i + 1; j < m; j++)
			if (a[i][n] < a[j][n])
				HoanVi(a[i][n], a[j][n]);
}

void SapCotTang(float a[][500], int m, int n)
{
	for (int i = 0; i < m - 1; i++)
		for (int j = i + 1; j < m ; j++)
			if (a[i][n] > a[j][n])
				HoanVi(a[i][n], a[j][n]);
}

void Xuat(float a[][500], int m, int n)
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