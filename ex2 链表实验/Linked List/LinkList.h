#ifndef _List_H
#define _List_H
#include <stdbool.h>
#define SIZE (sizeof(struct Node))
struct Node;			//�����.c�ļ�
typedef struct Node *List;
typedef struct Node *node;
typedef int ElementType;
struct Node
{
	ElementType Element;  		//������
	node        Next;						//��һ�����
};
List CreateListInsertHead(); //ͷ�巨����
List CreateListInsertRear(); //β�巨����
bool IsEmpty( List Head );
bool IsExist(List Head);
int ReverseList( List Head );
int DestoryList( List Head );
int TravelList( List Head );
int DeleteElement( int i, List Head );//�����ɾ�����
int Insert( ElementType X, List Head, int i );//���Ҳһ��������Ӧ��ֻ��λ�úͱ�
int InsertIncrease( ElementType x, List Head );	//����Ĳ���
int ListLength( List Head );
int Separate ( List Head );							//�ֽ���ż��
List FindCommon( List L1, List L2);		  //����ͬԪ�طŵ��±�
void OrderedListDelSame( List Head ); //���������ȥ��
void UnionAandB( List L1, List L2 );	 //�ϲ�������1,��Ϊһ�����ϣ�11.8��19.42
node Find( ElementType X, List Head ); 	//��ֵȡ���
node FindPrevious( int i, List Head );		//�����ȡǰ�����
ElementType GetElementInOrder( List Head, int i ); //�����ȡԪ��
int AInsertBToC( List A, List B, List C );  //C = A��B //done at 11.12 11:40
int AUnionBToC( List A, List B, List C ); //C = A��B  //done at 11.12 11:40
int ASubBToC( List A, List B, List C );     //C = A - B  //done at 11.12 22.37
void AInsertBToA( List A, List B ); 			//A = A��B
int AUnionBToA( List A, List B );		   	//A =  A��B
int ASubBToA( List A, List B );				//A = A-B
int GetReverseOrder( List Head, int k );  //����������k������ֵ
void FindMid( List A, List B );
bool AisSubB( List A, List B );		//�ж�A�Ƿ���B���Ӽ�
#endif
