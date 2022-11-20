// Фомичев Андрей Михайлович, II Вариант
// ЛР3(2)

/*
Что-то там с рядом Тейлора
*/

#include <cmath>
#include <iostream>
#include <iomanip>
using namespace std;

void printRow(double n, double x, double Fx, double precision = 1e-10)
{
     cout << setfill('0') << setw(5) << n << "\t"
          << setfill(' ') << x << setw((int)x == x ? 7 : 5)
          << " " << setprecision(3 + abs((int)log10(precision))) << Fx << endl;
}
void printHeader()
{
     cout << "  n  "
          << "\tx"
          << "       "
          << "F(x)" << endl;
}
int main()
{
     double xbegin,xend,dx, e;
     cin >> xbegin >> xend >> dx >> e;
     for (double x = xbegin; x < xend; x += dx)
     {
          printHeader();
          double F_x = 1, n = 1;
          for (double current = 1, next = current * x / n;
               //Выход по достижению точности.
               abs(-abs(next = current * x / n) - abs(current)) > e;
               n++)
          {
               printRow(n, x, F_x, e);
               // Расчет текущего значнния функции с учетом знака
               F_x += next * ((int)n % 2 ? -1 : 1);
               current = next;
          }
          cout << endl;
     }
     system("PAUSE");
     return 0;
}
