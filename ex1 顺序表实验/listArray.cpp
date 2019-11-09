#include "listArray.h"
#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;

//*********************************************************
//�������ܣ��ж��б��Ƿ�Ϊ��
//����������б�ָ��
//�����������
//����ֵ�� 	bool��
//*********************************************************
bool IsEmpty( ptList L )
{
    return L.listLen == 0;
}

//*********************************************************
//�������ܣ���ʼ��һ����
//�����������ͷ
//�����������
//����ֵ�� 	��
//*********************************************************
void InitialList( ptList L )
{
    L.listLen = 0;
}

//*********************************************************
//�������ܣ��ж��б����Ƿ����Ԫ��x
//����������б�ָ�룬���ж�Ԫ��x
//�����������
//����ֵ�� 	bool��
//*********************************************************
bool IsFull( ptList L )
{
    return L.listLen == MAXLEN;
}

//*********************************************************
//�������ܣ�����Ż�ȡֵ
//���������˳���ָ�룬���i
//�������������ֵ����x��
//����ֵ�� 	0��ʾ�ɹ���1��ʾʧ��
//*********************************************************
int GetElement( ptList L, ElementType *x, int i )
{
    if ( IsEmpty( L ) ) //�ձ�����1
    {
        printf("���Ǹ��ձ�");
        return 1;
    }
    if ( i < 1 || i > L.listLen ) //Խ�磬��ʾ����ѡ��λ��
    {
        printf("ѡ��λ���쳣�������˳�");
        return 1;
    }
    *x = L.data[i - 1];
    return 0;
}

//*********************************************************
//�������ܣ��ڵ�i�����ǰ����Ԫ��
//����������б�ָ�룬������Ԫ��x������λ��i
//���������˳���L
//����ֵ�� 	0��ʾ�ɹ���1��ʾʧ��
//*********************************************************
int InsertElement( ptList L, ElementType x, int i )
{
    if ( IsFull( L ) || i > L.listLen + 1 || i < 1 )
    {
        return 1; //�������߲���λ��Խ�磬����ʧ��
    }
    int j; //��i����λ����������Ԫ�ض�����һλ
    for ( j = L.listLen ; j > i - 1 ; j-- )
    {
        L.data[j] = L.data[j - 1];
    }
    L.data[i - 1] = x;
    L.listLen++;
    return 0;
}

//*********************************************************
//�������ܣ�ɾ��˳����е�i�����
//�����������ͷ��ɾ�����
//���������˳���L
//����ֵ�� 	0��ʾ�ɹ���1��ʾʧ��
//*********************************************************
int DeleteElementOrder( ptList L, int i )
{
    if( IsFull( L ) || i > L.listLen || i < 1 ) //�ձ��Խ�磬����ʧ��
    {
        return 1;
    }
    int j; //�Ӵ�ɾ��λ�ÿ�ʼ�������ú����Ԫ�ظ��ǵ�ǰԪ��
    for ( j = i - 1 ; j < L.listLen ; j++ )
    {
        L.data[j] = L.data[j + 1];
    }
    L.listLen--;//���±���
    return 0;
}

//*********************************************************
//�������ܣ���Ԫ��x˳�����һ����ʹ�����ı���������
//�����������ͷL��Ԫ��x
//�����������L
//����ֵ�� 	0��ʾ�ɹ���1��ʾʧ��
//*********************************************************
int OrderInsert( ptList L, ElementType x )
{
    int i;
    if ( L.listLen == MAXLEN )
    {
        return 1;
    }
    for ( i = L.listLen - 1; L.data[i] >= x ; i--)
    {
        L.data[i + 1] = L.data[i];
    }
    //����for�����i--�ĸ����ã���������Ҫ��i+1
    L.data[i + 1] = x;
    L.listLen++;
    return 0;
}

