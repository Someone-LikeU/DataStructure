#ifndef List_Array
#define List_Array
#include <stdbool.h>
#define MAXLEN 100
#define ElementType int
struct sList
{
    ElementType data[MAXLEN];   //�������Ԫ�ص�����
    int listLen;                //��¼����
};
typedef struct sList seqList;
typedef struct sList &ptList;   //ָ������ṹ������

int GetElement( ptList L, ElementType *x, int i );//�����ȡֵ
int InsertElement( ptList L, ElementType x, int i );//�ڵ�i�����ǰ����ֵΪx�Ľ��
int DeleteElementOrder( ptList L, int i );//ɾ����i�����
int OrderInsert( ptList L, ElementType x ); //�ڵ�������˳������Ԫ�أ������������
int seprate( ptList L , ptList A, ptList C );
int func6( ptList L1, ptList L2, ptList L3 );
int OrderedListDeleteSame( ptList A );      //ɾ������˳�����ظ�Ԫ��
void AunionBtoA( ptList A, ptList B );      //A = AUB
void InterSecToA( ptList A, ptList B );     //A = A��B
void SubtractToA( ptList A, ptList B );     //A = A-B
void Intersection( ptList A, ptList B, ptList C ); //C=A��B
void Union( ptList A, ptList B, ptList C ); //C = A U B
void setSubtract( ptList A, ptList B, ptList C );   //C = A-B
bool IsSub( ptList A, ptList B );           //�жϵ�����A��B��A�Ƿ���B���Ӽ�
int L1pulsL2ToL1( ptList L1, ptList L2 );   //�ϲ����ϱ�1��2
int FindMidNum( ptList L1, ptList L2 );     //�ҵ�����������������λ��

//�����Ǳ���ʵ�����Ŀ�����º����ǲ��Ը�������

int TravelList( ptList L );                 //�����б����ڲ���ǰ��ĺ���
int DeleteElement( ptList L, ElementType x );//��ֵɾ��Ԫ�أ��ò���ǰ��ĺ���
bool IsEmpty( ptList L );
void InitialList( ptList L );
bool IsFull( ptList L );
#endif // List_Array
