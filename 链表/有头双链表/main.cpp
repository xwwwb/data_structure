#include "MyList.h"

int main()
{
  MyList<int> List;
  List.push_front(1);
  List.push_front(5);
  List.push_front(6);
  List.travel();
  List.clear((size_t)3);
  List.travel();
  return 0;
}