#include <iostream>
#include <iomanip>
using namespace std;

void Nhap(float[][100], int&, int&);
void Xuat(float[][100], int, int);

void TimConToanDuong(float[][100], int, int, int&, int&, int&, int&);

int main()
{
	float b[100][100];
	int k, l;
	cout << "Ma tran: \n";
	Nhap(b, k, l);

	cout << "\nMa tran ban dau:\n";
	Xuat(b, k, l);

    cout << "\n\n\nKet thuc!!!";
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

void TimConToanDuong(float a[][100], int m, int n, int& vtd, int& vtc, int& sd, int& sc)
{
	for (sd = m - 1; sd >= 0; sd--)
		for (sc = n - 1; sc >= 0; sc--)
			for (vtd = 0; vtd <= m - sd; vtd++)
				for (vtc = 0; vtc < n - sc; vtc++)
					for (int i = 0; i < sd; i++)
						for (int j = 0; j < sc; j++)
							if (a[vtd - i][vtc - j] < 0)
								return;

}