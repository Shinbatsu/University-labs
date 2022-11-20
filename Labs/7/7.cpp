// Фомичев Андрей Михайлович, II Вариант
// ЛР7

/*
Описать структуру с именем STUDENT, содержащую следующие поля: 
фамилия и инициалы, номер группы, 
успеваемость(массив из пяти элементов). 
Написать программу, выполняющую следующие действия:
Задание 1:
Ввод с клавиатуры данных в массив, 
состоящий из пяти структур типа STUDENT;
Записи должны быть упорядочены 
по возрастанию среднего балла.
Задание 2:
Вывод на экран фамилий и номеров 
групп всех студентов, имеющих оценки 
4 и 5;если таких студентов нет,вывести 
соответствующее сообщение
*/

// P.S. На aнглийской винде лаба не компилится
// из-за цыганского названия файла.cpp

#include <vector>
#include <algorithm>
#include <string>
#include <iostream>
using namespace std;
struct STUDENT
{
    string name;
    string initials;
    int groupNumber;
    int notes[5];
};
typedef vector<STUDENT> vS;

bool R(int a[])
{
    for (int i = 0; i < 5; i++)
        if (a[i] == 4 || a[i] == 5)
            return true;
    return false;
}
void FS(vS a)
{
    vS res;
    for (int i = 0; i < a.size(); i++)
        if (R(a[i].notes))
            res.push_back(a[i]);
    if (res.size()==0)
        cout<<"Students with notes 4 or 5 not found";
    else
        for (int i = 0; i < res.size(); i++)
            cout << res[i].name << " " << res[i].groupNumber << endl;
}
int SM(int a[], double res = 0)
{
    for (auto i = 0; i < 5; i++)
        res += a[i];
    return res / 5;
};
vS SS(vS st)
{
    sort(st.begin(), st.end(), [](auto a, auto b)
         { return SM(a.notes) > SM(b.notes); });
    return st;
}
int main(int argc, char const *argv[])
{
    vS students;
    while (students.size() < 5)
    {
        STUDENT student;
        cout << "Type \"Name\" :" << endl;
        cin >> student.name;
        cout << "Type \"Initials\" :" << endl;
        cin >> student.initials;
        cout << "Type \"Group number\" :" << endl;
        cin >> student.groupNumber;
        for (int i = 0; i < 5; i++)
        {
            cout << "Type Notes" << endl;
            cin >> student.notes[i];
        }
        students.push_back(student);
    }
    SS(students);
    FS(students);
    return 0;
}

;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
/*                                                  */
/*               Пояснение к работе 😊             */
/*                                                  */
/* vS - vector<STUDENT>                             */
/*                                                  */
/* SS - Функция выполняет задание 1                 */
/* Простая функция сортировки sort с умной          */
/* функцией сортировки                              */
/*                                                  */
/* FS - Функция выполняет задание 2                 */
/* Печатает имя и группу студентов, которые         */
/* имеют среди оценок 4 или 5, если  таких          */
/* студентов не найдется, то выведет надпись:       */
/* "Students with notes 4 or 5 not found"           */
/*                                                  */
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;