#include <iostream>
#include <iomanip>
using namespace std;

void Nhap(float[][100], int&, int&);
void Xuat(float[][100], int, int);

bool ktDong(float[][100], int, int, int);
void LietKe(float[][100], int, int);

int main()
{
    float b[100][100];
    int k, l;
    
    cout << "Ma tran: \n";
    Nhap(b, k, l);

    cout << "\nMa tran ban dau:\n";
    Xuat(b, k, l);

    LietKe(b, k, l);
    cout << "\n\n\nKet thuc!!!";
    return 0;
}

void Nhap(float a[][100], int& m, int& n)
{
    cout << "\nNhap so dong : ";
    cin >> m;
    cout << "\nNhap so cot : ";
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

bool ktDong(float a[][100], int m, int n, int xx)
{ 
    for (int j = 0; j < n - 1; j++)
        for (int h = j + 1; h < n; h++)
            if (a[xx][h] <= a[xx][j])
                return false;
    return true;
}

void LietKe(float a[][100], int m, int n)
{
    int flag = 1;
    for (int j = 0; j < n; j++)
        if (ktDong(a, m, n, j))
            flag = 0;
    if (flag == 1)
        cout << "khong co dong nao giam dan";
    else
    {
        cout << "\nCac cot tang dan la:" << endl;
        for (int j = 0; j < n; j++)
            if (ktDong(a, m, n, j))
                cout << setw(10) << j << endl;
    }
}