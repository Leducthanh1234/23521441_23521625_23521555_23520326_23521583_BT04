#include <iostream>
#include <iomanip>
using namespace std;

void Nhap(float[][100], int&, int&);
void Xuat(float[][100], int, int);

int DemCon(float[][100], int, int, float[][100], int, int);

int main()
{
	float b[100][100];
	int k, l;
	cout << "Ma tran com: \n";
	Nhap(b, k, l);

	cout << "\nMa tran con ban dau:\n";
	Xuat(b, k, l);

	float c[100][100];
	int g, h;
	cout << "Ma tran lon: \n";
	Nhap(c, g, h);

	cout << "\nMa tran lon ban dau:\n";
	Xuat(c, g, h);

	cout << "\nSo lan xuat hien cua ma tran con: " << DemCon(b, k, l, c, g, h);
	Xuat(c, h, g);
	float d[100][100];
	int x, y;
	cout << "Ma tran lon hon:\n";
	Nhap(d, x, y);
	
	Xuat(d, x, y);
	if (DemCon(c, h, g, d, x, y) == 0)
		cout << "\nKhong ton tai ma tran con trong ma tran lon hon!";
	else
		cout << "\nSo lan xuat hien cua ma tran con: " << DemCon(c, h, g, d, x, y);
	cout << "\n\n\nKet thuc !!!";
	return 0;
}

void Nhap(float a[][100], int& m, int& n)
{
	cout << "Nhap dong: ";
	cin >> m;
	cout << "Nhap cot: ";
	cin >> n;
	srand(time(NULL));
	for (int i = 0; i < m; i++)
		for (int j = 0; j < n; j++)
			a[i][j] = -100 + rand() / ((float)RAND_MAX / 200);
}

void Xuat(float a[][100], int m, int n)
{
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
			cout << fixed << setw(10) << setprecision(3) << a[i][j];
		cout << endl;
	}
}

int DemCon(float a[][100], int m, int n, float b[][100], int k, int l)
{
	if (m > k || n > l)
		return 0;
	int dem = 0;
	for(int d = 0; d <= k - m; d++)
		for (int c = 0; c <= l - n; c++)
		{
			int flag = 1;
			for (int i = 0; i < m; i++)
				for (int j = 0; j < n; j++)
					if (b[d + i][c + j] != a[i][j])
						flag = 0;
			if (flag == 1)
				dem++;
		}
	return dem;
}