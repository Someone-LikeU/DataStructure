#include "sort.h"
#include <iostream>
#include <cstdlib>
#include <Windows.h>
#include <string>
using namespace std;

//*********************************************************
//�������ܣ�
//���������
//���������
//����ֵ��
//*********************************************************

//*********************************************************
//�������ܣ���ӡ���
//������������飬����
//�����������
//����ֵ�� 	��
//*********************************************************
void ShowResult( ElementType *arr, int &len )
{
	int i;
	for ( i = 0; i < len; i++ )
	{
		cout << arr[ i ] << " ";
	}
	cout << "\n";
}

//*********************************************************
//�������ܣ�ֱ�Ӳ��������㷨
//�������������������arr�����鳤��len��Re�Ƿ�ݼ���show�Ƿ���ʾ�������
//����������ź��������arr
//����ֵ�� 	��
//*********************************************************
void InsertSort( ElementType *arr, int len, bool &Re, bool &show )
{
	int i, j ,cnt = 0;	  //a counter
	if ( Re == false )		//��������
	{
		for ( i = 2; i <= len; i++ )			//begin with second element, exeute insert operation
		{							  //use arr[0] as a solider
			arr[0] = arr[ i ];				 //arr[0] represent the num to be insert
			j = i - 1;							//j is the i pre num 's index
			while ( arr[ j ] > arr[0] )	 //increase order sort
			{
				arr[ j + 1 ] = arr[ j ];   //move a[j] to it's back
				cnt++;
				j--;
			}
			arr[ j + 1 ] = arr[0]; //insert arr[0]
			if ( show == true )		 //show each steps
			{
				cout << "�� " << i - 1 << " �������\n";
				ShowResult( arr, len );
				Sleep( 500 );
			}
		}
	}
	else	  //decrease order sort
	{
		for ( i = 2; i <= len; i++ )			//begin with second element, exeute insert operation
		{							  //use arr[0] as a solider
			arr[0] = arr[ i ];				 //arr[0] represent the num to be insert
			j = i - 1;							//j is the i pre num 's index
			while ( arr[ j ] > arr[0] )	 //increase order sort
			{
				arr[ j + 1 ] = arr[ j ];   //move a[j] to it's back
				cnt++;
				j--;
			}
			arr[ j + 1 ] = arr[0]; //insert arr[0]
			if ( show == true )		 //show each steps
			{
				cout << "�� " << i - 1 << " �������\n";
				cout << "�� " << i - 1 << " �������\n";
				ShowResult( arr, len );
				Sleep( 500 );
			}
		}
	}
	cout << "\nFor " << len << " elements, Insert Sort algorithm moved elements " << cnt << " tiems";
}

//*********************************************************
//�������ܣ�ϣ������
//�����������������arr�����鳤��r��show��������������dh���䳤�ȣ�
//����������ź��������arr
//����ֵ�� 	��
//*********************************************************
void ShellSort( ElementType *arr, int r, bool &show, int *dh, int dhlen )
{
	//��������1.5.19.����������4^i - 3 * 2 ^ i + 1
	//1 4 13 40 121 364 1093 3280... h = 1 h = 3 * h +1
	//1.3.7......2^k - 1
	//1.4.13........����3^k - 1) / 2
	int i, j, d, step, temp;
	int cntCom, cntMove;
	cntCom = cntMove = 0;
	if ( show == true )
	{
		for ( step = dhlen - 1; step >= 0; step-- )//�Ӳ���������ѡ�񲽳�
		{
			d = dh[ step ]; //ÿ�δӲ���������ѡ�񲽳�
			for ( i = d; i < r; i++ )	   //���β���Ԫ�ص�ǰ���������
			{								   //iָʾ����Ԫ��
				temp = arr[ i ];				  //�ڳ���λ��jָʾ��λ	   
				for ( j = i; j >= d && arr[ j - d ] > temp; j -= d )
				{
					arr[ j ] = arr[ j - d ];   //�ƶ�Ԫ��
					//j-=d	jǰ��
					cntCom++; //�Ƚϴ���++
					cntMove++;	//�ƶ�����++
				}
				arr[ j ] = temp;
				cntMove++;	//�ƶ�����++
			}
			ShowResult( arr, r ); //��ӡһ������Ľ��
			Sleep( 500 );
		}
	}
	else
	{
		for ( step = dhlen - 1; step >= 0; step-- )//�Ӳ���������ѡ�񲽳�
		{
			d = dh[ step ]; //ÿ�δӲ���������ѡ�񲽳�
			for ( i = d; i < r; i++ )	   //���β���Ԫ�ص�ǰ���������
			{								   //iָʾ����Ԫ��
				temp = arr[ i ];				  //�ڳ���λ��jָʾ��λ	   
				for ( j = i; j >= d && arr[ j - d ] > temp; j -= d )
				{
					arr[ j ] = arr[ j - d ];   //�ƶ�Ԫ��
					//j-=d	jǰ��
					cntCom++; //�Ƚϴ���++
					cntMove++;	//�ƶ�����++
				}
				arr[ j ] = temp;
				cntMove++;	//�ƶ�����++
			}
		}
	}
	cout << "�ò������бȽϴ��� " << cntCom << " ������Ԫ�ش��� " << cntMove << endl;
}

