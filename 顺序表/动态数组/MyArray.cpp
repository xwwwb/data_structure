#include "MyArray.h"

void MyArray::_clear()
{
  if (pArr)
  {
    delete[] pArr;
    pArr = NULL;
    capacity = size = 0;
  }
}

MyArray::MyArray(const MyArray &a)
{
  capacity = a.capacity;
  size = a.size;
  if (capacity)
  {
    pArr = new int[capacity];
    memcpy(pArr, a.pArr, sizeof(int) * size);
  }
}

void MyArray::push(int data)
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
    int *pNew = new int[capacity];
    if (pArr)
    {
      memcpy(pNew, pArr, sizeof(int) * size);
      delete[] pArr;
    }
    pArr = pNew;
  }
  pArr[size++] = data;
}

void MyArray::travel()
{
  cout << "MyArray capacity:" << capacity << " size:" << size << " :";
  for (int i = 0; i < size; i++)
  {
    cout << pArr[i] << " ";
  }
  cout << endl;
}