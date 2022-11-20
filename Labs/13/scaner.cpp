#include "scaner.h"
#include <bits/stdc++.h>
#include <fstream>
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
    scan_info s[S];
    for (int i = 0; i < S; i++)
    {
        input_file.read((char *)&s[i].price, sizeof(s[0].price));
        input_file.read((char *)&temp, 4);
        input_file.read((char *)&s[i].x_size, sizeof(s[0].x_size));
        input_file.read((char *)&s[i].y_size, sizeof(s[0].y_size));
        input_file.read((char *)&s[i].optr, sizeof(s[0].optr));
        input_file.read((char *)&s[i].grey, sizeof(s[0].grey));
        input_file.read((char *)&s[i].model, sizeof(s[0].model));
        cout << s[i].model << endl;
        input_file.read((char *)&temp, 3);
    }
    input_file.close();
}
void writeScaners(scan_info *a, string filename, short count)
{
    try
    {
        if (count < 1)
            throw(count);
        scan_info s[count];
        for (int i = 0; i < count; i++)
            s[i] = a[i];
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