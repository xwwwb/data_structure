#include <iostream>
#include <string.h>
using std::cout;
using std::endl;
int *pArr;
int size;
void initMyArray();
void push(int data);
void travel();
int main()
{
    initMyArray();
    travel();
    push(8);
    travel();
    push(8);
    push(8);
    push(8);
    travel();
    return 0;
}
void initMyArray()
{
    pArr = NULL;
    size = 0;
}
void push(int data)
{
    int *pNew = new int[size + 1];
    if (pArr)
    {
        memcpy(pNew, pArr, sizeof(int) * size);
        delete[] pArr;
    }

    pArr = pNew;
    pArr[size++] = data;
}

void travel()
{
    cout << "MyArray:";
    for (int i = 0; i < size; i++)
    {
        cout << pArr[i] << " ";
    }
    cout << endl;
}
