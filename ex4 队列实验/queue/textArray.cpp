#include "queueArray.h"
#include "queueLink.h"
#include <iostream>
#include <cstdlib>
#include <cstdio>
using namespace std;

int main()
{
    seqQueue SQ;
    LinkQueue LQ;
    int choose, num, i;
    bool exit = false;
    while ( !exit )
    {
        cout << "*******************************\n";
        cout << "*���в��Գ���˳�����Ĭ���������100����\n";
        cout << "*1.��ʼ��˳�����\n";
        cout << "*2.��ʼ��������\n";
        cout << "*3.�ж�˳����п�\n";
        cout << "*4.�ж������п�\n";
        cout << "*5.�ж�˳�������\n";
        cout << "*6.�ж���������\n";
        cout << "*7.˳��������\n";
        cout << "*8.���������\n";
        cout << "*9.˳����г���\n";
        cout << "*10.�����г���\n";
        cout << "*11.ȡ˳�����ͷ\n";
        cout << "*12.ȡ������ͷ\n";
        cout << "*13.��ǰ˳�����Ԫ�ظ���\n";
        cout << "*14.��ǰ������Ԫ�ظ���\n";
        cout << "*15.��8��˳����а�\n";
        cout << "*16.��8�������а�\n";
        cout << "*17.�˳�.\n";
        cout << "*******************************\n";
        cout << "*��ѡ��";
        scanf("%d",&choose);
        while ( choose < 1 || choose > 17)
        {
            cout << "�������룬������ѡ��.\n";
            cout << "��ѡ��: ";
            scanf("%d",&choose);
        }
        switch (choose)
        {
        case 1:
            InitialQueue(SQ);
            printf("��ʼ�����\n");
            break;

        case 2:
            InitLinkQueue(LQ);
            printf("��ʼ�����\n");
            break;

        case 3:
            if(IsQueueEmpty(SQ))
            {
                cout << "˳�����Ϊ��" << endl;
            }
            else
            {
                cout << "˳����в���" << endl;
            }
            break;

        case 4:
           if(IsLinkQueueEmpty(LQ))
           {
                cout << "������Ϊ��" << endl;
           }
           else
            {
                cout << "�����в���" << endl;
            }
            break;

        case 5:
            cout << "��һ����ԣ��������ݣ�ֱ��#�˳�\n";
            while(scanf("%d",&num) == 1)
            {
                if (IsQueueFull(SQ))    //�ȼ���Ƿ����
                {
                    printf("���������������\n");
                    break;
                }
                if(!EnQueue(&SQ, num))     //����Ӳ���
                {
                    cout << "��ӳɹ�" << endl;
                }
            }
            system("pause");
            InitialQueue(SQ);   //��ʼ����������һ�β���
            cout << "length:" << CoutElement(SQ);
            cout << "�ڶ���:" << endl;
            for ( i = 1 ; i < 100 ; i++ )
            {
                cout << "���" << i << endl;
                EnQueue(&SQ, i);
            }
            if(IsQueueFull(SQ))
            {
                cout << "˳�������" << endl;
            }
            break;

        case 6: //done at 23.17
            cout << "��һ����ԣ��������ݣ�ֱ��#�˳�\n";
            while(scanf("%d",&num) == 1)
            {
                if( IsLinkQueueFull( LQ ) )
                {
                    printf("���������������\n");
                    break;
                }
                EnLinkQueue(LQ, num);
            }
            break;

        case 7:
            cout << "�������ݣ�ֱ��#�˳�\n";
            while(scanf("%d",&num) == 1)
            {
                if (IsQueueFull(SQ))    //�ȼ���Ƿ����
                {
                    printf("���������������\n");
                    break;
                }
                EnQueue(&SQ, num);      //����Ӳ���
            }
            cout << "��ӳɹ�\n";
            break;

        case 8:
            cout << "�������ݣ�ֱ��#�˳�\n";
            while(scanf("%d",&num) == 1)
            {
                if(IsLinkQueueFull(LQ))
                {
                    printf("���������������\n");
                    break;
                }
                EnLinkQueue( LQ, num );
            }
            cout << "��ӳɹ�\n";
            break;

        case 9:
            if( IsQueueEmpty(SQ) )
            {
                cout << "�ӿգ��������" << endl;
                break;
            }
            GetQueueFront(SQ, num);
            DeQueue(&SQ);
            cout << "��ͷΪ" << num << ", ���Գɹ�\n";
            break;

        case 10:
            if(IsLinkQueueEmpty(LQ))
            {
                cout << "�ӿգ��������" << endl;
                break;
            }
            GetLinkQFront(LQ, num);
            DeLinkQueue(LQ);
            cout << "��ͷΪ" << num << ", ���ӳɹ�\n";
            break;

        case 11:
            if( IsQueueEmpty(SQ) )
            {
                cout << "�ӿգ��������" << endl;
                break;
            }
            GetQueueFront(SQ, num);
            cout << "��ͷΪ" << num << endl;
            break;

        case 12:
            if(IsLinkQueueEmpty(LQ))
            {
                cout << "�ӿգ��������" << endl;
                break;
            }
            GetLinkQFront(LQ, num);
            cout << "��ͷΪ" << num << endl;
            break;

        case 13:
            cout << "��ǰ˳�����Ԫ�ظ�����" << CoutElement(SQ);
            break;

        case 14:
            cout << "��ǰ������Ԫ�ظ��� :" << CountLinkQ(LQ);
            break;

        case 15:
            InitialQueue(SQ);
            cout << "������һЩ��,����0������";
            scanf("%d",&num);
            while(num != 0)
            {
                if(num % 2 == 1)
                {
                    cout << "����,���\n";
                    EnQueue(&SQ, num);
                }
                else
                {
                    cout << "ż��,����\n";
                    if(IsQueueEmpty(SQ))
                    {
                        cout <<  "�ӿգ��޷�����\n";
                        break;
                    }
                    DeQueue(&SQ);
                }
                TravelQueue(SQ);
                scanf("%d",&num);
            }
            cout << "������\n";
            TravelQueue(SQ);
            break;

        case 16:
            InitLinkQueue(LQ);
            cout << "������һЩ��,����0������";
            scanf("%d",&num);
            while(num != 0)
            {

                if(num % 2 == 1)
                {
                    cout << "����,���\n";
                    EnLinkQueue(LQ, num);
                }
                else
                {
                    cout << "ż��,����\n";
                    if(IsLinkQueueEmpty(LQ))
                    {
                        cout <<  "�ӿգ��޷�����\n";
                        break;
                    }
                    DeLinkQueue(LQ);
                }
                TravelLinkQueue(LQ);
                scanf("%d",&num);
            }
            cout << "������\n";
            TravelLinkQueue(LQ);
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
