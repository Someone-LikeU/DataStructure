#include "StackArray.h"
#include "StackLink.h"
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <queue>
#include <stack>
using namespace std;

int main()
{
    int n, mode, i, choose, ars, *arr;
    queue<int> Q;
    queue<int> Q2;
    stack<int> S1;
    mode = 16;
    char s[80];
    while(true)
    {
        printf("***********************************************\n");
        printf("���Ժ���\n");
        printf("*1.˳��ջʵ�ֽ���ת����\n");
        printf("*2.˳��ջ�жϱ��ʽ�е������Ƿ�ƥ�䡣\n");
        printf("*3.��ջʵ�ֽ���ת����\n");
        printf("*4.��ջ�жϱ��ʽ������ƥ�䡣\n");
        printf("*5.��չ��1.\n");
        printf("*6.��չ��2.\n");
        printf("*7.��չ��3\n");
        printf("*8.�˳�\n");
        printf("***********************************************\n");
        printf("��ѡ��");
        scanf("%d",&choose);
        while (choose > 8 || choose < 1)
        {
            printf("ѡ���������ѡ: ");
            scanf("%d",&choose);
        }
        switch(choose)
        {
        case 1:
             for ( i = 0 ; i < 4 ; i++)
            {
                printf("��%d����ԣ�\n",i + 1);
                printf("����������ת������\n");
                scanf("%d",&n);
                ChangeScale(n,mode);
            }
            break;

        case 2:
            printf("������һ���������ʽ��������79���ַ�����\n");
            scanf("%s",s);
            if(IsMatch(s))//5+{10-[6*(2+8)}
            {
                printf("�ñ��ʽ�е�����ƥ�䡣\n");
            }
            else                        //5+{6+7*[5*(1+2)]
            {
                printf("�ñ��ʽ�е����Ų�ƥ�䡣\n");
            }
            break;

        case 3:
            for ( i = 0 ; i < 4 ; i++)
            {
                printf("��%d����ԣ�\n",i + 1);
                printf("������Ҫת��������");
                scanf("%d",&n);
                LinkChangeScale(n, mode);
            }
            break;

        case 4:
            printf("������һ���������ʽ��������79���ַ�����\n");
            scanf("%s",s);
             if(LinkIsmatch(s))//5+{10-[6*(2+8)}
            {
                printf("�ñ��ʽ�е�����ƥ�䡣\n");
            }
            else                        //5+{6+7*[5*(1+2)]
            {
                printf("�ñ��ʽ�е����Ų�ƥ�䡣\n");
            }
            break;

        case 5: //done at 11.21   15.04��
            printf( "���������г��ȣ�");
            scanf("%d",&ars);
            arr = new int (sizeof(int) * ars);
            printf("������������У�\n");
            for ( i = 0 ; i < ars ; i++ )
            {
                scanf("%d",&arr[i]);
            }
            if(IsSeqValid(arr, ars))
            {
                cout << "�����кϷ�\n";
            }
            else
            {
                cout << "�����в��Ϸ�\n";
            }
            break;

        case 6:         //ok

            printf("������һ�����У���#������\n");
            while (scanf("%d",&n) == 1)
            {
                Q.push(n);
            }
            printf("���������кϷ����ջ����Ϊ��\n");
            AllValidSeq(Q, S1, Q2);
            break;

        case 7:
            cout << "������һ�����ʽ����#�������루������79���ַ�����";
            scanf("%s",s);
            cout << "��������" << CalculateExpression(s) << endl;
            break;

        default :
            break;
        }
        system("pause");
        system("CLS");
        fflush(stdin);
    }
    return 0;
}
