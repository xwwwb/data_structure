#include "MyArray.h"
#include <string>
int main()
{
  MyArray<int> arr;
  MyArray<double> darr;
  MyArray<string> sarr;
  for (int i = 0; i < 10; i++)
  {
    arr.push_back(i);
    arr.travel();
  }
  for (int i = 0; i < 10; i++)
  {
    darr.push_back(i + 0.1);
    darr.travel();
  }
  for (int i = 0; i < 10; i++)
  {
    sarr.push_front(to_string(i));
    sarr.travel();
  }
  return 0;
}