//*********************************************************
//�������ܣ���������Ļ���
//������������飬��������λ��s��t������Re���м�Ԫ��λ��cutpoint
//������������ֺ������
//����ֵ�� 	��
//*********************************************************
void Partition( ElementType *arr, int s, int t, bool &Re, int &cutPoint, int &cntComp, int &cntExchange )
{
	int x, i, j;
	x = arr[ s ]; //save mid element to temp element x to make a empty palce
	i = s;		  //init search place
	j = t;
	if ( Re == false )  //increase
	{
		while ( i != j )	   //��������λ��δ�غϣ�����
		{
			while ( i < j && arr[ j ] > x )		//�Ӻ����������м�Ԫ��С����
			{
				j--;
				cntComp++;  //�Ƚϴ�����1
			}
			if ( i < j )				  //�ҵ��˾ͷŵ�ǰ��Ŀ�λ��
			{
				arr[ i ] = arr[ j ];
				cntExchange++;  //����������1
				++i;
			}
			while ( i < j && arr[ i ] < x )	  //��ǰ���ұ��м�Ԫ�ش����
			{
				i++;
				cntComp++;  //�Ƚϴ�����1
			}
			if ( i < j )						  //�ҵ��˾Ͱ������������λ��
			{
				arr[ j ] = arr[ i ];
				cntExchange++;  //����������1
				--j;
			}
		}
	}
	else			  //decrease order
	{
		while ( i != j )	   //��������λ��δ�غϣ�����
		{
			while ( i < j && arr[ j ] > x )		//�Ӻ����������м�Ԫ��С����
			{
				j--;
				cntComp++;  //�Ƚϴ�����1
			}
			if ( i < j )				  //�ҵ��˾ͷŵ�ǰ��Ŀ�λ��
			{
				arr[ i ] = arr[ j ];
				cntExchange++;  //����������1
				++i;
			}
			while ( i < j && arr[ i ] < x )	  //��ǰ���ұ��м�Ԫ�ش����
			{
				i++;
				cntComp++;  //�Ƚϴ�����1
			}
			if ( i < j )						  //�ҵ��˾Ͱ������������λ��
			{
				arr[ j ] = arr[ i ];
				cntExchange++;  //����������1
				--j;
			}
		}
	}
	arr[ i ] = x;		 //���м�Ԫ�طŵ�����λ����
	cutPoint = i; //�����м�Ԫ�ص�λ��
}

//*********************************************************
//�������ܣ���������
//������������飬���鳤�ȣ���������λ��s��t������Re����ʾ���show
//����������ź��������
//����ֵ�� 	��
//*********************************************************
void QuickSort( ElementType *arr, int len, int s, int t, bool &Re, int &cntComp, int &cntExchange )
{
	int i;
	if ( s < t )						  //������������Ԫ��
	{
		Partition( arr, s, t, Re, i,cntComp, cntExchange );	//�Ƚ���һ�λ���
		QuickSort( arr, len, s, i - 1, Re, cntComp, cntExchange );
		QuickSort( arr, len, i + 1, t, Re, cntComp, cntExchange );
	}
}

void QuickShow( ElementType *arr, int len, int s, int t, bool &Re, int &cntComp, int &cntExchange )
{
	int i;
	if ( s < t )						  //������������Ԫ��
	{
		Partition( arr, s, t, Re, i,cntComp, cntExchange );	//�Ƚ���һ�λ���
		DrawResult( arr, len, i );
		Sleep( 250 );
		QuickShow( arr, len, s, i - 1, Re, cntComp, cntExchange );
		QuickShow( arr, len, i + 1, t, Re, cntComp, cntExchange );
	}
}

//*********************************************************
//�������ܣ�build a max heap
//���������an array, root place p, total size n
//���������a max heap
//����ֵ�� 	��
//*********************************************************
void PercDown( ElementType *arr, int p, int &n )
{
	int parent, child;
	ElementType x;
	x = arr[ p ];  //ȡ����ֵ
	for ( parent = p; ( parent * 2 + 1 ) < n; parent = child )
	{
		child = parent * 2 + 1;		   //�����±��һ��ʼ�Ļ����������±�Ϊ2*i+1
		if ( ( child != n - 1 ) && ( arr[ child ] < arr[ child + 1 ] ) )
		{
			child++;				  //�ҵ������Ǹ��ӽڵ�
		}
		if ( x >= arr[ child ] )
		{
			break;   //find the suitable place
		}
		else			  //otherwise , go down to find the suitable place
		{
			arr[ parent ] = arr[ child ];
		}
	}
	arr[ parent ] = x;
}

