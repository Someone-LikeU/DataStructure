#include "listArray.h"
#include <cstdio>
#include <iostream>
using namespace std;
int main()
{
    int t4[] = {10,20,30,40,50,60,70,80,90,100};
    int t5[] = {1,2,3,4,5,6,7,8,9,10,20,30,40,50,60};
    int t52[] = {10,20,30,40,50,60,70,80,90,100};
    int t6[] = {1,3,6,10,15,16,17,18,19,20};
    int t62[] = {1,2,3,4,5,6,7,8,9,10,18,20,30};
    seqList L1, L2, L3;
    int
    //�Ƚ��������ʼ��
    InitialList( L1 );
    InitialList( L2 );
    InitialList( L3 );
    printf("��������ԣ�");
    int x = 25;
    for ( int i = 0 ; i < 10 ; i++ )
    {
        L1.data[i] = t4[i];
        L1.listLen++;
    }
    printf("����ǰ:\n");
    for ( int i = 0 ; i < L1.listLen ; i++ )
    {
        printf("%3d ",L1.data[i]);
    }
    OrderInsert( L1, x );
    printf("\n�����\n");
    for ( int i = 0 ; i < L1.listLen ; i++ )
    {
        printf("%3d ",L1.data[i]);
    }

    return 0;
}
