#include <iostream>
#include <cmath>

using namespace std;

void Nhap(int[][500], int&, int&);
bool ktDang(int);
int TongBien(int[][500], int, int);

int main()
{
	int a[500][500];
	int m, n;
	Nhap(a, m, n);
	cout << "s= " << TongBien(a, m, n);
	return 0;
}
void Nhap(int a[][500], int& m, int& n)
{
	cout << "Nhap m la: ";
	cin >> m;
	cout << "Nhap n la: ";
	cin >> n;
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> a[i][j];
		}
	}
}
bool ktDang(int k)
{
	if (k < 1)
		return false;
	bool flag = true;
	for (int t = k; t > 1; t = t / 5)
	{
		if (t % 5 != 0)
			flag = false;
	}
	return flag;
}
int TongBien(int a[][500], int n, int m)
{
	int s = 0;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			if (i == 0 || i == (n - 1) || j == 0 || j == (m - 1))
				if (ktDang(a[i][j]) == true)
					s += a[i][j];
	return s;
}