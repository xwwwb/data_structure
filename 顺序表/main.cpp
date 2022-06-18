#include "MyArray.h"
#include <string>
int main()
{
  MyArray<int> arr;
  // MyArray<double> darr;
  // MyArray<string> sarr;
  // for (int i = 0; i < 10; i++)
  // {
  //   arr.push_back(i);
  //   arr.travel();
  // }
  // for (int i = 0; i < 10; i++)
  // {
  //   darr.push_back(i + 0.1);
  //   darr.travel();
  // }
  // for (int i = 0; i < 10; i++)
  // {
  //   sarr.push_front(to_string(i));
  //   sarr.travel();
  // }

  arr.push_back(1);
  arr.push_back(2);
  arr.push_back(3);
  arr.push_back(4);
  arr.push_back(5);
  arr.push_back(6);
  arr.insertByPos(3, 3);
  arr.travel();
  arr.insertByData(9, 2);
  arr.travel();
  arr.insertByData(0, 1);
  arr.travel();
  arr.insertByPos(0, 0);
  arr.travel();
  arr.insertByPos(4, 2);
  arr.travel();
  return 0;
}