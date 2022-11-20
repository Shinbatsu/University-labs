// Фомичев Андрей Михайлович, II Вариант
// ЛР6

/*
Из заданного на плоскости множества точек выбрать 
три различные точки так, чтобы разность между плошадью 
круга, ограниченного окружностью, проходящей через эти 
три точки, и площадью треугольника с вершинами в этих 
точках была минимальной.
*/

// P.S. На aнглийской винде лаба не компилится
// из-за цыганского названия файла.cpp
#include <vector>
#include <iostream>
using namespace std;
template < class T >
void func(int lstr, T **a1, T **s1) {
  int i, j;
  T **s = new T *[lstr];
  for (i = 0; i < lstr; i++) s[i] = new T[4];
  T **a = new T *[lstr];
  for (i = 0; i < lstr; i++) a[i] = new T[2];
  cout << "Enter matrix: ";
  for (i = 0; i < lstr; i++)
    for (j = 0; j < 2; j++) cin >> a[i][j];
  for (i = 0; i < lstr; i++)
    for (j = 0; j < 2; j++) cout << setw(4) << a[i][j] << "  ";
  double const pi = 3.1456;
  T x1, x2, x3, y1, y2, y3, ma, mb, x, y;
  for (i = 0; i < lstr - 2; i++)
    for (j = i + 1; j < lstr - 1; j++)
      for (int k = j + 1; k < lstr; k++) {
        x1 = a[i][0], y1 = a[i][1], x2 = a[i + 1][0], y2 = a[i + 1][0],
        x3 = a[i + 3][0], y3 = a[i + 3][0];
        ;
        ma = (y1 - y2) / (x2 - x1), mb = (y3 - y2) / (x3 - x2);
        if (mb - ma == 0)
          break;
        x = (ma * mb * (y1 - y3) + mb * (x1 + x2) - ma * (x2 + x3)) / 2 *
            (mb - ma);
        y = (-1) * (x - (x1 + x2) / 2) / ma + (y1 + y2) / 2;
        T r = (T)sqrt(double((x1 - x) * (x1 - x) - (y1 - y) * (y1 - y)));
        double SC = pi * r * r;
        T ST = ((x1 - x3) * (y2 - y3) - (x2 - x3) * (y1 - y3)) / 2.0;
        for (int f = 0; f < lstr; f++) {
          s[f][0] = f;
          s[f][1] = SC;
          s[f][3] = ST;
          s[f][4] = SC - ST;
        }
        for (int f = 0; f < lstr; f++)
          for (int g = 0; g < 4; g++)
            cout << setw(4) << s[f][g] << "  "<<endl;
      }
  for (j = lstr - 1; j > 0; j--)
    for (i = 0; i < j; i++)
      if (s[i + 1][4] < s[i][4]) {
        T *min = s[i];
        s[i] = s[i + 1];
        s[i + 1] = min;
      }
  for (i = 0; i < lstr; i++)
    for (j = 0; j < 4; j++) cout << setw(4) << s[i][j] << "  ";
  cout << endl;
}
int main() {
  int lstr, x;
  cout << "Enter lstr strings" << endl;
  cin >> lstr;
  double **s2, **a2;
  func(lstr, a2, s2);
  return 0;
}

;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
/*                                                  */
/*               Пояснение к работе 😊             */
/*                                                  */
/* Сложно что-то сказать по поводу задачи,          */
/* я не смог придумать крутой алгоритм              */
/* решения, поэтому функция имеет сложность         */
/* как при брутфорсе O(!(max(1,N-3)))               */
/* где N это кол-во точек на ввод                   */
/*                                                  */
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
