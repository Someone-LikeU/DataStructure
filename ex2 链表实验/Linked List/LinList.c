#include "LinkList.h"
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>


//*********************************************************
//�������ܣ�ͷ�巨��������
//�����������
//�����������
//����ֵ�� 	�ɹ������򷵻�һ�������ͷ�����򷵻�NULL
//*********************************************************
List CreateListInsertHead()
{
	List Head;
	node cur;
	int num;
	Head = ( node ) malloc( SIZE );
	if ( Head == NULL )
	{
		printf( "Memory allocation failed, program exit !\n" );
		system( "pause" );
		return NULL;
	}
	Head->Next = NULL;
	printf( "������һЩ�����Կո�ָ�����#������\n" );
	while ( scanf( "%d", &num ) == 1 )
	{
		cur = ( node ) malloc( SIZE );
		if ( cur == NULL )
		{
			printf( "Memory allocation failed, program exit !\n" );
			system( "pause" );
			return NULL;
		}
		cur->Element = num;
		cur->Next = Head->Next;
		Head->Next = cur;
	}
	return Head;
}

//*********************************************************
//�������ܣ�β�巨��������
//�����������
//�����������
//����ֵ�� 	�ɹ������򷵻�һ�������ͷ�����򷵻�NULL
//*********************************************************
List CreateListInsertRear( )
{
	List Head;	  //ͷ���
	node cur, pre;
	int num;
	pre = ( node ) malloc( SIZE );   //����ͷ�ڵ�
	Head = pre;
	Head->Next = NULL;
	if ( Head == NULL )
	{
		printf( "Memory allocation failed, program exit !\n" );
		system( "pause" );
		return NULL;
	}
	printf( "������һЩ������#����\n" );  //�������ַ���������
	while ( scanf( "%d", &num ) == 1 )
	{
		cur = ( node ) malloc( SIZE );
		if ( cur == NULL )
		{
			printf( "Memory allocation failed, program exit !\n" );
			return NULL;
		}
		cur->Element = num;
		cur->Next = NULL;
		pre->Next = cur;
		pre = cur;
	}
	return Head;
}

//*********************************************************
//�������ܣ��ж�һ�������Ƿ�Ϊ�ձ�
//���������һ������ı�ͷ
//�����������
//����ֵ�� 	bool���ͱ���
//*********************************************************
bool IsEmpty( List Head )
{
	return Head->Next == NULL;
}

//*********************************************************
//�������ܣ��ж�����ͷ����Ƿ�Ϊ��
//�����������ͷ
//�����������
//����ֵ�� 	boolֵ
//*********************************************************
bool IsExist( List Head )
{
	if  ( Head == NULL )
	{
		printf("WTF!\n");
	}
	return Head == NULL;
}

int TravelList( List Head )
{
	if ( IsExist( Head ) )		//���ж����ͷ�ڵ��Ƿ����
	{
		printf( "��������.\n" );
		return 1;
	}
	if ( IsEmpty( Head ) )	   //���ж��Ƿ�Ϊ��
	{
		printf( "���Ǹ��ձ�.\n" );
		return 1;
	}
	printf( "�����������Ԫ�أ�\n" );
	node cur = Head->Next;
	while ( cur != NULL )
	{
		printf( "%2d ", cur->Element );
		cur = cur->Next;
	}
	return 0;  //�ɹ�����������0
}

//*********************************************************
//�������ܣ���������
//���������һ����ͷ
//�����������
//����ֵ�� 	ʧ�ܷ���1���ɹ�����0
//*********************************************************
int DestoryList( List Head )
{
	if ( IsEmpty( Head ) ) //�ж��Ƿ�Ϊ�գ��ǵĻ���ʣ��ѭ��ʱ��
	{
		free(Head);
		Head = NULL;
		return 0;
	}
	node P, Temp;
	P = Head;	 //��Ԫ�ص�λ��
	while ( P != NULL )
	{
		Temp = P->Next;
		free( P );
		P = Temp;
	}
	return 0;
}