//*********************************************************
//�������ܣ�heap sort
//���������array and it's len and show
//���������an sorted array
//����ֵ�� 	none
//*********************************************************
void HeapSort( ElementType *arr, int len, bool &show )
{
	int i;
	for ( i = len / 2 - 1; i >= 0; i-- ) //first, build the max heap
	{
		PercDown( arr, i, len );
	}
	if ( show == true )					//show each steps 's result
	{
		for ( i = len - 1; i > 0; i-- )
		{
			//delete the top of heap, that means swap top and arr[i]
			swap( arr[ 0 ], arr[ i ] );
			PercDown( arr, 0, i );
			DrawResult( arr, len, i );
			Sleep( 250 );
		}
	}
	else
	{
		for ( i = len - 1; i > 0; i-- )
		{
			//delete the top of heap, that means swap top and arr[i]
			swap( arr[ 0 ], arr[ i ] );
			PercDown( arr, 0, i );
		}
	}
}
//*********************************************************
//�������ܣ�
//���������
//���������
//����ֵ��
//*********************************************************
void swap( ElementType &a, ElementType &b )
{
	ElementType t = a;
	a = b;
	b = t;
}

//*********************************************************
//�������ܣ�
//���������
//���������
//����ֵ��
//*********************************************************
void Merge( ElementType A[ ], ElementType TmpA[ ], int L, int R, int RightEnd, int &cntcmp )
{ /* �������A[L]~A[R-1]��A[R]~A[RightEnd]�鲢��һ���������� */
	int LeftEnd, NumElements, Tmp;
	int i;

	LeftEnd = R - 1; /* ����յ�λ�� */
	Tmp = L;         /* �������е���ʼλ�� */
	NumElements = RightEnd - L + 1;

	while ( L <= LeftEnd && R <= RightEnd )
	{
		if ( A[ L ] <= A[ R ] )
			TmpA[ Tmp++ ] = A[ L++ ]; /* �����Ԫ�ظ��Ƶ�TmpA */
		else
			TmpA[ Tmp++ ] = A[ R++ ]; /* ���ұ�Ԫ�ظ��Ƶ�TmpA */
		cntcmp++;
	}

	while ( L <= LeftEnd )
		TmpA[ Tmp++ ] = A[ L++ ]; /* ֱ�Ӹ������ʣ�µ� */
	while ( R <= RightEnd )
		TmpA[ Tmp++ ] = A[ R++ ]; /* ֱ�Ӹ����ұ�ʣ�µ� */

	for ( i = 0; i < NumElements; i++, RightEnd-- )
		A[ RightEnd ] = TmpA[ RightEnd ]; /* �������TmpA[]���ƻ�A[] */
}

//*********************************************************
//�������ܣ��鲢����������
//���������
//���������
//����ֵ��
//*********************************************************
void Msort( ElementType A[ ], ElementType TmpA[ ], int L, int RightEnd, int &cntcmp )
{ /* ���ĵݹ������� */
	int Center;

	if ( L < RightEnd )
	{
		Center = ( L + RightEnd ) / 2;
		Msort( A, TmpA, L, Center, cntcmp );              /* �ݹ������ */
		Msort( A, TmpA, Center + 1, RightEnd, cntcmp );     /* �ݹ����ұ� */
		Merge( A, TmpA, L, Center + 1, RightEnd, cntcmp );  /* �ϲ������������� */
	}
}

//*********************************************************
//�������ܣ��鲢������ں���
//�����������������
//����������źõ�����
//����ֵ��	��
//*********************************************************
void MergeSort( ElementType A[ ], int N, int &cntcmp )
{ /* �鲢���� */
	ElementType *TmpA;
	TmpA = new ElementType[ N ];

	if ( TmpA != NULL )
	{
		Msort( A, TmpA, 0, N - 1, cntcmp );
		delete TmpA;
	}
	else cout << "�ռ䲻��";
}


void ChooseSort( ElementType *arr, int len )
{
	int low, high, p, cntCom, cntExch;
	low = p = cntCom = cntExch = 0;
	high = len - 1;
	while ( p < len )	 //��һ��ѡ�񣬰�3�ı����ŵ��������
	{
		if ( arr[ p ] % 3 == 0  )//���pָʾ��Ԫ����3�ı������ͺ�lowλ��ָʾ�Ľ���
		{
			swap( arr[ p ], arr[ low ] );
			cntExch++;  //��������++
			low++;
		}
		p++;
		cntCom++;
	}
	p = high;  //Ȼ��ӱ�β��ʼ��ǰ�������ѳ�3��2��Ԫ�طŵ����ұ�
	while ( p >= low )
	{
		if ( arr[ p ] % 3 == 2 )
		{
			swap( arr[ p ], arr[ high ] );
			high--;
			cntExch++;
		}
		p--;
		cntCom++;
	}
	cout << "�Ƚϴ��� " << cntCom << " ���������� " << cntExch << " .\n";
}