//*********************************************************
//�������ܣ�����L���������ż����ֿ����ŵ���A��C�У������
//�����������ͷL��A,C
//�����������
//����ֵ�� 	0��ʾ�ɹ���1��ʾʧ��
//*********************************************************
int seprate( ptList L , ptList A, ptList C )
{
    if ( IsEmpty( L ) ) //�ձ���ʧ��
    {
        return 1;
    }
    InitialList( A ); //��ʼ����A,C��ȷ�����
    InitialList( C );
    int i,ia,ic;
    ia = ic = 0;
    for ( i = 0 ; i < L.listLen ; i++ )
    {
        if ( L.data[i] % 2 == 0 )//ż�����ŵ�A��
        {
            A.data[ia++] = L.data[i];
            A.listLen++;         //���±���
        }
        else                      //�������ŵ�C��
        {
            C.data[ic++] = L.data[i];
            C.listLen++;
        }
    }

    printf("\nԭ��Ԫ�أ�\n");
    for ( i = 0 ; i < L.listLen ; i++ )
    {
        printf("%d ",L.data[i]);
    }
    printf("\nż��Ԫ�أ�\n");
    for ( i = 0 ; i < A.listLen ; i++ )
    {
        printf("%d ",A.data[i]);
    }
    printf("\n����Ԫ��:\n");
    for ( i = 0 ; i < C.listLen ; i++ )
    {
        printf("%d ",C.data[i]);
    }
    return 0;
}

//*********************************************************
//�������ܣ���������������˳���L1��L2�еĹ���Ԫ�أ������µ�˳���L3�С�
//�����������ͷL1,L2,L3
//���������L3
//����ֵ�� 	0��ʾ�ɹ���1��ʾʧ��
//*********************************************************
int func6( ptList L1, ptList L2, ptList L3 )
{
    int i1, i2, i3;
    i1 = i2 = i3 = 0;
    InitialList( L3 );//ȷ��L3Ϊ��
    if (IsEmpty(L1) || IsEmpty(L2))
    {
        return 1;
    }
    while ( i1 < L1.listLen && i2 < L2.listLen )
    {
        if ( L1.data[i1] < L2.data[i2] ) //L1��ǰԪ��С��L2��
        {
            i1++;
        }
        else if ( L1.data[i1] > L2.data[i2] )
        {
            i2++;
        }
        else
        {
            L3.data[i3] = L1.data[i1];
            L3.listLen++;
            i3++;
            i1++;
            i2++;
        }
    }
    printf("��1Ԫ�أ�\n");
    for ( i1 = 0 ; i1 < L1.listLen ; i1++ )
    {
        printf("%d ", L1.data[i1]);
    }
    printf("\n��2Ԫ�أ�\n");
    for ( i2 = 0 ; i2 < L2.listLen ; i2++ )
    {
        printf("%d ", L2.data[i2]);
    }
    printf("\n����Ԫ�أ�\n");
    for ( i3 = 0 ; i3 < L3.listLen ; i3++ )
    {
        printf("%d ", L3.data[i3]);
    }
    return 0;
}

//*********************************************************
//�������ܣ�ɾ������˳������ظ�Ԫ��
//�����������A
//�����������A
//����ֵ�� 	�ƶ�Ԫ�ش���
//*********************************************************
int OrderedListDeleteSame( ptList A )
{
    int times = 0, i = 0, j = 1;   //times�����ƶ�������i��j�ж��Ƿ��ظ�
    while (j < A.listLen )         //�ӵڶ���Ԫ�ؿ�ʼ�ж����i��Ԫ�ع�ϵ
    {
        if(A.data[j] == A.data[i]) //��ȵĻ���j����������
        {                          //ֱ����һ�������ڵ�i��Ԫ�ص�λ��
            j++;
            times++; //ͬʱ��¼�ƶ�����
            continue;
        }
        else //������һ�����ȵģ��Ͱ�������ȵĸ���i+1λ���ϵ�Ԫ��
        {
            A.data[++i] = A.data[j];
        }
        j++;
    }
    A.listLen = i + 1;          //���±��ȣ�
    return times;
}

