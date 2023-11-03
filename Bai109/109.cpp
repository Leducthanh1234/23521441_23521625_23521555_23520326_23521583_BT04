#include <iostream>
using namespace std;

void nhap(float[][500], int&, int&);
int ktdong(float[][500], int, int, int);
void lietke(float[][500], int, int);
void xuat(float[][500], int, int);

int main()
{
	int m, n;
	float a[500][500];
	nhap(a, m, n);
	xuat(a, m, n);
	return 0;
}

void nhap(float a[][500], int& m, int& n)
{
	cout << "nhap vao so dong: ";
	cin >> m;
	cout << "nhap vao so cot: ";
	cin >> n;
	cout << "Nhap vao ma tran: " << endl;
	for (int i = 0; i < m; i++)
		for (int j = 0; j < n; j++)
			cin >> a[i][j];
}
int ktdong(float a[][500], int m, int n, int d)
{
	for (int j = 0; j < n; j++)
		if (a[d][j] < 0)
			return 1;
	return 0;
}

void lietke(float a[][500], int m, int n)
{
	for (int i = 0; i < m; i++)
		if (ktdong(a, m, n, i) == 1)
			cout << i << " ";
}


void xuat(float a[][500], int m, int n)
{
	cout << "cac dong co gia tri am: ";
	lietke(a, m, n);
}