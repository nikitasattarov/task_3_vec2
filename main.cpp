#include <iostream>
#include <vector>
#include <locale.h>

using namespace std;

int main()
{
    setlocale(0, "Russian");
    cout << "Введите размеры матрицы: (сначала количество строк, затем столбцов) " << endl;
    int n, m;
    cin >> m >> n;
    cout << endl << "Введите матрицу размера: " << m << " на " << n << endl;

    vector< vector<int> > a, c(m);
    vector<int> b(n * m), d;
    vector < vector<int> >::iterator ia = a.begin();
    vector<int>::iterator ib = b.begin();
    vector<int>::iterator id = d.begin();
    vector < vector<int> >::iterator ic = c.begin();


    for (ic = c.begin(); ic != c.end(); ic++)
    {
        (*ic).resize(n);
    }
    ic = c.begin();



    int val;
    for (int j = 0; j < m; j++)
    {
        for (int i = 0; i < n; i++)
       {
        cin >> val;
        d.push_back(val);
       }
       a.push_back(d);
       d.clear();
    }

    cout << endl << "Наша исходная матрица: " << endl;

    vector <int>:: iterator iaa, icc;

    ia = a.begin();
    iaa = (*ia).begin();
    while (ia != a.end())
    {
        iaa = (*ia).begin();
        while (iaa != (*ia).end())
        {
            cout << *iaa << " ";
            ++iaa;
        }
        cout << endl;
        ++ia;
    }
    cout << endl << "Преобразовываем матрицу размера " << m << " на " << n << " в строку размера " << m * n << endl;


    for (ia = a.begin(); ia != a.end(); ia++)
    {
        for (iaa = (*ia).begin(); iaa != (*ia).end(); iaa++)
        {
            ib = b.begin() + (ia - a.begin()) * n + (iaa - (*ia).begin());
            *ib = *iaa;
        }
    }

    ib = b.begin();
    while (ib != b.end())
    {
        cout << *ib << " ";
        ++ib;
    }

    cout << endl << endl << "Преобразовываем строку обратно в матрицу размера: " << m << " на " << n << endl;

    ib = b.begin();
    ic = c.begin();
    icc = (*ic).begin();
    for (ib = b.begin(); ib != b.end(); ib++)
    {
        ic = c.begin() + (ib - b.begin()) / n;
        icc = (*ic).begin() + (ib - b.begin()) % n;
        *icc = *ib;
    }


    ic = c.begin();
    icc = (*ic).begin();
    while (ic != c.end())
    {
        icc = (*ic).begin();
        while (icc != (*ic).end())
        {
            cout << *icc << " ";
            ++icc;
        }
        cout << endl;
        ++ic;
    }
    return 0;
}