//*********************************************************
//�������ܣ���������˳���A��B����A = AUB��
//�����������A��B
//�����������A
//����ֵ�� 	��
//*********************************************************
void AunionBtoA( ptList A, ptList B )
{
    int ia, ib,t;
    ia = ib = 0;
    t = A.listLen;//�������±��ȣ������ȱ��濪ʼ�ĳ���
    while (ia < t && ib < B.listLen )
    {
        if (A.listLen == MAXLEN) //ÿ�β���ǰ�����жϱ�A�Ƿ���
        {
            printf("��A�������޷��ٲ�����\n");
            break;
        }

        if ( A.data[ia] < B.data[ib] ) //A��ǰԪ��С��B��ǰԪ��
            ia++;                    //�ͺ���ia�������Ƚ�
        else if ( A.data[ia] == B.data[ib] )  //�����ͬʱ����
        {
            ia++;
            ib++;
        }
        else      //���ڣ�˵��B��ǰԪ�ؿ϶�����A��ͼ���A
        {
            A.data[A.listLen++] = B.data[ib];
            ib++;
        }
    }
    if (ib != B.listLen) //����while�˳������B��û�����꣬˵��ʣ�µ�B�����Բ���A
    {
        while(ib < B.listLen && A.listLen < MAXLEN)
        {
            A.data[A.listLen++] = B.data[ib];
            ib++;
        }
    }
    sort(A.data, A.data+A.listLen);
}

//*********************************************************
//�������ܣ���������˳���A��B���ж�A�Ƿ�ΪB���Ӽ�
//�����������A��B
//�����������
//����ֵ�� 	true or false
//*********************************************************
bool IsSub( ptList A, ptList B )
{
    int ia, ib;
    ia = ib = 0;
    bool flag = true;
    while ( ia < A.listLen && ib < B.listLen )
    {
        if (A.data[ia] < B.data[ib] )//���A��ǰԪ��С��B�ĵ�ǰ��
        {                            //�ǿ϶�С��B�������еģ�
            flag = false;            //�����Ԫ�ؾͿ϶�����B���棬���˳�
            break;
        }
        else if (A.data[ia] > B.data[ib])//A��ǰԪ�ش���B��ǰ��
        {                                //�ͻ����ж�B�����
            ib++;
        }
        else                         //�����ȣ�������ж�A��һ��Ԫ��
        {
            ia++;
            ib++;
        }
    }
    return flag;
}

//*********************************************************
//�������ܣ����������1��2��������ϲ����طŻ�1
//�����������1��2
//�����������1
//����ֵ�� 	�ɹ�����0��ʧ�ܷ���1
//*********************************************************
int L1pulsL2ToL1( ptList A, ptList B )
{
    //���ﲢûҪ����������Ȼ�������� ֱ����1������2���Ԫ��
    int ia, ib, t;
    ia = ib = 0;
    t = A.listLen;//�������±��ȣ������ȱ��濪ʼ�ĳ���
    while (ia < t && ib < B.listLen )
    {
        if (A.listLen == MAXLEN) //ÿ�β���ǰ�����жϱ�A�Ƿ���
        {
            printf("��A�������޷��ٲ�����\n");
            break;
        }

        if ( A.data[ia] < B.data[ib] ) //A��ǰԪ��С��B��ǰԪ��
            ia++;                    //�ͺ���ia�������Ƚ�
        else if ( A.data[ia] == B.data[ib] )  //�����ͬʱ����
        {
            ia++;
            ib++;
        }
        else      //���ڣ�˵��B��ǰԪ�ؿ϶�����A��ͼ���A
        {
            A.data[A.listLen++] = B.data[ib];
            ib++;
        }
    }
    if (ib != B.listLen) //����while�˳������B��û�����꣬˵��ʣ�µ�B�����Բ���A
    {
        while(ib < B.listLen && A.listLen < MAXLEN)
        {
            A.data[A.listLen++] = B.data[ib];
            ib++;
        }
    }
    return 0;
}

