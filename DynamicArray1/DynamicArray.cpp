#include "DynamicArray.h"
#include <iostream>
using namespace std;

DynamicArray::DynamicArray()
{
    // cout << "Constructor" << endl;
    _array = nullptr;
    _size = 0;
}

DynamicArray::~DynamicArray()
{
    //cout << "Destructor" << endl;
    if(_array != nullptr)
        delete[] _array;
}

//Конструктор копирования
DynamicArray::DynamicArray(const DynamicArray& obj)
{
    _array = new int[obj._size];
    _size = obj._size;

    for (size_t i = 0; i < _size; i++)
    {
        _array[i] = obj._array[i];
    }
}
//оператор присваивания всегда перегружается как метод класса
DynamicArray DynamicArray::operator=(const DynamicArray& obj)
{
    if (this == &obj) //проверка на самоприсваивание
        return *this;

    if (_array != nullptr)
        delete[] _array; //удаление старых данных, если они были

    _array = new int[obj._size];
    _size = obj._size;

    for (size_t i = 0; i < _size; i++)
    {
        _array[i] = obj._array[i];
    }

    return *this;
}


void DynamicArray::Add(int value)
{
    int* tmp = new int[_size + 1];

    for (size_t i = 0; i < _size; i++)
    {
        tmp[i] = _array[i];
    }

    tmp[_size] = value;

    delete[] _array;
    _array = tmp;
    _size++;
}

void DynamicArray::RemoveAt(int index)
{
    int* tmp = new int[_size - 1];

    for (size_t i = 0; i < index; i++)
    {
        tmp[i] = _array[i];
    }

    for (size_t i = index; i < _size - 1; i++)
    {
        tmp[i] = _array[i + 1];
    }

    delete[] _array;
    _array = tmp;
    _size--;
}

void DynamicArray::Print()
{
    for (size_t i = 0; i < _size; i++)
    {
        cout << _array[i] << "\t";
    }
    cout << "\n";
}