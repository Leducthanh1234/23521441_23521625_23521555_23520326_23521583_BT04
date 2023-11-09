#include <iostream>
#include <iomanip>
using namespace std;

void Nhap(float[][100], int&, int&);
void Xuat(float[][100], int, int);

int TimConLonNhat(float[][100], int, int, int&, int&, int&);

int main()
{
	float c[100][100];
	int h, g;
	cout <<"Nhap ma tran : \n";
	Nhap(c, h, g);

	Xuat(c, h, g);
	cout << "\nMa tran con co tong lon nhat:\n";
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
			a[i][j] = -100 + rand() / ((float)RAND_MAX + 200);
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

int TimConLonNhat(float a[][100], int m, int n, int& vtd, int& vtc, int& sd, int& sc)
{
}
//Tui em chua lam duoc thua thay!