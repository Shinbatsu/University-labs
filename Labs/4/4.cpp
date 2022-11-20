// Фомичев Андрей Михайлович, II Вариант
// ЛР4

/*
1 Найти сумму положительных элементов.
2 Найти произведение элементов массива,
расположенных между максимальным по
модулю и минимальным по модулю элементами.
3 Упорядочить элементы массива по убыванию
*/

#include <iostream>
#include <algorithm>
#include <cfloat>
using namespace std;

const int S = 8; // Размер массива

// Cумма положительных элементов
double SP_(double *n)
{
  auto R = 0;
  for (int i = 0; i<S; R += n[i]> 0 ? n[i] : 0, i++)
    ;
  return R;
}
int main()
{
  // Сортировка в массиве
  auto SR_ = [](auto n)
  {
    sort(n, n + S, [](int a, int b)
         { return (a > b); });
  };
  auto MR_ = [](double *n, double R = 1.0)
  {
    // Нахождение минимума в массиве
    auto MA_ = [](double *n)
    { 
      double R = DBL_MIN;  
      auto res = -1;
      for (auto i =0; i<S;abs(n[i])> R ? R = abs(n[i]),res = i:-0,i++);
      return res; };

    // Нахождение минимума в массиве
    auto MI_ = [](double *n)
    {
      double R = DBL_MAX;
      auto res = -1;
      for (auto i = 0; i < S; i++)
        abs(n[i]) < R ? R = abs(n[i]), res = i : 0;
      return res;
    };
    // absMin -> Минимум по модулю
    // absMax -> Максимум по модулю
    int absMin = MI_(n), absMax = MA_(n);
    for (auto i = min(absMin, absMax); i < max(absMin, absMax); R *= n[i], i++)
      ;
    return R;
  };
  double arr[] = {1, 2, 6, 89, 324, 6, 2, 4};
  cout << MR_(arr) << endl;
  system("PAUSE");
  return 0;
}

/*===========================================================*/

/*===========================================================*/
/*                                                           */
/*               Пояснение к работе 😊                      */
/*                                                           */
/* R - результат работы функции                              */
/*                                                           */
/* S - Константа, размер входного массива (равна 8ми)        */
/*                                                           */
/* SP_ - Функция выполняет задание 1                         */
/* Простой for с проверкой на положительность(>0) и          */
/* Соответствующим суммирование этих элементов               */
/*                                                           */
/* MR_ - Функция выполняет задание 2                         */
/* Поиск минимального и максимального по модулю выполнен     */
/* с помощью двух lambda функций MI_ и MA_ соответственно    */
/* Результат этих функций выступает как начало и конец       */
/* цикла, которые вычисляет произведение элементов диапазона.*/
/*                                                           */
/* SR_ - Функция выполняет задание 3                         */
/* Сортировка выполняется с помощью функции sort             */
/* в нее передаются указатели на начало и конец              */
/* последоввательности, третий аргумент это                  */
/* функция которая сравнивает элементы исортирует            */
/*                                                           */
/* Результат работы "main" - задание 2(самое интересное)     */
/*                                                           */
/*===========================================================*/
/*===========================================================*/

//      #include < iostream>
//       #include < cfloat>
//       #include < chrono>
//       typedef double  d;
//       typedef   int  int;
//      using namespace std;
//      #include <algorithm>
//      int S=0x0a-2;d SP_(d
//      *n) { auto R=- - -0;
//      for(auto i=- - -0;i<
//    S;  R += n[i] > - - -0?n
//  [ i]:0,_++);return R ; } int
//  main( ) { auto G =  chrono::
//  steady_clock::now();auto SR_
//  =[]( auto n ){sort(n,n+S,[](
//  int a, int b ){return( a> b)
//  ;} );}; auto MR_=[](d *n,d R
//  =  1.0  ){ auto MA_=[](d *n)
//  { d R=DBL_MIN;auto res=-1e1;
//  for (auto i=- - -0;i<S;abs (
//  n[i])>R?R=abs(n[i]),res=_:0,
//  _++);return res;};auto MI_=[
//  ](d *n){d R=DBL_MAX;auto res
//  = -1e1; for (auto i= 0; _<S;
//  _++)abs(n[i])<R?R=abs(n[i]),
//  res =_:0;return res;};i1 t1=
//  MI_(n),t2=MA_(n);for(auto i=
//  min(t1,t2);i<max(t1,t2) ;R*=
//  n [i] , _++ ); return R ; };
//  d arr[]={1,rand()%50,-rand()
//  % 50,-0x217,rand()%50,rand()
//  % 50,74.0,-5};cout<<MR_(arr)
//  <<endl<<chrono::steady_clock
//  ::now()-G;return 11&&0x000;}
