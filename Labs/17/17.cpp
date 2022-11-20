// Фомичев Андрей Михайлович, II Вариант
// ЛР17

/*
Создание шаблона класса "стек". 
Использоввать его при решении 
задачи варианта 7 лабораторной 
работы № 14.
*/

// P.S. На aнглийской винде лаба не компилится
// из-за цыганского названия файла.cpp

#include <iostream>
#include <string>
#include <vector>
#include <stack>

const int SIZE=8;
using namespace std;

  bool path_finder(string maze)
  {
    vector<string> temp;
    string t = "";
    for (size_t i = 0; i < maze.length(); i++)
      if (maze[i] == '\n')
        temp.push_back(t), t.clear();
      else
        t.push_back(maze[i]);
    if (!t.empty())
      temp.push_back(t);
    vector<vector<char>> table;
    for (string &ele : temp)
    {
      vector<char> t;
      for (size_t i = 0; i < ele.length(); i++)
        t.push_back(ele[i]);
      table.push_back(t);
    }
    int M = table[0].size() - 1;
    stack<pair<int, int>> st;
    st.push({0, 0});
    bool visited[SIZE + 1][SIZE + 1];
    for (int i = 0; i <= M; i++)
      for (int j = 0; j <= M; j++)
        visited[i][j] = false;
    while (!st.empty())
    {
      pair<int, int> ele = st.top();
      int x = ele.first;
      int y = ele.second;
      st.pop();
      if (x == M && y == M)
        return true;
      if (visited[x][y])
        continue;
      visited[x][y] = true;
      if ((x <= M && y + 1 <= M) && table[x][y + 1] == '.' && !visited[x][y + 1])
        st.push({x, y + 1});
      if ((x >= 0 && y - 1 >= 0) && table[x][y - 1] == '.' && !visited[x][y - 1])
        st.push({x, y - 1});
      if ((x - 1 >= 0 && y >= 0) && table[x - 1][y] == '.' && !visited[x - 1][y])
        st.push({x - 1, y});
      if ((x + 1 <= M && y <= M) && table[x + 1][y] == '.' && !visited[x + 1][y])
        st.push({x + 1, y});
    }
    return false;
  }

;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
/*                                                        */
/*               Пояснение к работе 😊                   */
/*                                                        */
/* 14-ая Работа: Выполнил задачу 7го варианта             */
/* с использованием класс stack, работа выполнена         */
/* с некоторыми модификациями, общая суть работы          */
/* не изменилась(применить класс stack при решении)       */
/* поэтому я позволил себе вместо возвращения массива     */
/* координат до выхода, выводить булевок значение         */
/* наличия пути к выходу, а также слегка упростил задачу  */
/* зафиксировав положение начала в точке (0,0) и          */
/* обозначив точку выхода в координатах (N-1,N-1)         */
/*                                                        */
/* Решено посредством использования волнового алгоритма.  */
/*                                                        */
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