//*********************************************************
//�������ܣ����������1��2������λ��
//���������������ͬ�ı�1��2
//�����������
//����ֵ��  ��λ��n
//*********************************************************
int FindMidNum( ptList L1, ptList L2 )
{
    const int len = L1.listLen;//ǰ������������һ��
    int i1, i2, j, num[len] = {0}; //ÿ�αȽϽ�С���Ǹ��������������
    i1 = i2 = j = 0;           //j����ѭ��
    while ( j < len )
    {
        if( L1.data[i1] < L2.data[i2] ) //1��ǰԪ��С��2��ǰ��
        {
            num[j++] = L1.data[i1];
            i1++;
        }
        else if (L1.data[i1] > L2.data[i2]) //����
        {
            num[j++] = L2.data[i2];
            i2++;
        }
        else //���ڵĻ����ͷ�������һ����Ȼ�����i1��i2
        {
            num[j++] = L1.data[i1];
            i1++;
            i2++;
        }
    }
    //������num�������һλ��Ϊ��λ��
    printf("��λ����  %d\n",num[len - 1]);
    return 0;
}

//*********************************************************
//�������ܣ����������ϵĽ���
//������������������A��B
//�����������C
//����ֵ�� 	��
//*********************************************************
void Intersection( ptList A, ptList B, ptList C )
{
    InitialList( C ); //�ȳ�ʼ��C������Cԭ����Ԫ��
    int ia, ib;
    ia = ib = 0;
    while (ia < A.listLen && ib < B.listLen )//˫ָ��ͬʱ����������
    {
        if ( A.data[ia] == B.data[ib] )//�����ȣ��ͷ�����һ����C��
        {
            C.data[C.listLen++] = A.data[ia];
            ia++;
            ib++;
        }
        else if ( A.data[ia] < B.data[ib] ) //С�ڣ��ͺ���A��ָ��
            ia++;
        else                             //���ڣ��ͺ���B
            ib++;
    }
}

//*********************************************************
//�������ܣ����������ϵĲ���
//������������������A��B
//�����������C
//����ֵ�� 	��
//*********************************************************
void Union( ptList A, ptList B, ptList C )
{
    int ia, ib;
    ia = ib = 0;
    InitialList( C );
    while ( ia < A.listLen && ib < B.listLen ) //ͬ���ģ�˫ָ�����������
    {
        if ( A.data[ia] == B.data[ib] ) //��Ⱦͷ�����һ����C��
        {
            C.data[C.listLen++] = A.data[ia];
        }
        else  //���Ⱦ���������
        {
            C.data[C.listLen++] = A.data[ia];
            C.data[C.listLen++] = B.data[ib];
        }
        ia++;
        ib++;
        if ( C.listLen == MAXLEN )
        {
            printf("������.");
            break;
        }
    }
    if ( ib < B.listLen ) //���B��û�����꣬˵��ʣ�µĶ����Բ���C
    {
        ib++;
        while ( ib < B.listLen && C.listLen < MAXLEN )
        {
            if ( B.data[ib] != A.data[ia] )
                C.data[C.listLen++] = B.data[ib];
            ib++;
        }
    }
    else                    //else˵��A��û�����꣬��Aʣ�µĲ���C
    {
        ia++;
        while (ia < A.listLen && C.listLen < MAXLEN )//ȷ��C�����鲻��Խ��
        {
            if ( A.data[ia] != B.data[ib] )
                C.data[C.listLen++] = A.data[ia];
            ia++;
        }
    }
}

//*********************************************************
//�������ܣ����������ϵĲ�
//������������������A��B
//�����������C
//����ֵ�� 	��
//*********************************************************
void setSubtract( ptList A, ptList B, ptList C )
{
    //���ж�A��B�Ŀգ������ȼ���A��b����Ϊ��
    InitialList( C );
    int ia, ib;
    ia = ib = 0;
    while ( ia < A.listLen && ib < B.listLen ) //˫ָ�����������
    {
        if ( A.data[ia] == B.data[ib] )        //���˵��A��ǰԪ�ز���Ŀ��Ԫ�أ�
        {
            ia++;                                //��������ָ�룬�����ж�
            ib++;
            continue;
        }
        else if ( A.data[ia] < B.data[ib] )    //A��ǰԪ��С��B�ģ�˵��A��ǰԪ������Ҫ��
        {
            C.data[C.listLen++] = A.data[ia]; //����C
            ia++;
        }
        else ib++;                               //���ڣ��ƶ�B��ָ�룬��B�����
    }
    if (ia < A.listLen )                        //���Aû�����꣬��Aʣ�µ�һ������Ҫ��
    {
        while ( ia < A.listLen && C.listLen < MAXLEN )
        {
            C.data[C.listLen++] = A.data[ia];
            ia++;
        }
    }
}

