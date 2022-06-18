#include <iostream>
#include <cstring>
using std::cout;
using std::endl;

class MyArray
{
  int *pArr;
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
  void push(int data);
  void travel();

private:
  void _clear();
};
