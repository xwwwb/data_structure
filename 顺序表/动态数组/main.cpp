#include "MyArray.h"

int main()
{
  MyArray<int> arr;
  arr.travel();
  for (int i = 0; i < 20; i++)
  {
    arr.push(i);
    arr.travel();
  }
  return 0;
}