//*********************************************************
//�������ܣ�������ֽ������Ԫ�������ż��Ԫ������
//���������һ����ͷ
//�����������
//����ֵ�� 	0��ʾ�ɹ���1��ʾʧ��
//*********************************************************
int Separate (List Head)
{
    List p1, p2;  //�ݴ���żԪ�ص�������
    p1 = (node)malloc(SIZE);
    p2 = (node)malloc(SIZE);
    if ( p1 == NULL || p2 == NULL )
    {
        printf("memory allocate failed!\n");
        system("pause");
        return 1;
    }
    p1->Next = NULL;
    p2->Next = NULL;
    node cur = Head->Next, t, Tp1, Tp2;
    Tp1 = p1; //tp1��tp2����β�巨�����±�
    Tp2 = p2;
    while (cur != NULL)
    {
        t = (node)malloc(SIZE);  //cur != NULL, �������ɸ����
        if( t == NULL )
        {
            printf("memory allocate failed!\n");
            system("pause");
            return 1;
        }
        t->Element = cur->Element;
        t->Next = NULL;
        if (cur->Element % 2 == 0)  //ż�����ŵ�p1��
        {
            Tp1->Next = t;
            Tp1 = t;
        }
        else                                //�������ŵ�p2��
        {
        	Tp2->Next = t;
            Tp2 = t;
        }
        cur = cur->Next;
    }
    printf("ԭ��Ϊ��");                 //���ԭ��ͷֿ��ı�
    TravelList(Head);
    printf("\nż����");
    TravelList(p1);
    printf("\n������");
    TravelList(p2);
    DestoryList(p1);                    //���ٱ�1���ͱ�2
    DestoryList(p2);
    return 0;
}

//*********************************************************
//�������ܣ����������������Ĺ���Ԫ�ط�����������
//�����������1��2��3
//�����������
//����ֵ�� 	  �ɹ������±��ͷ��ʧ�ܷ��ؿ�ָ��
//*********************************************************
List FindCommon( List L1, List L2 )
{
	List L = NULL;			//Ҫ���ص��±�
	node p = (node)malloc(SIZE);
	node p1, p2,cur;
	if ( NULL == p )
	{
		printf("memory allocate failed. Please try again.");
		return NULL;
	}
	p->Next = NULL;
	L = p;							//����β�巨׼���������
	p1 = L1->Next;
	p2 = L2->Next;
	while ( p1 != NULL && p2 != NULL )
	{
		if  ( p1->Element < p2->Element )
			p1 = p1->Next;
		else if ( p1->Element > p2->Element )
			p2 = p2->Next;
		else 											//��ȣ���β�嵽�±�
		{
			cur = (node)malloc(SIZE);
			if ( NULL == cur )
			{
				printf("memory allocate failed. Please try again.");
				return NULL;
			}
			cur->Element = p1->Element;
			cur->Next = NULL;
			p->Next = cur;
			p = cur;						//β��������
			p1 = p1->Next;			//����p1,p2
			p2 = p2->Next;
		}
	}
	return L;								//�����±��ͷ
}

//*********************************************************
//�������ܣ�ɾ��������������ظ�Ԫ��
//�����������ͷ
//���������ȥ�غ�ı�
//����ֵ�� 	  ��
//*********************************************************
void OrderedListDelSame( List Head )//���ԣ�����һ��1 2 3 4 5 6 7 7 7 10û�� 11.11��22.20
{
	node p1, p2, t; //p1,p2������t��u����ɾ�����
	p1 = Head->Next;
	p2 = p1->Next;
	while ( p2  != NULL )
	{
		if ( p1->Element != p2->Element ) //��������������Ԫ�ز���
		{
			p1 = p1->Next;								 //��ͬʱ����p1,p2
			p2 = p2->Next;
		}
		else 	//��ȣ������p2ֱ����һ��������p1�Ľ�㣬
		{
			while ( p2 != NULL && p2->Element == p1->Element )
			{
				t = p2;					//һ�ߺ���һ�߻����ظ����
				p2 = p2->Next;
				free(t);
			}
			p1->Next = p2;
		}
	}
}

