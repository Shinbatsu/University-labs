#pragma once
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
              int optr = 2, int grey = 211) {}
};
void readScaners(string filename);
void writeScaners(scan_info *a, string filename, short count);