//*********************************************************
//�������ܣ�ȡ������Ľ������ٸ���A
//������������������A��B
//�����������A
//����ֵ�� 	��
//*********************************************************
void InterSecToA( ptList A, ptList B )
{
    int ia = 0, ib = 0, k = 0; //k���A�����Ԫ��Ҫ�ƶ�����λ��
    while ( ia < A.listLen && ib < B.listLen ) //˫ָ��ͬʱ����������
    {
        if ( A.data[ia] == B.data[ib] )    //�����ǽ�����Ԫ�ظ����ǵ���ʵ����ԭ���ϲ���
        {
            A.data[k] = A.data[ia];
            k++;
            ia++;
            ib++;
        }
        else if ( A.data[ia] > B.data[ib] )
            ib++;
        else
            ia++;
    }
    //����ǰ��k++����׺++�ĸ����ã���������ֻ��k��������k+1
    A.listLen = k; //���±���
}

//*********************************************************
//�������ܣ�ȡ������Ĳ�ٸ���A
//�������������������A��B
//�����������A
//����ֵ�� 	��
//*********************************************************
void SubtractToA( ptList A, ptList B )
{
    int ia = 0, ib = 0, k = 0, times = 0; //times��¼�����˶��ٸ������ڸ��±���
    while ( ia < A.listLen && ib < B.listLen )
    {
        if ( A.data[ia] == B.data[ib] )   //��ȣ�������Ҫ�󣬼���������������
        {
            ia++;
            ib++;
            times++;                        //ͬʱtimes++
            continue;
        }
        else if ( A.data[ia] > B.data[ib] )
        {
            ib++;
            continue;
        }                                   //ֻ��С�ڲ�˵������Ҫ��ִ�и��ǲ���
        A.data[k] = A.data[ia];
        k++;
        ia++;
    }
    while (ia < A.listLen)//���Aû�����꣬�Ͱ�ʣ�µ�������ǰ����times��λ��
    {
        A.data[ia - times] = A.data[ia];
        ia++;
    }
    A.listLen -= times; //���±���
}

//*********************************************************
//�������ܣ������б�Ԫ��
//����������б�ָ��
//�����������
//����ֵ�� 	�ɹ�����0��ʧ�ܷ���1
//*********************************************************
int TravelList( ptList L )
{
    if ( IsEmpty( L ) )
        return 1;
    int i;
    for ( i = 0 ; i < L.listLen ; i++ )
    {
        printf("%3d  ", L.data[i]);
    }
    printf("\n");
    return 0;
}

//*********************************************************
//�������ܣ�ɾ������һ��Ԫ��
//����������б�ָ�룬��ɾ��Ԫ��x
//�����������
//����ֵ�� 	0��ʾɾ���ɹ���1Ԫ�ز����ڣ�2��ʾ��Ϊ��
//*********************************************************
int DeleteElement( ptList L, ElementType x )
{
    int i, j;
    i = 0;
    while (L.data[i] != x && i < L.listLen)
        i++;
    if (i == L.listLen)
        return 1;
    if ( IsEmpty( L ) )
    {
        return 2;
    }
    for ( j = i - 1; j < L.listLen ; j++)
    {
        L.data[j] = L.data[j + 1];
    }
    L.data[L.listLen - 1] = 0; //��ĩβ��0
    L.listLen--;               //���ȼ�һ
    return 0;
}