//*********************************************************
//�������ܣ������ɾ�����
//���������λ��i����ͷ
//�����������
//����ֵ�� 	int�ͱ�����0��ʾ�ɹ���1��ʾʧ��
//*********************************************************
int DeleteElement( int i, List Head )
{
	if ( IsEmpty( Head) ) //�ձ�����1
	{
		printf("�ձ����ȴ���һ����\n");
		return 1;
	}
	int len = ListLength( Head );
	if ( i < 1 || i > len )
	{
		printf("λ��Խ�磬����ѡ \n");
		return 1;
	}
	node cur, u;
	cur = Head;
	int j = 1;
	while ( j < i )		//�ҵ���i�Ž���ǰ�����
	{
		cur = cur->Next;
		j++;
	}
	u = cur->Next; //u��ΪĿ����
	cur->Next = u->Next;	//���u��ʵ��ɾ��
	free(u);
	u = NULL;
	return 0;
}

//*********************************************************
//�������ܣ��ڵ�i��������Ԫ��x
//���������ElementType ����X ��һ����ͷ��һ��λ�ò���λ�ý��
//�����������
//����ֵ�� 	int�ͱ�����0��ʾ�ɹ���1��ʾʧ��
//*********************************************************
int Insert( ElementType X, List Head, int i )
{
	if ( IsExist( Head ) )	//���ж����ͷ��㲻���ڣ���ʾ������ʧ��
	{
		printf( "This list does not exist, please create it first.\n" );
		return 1;
	}
	else if ( i < 1 || i > ListLength( Head ) + 1) //Խ��
		return 1;

	node pre, New;		  //preָ��ָ��P�������ǰһ�����
	New = ( node ) malloc( SIZE );	 //�·���һ�����
	if ( New == NULL )
	{
		printf( "Memory allocation failed.\n" );
		return 1;
	}
	pre = FindPrevious( i, Head );	//��i- 1�����
	New->Element = X;
	New->Next = pre->Next;					//New������һ�������pre����һ�����
	pre->Next = New;						//pre����һ�������new
	return 0;
}

//*********************************************************
//�������ܣ��ڵ���������в���Ԫ�أ��������Ȼ����
//���������ElementType ����X ����ͷ
//�����������
//����ֵ�� 	int�ͱ�����0��ʾ�ɹ���1��ʾʧ��
//*********************************************************
int InsertIncrease( ElementType x, List Head )
{
    node cur = Head,p;
    while ( cur->Next != NULL && cur->Next->Element < x )  //�ҵ����һ��С�ڴ�����Ԫ�صĽ��
    {
        cur = cur->Next;
    }
    p = (node)malloc(SIZE); //�����½ڵ�
    if ( NULL == p )
    {
        printf("memory allocate failed.\n");
        return 1;
    }
    p->Element = x;
    p->Next = cur->Next;
    cur->Next = p;
    return 0;
}

//*********************************************************
//�������ܣ�����������
//���������һ����ͷ
//�����������
//����ֵ�� 	 �ɹ����ر��ȣ�ʧ�ܷ���-1
//*********************************************************
int ListLength( List Head )
{

	if (IsExist(Head) )
	{
		printf("return -1.\n");
		return -1;
	}
	node cur = Head->Next;
	int count = 0;
	while ( cur != NULL )
	{
		count++;
		cur = cur->Next;
	}
	return count;
}

//*********************************************************
//�������ܣ��ҵ�Ԫ��X���ڽ��
//���������ElementType���ͱ���X�������ͷ
//�����������
//����ֵ�� 	Ԫ�ش��ھͷ���һ�����ָ�룬���򷵻�һ��NULLָ��
//*********************************************************
node Find( ElementType X, List Head )
{
	node cur = Head->Next;
	while (  cur != NULL &&  cur->Element != X )  //�ҵ�Ŀ����
	{
		cur = cur->Next;
	}
	if ( cur == NULL )	//�ҵ����curΪ�գ�˵��Ԫ�ز����ڣ���ʾ�û�������NULL
	{
		printf( "������Ԫ��%d������ѡ\n", X);
		return NULL;
	}
	else									   //Ԫ�ش��ڣ�����������
	{
		return cur;
	}
}

