#pragma once
#include <iostream>
using namespace std;

// 无头单链表
template <class T>
class MyList
{
  class Node
  {
  public:
    T data;
    Node *pNext;
    Node()
    {
      pNext = NULL;
    }
    Node(const T &data)
    {
      this->data = data;
      pNext = NULL;
    }
    // 拷贝构造
    Node(const Node &n)
    {
      this->data = n.data;
      this->pNext = n.pNext;
    }
    ~Node()
    {
    }
  };

private:
  Node *pHead; // 头节点
  // Node *pTail; // 尾节点
  // size_t len;  // 长度

public:
  // 构造函数
  MyList()
  {
    pHead = NULL;
  }
  // 析构函数
  ~MyList()
  {
    clear();
  }
  // 清空全部
  void clear()
  {
    _clear();
  }
  void clear(Node *pDeleteNode);
  void clear(const T &delData);
  void clear(size_t pos);

  // 增加节点
  void push_front(const T &insertData);
  void push_back(const T &insertData);
  void insert(const T &insertData, const T &findData);
  void insert(const T &insertData, size_t pos);
  // 遍历节点
  void travel()
  {
    _travel(pHead);
  }

private:
  // 循环删除每一个节点
  void _clear(){

  };
  // 从某个位置开始遍历
  void _travel(Node *pTemp);
  // 找到尾节点
  Node *_findNode(Node *pTemp, Node *pFind = NULL);
  // 数据转指针
  Node *_data2ptr(Node *pTemp, const T &data);
  // 位置转指针
  Node *_pos2ptr(Node *pTemp, size_t pos);
};

template <class T>
void MyList<T>::push_front(const T &insertData)
{
  Node *pNew = new Node(insertData);
  pNew->pNext = pHead;
  pHead = pNew;
}

template <class T>
void MyList<T>::push_back(const T &insertData)
{
  Node *pTail = _findNode(pHead);
  Node *pNew = new Node(insertData);
  // 注意要判断是不是第一个节点
  if (pTail)
  {
    pTail->pNext = pNew;
  }
  else
  {
    pHead = pNew;
  }
}

template <class T>
void MyList<T>::insert(const T &insertData, const T &findData)
{
  // 找到数据为 findData的节点
  Node *pFind = _data2ptr(pHead, findData);

  if (NULL == pFind)
    return; // 如果找不到 直接放弃插入
  Node *pNew = new Node(insertData);
  pNew->pNext = pFind->pNext;
  pFind->pNext = pNew;
}

template <class T>
void MyList<T>::insert(const T &insertData, size_t pos)
{
  Node *pFind = _pos2ptr(pHead, pos);

  if (NULL == pFind)
    return; // 如果找不到 直接放弃插入
  Node *pNew = new Node(insertData);
  pNew->pNext = pFind->pNext;
  pFind->pNext = pNew;
}

template <class T>
void MyList<T>::_travel(Node *pTemp)
{
  cout << "list:";
  while (NULL != pTemp)
  {
    cout << pTemp->data << " ";
    pTemp = pTemp->pNext;
  }
  cout << endl;
}

template <class T>
typename MyList<T>::Node *MyList<T>::_findNode(Node *pTemp, Node *pFind)
{
  if (NULL == pTemp)
    return NULL;
  while (pTemp->pNext != pFind)
  {
    pTemp = pTemp->pNext;
  }
  return pTemp;
}

template <class T>
typename MyList<T>::Node *MyList<T>::_data2ptr(Node *pTemp, const T &data)
{
  if (NULL == pTemp)
    return NULL;
  while (pTemp)
  {
    if (data == pTemp->data)
    {
      return pTemp;
    }
    pTemp = pTemp->pNext;
  }
  return NULL;
}

template <class T>
typename MyList<T>::Node *MyList<T>::_pos2ptr(Node *pTemp, size_t pos)
{
  if (NULL == pTemp)
    return NULL;

  for (size_t i = 0; i < pos; i++)
  {
    if (pTemp == NULL)
      return NULL;
    pTemp = pTemp->pNext;
  }

  return pTemp;
}

template <class T>
void MyList<T>::clear(size_t pos)
{
  if (pHead == NULL)
    return; // 空链表 不删

  Node *pDel = pHead;
  if (0 == pos)
  {
    pHead = pHead->pNext;
    delete pDel;
    return;
  }
  pDel = _pos2ptr(pHead, pos);
  if (NULL == pDel)
    return;

  Node *pDelPret = _pos2ptr(pHead, pos - 1);
  pDelPret->pNext = pDel->pNext;
  delete pDel;
}