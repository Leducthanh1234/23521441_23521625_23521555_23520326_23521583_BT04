#include <iostream>
#include <iomanip>
using namespace std;

void Nhap(float[][100], int&, int&);
void Xuat(float[][100], int, int);
void DuongGiam(float[][100], int, int);
void AmTang(float[][100], int, int);
void SapXep(float[][100], int, int);

int main()
{
    float b[100][100];
    int k, l;

    Nhap(b, k, l);
    cout << "Ma tran ban dau: " << endl;
    Xuat(b, k, l);
    SapXep(b, k, l);
    cout << "Ma tran luc sau: " << endl;
    Xuat(b, k, l);

    cout << "Ket thuc!!!\n\n\n";
    return 0;
}

void Nhap(float a[][100], int& m, int& n)
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

void Xuat(float a[][100], int m, int n)
{
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
            cout << fixed << setw(10) << setprecision(3) << a[i][j];
        cout << endl;
    }
}

void HoanVi(float& a, float& b)
{
    float temp = a;
    a = b;
    b = temp;
}

void DuongGiam(float a[][100], int m, int n)
{
    float b[100];
    int k;
    int i, j;

    k = 0;
    for (i = 0; i < m; i++)
        for (j = 0; j < n; j++)
            if (a[i][j] > 0)
                b[k++] = a[i][j];

    for (i = 0; i <= k - 2; i++)
        for (j = i + 1; j <= k - 1; j++)
            HoanVi(b[i], b[j]);

    k = 0;
    for (i = 0; i < m; i++)
        for (j = 0; j < n; j++)
            if (a[i][j] > 0)
                a[i][j] = b[k++];
}

void AmTang(float a[][100], int m, int n)
{
    float b[100];
    int k;
    int i, j;

    k = 0;
    for (i = 0; i < m; i++)
        for (j = 0; j < n; j++)
            if (a[i][j] < 0)
                b[k++] = a[i][j];

    for (i = 0; i <= k - 2; i++)
        for (j = i + 1; j <= k - 1; j++)
            if (b[i] > b[j])
                HoanVi(b[i], b[j]);

    k = 0;
    for (i = 0; i < m; i++)
        for (j = 0; j < n; j++)
            if (a[i][j] < 0)
                a[i][j] = b[k++];
}

void SapXep(float a[][100], int m, int n)
{
    AmTang(a, m, n);
    DuongGiam(a, m, n);
}