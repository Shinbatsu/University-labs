// Фомичев Андрей Михайлович, II Вариант
// ЛР6

/*
Из заданного на плоскости множества точек выбрать
три различные точки так, чтобы разность между плошадью
круга, ограниченного окружностью, проходящей через эти
три точки, и площадью треугольника с вершинами в этих
точках была минимальной.
*/

#include <vector>
#include <iostream>
#include <iomanip>
using namespace std;
#include <cmath>
#define _USE_MATH_DEFINES ;

template <class T>
void calc(T Pcount)
{
  int i, j;
  T **s = new T *[Pcount];
  for (i = 0; i < Pcount; i++)
    s[i] = new T[4];
  T **a = new T *[Pcount];
  for (i = 0; i < Pcount; i++)
    a[i] = new T[2];
  cout << "Ввод массива точек";
  for (i = 0; i < Pcount; i++)
    for (j = 0; j < 2; j++)
    {
      cout << "Точка номер: " << i + 1 << " Координата: " << j % 2 == 0 ? "X" : "Y" << ;
      cin >> a[i][j];
    }
  for (i = 0; i < Pcount; i++)
    for (j = 0; j < 2; j++)
      cout << setw(4) << a[i][j] << "  ";

  T x1, x2, x3, y1, y2, y3, ma, mb, x, y;
  // Алгоритм вычисления площадей для каждойго набора точек
  for (i = 0; i < Pcount - 2; i++)
    for (j = i + 1; j < Pcount - 1; j++)
      for (int k = j + 1; k < Pcount; k++)
      {
        x1 = a[i][0],
        y1 = a[i][1],
        x2 = a[i + 1][0],
        y2 = a[i + 1][0],
        x3 = a[i + 3][0],
        y3 = a[i + 3][0];
        // Абсолютные расстояния между точками
        ma = (y1 - y2) / (x2 - x1),
        mb = (y3 - y2) / (x3 - x2);
        // Оптимизация
        if (mb - ma == 0)
          break;
        // уравнения для координат
        x = (ma * mb * (y1 - y3) + mb * (x1 + x2) - ma * (x2 + x3)) / 2 * (mb - ma);
        y = (-1) * (x - (x1 + x2) / 2) / ma + (y1 + y2) / 2;
        // Радиус круга
        T radius = (T)sqrt(double((x1 - x) * (x1 - x) - (y1 - y) * (y1 - y)));
        // Площадь круга
        double circleArea = M_PI * pow(radius, 2);
        // Площадь треугольника
        T triangleArea = ((x1 - x3) * (y2 - y3) - (x2 - x3) * (y1 - y3)) / 2.0;
        for (int _ = 0; _ < Pcount; _++)
        {
          s[f][0] = _;
          s[f][1] = circleArea;
          s[f][3] = triangleArea;
          s[f][4] = circleArea - ST;
        }
      }
  // Поиск минимальных значений
  for (j = Pcount - 1; j > 0; j--)
    for (i = 0; i < j; i++)
      if (s[i + 1][4] < s[i][4])
      {
        T *min = s[i];
        s[i] = s[i + 1];
        s[i + 1] = min;
      }
  // Вывод результатов
  for (i = 0; i < Pcount; i++)
    for (j = 0; j < 4; j++)
      cout << setw(4) << s[i][j] << "  ";
}
int main()
{
  setlocale(LC_ALL, "Russian");
  int Pcount;
  cout << "Кол-во точек: " << endl;
  cin >> Pcount;
  calc<int>(Pcount);
  system("PAUSE");
  return 0;
}

/*==================================================*/
/*                                                  */
/*               Пояснение к работе 😊             */
/*                                                  */
/* Сложно что-то сказать по поводу задачи,          */
/* я не смог придумать крутой алгоритм              */
/* решения, поэтому функция имеет сложность         */
/* как при брутфорсе O(!(max(1,N-3)))               */
/* где N это кол-во точек на ввод                   */
/*                                                  */
/*==================================================*/