//*********************************************************
//�������ܣ����ص�i���ڵ��ǰ�����
//�����������i�����,��ͷ
//�����������
//����ֵ�� 	  Ԫ�ش��ڣ��ͷ���һ�����ָ�룬���򷵻ؿ�
//*********************************************************
node FindPrevious( int i, List Head )
{
	int len = ListLength(Head);
	if (i < 1 || i > len )
	{
		printf("λ��Խ�磬�����ԡ�\n");
		return NULL;
	}
	node cur = Head; //Ҫ�ӵ�һ�����ݽ�㿪ʼ�ң����԰�ͷ�ڵ㸳��cur
	int j;
	for ( j = 0 ; j < i - 1 ; j++ )
		cur = cur->Next;
	return cur;
}

//*********************************************************
//�������ܣ������ȡ���Ԫ��
//���������ͷָ��
//�����������
//����ֵ�� 	�������i������Ԫ��, -1��ʾԽ��
//*********************************************************
ElementType GetElementInOrder( List Head, int i )
{
	int total = ListLength( Head ), t = 1;
	node cur = Head->Next; //��һ�����
	if ( i < 1 || i > total )  //Խ��
	{
	    return -1;
	}
	while ( t != i )
	{
		cur = cur->Next;
		t++;
	}
	return cur->Element;
}

//*********************************************************
//�������ܣ�ԭ������һ��������
//���������һ����ͷ
//������������ú�ı�
//����ֵ�� 	1��ʾʧ�ܣ�0��ʾ�ɹ�
//*********************************************************
int ReverseList( List Head )
{
	if(IsEmpty(Head) || ListLength(Head) == 1) //�ձ����ֻ��һ�����
		return 1;
	node p1, p2, t;
	p1 = Head;			 		//p1ָ��ͷ�ڵ�
	p2 = p1->Next; 		//p2ָ���һ��Ԫ�ؽ��
	t = p2->Next;				//tָ��ڶ���Ԫ�ؽ��
	p2->Next = NULL;    //�ȶϿ�ͷ���ͺ��������
	while ( t != NULL )	//tָ��NULLʱ�ͽ���
	{
		p1 = p2;					//�Ⱥ�������ָ��
		p2 = t;
		t = t->Next;
		p2->Next = p1;		//���������������ڽ���ָ��
	}
	Head->Next = p2;		//��һ��Ԫ�ؽ��
	return 0;
}

//*********************************************************
//�������ܣ��ϲ������������γ�һ�����ϣ�ֻ���±�1��ͷ
//�����������1��2
//�����������1
//����ֵ�� 	  ��
//*********************************************************
void UnionAandB( List L1, List L2 )
{
	node t, p1, p2, u, s; //t�����ͷű�2�Ľ�㣬uΪ��2����ʱָ��
	p1 = L1->Next;			//������ͷ��㿪ʼ����
	p2 = L2->Next;
	s = L1;//sΪ��1�Ľ���ǰ����㣬������ָ��ͷ����ֹ��1Ϊ��ʱ�����bug
	while ( p1 != NULL && p2 != NULL )
	{
		if ( p1->Element == p2->Element )		//�����1��ǰԪ�ص��ڱ�2��
		{
			t = p2;							//��ʱָ��
			p2 = p2->Next; 		//�ͺ���p2��Ȼ������Ƚ�
			free(t);						//�ͷŵ���2�бȽϹ��Ľ��
		}
		else if ( p1->Element < p2->Element )  //С��
		{
			s = p1;						//�ͺ���p1������֤sʼ����p1��ǰ�����
			p1 = p1->Next;
		}
		else  //���ڣ�˵�����Բ����1
		{		//���ڶ��ǵ��������Դ���ʱtһ��ָ��p1��ǰ��
			u = p2->Next; //��ʱָ��p2����һ�����
			p2->Next = s->Next;		//����2�е�ǰ�������1
			s->Next = p2;
			s = s->Next;		 //����p1��ǰ�����
			p2 = u; 				//����p2ָ��ԭ��p2����һ���ڵ�
		}
	}
	//����while�����󣬱�2����û�б����꣬���2ʣ�µĽ�㶼�ܲ���
	while( p2 != NULL )
	{
		s->Next = p2;
		s = p2;
		p2 = p2->Next;
	}
	free(L2);//����ͷŵ�L2ͷ���
	L2 = NULL;
}

