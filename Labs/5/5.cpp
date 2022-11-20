// Фомичев Андрей Михайлович, II Вариант
// ЛР5

/*
Дана целочисленная прямоугольная матрица.Определить количество 
столбцов не содержащих ни одного нулевого элемента.
Характеристикой строки целочисленной матрицы назовем сумму ее 
положительных четных элементов. Переставляя строки заданной матрицы, 
расположите их в соответствии с ростом характеристики.
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef vector<vector<int>> vvi;

void CN(vvi a, int ctr = 0)
{
    cout << "TASK 1⤵" << endl;
    for (auto i = 0; i < a[0].size(); i++)
        for (auto j = 0; j < a.size(); j++)
            if (a[j][i] == 0)
            {
                ctr++;
                break;
            }
    cout << "Columns without zeros: "
         << a[0].size() - ctr << endl;
}

void SR(vvi a)
{
    cout << "TASK 2⤵" << endl
         << "Unsorted: " << endl;
    for (auto e : a)
    {
        for (auto t : e)
            cout << t << " ";
        cout << endl;
    } // Функция сортировки
    sort(a.begin(), a.end(), [](auto a, auto b)
         {
            auto F = [](auto t,int res = 0)
            {
            for (auto i = t.begin();
                        i!= t.end();
         // res - Кол-во положительных четных элементов
            res += ((*i) > 0 && (*i) % 2==0)?(*i):0,

            i++);
            return res;
            };
    return F(a) < F(b); });
    cout << "\nSorted:" << endl;
    for (auto e : a)
    {
        for (auto t : e)
            cout << t << " ";
        cout << endl;
    }
}

int main()
{
    vvi a = {{1, 2, 5, 6, 4},
             {1, 54, 7, 0, 2},
             {2, 5, 3, 7, 5},
             {1, 2, 5, 2, 1},
             {1, 0, 0, 0, 1}};
    CN(a);//Задание № 1⤵:
    cout << endl;
    SR(a);//Задание № 2⤵:
    system("PAUSE");
    return 0;
}
/*===========================================================*/
/*                                                           */
/*               Пояснение к работе 😊                      */
/*                                                           */
/* E - сокращение от endl                                    */
/*                                                           */
/* vvi - сокращение от vector<vector<int>>                   */
/*                                                           */
/* CN - Функция выполняет задание 1                          */
/* Перебор двухмерного массива с помощью for и проверка      */
/* Наличия нулей в колонке матрицы,если их нет, то считаем   */
/*                                                           */
/* SR - Функция выполняет задание 2                          */
/* Сортировка по ключу котоорый был описан в задаче          */
/* Для решения я использовал функцию sort, передал ей        */
/* ключ сортироввки третьим элементов                        */
/*                                                           */
/* Результат работы "main" - запуск 2-ух функций             */
/* описанных мной чуть выше                                  */
/*                                                           */
/*===========================================================*/