//**************************************************************
//Filename	         : Search.cpp
//Abstract           : ���ļ��ǲ��ҵ�����㷨ʵ���ļ�
//Author  	         : �ܽ���
//Accomplished Date  : 2018.12.22
//Beginning Date     : 2018.12.22
//Student ID         : 2017217866
//**************************************************************

#include "Search.h"
#include <iostream>
#include <cstdlib>
#include <iomanip>
using namespace std;
struct BinSearchTree
{
	BSTelement data;
	BSTnode left;
	BSTnode right;
};


//*****************************************************
//�������ܣ��ڶ����������в���ĳ��Ԫ��
//���������������Ԫ��x������T
//�����������
//����ֵ��	�ҵ����ؽ��ָ�룬ʧ�ܷ��ؿ�ָ��
//*****************************************************
BSTnode Find( BSTelement &x, BSTnode T )
{
	if ( T == NULL ) //��������û������û�����ֵ�����ؿ�ָ��
	{
		return NULL;
	}
	if ( T->data < x )				 //С�ڸ��ڵ㣬�ݹ�����������
	{
		return Find( x, T->left );
	}
	else if ( T->data >x )				//���ڣ�������������
	{
		return Find( x, T->right );
	}
	else								//�ҵ��ˣ��ͷ���������
	{
		return T;
	}
}

//*****************************************************
//�������ܣ��ڶ����������в���ĳ��Ԫ��
//���������������Ԫ��x������T
//�����������
//����ֵ��	�ҵ����ؽ��ָ�룬ʧ�ܷ��ؿ�ָ��
//*****************************************************
BSTnode Find2( BSTelement &x, BSTnode T )
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
//�������ܣ��Ҷ����������е���Сֵ
//�������������T
//�����������
//����ֵ��	��Сֵ���ָ��
//*****************************************************
BSTnode FindMin( BSTnode T )
{
	if ( T == NULL ) //empty tree, return NULL
	{
		return NULL;
	}
	BSTnode t = T;	   //none recursion
	while ( t->left )
	{
		t = t->left;
	}
	return t;
}

//*****************************************************
//�������ܣ��Ҷ����������е����ֵ
//�������������T
//�����������
//����ֵ��	��Сֵ���ָ��
//*****************************************************
BSTnode FindMax( BSTnode T )
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
		return FindMax( T->right );
	}
}

//*****************************************************
//�������ܣ����ٶ���������
//�������������
//�����������
//����ֵ��	��
//*****************************************************
void DestoryBST( BSTnode &T )
{
	if ( T )				//like last order travel
	{
		DestoryBST( T->left );
		DestoryBST( T->right );
		delete T;
		T = NULL;
	}
}

//*****************************************************
//�������ܣ��ڶ����������в���һ�����
//�����������������T��������ֵx
//���������������T
//����ֵ��	��
//*****************************************************
bool Insert( BSTnode &T, BSTelement &x )
{
	if ( T == NULL )		   //������һ�ÿ���������ڵ��Ϊ�¸��ڵ�
	{
		T = new BST;
		/*if ( T == NULL )
		{
			cout << "Memory allocate failed.Please try agiain.\n";
			return false;
		}*/
		T->data = x;
		T->left = NULL;
		T->right = NULL;
	}
	else if ( x > T->data )		   //�������x���ڵ�ǰ���ֵ
	{
		Insert( T->right, x );	   //�͵��������в�
	}
	else if ( x < T->data )
	{
		Insert( T->left, x );		//����͵��������в�
	}
	//if there is a x ,do nothing
}

//*****************************************************
//�������ܣ��������
//�������������ָ��
//�����������
//����ֵ��	��
//*****************************************************
void MidOrderTravel( BSTnode T )
{
	if ( T )
	{
		MidOrderTravel( T->left );
		cout << setw( 3 ) << T->data << " ";
		MidOrderTravel( T->right );
	}
}

//*****************************************************
//�������ܣ�ɾ������һ��Ԫ��x
//�����������������ɾ��Ԫ��x
//�����������
//����ֵ��	ɾ�������������
//*****************************************************
BSTnode Delete( BSTnode T, BSTelement &x )
{
	BSTnode temp;
	if ( T == NULL )
	{
		cout <<endl;
		cout << setw(3) << x <<  " was not found! Please try again.\n";
	}
	else if ( x < T->data )				 //x��TֵС������������ɾ��
	{
		T->left = Delete( T->left, x );
	}
	else if ( x > T->data )				//x��T�Ĵ󣬵���������ɾ
	{
		T->right = Delete( T->right, x );
	}
	else  //�ҵ�Ҫɾ���Ľ����
	{
		if ( T->left && T->right )
		{
			temp = FindMin( T->right );//������������һ����С�Ľ��
			T->data = temp->data;
			T->right = Delete( T->right, T->data );//������������ɾ����СԪ��
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
//�������ܣ������鴴��һ������������
//�������������ָ�����ã���������
//��������������õ�����
//����ֵ��	�ɹ�����0��ʧ�ܷ���1
//*****************************************************
bool CreateBSTfromArr( BSTnode &T, BSTelement *arr, int len )
{
	//����˼����ǲ��ϵ��õ��ò��뺯��
	int i;
	for ( i = 0; i < len; i++ )
	{
		 Insert( T, arr[ i ] );
		//{
		//	cout << "Create failed.Please try again.\n";
		//	return false;
		//}
	}
	return true;
}

//*****************************************************
//�������ܣ����ֲ���
//����������������飬������Ԫ��x
//�����������
//����ֵ��	�ɹ����ش�����Ԫ���±꣬ʧ�ܷ���-1
//*****************************************************
int BinarySearch( BSTelement *arr, int len, BSTelement &x )
{
	int mid, low, high;
	low = 0;
	high = len - 1;
	while ( low <= high )
	{
		mid = ( low + high ) / 2;
		if ( x > arr[ mid ] )
		{
			low = mid + 1;
		}
		else if ( x < arr[ mid ] )
		{
			high = mid - 1;
		}
		else
		{
			return mid;
		}
	}
	return -1;
}

//*****************************************************
//�������ܣ��ݹ鷨���ֲ���
//����������������飬����Ԫ��x��low��high
//�����������
//����ֵ��	�ɹ������±꣬ʧ�ܷ���-1
//*****************************************************
int BinSearchRecu( BSTelement *arr, BSTelement &x, int low, int high )
{
	int mid;
	if ( low > high )  //�ݹ����������
	{
		return -1;
	}
	else
	{
		mid = ( low + high ) / 2;
		if ( x > arr[ mid ] )
		{
			return BinSearchRecu( arr, x, mid + 1, high );
		}
		else if ( x < arr[ mid ] )
		{
			return BinSearchRecu( arr, x, low, mid - 1 );
		}
		else
		{
			return mid;
		}
	}
}
//*****************************************************
//�������ܣ�
//���������
//���������
//����ֵ��
//*****************************************************