//*********************************************************
//�������ܣ�
//���������
//���������
//����ֵ��
//*********************************************************

//*********************************************************
//�������ܣ�ʵ�ּ���C = A��B
//��������������ʾ�ļ���A��B��C
//�����������C
//����ֵ�� 	  �ɹ�����0��ʧ�ܷ���1
//*********************************************************
int AInsertBToC( List A, List B, List C )
{
	node pA, pB, pC, cur;			//������a��b����ʾA��B��ǰԪ��
	pA = A->Next;
	pB = B->Next;
	pC = C;
	cur = NULL; 						//curΪ׼��������½ڵ㣬׼���������
	while ( pA != NULL && pB != NULL )
	{
		if ( pA->Element < pB->Element ) //a С�� b
		{
			//printf("pA = pA->Next\n");
			pA = pA->Next;	//����pA�������Ƚ�
		}
		else if ( pA->Element > pB->Element ) //����
		{
			//printf("pB = pB->Next\n");
			pB = pB->Next;		//�ͺ���pB
		}
		else				//��ȣ���β�嵽C��Ȼ��ͬʱ����pA��pB
		{
			cur = (node)malloc(SIZE);
			if ( NULL == cur )		//�����ڴ�ʧ�ܣ�����1
			{
				printf("Memory allocation failed!\n");
				return 1;
			}
			cur->Element = pA->Element;
			pC->Next = cur;
			pC = cur;					//β�嵽C��ϣ�Ȼ�����A��B
			pA = pA->Next;
			pB = pB->Next;
			//printf("pC = cur;\n");
		}
	}
	pC->Next = NULL;
	return 0;
}

//*********************************************************
//�������ܣ� ���������A��B��ʵ��C =  A��B
//��������� �����ʾ�ļ���A��B��C
//��������� ��C
//����ֵ�� 	   �ɹ�����0��ʧ�ܷ���1
//*********************************************************
int AUnionBToC( List A, List B, List C )
{
	node pA, pB, pC, cur;			//������a��b����ʾA��B��ǰԪ��
	pA = A->Next;
	pB = B->Next;
	pC = C;
	cur = NULL; 						//curΪ׼��������½ڵ㣬׼���������
	while ( pA != NULL && pB != NULL )//Ϊȷ���������c����Ȼ��������
	{ 																//ÿ�αȽϺ�ֻβ���С���Ǹ���C
		cur = (node)malloc(SIZE);	//�ȷ����㣬β�嵽C��ֵ���ݺ���ıȽ�����ٸ�
		if ( NULL == cur )
		{
			printf("Memory allocate failed.");			//�����ڴ�ʧ�ܣ�����1
			return 1;
		}
		pC->Next = cur;
		pC = cur;
		if( pA->Element < pB->Element ) //a < b
		{
			cur->Element = pA->Element;
			pA = pA->Next;
		}
		else if( pA->Element > pB->Element ) //a > b
		{
			cur->Element = pB->Element;
			pB = pB->Next;
		}
		else  //a = b
		{
			cur->Element = pB->Element;
			pA = pA->Next;
			pB = pB->Next;
		}
	}
	//whileִ�����A��B���ܻ�û�����꣬��ʣ�µĶ����Բ���C
	while ( pB != NULL )
	{
		cur = (node)malloc(SIZE);
		if ( NULL == cur )
		{
			printf("Memory allocate failed.");
			return 1;
		}
		cur->Element = pB->Element;
		pC->Next = cur;
		pC = cur;
		pB = pB->Next;
	}
	while(pA != NULL)
	{
		cur = (node)malloc(SIZE);
		if ( NULL == cur )
		{
			printf("Memory allocate failed.");
			return 1;
		}
		cur->Element = pA->Element;
		pC->Next = cur;
		pC = pC->Next;
		pA = pA->Next;
	}
	pC->Next = NULL;
	return 0;
}

