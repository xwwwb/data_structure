#include <iostream>
#include <cstring>
#include <string>
using namespace std;

template <class T>
class MyArray
{
  T *pArr;
  int size;
  int capacity;

public:
  // 构造
  MyArray()
  {
    pArr = NULL;
    capacity = size = 0;
  }
  // 析构
  ~MyArray()
  {
    _clear();
  }
  // 拷贝构造
  MyArray(const MyArray &a);
  // 成员函数
  void push(T data);
  void travel();

private:
  void _clear();
};

template <class T>
void MyArray<T>::_clear()
{
  if (pArr)
  {
    delete[] pArr;
    pArr = NULL;
    capacity = size = 0;
  }
}

template <class T>
MyArray<T>::MyArray(const MyArray<T> &a)
{
  capacity = a.capacity;
  size = a.size;
  if (capacity)
  {
    pArr = new T[capacity];
    memcpy(pArr, a.pArr, sizeof(T) * size);
  }
}

template <class T>
void MyArray<T>::push(T data)
{
  // 判断是否需要开空间
  if (size >= capacity)
  {
    // 计算新开空间大小
    // 0.5倍大于1 加0/5倍 如果不大于一 加1
    // 这里括号要打上 如果不打最外层 会出现优先级问题
    // 抽时间学习优先级
    capacity = capacity +
               (((capacity >> 1) > 1)
                    ? (capacity >> 1)
                    : 1);
    T *pNew = new T[capacity];
    if (pArr)
    {
      memcpy(pNew, pArr, sizeof(T) * size);
      delete[] pArr;
    }
    pArr = pNew;
  }
  pArr[size++] = data;
}

template <class T>
void MyArray<T>::travel()
{
  cout << "MyArray capacity:" << capacity << " size:" << size << " :";
  for (int i = 0; i < size; i++)
  {
    cout << pArr[i] << " ";
  }
  cout << endl;
}