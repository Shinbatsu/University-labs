// Фомичев Андрей Михайлович, II Вариант
// ЛР16

/*
Создать абстрактный класс Point(точка). На его основе 
создать классы ColoredPoint и Line. На основе класса 
Line создать содать классы ColoredLine и PolyLine 
(многоугольник). Все классы должны иметь виртуальные 
методы установки и получения значений всех координат, 
а также изменения цвета и получения текущего цвета.

Создать класс Picture содержащий список (или массив) 
объектов этих классов в динамической памяти. 
Предусмотреть возможность вывода характеристик 
объектов списка. Написать демонстрационную программу,
в которой будут использоваться все методы классов.
*/

// P.S. На aнглийской винде лаба не компилится
// из-за цыганского названия файла.cpp

#include <vector>
#include <iostream>
typedef unsigned short ust;
using namespace std;
class Drawable
{
public:
    void virtual draw() = 0;
};
struct Color
{
private:
    ust r, g, b;

public:
    Color() : r(0), g(0), b(0) {}
    template <typename T>
    Color(T r, T g, T b) : r(min(r, 255)), g(min(g, 255)), b(min(b, 255)) {}
    void getColors()
    {
        cout << r << ", " << g << ", " << b;
    }
};
class Figure
{
    bool isFigure = true;
};
class IColored : public Drawable
{
private:
    Color color;

public:
    void setColor(Color clr)
    {
        this->color = clr;
    }
    Color *getColor()
    {
        return &color;
    }
    void draw()
    {
        cout << "Color is : ";
        this->getColor()->getColors();
    }
};

class Point : public Drawable, public Figure
{

private:
    double x, y;

public:
    void draw() override
    {
        cout << "Drawing a point with coodinates x: " << x << ", y: " << y << endl;
    }
    Point() : x(0), y(0) {}
    Point(double x, double y) : x(x), y(y) {}
    double getX() const { return x; }
    double getY() const { return y; }
    void setX(double x) { x = x; }
    void setY(double y) { y = y; }
};

class Line : public Drawable, public Figure
{
private:
    Point p1, p2;

public:
    void draw() override
    {
        cout << "Drawing a line where: " << endl;
        p1.draw();
        p2.draw();
        cout << endl;
    }
    Line() {}
    Line(Point &p1_, Point &p2_) : p1(p1_), p2(p2_) {}
    Point *getPoint1()
    {
        return &p1;
    }
    Point *getPoint2()
    {
        return &p2;
    }
    void setPoint1(Point &p) { p1 = p; }
    void setPoint2(Point &p) { p2 = p; }
};

class ColoredPoint : public Point, public IColored
{
    void draw() override
    {
        Point::draw();
        IColored::draw();
    }
    ColoredPoint() : Point()
    {
        this->setColor(Color());
    }
    ColoredPoint(double x, double y, Color color) : Point(x, y)
    {
        this->setColor(color);
    }
};

class ColoredLine : public Line, public IColored
{
public:
    void draw() override
    {
        Line::draw();
        IColored::draw();
    }
    ColoredLine() : Line()
    {
        this->setColor(Color());
    }
    ColoredLine(Point &p1_, Point &p2_, Color color) : Line(p1_, p2_)
    {
        this->setColor(color);
    }
};
class Polyline : public Drawable, public Figure
{
public:
    vector<Line> lines;
    Polyline(vector<Line> lines_)
    {
        for (int i = 0; i < lines_.size(); i++)
            this->lines.push_back(lines_[i]);
    }
    void draw() override
    {
        for (int i = 0; i < this->lines.size(); i++)
            this->lines[i].draw();
    }
};
class Picture: public Drawable
{
private:
    vector<Figure> elements;

public:
    Picture(vector<Figure> figures_)
    {
        this->elements = figures_;
    }
};
int main(int argc, char const *argv[])
{
    Point p1(2.5, 4);
    Point p2(6.5, 3);
    vector<Line> lines = {Line(p1, p2), Line(p1, p2), Line(p1, p2)};
    vector<Figure> figures = {Line(p1, p2), p1, p2};
    return 0;
}

;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
/*                                                  */
/*               Пояснение к работе 😊             */
/*                                                  */
/* При проектировании архитектуры у меня            */
/* появились некоторые вопросы к реализации         */
/* наследования, согласно классической задумке      */
/* этой задачи, требуется отнаследовать             */
/* ColoredLine от Line, однако в том случае         */
/* если мы будем производить манипуляции с цветом   */
/* мы можем нарушить принцип Барбары Лисков         */
/* soLid (Liskov substition principle)              */
/* поскольку родитель не сможет обеспечить          */
/* функционал потомка, например метод ChangeColor,  */
/* поэтому я предпринял решение вынести само        */
/* понятие цвета в структуру, и применять           */
/* его через Абстрактный класс, который             */
/* будет выступать в роли некоего интерфейса.       */
/* Также я решил что создание Базового класс        */
/* над всеми объектами является кощунством и        */
/* не несет в себе никакого положительного          */
/* эффекта, вместо этого я старался заменять        */
/* наследование композицией, я считаю что           */
/* это может убрать много дублирования кода         */
/* при расширении проекта, кроме прочего            */
/* пришлось использовать псевдобазовую              */
/* прослойку в виде класс Figure,я его создал       */ 
/* только для того, чтобы подружить все объекты     */
/* в одном массиве (Нужно было для задания 2).      */
/*                                                  */
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
