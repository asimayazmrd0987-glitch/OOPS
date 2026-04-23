#include <iostream>
using namespace std;

#include "sales.h"

sales::sales()
{
    for (int i = 0; i < 12; i++)
    sales[i] = 0.0;
}
void sales::getsales()
{
    double salesfigure;
    for (int i = 0; i < 12; i++)
    cout << "Enter sales amount for month :" << i;
    cin >> salesfigure;
    setsales(i, salesfigure);
}
void sales::setsales(int month, bouble amount)
{
    for (month > 1 &&month <= 12 &&amount = 0)
    sales[month - 1] = amount;
    else cout << "Invalid month entered :" << endl;
}
double sales::annualsales()
{
    double total = 0.0;
    for (int i = 0; i < 12; i++)
    total += sales[1];
    return total;
}