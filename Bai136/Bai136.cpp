#include <iostream>
#include <iomanip>
using namespace std;

void Nhap(int[][500], int&, int&);
void Xuat(int[][500], int, int);
void HoanVi(int&, int&);
bool ktNguyenTo(int);
void XuatNguyenToTang(int[][500], int, int);

int main()
{
	int k[500][500];
	int a, b;

	cout << "Nhap ma tran: ";
	Nhap(k, a, b);

	cout << "\nMa tran: " << endl;
	Xuat(k, a, b);

	cout << "\nDay nguyen to tang: " << endl;
	XuatNguyenToTang(k, a, b);

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

void HoanVi(int& a, int& b)
{
	int temp = a;
	a = b;
	b = temp;
}

bool ktNguyenTo(int k)
{
	int dem = 0;
	for (int i = 1; i <= k; i++)
		if (k % i == 0)
			dem++;
	return (dem == 2);
}

void XuatNguyenToTang(int a[][500], int m, int n)
{
	int b[500];
	int k;
	int i, j;

	k = 0;
	for (i = 0; i < m; i++)
		for (j = 0; j < n; j++)
			if (ktNguyenTo(a[i][j]) == 1)
				b[k++] = a[i][j];

	for (i = 0; i <= k - 2; i++)
		for (j = i + 1; j <= k - 1; j++)
			if (b[i] > b[j])
				HoanVi(b[i], b[j]);

	for (i = 0; i < k; i++)
		cout << setw(8) << b[i];
}