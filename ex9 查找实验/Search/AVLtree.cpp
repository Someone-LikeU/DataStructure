#include "AVLtree.h"
#include <iostream>
#include <cstdlib>
#include <iomanip>
using namespace std;
struct AVL
{
	TreeElement data;
	AVLnode     left;
	AVLnode     right;
	int         height;
};

//*****************************************************
//�������ܣ��������д���AVL��
//����������������ã���������
//�����������
//����ֵ��	�ɹ�����true�����򷵻�false
//*****************************************************
bool CreateAVLformArr( AVLTree &T, TreeElement *arr, int len )
{
	int i;
	for ( i = 0; i < len; i++ )
	{
		AVLInsert( arr[ i ], T );
	}
	return true;
}

//*****************************************************
//�������ܣ���AVL������Ԫ��ֵΪx�Ľ��
//��������������
//�����������
//����ֵ��	��
//*****************************************************
AVLnode AVLFind( TreeElement x, AVLTree T )
{
	while ( T )
	{
		if ( x > T->data )			 //���ڸ��ڵ㣬���������м�����
		{
			T = T->right;
		}
		else if ( x < T->data )		  //С�ڣ����������м�����
		{
			T = T->left;
		}
		else							  //��ȣ��ͷ������ָ��
			return T;
	}
	return NULL;
}

//*****************************************************
//�������ܣ���AVL���е���Сֵ
//�������������T
//�����������
//����ֵ��	��Сֵ���ָ��
//*****************************************************
AVLnode AVLFindMin( AVLTree T )
{
	if ( T == NULL ) //empty tree, return NULL
	{
		return NULL;
	}
	AVLnode t = T;	   //none recursion
	while ( t->left )
	{
		t = t->left;
	}
	return t;
}

//*****************************************************
//�������ܣ���AVL���е����ֵ
//�������������T
//�����������
//����ֵ��	��Сֵ���ָ��
//*****************************************************
AVLnode AVLFindMax( AVLTree T )
{
	if ( T == NULL )  //empty tree, return NULL
	{
		return NULL;
	}
	else if ( T->right == NULL ) //if fight sibling tree is empty,return itself,which is answer
	{
		return T;
	}
	else
	{
		return AVLFindMax( T->right );
	}
}

//*****************************************************
//�������ܣ�����AVL��
//��������������
//�����������
//����ֵ��	��
//*****************************************************
void DestoryAVLtree( AVLTree &T )
{
	if ( T )
	{
		DestoryAVLtree( T->left );
		DestoryAVLtree( T->right );
		delete T;
		T = NULL;
	}
}

//*****************************************************
//�������ܣ��������AVL��
//��������������
//�����������
//����ֵ��	��
//*****************************************************
void AVLmidorderTravel( AVLTree T)
{
	if ( T )
	{
		AVLmidorderTravel( T->left );
		cout << setw( 3 ) << T->data << " ";
		AVLmidorderTravel( T->right );
	}
}

//*****************************************************
//�������ܣ�ɾ��AVL����Ԫ��x
//�������������㣬��ɾ��Ԫ��x
//�����������
//����ֵ��	ɾ���������
//*****************************************************
AVLTree AVLDelete(  AVLTree T, TreeElement x )
{
	AVLnode temp;
	if ( T == NULL )
	{
		cout << "Element not found! Please try again.\n";
	}
	else if ( x < T->data )				 //x��TֵС������������ɾ��
	{
		T->left = AVLDelete( T->left, x );
	}
	else if ( x > T->data )				//x��T�Ĵ󣬵���������ɾ
	{
		T->right = AVLDelete( T->right, x );
	}
	else  //�ҵ�Ҫɾ���Ľ����
	{
		if ( T->left && T->right )
		{
			temp = AVLFindMin( T->right );//������������һ����С�Ľ��
			T->data = temp->data;
			T->right = AVLDelete( T->right, T->data );//������������ɾ����СԪ��
		}
		else	//��ɾ���ֻ��һ���ӽ������ӽڵ�
		{
			temp = T;
			if ( !T->left )//�����ӽڵ�����ӽڵ�
				T = T->right;
			else if ( !T->right )
				T = T->left;
			free( temp );
			temp = NULL;
		}
	}
	return T;
}

