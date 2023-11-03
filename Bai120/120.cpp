#include <iostream>
using namespace std;

void nhap(int[][500], int&, int&, int&, int&);
void hoanvi(int[][500], int, int, int, int);
void xuat(int[][500], int, int,int ,int);

int main()
{
	int m, n, d1, d2;
	int a[500][500];
	nhap(a, m, n, d1, d2);
	xuat(a, m, n, d1, d2);
	return 0;
}

void nhap(int a[][500], int& m, int& n, int& d1,int& d2)
{
	cout << "nhap vao so dong: ";
	cin >> m;
	cout << "nhap vao so cot: ";
	cin >> n;
	cout << "Nhap vao ma tran: " << endl;
	for (int i = 0; i < m; i++)
		for (int j = 0; j < n; j++)
			cin >> a[i][j];
	cout << "nhap vao 2 dong can doi voi nhau: ";
	cin >> d1 >> d2;
}

void hoanvi(int a[][500], int m, int n, int d1, int d2)
{
	for (int j = 0; j < n; j++)
		swap(a[d1][j], a[d2][j]);
}

void xuat(int a[][500], int m, int n, int d1, int d2)
{
	hoanvi(a, m, n, d1, d2);
	cout << "ma tran sau khi hoan doi:\n";
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
			cout << a[i][j] << " ";
		cout << endl;
	}
}