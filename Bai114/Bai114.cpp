#include <iostream>
#include <iomanip>
using namespace std;

void Nhap(int[][500], int&, int&);
void Xuat(int[][500], int, int);
bool ktChinhPhuong(int);
int ktCot(int[][500], int, int, int);
void LietKe(int[][500], int, int);

int main()
{
	int k[500][500];
	int a, b;

	cout << "Nhap ma tran: ";
	Nhap(k, a, b);

	cout << "\nMa tran: " << endl;
	Xuat(k, a, b);

	cout << "\nMa tran: " << endl;
	LietKe(k, a, b);

	cout << "\n\n\nKet Thuc!!!";
	return 0;
}

void Nhap(int a[][500], int& m, int& n)
{
	cout << "\nNhap so dong: ";
	cin >> m;
	cout << "\nNhap so cot: ";
	cin >> n;
	srand(time(NULL));
	for (int i = 0; i < m; i++)
		for (int j = 0; j < n; j++)
			a[i][j] = rand() % (201) - 100;
}

void Xuat(int a[][500], int m, int n)
{
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
			cout << setw(10) << a[i][j];
		cout << endl;
	}
}

bool ktChinhPhuong(int k)
{
	bool flag = false;
	for (int i = 0; i <= k; i++)
		if (i * i == k)
			flag = true;
	return flag;
}

int ktCot(int a[][500], int m, int n, int c)
{
	int flag = 0;
	for (int i = 0; i < m; i++)
		if (ktChinhPhuong(a[i][c]) == true)
			flag = 1;
	return flag;
}

void LietKe(int a[][500], int m, int n)
{
	for (int j = 0; j < n; j++)
		if (ktCot(a, m, n, j) == 1)
			cout << setw(10) << j;
}