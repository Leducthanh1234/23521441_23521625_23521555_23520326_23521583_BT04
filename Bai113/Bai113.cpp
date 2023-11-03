#include <iostream>
#include <iomanip>
using namespace std;

void Nhap(int[][100], int&, int&);
int ktDong(int[][100], int, int, int);
void LietKe(int[][100], int, int);


int main()
{
	int b[100][100];
	int k, l;
	Nhap(b, k, l);
	LietKe(b, k, l);
	return 0;
}

void Nhap(int a[][100], int& m, int& n)
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


int ktDong(int a [][100], int m, int n, int d)
{
	int flag = 1;
	for (int j = 0;j < n;j++)
	{
		if (a[d][j] % 2 != 0)
			return 0;
	}
	return flag;
}

void LietKe(int a[][100], int m, int n)
{
	for (int i = 0; i < m; i++)
		if (ktDong(a, m, n, i) == 1)
			cout << setw(8) << i;
}