//*********************************************************
//�������ܣ� ����ʵ��C = A - B
//��������� ��ͷA��B��C
//��������� ��C
//����ֵ�� 	   �ɹ�����0��ʧ�ܷ���1
//*********************************************************
int ASubBToC( List A, List B, List C )
{
	node pA, pB, pC, cur;			//������a��b����ʾA��B��ǰԪ��
	pA = A->Next;
	pB = B->Next;
	pC = C;
	cur = NULL; 						//curΪ׼��������½ڵ㣬׼���������
	while ( pA != NULL && pB != NULL )
	{
		if ( pA->Element < pB->Element )  //a < b˵��a��������
		{
			cur = (node)malloc(SIZE);			//�ͷ������ڴ��C
			if (cur == NULL )
			{
				printf("memory allocate failed.\n");
				return 1;
			}
			cur->Element = pA->Element; //β�嵽C
			pC->Next = cur;
			pC = cur;
			pA = pA->Next;
		}
		else if (pA->Element == pB->Element)	// ��ȣ�˵��������Ҫ��ͬʱ����
		{
			pA = pA->Next;
			pB = pB->Next;
		}
		else 				//���ڣ������B
		{
			pB = pB->Next;
		}
	}
	//����while�϶��Ǳ�B�Ƚ�����������ʣ�µ�A�϶�����Ҫ��
	while ( pA != NULL )
	{
		    cur = (node)malloc(SIZE);			//�ͷ������ڴ��C
			if (cur == NULL )
			{
				printf("memory allocate failed.\n");
				return 1;
			}
			cur->Element = pA->Element; //β�嵽C
			pC->Next = cur;
			pC = cur;
			pA = pA->Next;
	}
	cur->Next = NULL;
	return 0;
}

//*********************************************************
//�������ܣ� ����ʵ��A = A��B
//��������� ��ͷA��B��C
//��������� ��C
//����ֵ�� 	   ��
//*********************************************************
void AInsertBToA( List A, List B )
{
	node pA, pB, t, u; //tΪpA��ǰ����㣬u���ڻ��ս��
	t = A;
	pA = A->Next;
	pB = B->Next;			//������a��b����ʾA��B��ǰԪ��
	while ( pA != NULL && pB != NULL )
	{
		if ( pA->Element == pB->Element ) //a = b,˵��a���㽻��Ҫ�󣬾�ͬʱ����pA��pB
		{
			 t = pA;
			 pA = pA->Next;
			 pB = pB->Next;
		}
		else if ( pA->Element > pB->Element)	//a > b,�ͺ���pB�������Ƚ�B�����
		{
			pB = pB->Next;
		}
		else 		//a < b,˵��a�����㽻��Ҫ�󣬾�������ƶ��߻��ս��
		{
			while ( pA->Element < pB->Element )
			{
				u = pA->Next;
				free(pA);
				pA = u;
			}
			t->Next = pA;		//����t��ָ��
		}
	}
}

int AUnionBToA( List A, List B )
{
	node cur, pA, pB, s; //cur���������½ڵ㣬uΪ��2����ʱָ��
	pA = A->Next;			//������ͷ��㿪ʼ����
	pB = B->Next;
	s = A;//sΪpA��ǰ����㣬������ָ��ͷ����ֹ��1Ϊ��ʱ�����bug
	while ( pA != NULL && pB != NULL )
	{
		if ( pA->Element > pB->Element )	//a > b���Ϳ��Բ���b
		{
			cur = (node)malloc(SIZE);
			if ( NULL == cur )     			//����ʧ�ܣ�����1
			{
				return  1;
			}
			cur->Element = pB->Element;
			cur->Next = pA;
			s->Next = cur;
			s = cur;
			pB = pB->Next;			//�ٺ���pB��������B������Ƿ���������
		}
		else if ( pA->Element < pB->Element ) //a < b,����pA�������Ƚ�
		{
			s = pA;    					//pA��ǰ�����Ҳ��Ҫ����
			pA = pA->Next;
		}
		else 									//a = b,��ͬʱ�����ٱȽ�
		{
			s = pA;
			pA = pA->Next;
			pB = pB->Next;
		}
	}
	//B����û�б����꣬��ʣ�µ�b�����Բ���A
	while(pB != NULL )
	{
		cur = (node)malloc(SIZE);
		if ( NULL == cur )     			//����ʧ�ܣ�����1
		{
			return  1;
		}
		cur->Element = pB->Element;
		cur->Next = pA;
		s->Next = cur;
		s = cur;
		pB = pB->Next;
	}
	return 0;
}

