#include "MyList.h"

int main()
{
  MyList<int> List;
  List.push_back(9);
  List.push_front(1);
  List.push_front(5);
  List.push_back(2);
  List.insert(8, 1);
  List.insert(999, 3); // 如果用插入到xx位置之后 这里不做类型转换 会出现二义性 触发插入到xxx数据后 找不到3就放弃插入了
  List.insert(999, (size_t)3);
  List.travel();
  List.clear((size_t)3);
  List.travel();
  return 0;
}