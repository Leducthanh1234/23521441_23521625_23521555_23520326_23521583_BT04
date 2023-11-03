#include<iostream>
#include<iomanip>
using namespace std;

void Nhap(float[][100], int&, int&);
void Xuat(float[][100], int, int);
int ktDong(float[][100], int, int, int);
void LietKe(float[][100], int, int);

int main()
{
	float b[100][100];
	int k, l;
	Nhap(b, k, l);

	cout << "\nMa tran ban dau:\n";
	Xuat(b, k, l);

	
	LietKe(b, k, l);
	cout << "\n\n\nKet Thuc!!!";
	return 0;
}

void Nhap(float a[][100], int& m, int& n)
{
	cout << "Nhap so dong: ";
	cin >> m;
	cout << "Nhap so cot: ";
	cin >> n;
	srand(time(NULL));
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			a[i][j] = -100.0 + (rand() / (RAND_MAX / (200.0)));
}

void Xuat(float a[][100], int n, int m)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
			cout << fixed << setw(10) << setprecision(3) << a[i][j];
		cout << endl;
	}
}

int ktDong(float a[][100], int m, int n, int d)
{
	int flag = 1;
	for (int j = 0; j < n; j++)
	{
		if (a[d][j] > 0)
			flag = 0;
	}
	return flag;
}



void LietKe(float a[][100], int m, int n)
{
	int dem = 0;
	for (int i = 0; i < m; i++)
		if (ktDong(a, m, n, i) == 1)
			dem++;
	if (dem == 0)
		cout << "\Khong co dong toan am!!";
	else
	{
		cout << "\nCac dong toan am la: ";
		for (int i = 0; i < m; i++)
			if (ktDong(a, m, n, i) == 1)
				cout << setw(10) << i;
	}
}
