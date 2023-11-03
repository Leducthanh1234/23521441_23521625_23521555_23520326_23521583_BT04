#include<iostream>
#include<iomanip>

using namespace std;

void Nhap(float[][100], int&, int&);
void Xuat(float[][100], int, int);
void XayDung(float[][100], int, int, float[][100], int&, int&);
int main()
{
	float a[100][100];
	int n, m;
	cout << "Ma tran: \n";
	Nhap(a, n, m);
	cout << "\nMa tran ban dau: \n";
	Xuat(a, n, m);
	float b[100][100];
	int k, l;
	XayDung(a, n, m, b, k, l);
	cout << "Ma tran B duoc xay dung: \n";
	Xuat(b, k, l);
	return 0;
}

void Nhap(float a[][100], int& n, int& m)
{
	cout << "Nhap so dong: ";
	cin >> n;
	cout << "Nhap so cot: ";
	cin >> m;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
		{
			cout << "Nhap a[" << i << "][" << j << "]: ";
			cin >> a[i][j];
		}
}

void Xuat(float a[][100], int n, int m)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
			cout << setw(8) << a[i][j];
		cout << endl;
	}
}

void XayDung(float a[][100], int n, int m, float b[][100], int& k, int& l)
{
	k = n;
	l = m;
	for (int i = 0; i < k; i++)
		for (int j = 0; j < l; j++)
			b[i][j] = abs(a[i][j]);
}