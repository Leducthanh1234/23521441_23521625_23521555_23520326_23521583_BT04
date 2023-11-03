#include<iostream>
#include<cfloat>
#include<cmath>
#include<iomanip>
using namespace std;

void Nhap(float[][100], int&, int&);
void Xuat(float[][100], int, int);
bool ktGiam(float[][100], int, int);

int main()
{
	float b[100][100];
	int k, l;
	Nhap(b, k, l);

	cout << "\nMa tran ban dau:\n";
	Xuat(b, k, l);

	if (ktGiam(b, k, l))
		cout << "Ma tran giam dan theo dong va cot";
	else
		cout << "Ma tran khong giam dan theo dong va cot";
	cout << "\n\n\nKetthuc!";
	return 0;
}

void Nhap(float a[][100], int& m, int& n)
{
	cout << "Nhap so dong: ";
	cin >> m;
	cout << "Nhap so cot: ";
	cin >> n;
	srand(time(NULL));
	for (int i = 0; i < m; i++)
		for (int j = 0; j < n; j++)
			a[i][j] = -100.0 + (rand() / (RAND_MAX / (100.0 - (-100.0))));
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

bool ktGiam(float a[][100], int m, int n)
{
	a[m][0] = FLT_MAX;
	int c, d;
	for (int i = 0;i < m;i++)
		for (int j = 0;j < n;j++)
		{
			d = i;
			c = j + 1;
			if (c == n)
			{
				c = 0;
				d = i + 1;
			}
			if (a[i][j] > a[d][c])
				return false;
		}
	return true;
}
