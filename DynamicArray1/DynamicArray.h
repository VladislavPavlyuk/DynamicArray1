#pragma once

class DynamicArray
{
public:
    DynamicArray();
    ~DynamicArray();

    //Конструктор копирования
    DynamicArray(const DynamicArray& obj);
    DynamicArray operator=(const DynamicArray& obj);

    void Add(int value);
    void RemoveAt(int index);
    void Print();

private:
    int* _array;
    size_t _size;
};
