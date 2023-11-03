#include <iostream>
#include <iomanip>
using namespace std;

void Nhap(int[][100], int&, int&);
void LietKe(int[][100], int, int);
int ktDong(int[][100], int, int, int);


int main()
{
    int b[100][100];
    int k, l;

    Nhap(b, k, l);
    cout << "Cac dong chua so nguyen to la: " << endl;
    LietKe(b, k, l);

    cout << "\nKet thuc!!!\n\n\n";
    return 0;
}

bool ktNguyenTo(int k)
{
    int dem = 0;
    for (int i = 1; i <= k; i++)
        if (k % i == 0)
            dem++;
    if (dem == 2)
        return true;
    return false;
}

int ktDong(int a[][100], int m, int n, int d)
{
    for (int j = 0; j <= n - 1; j++)
        if (ktNguyenTo(a[d][j]))
            return d;
}

void Nhap(int a[][100], int& m, int& n)
{
    cout << "Nhap m : ";
    cin >> m;
    cout << "Nhap n : ";
    cin >> n;
    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
        {
            cout << "Nhap a[" << i << "][" << j << "]:";
            cin >> a[i][j];
        }
}

void LietKe(int a[][100], int m, int n)
{
    for (int i = 0; i < m; i++)
        cout << ktDong(a, m, n, i) << endl;
}