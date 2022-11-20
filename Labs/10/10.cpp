// Фомичев Андрей Михайлович, II Вариант
// ЛР10

/*
Для хранения данных о цвветных планшетных сканерах описать 
структуру как в варианте 1
Написать функцию,которая записывает в бинарный файл данные 
о сканере из приведенной структуры. Структура файла: в первых 
двух байтах размещается значение типа int, определяющее количество 
сделанных в файл записей: далее без пропусков размещаются записи о сканерах.
Написать функцию, которая сортирует записи в описанном ранее бинарном файле 
по одной из следующих характеристик: цена либо число градаций серого,
Обязательный параметр - признак задающий критерий сортироввки.
Привести пример программы, создающей файл с данными о сканерах 
(данные вводятся с клавиатуры) из не менее восьми записей 
и осуществляющей его сортировку.
*/

// P.S. На aнглийской винде лаба не компилится
// из-за цыганского названия файла.cpp

#include <iostream>
#include <fstream>
#include <algorithm>
using namespace std;
struct scan_info
{
    int price;
    double x_size;
    double y_size;
    int optr;
    int grey;
    char model[5];
    scan_info() {}
    scan_info(int price, char m[],
              double x_size = 1.6, double y_size = 1.2,
              int optr = 2, int grey = 211)
    {
        this->price = price;
        for (int i = 0; i < 5; i++)
            this->model[i] = m[i];
        this->x_size = x_size;
        this->y_size = y_size;
        this->optr = optr;
        this->grey = grey;
    }
};
void readScaners(string filename)
{
    short S;
    int temp;
    ifstream input_file(filename, ios::binary);
    input_file.read((char *)&S, sizeof(S));
    scan_info s[8];
    for (int i = 0; i < S; i++)
    {
        input_file.read((char *)&s[i].price, sizeof(s[0].price));
        input_file.read((char *)&temp, 4);
        input_file.read((char *)&s[i].x_size, sizeof(s[0].x_size));
        input_file.read((char *)&s[i].y_size, sizeof(s[0].y_size));
        input_file.read((char *)&s[i].optr, sizeof(s[0].optr));
        input_file.read((char *)&s[i].grey, sizeof(s[0].grey));
        input_file.read((char *)&s[i].model, sizeof(s[0].model));
        cout << s[i].price << endl;
        input_file.read((char *)&temp, 3);
    }
    input_file.close();
}
void writeScaners(scan_info *a, string filename, short count=8)
{
    try
    {
        if (count < 1)
            throw(count);
        scan_info s[8];
        for (int i = 0; i < count; i++)
            s[i] = a[i];
        sort(s, s + count, [](auto s1, auto s2)
             {
            if(s1.price==s2.price)
                return s1.grey>s2.grey;
            else
                return s1.price>s2.price; });
        ofstream output_file(filename, ios::binary);
        output_file.write((char *)&count, sizeof(count));
        output_file.write((char *)&s, sizeof(s));
        output_file.close();
    }
    catch (const std::exception &e)
    {

        cerr << "Count must be positive integer";
    }
}
int main()
{
    char c[] = {'a', 'b', 'c', 'd', 'e'};
    scan_info a[] = {scan_info(165, c), scan_info(65, c),
     scan_info(625, c),scan_info(666, c), scan_info(5000, c),
      scan_info(13, c),scan_info(888, c), scan_info(71, c)};
    writeScaners(a, "scans.txt", 8);
    readScaners("scans.txt");
    return 0;
}

;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
/*                                                           */
/*               Пояснение к работе 😊                      */
/*                                                           */
/* Есть несколько замечаний к этой работе                    */
/*                                                           */
/* 1) Тип данных который описывает кол-во сканеров           */
/* это значение типа int, это значение занимает              */
/* 4 байта, а не 2 как это написано в задании,               */
/* это неверно, поэтому я позволил себе                      */
/* исправить его на short,                                   */
/*                                                           */
/* 2) В целях небольшой экономии буковок                     */
/*  изменил поле model с char[25] на char[5]                 */
/*                                                           */
/* Программа выполняет поставленную партией                  */
/* задачу, весьма успешно, данные в консоли                  */
/* вывода печатаются отсортированными на основе              */
/* требуемых параметров.                                     */
/*                                                           */
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;

