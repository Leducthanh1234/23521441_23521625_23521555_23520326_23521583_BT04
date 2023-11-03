#include<iostream>
#include<cmath>
#include<iomanip>
using namespace std;

void Nhap(int[][100], int&, int&);
void Xuat(int[][100], int, int);
void HoanVi(int&, int&);
void XuatChanGiam(int[][100], int, int);

int main()
{
	int c[100][100];
	int k, l;
	Nhap(c, k, l);

	cout << "Ma tran ban dau:\n";
	Xuat(c, k, l);


	XuatChanGiam(c, k, l);
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
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			a[i][j] = rand() % (200 + 1) - 100;
}

void Xuat(int a[][100], int n, int m)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
			cout << setw(10) << a[i][j];
		cout << endl;
	}
}

void HoanVi(int& a, int& b)
{
	int temp = a;
	a = b;
	b = temp;
}

void XuatChanGiam(int a[][100], int m, int n)
{
	int k = 0;
	int i, j;
	int b[100];
	cout << "Cac gia tri chan trong ma tran theo thu tu giam dan: \n";
	for (i = 0; i < m; i++)
		for (j = 0; j < n; j++)
			if (a[i][j] % 2 == 0)
				b[k++] = a[i][j];
	for (i = 0; i <= k - 2; i++)
		for (j = i + 1; j <= k - 1; j++)
			if (b[i] < b[j])
				HoanVi(b[i], b[j]);
	for (i = 0; i < k; i++)
		cout << setw(10) << b[i];
}