//*********************************************************
//�������ܣ� ����ʵ��A = A-B
//��������� ��A��B
//��������� ��A
//����ֵ�� 	   �ɹ�����0��ʧ�ܷ���1
//*********************************************************
int ASubBToA( List A, List B )
{
	node pA, pB, u, s; //cur���������½ڵ㣬uΪ��2����ʱָ��
	pA = A->Next;			//������ͷ��㿪ʼ����
	pB = B->Next;
	s = A;
	while ( pA != NULL && pB != NULL )
	{
		if ( pA->Element == pB->Element )  //a = b,�Ͱ�a��������յ���
		{
			u = pA->Next;
			free(pA);
			pA = u;
			s->Next = pA;					//Ȼ�����s��next���pB
			pB = pB->Next;
		}
		else if ( pA->Element > pB->Element )  //a > b,�ͺ���pB�������Ƚ�
		{
			pB = pB->Next;
		}
		else 								//a < b,��ͬʱ����pA������ǰ��ָ��
		{
			s = s->Next;
			pA = pA->Next;
		}
	}
	return 0;
}

//*********************************************************
//�������ܣ� ����������k������ֵ
//��������� ��ͷ��λ��k
//��������� ��A
//����ֵ�� 	   �ɹ�����0��ʧ�ܷ���1
//*********************************************************
int GetReverseOrder( List Head, int k )
{
	int len = ListLength( Head ),i = 0;
	if ( k < 1 || k > len )			//Խ�磬����1
	{
		return 0;
	}
	node cur = Head->Next;
	while ( i < len - k )				//������k���Ǿ������ȥlen - k��λ�þ��С�
	{
		cur = cur->Next;
		i++;
	}
	printf("������%d��λ���ϵ�Ԫ��Ϊ��%d", k, cur->Element );
	return 1;
}

//*********************************************************
//�������ܣ� �������ȳ�������������Ԫ�ص�������λ��
//��������� ��A��B
//��������� ��
//����ֵ�� 	   ��λ��n
//*********************************************************
void FindMid( List A, List B )
{
	ElementType mid;
	node pA, pB;
	pA = A->Next;
	pB = B->Next;
	int len = ListLength( A ),i = 0; //������ȳ�������������������Ƚ�len��
	while ( i < len )				//ÿ�αȽ���mid���ڽ�С���Ǹ������mid����Ҫ���
	{
		if(pA->Element < pB->Element)
		{
			mid = pA->Element;
			pA = pA->Next;
		}
		else if ( pA->Element > pB->Element )
		{
			mid = pB->Element;
			pB = pB->Next;
		}
		else
		{
			mid = pB->Element;
			pB = pB->Next;
		}
		i++;
	}
	printf("��λ����%d \n",mid);
}

//*********************************************************
//�������ܣ� �жϵ�����A�Ƿ��Ǳ�B���Ӽ�
//��������� ������A��B
//��������� ��
//����ֵ�� 	    true or false
//*********************************************************
bool AisSubB( List A, List B )
{
	node pA, pB;
	bool flag = true;
	pA = A->Next;
	pB = B->Next;
	while (pA != NULL && pB != NULL && flag)
	{
		if ( pA->Element < pB->Element )
		{
			flag = false;			//���a<b����˵���϶������Ӽ���flag��Ϊfalse
		}
		else if ( pA->Element > pB->Element ) //a < b
		{
			pB = pB->Next;		//����pB�������Ƚ�
		}
		else 								//a = b,ͬʱ����
		{
			pA = pA->Next;
			pB = pB->Next;
		}
	}
	return flag;
}
