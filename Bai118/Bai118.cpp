#include<iostream>
#include<iomanip>
#include<cmath>
using namespace std;

void Nhap(float[][100], int&, int&);
void Xuat(float[][100], int, int);
float LonNhatDong(float[][100], int, int, int);
float LonNhatCot(float[][100], int, int, int);
void XayDung(float[][100], int, int, float[][100]);

int main()
{
	float b[100][100];
	int k, l;
	Nhap(b, k, l);

	cout << "\nMa tran ban dau:\n";
	Xuat(b, k, l);

	float c[100][100];
	XayDung(b, k, l, c);

	cout << "Ma tran moi :\n";
	Xuat(c, k, l);
	cout << "\n\n\nKetthuc!";
	return 0;
}

void Nhap(float a[][100], int& m, int& n)
{
	cout << "Nhap so dong: ";
	cin >> m;
	cout << "Nhap so cot: ";
	cin >> n;
	srand(time(NULL));
	for (int i = 0; i < m; i++)
		for (int j = 0; j < n; j++)
			a[i][j] = -100.0 + (rand() / (RAND_MAX / (100.0 - (-100.0))));
}

void Xuat(float a[][100], int m, int n)
{
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
			cout << fixed << setw(10) << setprecision(3) << a[i][j];
		cout << endl;
	}
}

float LonNhatDong(float a[][100], int m, int n, int c)
{
	float res = a[c][0];
	for (int j = 0;j < n;j++)
		res = max(res, a[c][j]);
	return res;
}

float LonNhatCot(float a[][100], int m, int n, int c)
{
	float res = a[0][c];
	for (int i = 0;i < m;i++)
		res = max(res, a[i][c]);
	return res;
}

void XayDung(float a[][100], int m, int n, float b[][100])
{
	for (int i = 0;i < m;i++)
		for (int j = 0;j < n;j++)
			b[i][j] = max(LonNhatDong(a, m, n, i), LonNhatCot(a, m, n, j));
}