//*****************************************************
//�������ܣ���AVL�����ĸ߶�
//���������AVL���
//�����������
//����ֵ��	�߶�height
//*****************************************************
static int Height( AVLnode p )
{
	if ( p == NULL )   //��������߶�Ϊ-1
	{
		return -1;
	}
	else
	{
		return p->height;
	}
}

//*****************************************************
//�������ܣ���AVL���в���Ԫ��x
//���������������Ԫ��x����T
//�����������
//����ֵ��	ɾ���������
//*****************************************************
AVLTree AVLInsert( TreeElement x, AVLTree &T )
{
	if ( T == NULL )//if it's empty, create and return a one-node tree
	{
		T = new AVL;
		T->data = x;
		T->height = 0;
		T->left = NULL;
		T->right = NULL;
	}
	else if ( x < T->data ) //x is smaller, go left son tree to insert
	{
		T->left = AVLInsert( x, T->left );
		if ( Height( T->left ) - Height( T->right ) == 2 )//left sibtree heigher than right
		{
			if ( x < T->left->data )   //LL rotate
			{
				T = RotateLL( T );
			}
			else				    //LR rotate
			{
				T = RotateLR( T );
			}
		}
	}
	else if ( x > T->data )//x is bigger than T's data,
	{
		T->right = AVLInsert( x, T->right );	// then go T's right sibtree to insert
		if ( Height( T->right ) - Height( T->left ) == 2 )
		{	//right sib son's balance was broken by x
			if ( x > T->right->data )//if x is bigger than T's right son
			{
				T = RotateRR( T );  //then RR rotate
			}
			else  //x is smaller than T's right son
			{
				T = RotateRL( T ); //then RL rotate
			}
		}
	}
	//else x is in the tree already, do nothing
	//upgrate T's height
	T->height = Max( Height( T->left ), Height( T->right ) ) + 1;
	return T;
}

//*****************************************************
//�������ܣ����������ϴ���Ǹ�
//�����������������
//�����������
//����ֵ��	���ֵ
//*****************************************************
int Max( int a, int b )
{
	return a > b ? a : b;
}

//*****************************************************
//�������ܣ�������ת
//�������������ת���
//�����������
//����ֵ��  ��ת����������ڵ�
//*****************************************************
AVLnode RotateRR( AVLTree k2 )
{
	AVLnode k1;
	k1 = k2->right;
	k2->right = k1->left;
	k1->left = k2;
	k2->height = Max( Height( k2->left ), Height( k2->right ) ) + 1;
	k1->height = Max( Height( k1->right ), k2->height ) + 1;
	return k1;
}

//*****************************************************
//�������ܣ�������ת
//�������������ת���
//�����������
//����ֵ��	��ת�������
//*****************************************************
AVLnode RotateLL( AVLTree k2 )
{
	AVLnode k1;
	k1 = k2->left;
	k2->left = k1->right;
	k1->right = k2;
	k2->height = Max( Height( k2->left ), Height( k2->right ) ) + 1;
	k1->height = Max( Height( k1->left ), k2->height ) + 1;
	return k1;
}

//*****************************************************
//�������ܣ�������ת
//�������������ת��
//�����������
//����ֵ��	��
//*****************************************************
AVLnode RotateLR( AVLTree k3 )
{
	k3->left = RotateRR( k3->left );//rotate k1 and k2
	return RotateLL( k3 );		 //rotate k3 and k2
}

//*****************************************************
//�������ܣ�������ת
//�������������ת��
//�����������
//����ֵ��	��ת�������
//*****************************************************
AVLnode RotateRL( AVLTree k3 )
{
	k3->right = RotateLL( k3->right );
	return RotateRR( k3 );
}
