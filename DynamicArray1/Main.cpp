#include <iostream>
#include "DynamicArray.h"
using namespace std;

void Foo(DynamicArray array)
{
    array.Print();
} //локальные параметры удаляются (вызов деструктора)


DynamicArray Bar()
{
    DynamicArray array;
    array.Add(100);
    array.Add(200);
    array.Add(300);

    return array; // копирование во временный объект, 
                  // а затем вызов деструктора для локального параметра
}

int main()
{
    DynamicArray array;
    array.Add(1);
    array.Add(2);
    array.Add(3);
    array.Add(4);
    array.Print();

    array.RemoveAt(2);
    array.Print();

    //Конструктор копирования вызывается в следующих случаях:

    //1. При создании нового объекта на основе существующего
    DynamicArray array2 = array;
    array2.Add(100);
    array2.Print();

    //2. При передаче в функцию по значению
    Foo(array); 

    //3. При возврате из функции по значению.
    // В точке вызова создается временный объект в который копируется возвращаемый из функции.
    Bar().Print();

    //оператор присваивания
    DynamicArray array3; //конструктор по умолчанию
    array3.Add(100);
    array3 = array; //array3.operator=(array)

    array = array;
}

