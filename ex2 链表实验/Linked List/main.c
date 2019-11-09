#include "LinkList.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int main( )
{
    int choice, DeEle, i, insertNum, len, location;
    List H = NULL;
    List H2 = NULL;
    List H3 = NULL;
    bool Exit = false;	     //Exit��������������������
    while ( !Exit )
    {
        printf("********************************\n");
        printf( "*����������������,��ѡ���Ӧ���ܣ�\n" );
        printf("*1.ͷ�巨��������ӡ���\n");   //  no problem
        printf("*2.β�巨��������ӡ�����\n");//  no problem
        printf("*3.��������\n");//  no problem
        printf("*4.��������.\n");          //small problem
        printf("*5.���i��Ԫ�ء�\n");//  no problem
        printf("*6.������\n");//  no problem
        printf("*7.��ֵ���ҽ�㡣\n");   //big problem
        printf("*8.ɾ����i�����.\n");
        printf("*9.��������㡣\n");
        printf("*10.�ֽ�����\n");
        printf("*11.��⹫��Ԫ��\n");
        printf("*12.���������ɾ���ظ�Ԫ��\n");
        printf("*13.�ϲ�����.\n");
        printf("*14.��������.\n");
        printf("*15.��չ��һ�⡣\n");
        printf("*16.��չ�ڶ��⡣\n");
        printf("*17.��չ�����⡣\n");
        printf("*18.��չ�����⡣\n");
        printf("*19.�˳���\n");
        printf("*********************************\n");
        printf( "��ѡ��" );
        scanf( "%d", &choice );
        while ( choice > 19 || choice < 1 )
        {
            printf( "ѡ����� �����ԣ�" );
            scanf( "%d", &choice );
        }
        switch ( choice )
        {
            case 1:  //ͷ��
                H = CreateListInsertHead();
                if ( H == NULL )
                {
                    printf( "������ʧ�ܣ������ԡ�\n" );
                    break;
                }
                printf( "�������ɹ���\n" );
                if(TravelList(H))
                    printf("����ʧ�ܣ���ִ����������.\n");
                break;

            case 2:							//β��
                H = CreateListInsertRear();
                if ( NULL == H )
                {
                    printf("������ʧ��.");
                    break;
                }
                printf("�����ɹ���\n");
                if (TravelList(H))
                    printf("����ʧ��\n");
                break;

            case 3:  //����
                if ( DestoryList(H))
                {
                        printf("�������ڣ���ѡ�񴴽�����\n");
                }
                else
                {
                        printf("�������ٳɹ���\n");
                        H = NULL;
                }
                break;

            case 4:  //�󳤶�,����������
                len = ListLength(H);
                if ( len == -1 )
                {
                        printf("�������ڣ���ѡ�񴴽�����.\n");
                        break;
                }
                else
                {
                        printf("������Ϊ%d\n",len);
                }
                break;

            case 5:  //�ҵ�i��Ԫ��
                printf("������i��\n");
                scanf("%d",&i);
                len = GetElementInOrder( H, i );
                if(len == -1)
                {
                        printf("���������Ԫ��,����ѡ.\n");
                }
                else
                {
                        printf("��%d��Ԫ���ǣ�%d", i, len );
                }
                break;

            case 6:   //���룺ok
                printf( "������������������" );
                scanf( "%d", &insertNum );
                printf( "\n�����ڵڼ��������룿��(Ŀǰһ����%d�����)\n", ListLength( H ) );
                scanf( "%d", &location );
                if ( Insert( insertNum, H, location ) )   //����ʧ�ܷ���1��if�ж�Ϊ�棬˵�����
                {
                    printf( "����λ��Խ�磬������ѡ��\n" );
                }
                else
                {
                    printf( "��������ɹ�\n" );
                }
                break;

            case 7:   //��ֵΪx�Ľ��,ok
                printf("��������Ҫ���ҵ�ֵ��\n");
                scanf("%d",&len);
                node p = Find(len, H);          //����������ָ��
                if (p == NULL )                         //��ָ��˵��û�ҵ�
                {
                        printf("����ʧ�ܣ���ѡ������ѡ�\n");
                }
                else
                {
                        printf("���ҳɹ�");
                }
                break;

            case 8:   //ɾ�����  //ok
                printf( "����ɾ���ڼ��Ž�㣿��" );
                scanf( "%d", &DeEle );
                if ( DeleteElement( DeEle, H ) )		 //����ʧ�ܷ���1 ��ʧ�ܷ���0
                {
                    printf( "����ʧ�ܣ������ԡ�\n" );
                }
                else
                {
                    printf( "�����ɹ�\n" );
                }
                break;

            case 9:  //ok
                printf("��������������:\n");
                scanf("%d",&len);
                printf("����ǰ:");
                TravelList(H);
                InsertIncrease(len,H);
                printf("\n�����");
                TravelList(H);
                break;

            case 10: //ok
                Separate(H);
                break;

            case 11:
                for ( int i = 0 ; i < 3 ; i++ )
                {
                        printf("\n��%d����ԣ�\n", i + 1);
                        printf("���ȴ�����1:\n") ;
                        H = CreateListInsertRear();  //β�崴����1
                        if ( H == NULL )                         //�жϴ����Ƿ�ɹ�
                        {
                                printf("��1����ʧ�ܣ�������.\n");
                                break;
                        }
                        getchar();//����ǰ�����Ļس����Ժ������Ӱ��
                        printf("\nȻ�󴴽���2��\n");
                        H2 = CreateListInsertRear(); //β�崴����2
                        if ( H2 == NULL )                         //�ж��Ƿ�ɹ�
                        {
                                printf("��2����ʧ�ܣ�������\n");
                                break;
                        }
                        getchar();
                        H3 = FindCommon( H, H2 );
                        printf("��1�ͱ�2����Ԫ��Ϊ��\n");
                        TravelList( H3 );
                        DestoryList( H );  //����������Ŀռ䣬������һ�β���
                        DestoryList( H2 );
                        DestoryList( H3 );
                }
                break;

            case 12:  //ok
                for ( int i = 0 ; i < 3 ; i++ )  //3�����
                {
                        printf("\n��%d����ԣ�\n", i + 1);
                        H = CreateListInsertRear(); //β�崴��
                        getchar();              //���Ļس�
                        printf("ȥ��ǰ��");
                        TravelList( H );
                        OrderedListDelSame( H );
                        printf("\nȥ�غ�");
                        TravelList( H );
                        DestoryList( H );//���տռ䣬������һ�β���
                        printf("\n");
                }
                break;

            case 13: //ok
                 for ( int i = 0 ; i < 3 ; i++ )  //3�����
                 {
                        printf("\n��%d����ԣ�\n", i + 1);
                        printf("�봴����1��\n");   //1 3 6 10 15 16 17 18 19 20
                        H = CreateListInsertRear();
                        getchar();              //����ǰ�����Ļس����Ժ������Ӱ��
                        printf("�봴����2��\n"); //1 2 3 4 5 6 7 8 9 10 18 20 30
                        H2 = CreateListInsertRear(); //2 4 5 7 8 9 12 22
                        getchar();//1 2 3 4 5 6 7 8 9 10
                        UnionAandB(H, H2);
                        printf("�ϲ���");
                        TravelList(H);
                        DestoryList(H);
                }
                break;

            case 14:
                TravelList(H);
                break;

            case 15:
                printf("C = A��B:\n");
                H = CreateListInsertRear();
                getchar();
                H2 = CreateListInsertRear();//1 3 6 10 15 16 17 18 19 20#
                getchar();
                H3 = (node)malloc(SIZE);//1 2 3 4 5 6 7 8 9 10 18 20 30#
                AInsertBToC( H, H2, H3 );
                printf("\nC:");//2 4 5 7 8 9 12 22#
                TravelList(H3);
                DestoryList(H);
                DestoryList(H2);
                DestoryList(H3);
                system("pause");
                system("CLS");
                printf("C = A��B:\n");
                H = CreateListInsertRear();
                getchar();
                H2 = CreateListInsertRear();
                getchar();
                H3 = (node)malloc(SIZE);
                AUnionBToC( H, H2, H3 );
                printf("\nC:\n");
                TravelList(H3);
                DestoryList(H);
                DestoryList(H2);
                DestoryList(H3);
                system("pause");
                system("CLS");
                printf("C = A - B:\n");
                H = CreateListInsertRear();
                getchar();
                H2 = CreateListInsertRear();
                getchar();
                H3 = (node)malloc(SIZE);
                ASubBToC(H, H2, H3 );
                printf("\nC:\n");
                TravelList(H3);
                DestoryList(H);
                DestoryList(H2);
                DestoryList(H3);
                system("pause");
                system("CLS");

                printf("A =  A��B:\n");
                H = CreateListInsertRear();
                getchar();
                H2 = CreateListInsertRear();
                getchar();
                AInsertBToA(H,H2);
                printf("\nAfter insert, \nA:");
                TravelList(H);
                DestoryList(H);
                DestoryList(H2);
                system("pause");
                system("CLS");

                printf("A = A��B:\n");
                H = CreateListInsertRear();
                getchar();
                H2 = CreateListInsertRear();
                getchar();
                AUnionBToA(H, H2);
                printf("\bAfter union, \nA");
                TravelList(H);
                DestoryList(H);
                DestoryList(H2);
                system("pause");
                system("CLS");
                printf("A = A-B:\n");
                H = CreateListInsertRear();
                getchar();
                H2 = CreateListInsertRear();
                getchar();
                ASubBToA(H,H2);
                printf("\nAfter subtract, \nA");
                TravelList(H);
                DestoryList(H);
                DestoryList(H2);
                system("pause");
                system("CLS");
                break;

            case 16:
                printf("�봴����һ��\n");
                H = CreateListInsertRear();
                getchar();
                printf("�봴�������\n");
                H2 = CreateListInsertRear();
                getchar();
                if ( AisSubB(H, H2) )
                {
                        printf("��1�Ǳ�2���Ӽ���\n");
                }
                else
                {
                        printf("��1���Ǳ�2���Ӽ���\n");
                }
                DestoryList(H);
                DestoryList(H2);
                break;

            case 17:
                printf("�봴����\n");
                H = CreateListInsertRear();
                getchar();
                printf("�����ҵ����ڼ���������\n");
                scanf("%d",&i);
                if ( !GetReverseOrder( H, i ))
                {
                        printf("λ��Խ�磬������");
                }
                break;

            case 18:
                printf("�봴����һ��\n");
                H = CreateListInsertRear();
                getchar();
                printf("�봴�������\n");
                H2 = CreateListInsertRear();
                getchar();
                FindMid( H, H2 );
                break;

            case  19:
                break;

            default:
                break;
        }
        system( "pause" );
        system( "CLS" );
        fflush(stdin);
    }
    if ( !IsExist( H ) )  //��ֹ֮ǰ�û��˳�ʱû��ѡ��ɾ�����������
    {
        DestoryList(H);
    }
    return 0;
}

