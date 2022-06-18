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
  void push_back(const T &data);
  void push_front(const T &data);
  // 插入到下标为pos的元素之后
  void insertByPos(const T &data, size_t pos);
  // 插入到数据为findData的元素之后
  void insertByData(const T &insertData, const T &findData);
  void travel();

private:
  void _clear();

  // 从容器中找数据为findData的元素
  // 找到了返回其下标 没找到返回-1
  int _findData(const T &findData);
};

template <class T>
int MyArray<T>::_findData(const T &findData)
{
  for (int i = 0; i < size; i++)
  {
    if (findData == pArr[i])
      return i;
  }
  return -1;
}

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
void MyArray<T>::push_back(const T &data)
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
void MyArray<T>::push_front(const T &data)
{
  if (size >= capacity)
  {
    capacity = capacity +
               (((capacity >> 1) > 1)
                    ? (capacity >> 1)
                    : 1);
    T *pNew = new T[capacity];
    if (pArr)
    {
      memcpy(pNew + 1, pArr, sizeof(T) * size);
      delete[] pArr;
    }
    pArr = pNew;
    pArr[0] = data;
    size++;
  }
  else
  {
    // 挪一下数据
    // 从后往前挪

    // for (int i = size - 1; i >= 0; i--)
    // {
    //   pArr[i + 1] = pArr[i];
    // }

    T *pTemp = new T[size];
    memcpy(pTemp, pArr, sizeof(T) * size);
    memcpy(pArr + 1, pTemp, sizeof(T) * size);
    delete[] pTemp;

    pArr[0] = data;
    size++;
  }
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

template <class T>
void MyArray<T>::insertByPos(const T &insertData, size_t pos)
{
  int ret = pos;
  if (ret == -1)
  {
    push_back(insertData);
  }
  else if (ret == 0)
  {
    push_front(insertData);
  }
  else
  {
    //插入到下标为pos的元素之后
    if (size >= capacity)
    {
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
    for (int i = size - 1; i >= ret; i--)
    {
      pArr[i + 1] = pArr[i];
    }
    pArr[ret + 1] = insertData;
    size++;
  }
}

template <class T>
void MyArray<T>::insertByData(const T &insertData, const T &findData)
{
  // 1. 找数据 可能存在找不到的情况
  int ret = _findData(findData);
  if (-1 == ret)
  {
    this->push_back(insertData);
  }
  else if (0 == ret)
  {
    push_front(insertData);
  }
  else
  {
    if (size >= capacity)
    {
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

    // 原 1 2 3 4 5 6
    // ret = 1
    // i>=ret
    //
    // 1 2 2 3 3 4 5
    // i >ret
    // 1 2 3 3 3 4 5
    // 中间差了一个
    // pArr[2]=pArr[1]
    // 但是这个位置搬不搬都会被pArr[ret+1]覆盖
    // 所以不搬更好 推荐用 > 而不是 >=
    for (int i = size - 1; i > ret; i--)
    {
      pArr[i + 1] = pArr[i];
    }
    pArr[ret + 1] = insertData;
    // size这里用于遍历和比较capacity 放在这里或者放前面都行
    // 放后面的话 在前面调用travel size会少一个
    size++;
  }
}