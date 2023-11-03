#include <iostream>
using namespace std;

void nhap(int[][500], int&, int&);
void ChanGiam1(int[][500], int, int);
void ChanGiam2(int[][500], int, int);
void xuat(int[][500], int, int);

int main()
{
	int m, n;
	int a[500][500];
	nhap(a, m, n);
	xuat(a, m, n);
	return 0;
}

void nhap(int a[][500], int& m, int& n)
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
// sử dụng mãng phụ

void ChanGiam1(int a[][500], int m, int n)
{
	int b[500];
	int k = 0;
	for (int i = 0; i < m; i++)
		for (int j = 0; j < n; j++)
			if (a[i][j] % 2 == 0)
				b[k++] = a[i][j];
	for (int i = 0; i <= k - 2; i++)
		for (int j = i + 1; j <= k - 1; j++)
			if (b[i] < b[j])
				swap(b[i], b[j]);
	k = 0;
	for (int i = 0; i < m; i++)
		for (int j = 0; j < n; j++)
			if (a[i][j] % 2 == 0)
				a[i][j] = b[k++];
}
//không sử dụng mãng phụ
void ChanGiam2(int a[][500], int m, int n)
{
	for (int k = 0; k <= m * n - 2; k++)
		for (int l = k + 1; l <= m * n - 1; l++)
			if (a[k / n][k % n] < a[l / n][l % n] && a[k / n][k % n] % 2 == 0 && a[l / n][l % n] % 2 == 0)
				swap(a[k / n][k % n], a[l / n][l % n]);
}

void xuat(int a[][500], int m, int n)
{
	ChanGiam1(a, m, n);
	cout << "Ma tran sau khi sap xep cac so chan tu lon den pe la: \n";
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
			cout << a[i][j] << " ";
		cout << endl;
	}
	cout << endl;
	cout << endl;
	ChanGiam2(a, m, n);
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
			cout << a[i][j] << " ";
		cout << endl;
	}
}