#ifndef _Search_H
#define _Search_H
typedef int BSTelement;//������ֵ����
struct BinSearchTree;
typedef struct BinSearchTree *BSTnode; //�������������ָ��
typedef struct BinSearchTree BST;//���


//��������������㷨
BSTnode Find( BSTelement &x, BSTnode T ); //����Ԫ��x
BSTnode Find2( BSTelement &x, BSTnode T ); //ѭ����ʽ����Ԫ��x
BSTnode FindMin( BSTnode T ); //����Сֵ
BSTnode FindMax( BSTnode T ); //�����ֵ
BSTnode Delete( BSTnode T, BSTelement &x );
bool CreateBSTfromArr( BSTnode &T, BSTelement *arr, int len );//�����鴴������������
void DestoryBST( BSTnode &T ); //����������������
bool Insert( BSTnode &T, BSTelement &x ); //����
void MidOrderTravel( BSTnode T );	//������������ڼ����������Ķ���������
int BinarySearch( BSTelement *arr, int len, BSTelement &x );//���ֲ���
int BinSearchRecu( BSTelement *arr, BSTelement &x, int low, int high );//�ݹ��㷨
//ƽ�����������㷨

#endif // _Search_H
