// Фомичев Андрей Михайлович, II Вариант
// ЛР3(1)

/*
Вычислить и вывести на экран в виде таблицы значений
функции F в соответствии с вариантом задания на интревале
от X1 до Xn с шагом dX,Через a, b, c, d обозначегы
действительные числа, черец A_ц и тд целые части этих чисел.
Значение a, b, c, d, X1, Xn, dX ввести с клавиатуры.
Операции НЕ, И, ИЛИ, и МОД2 - поразрядные
*/

#include <cmath>
#include <iostream>
#include <iomanip>
using namespace std;

template <typename Type>
void F(Type a, Type b, Type c, Type xbegin, Type xend, Type dx)
{
  // Привести к целым если выражение равно нулю
  if (!(((int)a & (int)b) | ((int)b & (int)c)))
    a = (int)a, b = (int)b, c = (int)c;

  for (double x = xbegin; x < xend; x+=dx)
  {
    cout << "x->" << setw(2 + (int)x == x ? 3 : 5) << x << "  ";
    if (x + 5 < 0 && !c)
      cout << "\tFormula 1-> " << (1 / (a * x)) - b << endl;
    else if (x + 5 > 0 && c)
      cout << "\tFormula 2-> " << (x - a) / x << endl;
    else
      cout << "\tFormula 3-> " << (10 * x) / (c - 4) << endl;
  }
}
int main()
{
  double a, b, c, xbegin, xend, dx;
  cin >> a >> b >> c >> xbegin >> xend >> dx;
  // a = 2, b = 5, c = 0, xbegin = -7, xend = 20, dx = 0.5;
  F(a, b, c, xbegin, xend, dx);
  system("PAUSE");
  return 0;
}