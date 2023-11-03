#include <iostream>
#include <iomanip>
using namespace std;

void Nhap(int[][100], int&, int&, int&);
void HoanVi(int, int);
void SapCotTang(int[][100], int, int, int);
void Xuat(int[][100], int, int);

int main()
{
	int a[100][100];
	int m, n, c;
	Nhap(a, m, n, c);
	cout << "Ma tran ban dau: \n";
	Xuat(a, m, n);
	cout << "Nhap cot muon sap xep: ";
	cin >> c;
	SapCotTang(a, m, n, c);
	Xuat(a, m, n);
	return 0;

}

void Nhap(int a[][100], int& m, int& n, int& c)
{
	cout << "Nhap m: ";
	cin >> m;
	cout << "Nhap n: ";
	cin >> n;
	for (int i = 0; i < m; i++)
		for (int j = 0; j < n; j++)
		{
			cout << "a[" << i << "][" << j << "]: ";
			cin >> a[i][j];
		}
}


void HoanVi(int a,int b)
{
	int temp = a;
	a = b;
	b = temp;
}

void SapCotTang(int a[][100], int m, int n,int c)
{
	for (int i = 0;i <= m - 2;i++)
		for (int j = i + 1;j <= m - 1;j++)
		if (a[i][c] > a[j][c])
			HoanVi(a[i][c], a[j][c]);
}

void Xuat(int a[][100], int m, int n)
{
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
			cout << setw(8) << a[i][j];
		cout << endl;
	}
}