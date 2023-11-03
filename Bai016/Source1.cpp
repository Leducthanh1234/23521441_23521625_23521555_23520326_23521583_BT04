#include <iostream>
#include <iomanip>
using namespace std;

void Nhap(int[][100], int&, int&);
int Dang3m(int);
void LietKe(int[][100], int, int, int);

int main()
{
	int d;
	cin >> d;
	int b[100][100];
	int k, l;
	Nhap(b, k, l);
	LietKe(b, k, l, d);

	cout << "Ket thuc!!!\n\n\n";
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

int Dang3m(int n)
{
	while (n > 1)
	{
		int du = n % 3;
		if (du != 0)
			return 0;
		n = n / 3;
	}
	return 1;
}

void LietKe(int a[][100], int m, int n, int d)
{
	for (int j = 0; j < n; j++)
		if (Dang3m(a[d][j]))
			cout << setw(5) << a[d][j];
	cout << endl;
}