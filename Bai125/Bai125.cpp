#include <iostream>
#include <iomanip>
using namespace std;

void Nhap(float[][500], int&, int&);
void Xuat(float[][500], int, int);
void HoanVi(float&, float&);
void SapCotGiam(float[][500], int, int, int);
void Xuat2(float[][500], int, int);

int main()
{
	float k[500][500];
	int a, b;

	cout << "Nhap ma tran: ";
	Nhap(k, a, b);

	cout << "\nMa tran: " << endl;
	Xuat(k, a, b);

	cout << "\nSau khi cot duoc sap xep giam dan: " << endl;
	Xuat2(k, a, b);

	cout << "\n\n\nKet Thuc!!!";
	return 0;
}

void Nhap(float a[][500], int& m, int& n)
{
	cout << "\nNhap so dong: ";
	cin >> m;
	cout << "\nNhap so cot: ";
	cin >> n;
	srand(time(NULL));
	for (int i = 0; i < m; i++)
		for (int j = 0; j < n; j++)
			a[i][j] = rand() / (RAND_MAX / 200.0) - 100.0;
}

void Xuat(float a[][500], int m, int n)
{
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
			cout << fixed << setw(10) << setprecision(2) << a[i][j];
		cout << endl;
	}
}

void HoanVi(float& a, float& b)
{
	float temp = a;
	a = b;
	b = temp;
}

void SapCotGiam(float a[][500], int m, int n, int c)
{
	for (int i = 0; i < m - 1; i++)
		for (int j = i + 1; j < m; j++)
			if (a[i][c] < a[j][c])
				HoanVi(a[i][c], a[j][c]);
}

void Xuat2(float a[][500], int m, int n)
{
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			SapCotGiam(a, m, n, j);
			cout << setw(10) << a[i][j];
		}
		cout << endl;
	}
}