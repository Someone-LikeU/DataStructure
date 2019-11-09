//**************************************************************
//Filename	         : LinkBiTree.cpp
//Abstract           : ���ļ��Ƕ�����������㷨ʵ���ļ�
//Author  	         : �ܽ���
//Accomplished Date  : 2018.12.9
//Beginning Date     : 2018.11.30
//Student ID         : 2017217866
//**************************************************************

#include "LinkBiTree.h"
#include <cstdlib>
#include <cstdio>
#include <iostream>
#include <queue>
#include <stack>
#include <cstring>
using namespace std;

//*****************************************************
//�������ܣ�
//���������
//���������
//����ֵ��
//*****************************************************

//*****************************************************
//�������ܣ����ʽ�㣬��������������Ĭ�����
//��������������
//�����������
//����ֵ��  ��
//*****************************************************
void Visit( BiTree BT )
{
    cout << BT->data << " ";
}

//*****************************************************
//�������ܣ��ݹ��������������
//����������������
//�����������
//����ֵ��     ��
//*****************************************************
void PreOrderTravel( BiTree BT )
{
    if( BT )
    {
        Visit(BT);                                          //���ʸ��ڵ�
        PreOrderTravel( BT->Left );      //�ݹ��������������
        PreOrderTravel( BT->Right );    //�ݹ��������������
    }
}

//*****************************************************
//�������ܣ��ݹ��������������
//����������������
//�����������
//����ֵ��     ��
//*****************************************************
void MidOrderTravel( BiTree BT )
{
    if(BT)
    {
        MidOrderTravel(BT->Left);       //�������������
        Visit(BT);                                          //���ʸ��ڵ�
        MidOrderTravel(BT->Right);     //�������������
    }
}

//*****************************************************
//�������ܣ��ݹ�������������
//����������������
//�����������
//����ֵ��     ��
//*****************************************************
void LastOrderTravel( BiTree BT )
{
    if (BT)
    {
        LastOrderTravel( BT->Left );    //��������������
        LastOrderTravel( BT->Right ); //��������������
        Visit(BT);                                          //���ʸ��ڵ�
    }
}

//*****************************************************
//�������ܣ��ǵݹ��������������
//�������������
//�����������
//����ֵ��     ��
//*****************************************************
void PreTravelNoRec( BiTree BT )
{
    BiNode *p;
    stack<BiNode*> S;       //Ҫ����һ��ջ
    p = BT;            //��ȻBT���βΣ������ڲ������޸�ʵ�Σ����������Ǹ���ϰ��
    while ( p || !S.empty() )
    {
        if ( p )
        {
            Visit(p);      //�������������ȷ��ʽ��
            S.push(p);      //pָ����ջ
            p = p->Left;    //Ȼ�����������
        }
        else
        {
            p = S.top();    //pΪ��ʱ������һ��ĸ��ڵ�ָ�뵯����p
            S.pop();
            p = p->Right;       //then travel right sib Tree
        }
    }
}

//*****************************************************
//�������ܣ��ǵݹ��������������
//�������������
//�����������
//����ֵ��     ��
//*****************************************************
void MidTravelNoRec( BiTree BT )
{
    BiNode *p;
    stack<BiNode *> S;
    p = BT;
    while ( p || !S.empty() )
    {
        if ( p )            //���ڵ�����ջ�����������������������ط��ʸ��ڵ�
        {
            S.push(p);
            p = p->Left;    //����������
        }
        else
        {
            p = S.top();    //ĳ�������ĸ��ڵ��ջ
            S.pop();
            Visit(p);           //������
            p = p->Right;   //����������
        }
    }
}

//*****************************************************
//�������ܣ��ǵݹ�������������
//�������������
//�����������
//����ֵ��     ��
//*****************************************************
/*void LastTravelNoRec( BiTree BT )
{
    BiNode *p;
    stack<BiNode*> S;     //����������ջ
    int tag[MAXNODES];      //�����������
    int n;
    p = BT;
    while( p != NULL || !S.empty() )
    {
        if ( p )            //pָ�뼴��ǰ���ڵ���ջ��
        {                       //�Ա����ʸ��ڵ��Լ�����������
            S.push(p);
            tag[S.top()] = 0;   //��Ǳ���������
            p = p->Right;
        }
        else        //p is NULL ,but stack is not empty
        {
            p = S.top();        //get stack top, but don't pop, to travel right sib tree
            if ( tag[S.top()] == 0 )   //this imply that left sibTree has been traveled, and right sibtree hasn't been traveled yet
            {
                tag[S.top()] = 1;        //set the tag that current node travel right sibtree
                p = p->Right;
            }
            else    //tag[S.top] == 1, this imply both right and left sibtree have been traveled
            {
                S.pop();        //then pop it
                Visit(p);       //visit a root
                //the pop operation make p useless, so let p point to NULL, go back to get next element of stack
                p = NULL;
            }
        }
    }
}*/

//*****************************************************
//�������ܣ��������Ĳ������
//�������������
//�����������
//����ֵ��     ��
//*****************************************************
void LevelOrderTravel( BiTree BT )
{
    queue<BiNode*> Q;
    BiTree T;
    if ( !BT )                                  //������ֱ�ӷ���
        return ;
    Q.push(BT);                          //�Ȱ��������push��ӣ�
    while ( !Q.empty() )           //���в�Ϊ�գ��ͻ��н��û���ʵ�
    {
        T = Q.front();                   //ȡ����ͷ����������
        Q.pop();                              //����ͷpop��
        Visit( T );                            //����
        if ( T->Left )                       //��������Ϊ�գ�����ӣ����ŷ���������
            Q.push(T->Left);
        if ( T->Right )                    //��������Ϊ�գ���ӣ� �´η���������
            Q.push(T->Right);
    }
}

//*****************************************************
//�������ܣ������������������������
//������������������level
//���������level
//����ֵ��     ��
//*****************************************************
void MidTravelAndLevel( BiTree BT, int Level )
{
    //�����������˼�룬��visit������������������
    if ( BT )
    {
        MidTravelAndLevel( BT->Left, Level + 1 );      //�������������
        cout << BT->data << " �ڵ� " << Level  << " �� " << endl;  //��������Ϣ�����
        MidTravelAndLevel( BT->Right, Level + 1 );      //�������������
    }
}

//*****************************************************
//�������ܣ���������ĸ߶�
//�������������
//�����������
//����ֵ��     ��
//*****************************************************
int GetTreeHeight( BiTree BT )
{
    int hl, hr, MaxH;
    hl = hr = MaxH = 0;
    if ( BT )                                                           //��������������˼�룬
    {
        hl = GetTreeHeight(BT->Left);           //�������������������������߶�
        hr = GetTreeHeight(BT->Right);        //������������������������߶�
        MaxH = (hl > hr) ? hl : hr;                      //ȡ���������
        return MaxH + 1;                                       //������������ټ�1
    }
    return 0;
}

//*****************************************************
//�������ܣ�������������н����
//���������������cnt
//���������cnt
//����ֵ��     ��
//*****************************************************
void TotalNodes( BiTree BT, int &cnt )
{
    //�������������˼�룬����������Ϣ��Ϊ�������һ
    if ( BT )
    {
        cnt++;      //node is not empty, make cnt +1
        TotalNodes( BT->Left, cnt );       //Pre order travel left sib tree
        TotalNodes( BT->Right,cnt );
    }
}

//*****************************************************
//�������ܣ��������������Ҷ�ӽ����
//���������������cnt
//���������cnt
//����ֵ��  ��
//*****************************************************
void NumOfLeaf( BiTree BT, int &cnt )
{
	//�������������˼�룬
	if ( BT )
	{
		if ( !BT->Left && !BT->Right )
			cnt++;
		NumOfLeaf( BT->Left, cnt );	//�������������
		NumOfLeaf( BT->Right, cnt );//�������������
	}
}

//*****************************************************
//�������ܣ����������������Ҷ���
//�������������
//�����������
//����ֵ��     ��
//*****************************************************
void ShowLeaves( BiTree BT )
{
    //�������������˼�룬ֻ������visitǰ��һ�仰
    if ( BT )
    {
        if ( !BT->Left && !BT->Right )  //�������������Ϊ�գ�����Ҷ���
            Visit(BT);
        ShowLeaves( BT->Left);
        ShowLeaves( BT->Right);
    }
}

//*****************************************************
//�������ܣ�����������������2�Ƚ��
//�������������,��������cnt
//���������cnt
//����ֵ��  ��
//*****************************************************
void NumOfDeg2( BiTree BT, int &cnt )
{
	if ( BT )
	{
		if ( (BT->Left != NULL) && (BT->Right != NULL) ) //������������Ϊ�գ�����2��
		{
			cnt++;				 //������+1
			//cout << BT->data << " ";
		}
		NumOfDeg2( BT->Left, cnt );	//�������������
		NumOfDeg2( BT->Right, cnt );//�������������
	}
}

//*****************************************************
//�������ܣ���ֵΪx�Ľ������ݽ��
//���������ֵx,����
//�����������
//����ֵ��  ��
//*****************************************************
void RelativeOfNode( BiTree BT, ElementType &x )
{
	BiNode *p, *pA;//left right ancester
	p = BT;//����ʱָ������
	pA = NULL;
	stack<BiNode*> S;
	while ( p || !S.empty() )	   //���÷ǵݹ����������˼��
	{
		if ( p )
		{
			//cout << "p - >data is " << p->data << endl;
			if ( p->data == x )		//�����ǰ���ֵ��x��ȣ����˳�ѭ��
				break;
			S.push( p );            //������ջ���ڵ㣬����������
			pA = p;
			p = p->Left;
		}
		else
		{
			p = S.top();
			S.pop();
			pA = p;
			p = p->Right;
		}
	}
	if ( p == NULL )//p==NULL�Ļ�˵��x���ڶ�������,ֱ��return
	{
		cout << "�ý�㲻����\n";
		return;
	}
	//���޸��ڵ�
	if ( pA == NULL )//���ڵ��ǿգ�˵���Ǹ��ڵ�
		cout << "�ý����������û�и��ڵ�" << endl;
	else
		cout << "�ý��ĸ��ڵ�ֵΪ " << pA->data << endl;
	//��������
	if ( p->Left )
		cout << "�ý�����ӽ��ֵΪ " << p->Left->data << endl;
	else
		cout << "�ý��û������." << endl;
	//�����Һ���
	if ( p->Right )
		cout << "�ý���Һ��ӽ��ֵΪ " << p->Right->data << endl;
	else
		cout << "�ý��û���Һ���." << endl;
	//�����ֵ�
	if ( p == pA->Left && pA->Right )
		cout << "�ý����ֵܽ��ֵΪ " << pA->Right->data << endl;
	else if ( p == pA->Left && pA->Right == NULL )
		cout << "�ý��û���ֵܽ��." << endl;
	else if ( p == pA->Right && pA->Left )
		cout << "�ý����ֵܽ��ֵΪ " << pA->Left->data << endl;
	else
		cout << "�ý��û���ֵܽ��." << endl;
}

//*****************************************************
//�������ܣ���ֵΪx�Ľ��Ĳ��
//������������������level���������x
//�����������
//����ֵ��  	�ɹ����ز��
//*****************************************************
void LevelOfNode( BiTree BT, ElementType &x , int level, bool &flag  )  				//������α���
{
	if ( BT )							//����֮ǰ�������ͬʱ����ڵ��ε�˼��
	{
		LevelOfNode( BT->Left, x, level + 1, flag );
		if ( BT->data == x )
		{
			cout << "�ý���ڵ� " << level << " ��" << endl;
			flag = true;
			return;
		}
		LevelOfNode( BT->Right, x, level + 1, flag );
	}
}

//*****************************************************
//�������ܣ���˳��洢�Ķ�����ת��Ϊ������ʽ������
//���������˳�����������
//�����������
//����ֵ��	���������ڵ�
//*****************************************************
void ChangeArrIntoLink( BiTree &BT,SeqBiTree &Tree, int i )
{
	BT = new BiNode;
	if ( NULL == BT )
	{
		cout << "memory allocate faile,";
		system( "pause" );
		return;
	}
	BT->data = Tree.data[ i ];	 //�����ֵ
	//cout << "BT ->data is " << BT->data << endl;
	BT->Left = NULL;
	BT->Right = NULL;
	if ( Tree.data[ i * 2 ] != '*'  && (i * 2) <= Tree.len )  //��������
		ChangeArrIntoLink( BT->Left, Tree, i * 2 );  //�ݹ鴴��������

	if ( Tree.data[ i * 2 + 1 ] != '*'  && (i * 2 + 1 )<= Tree.len) //��������
		ChangeArrIntoLink( BT->Right, Tree, i * 2 + 1 ); //�ݹ鴴��������
}

//*****************************************************
//�������ܣ����������ֵΪx�Ľ��ĺ��ӽ��
//�������������BT�����ֵx�������ӽڵ�ָ��c1��c2
//���������c1��c2
//����ֵ��	��
//*****************************************************
void GetChild( BiTree BT, ElementType &x, BiNode* &C1, BiNode* &C2 )
{
	BiNode *p = GetNode( x, BT ); //���ҵ�ֵΪx���Ǹ����
	if ( p == NULL )
	{
		cout << "�ýڵ㲻����,������";
		system( "pause" );
		return;
	}
	if ( p->Left == NULL )  //�ý��������Ϊ��
	{
		cout << "�ý��û������.";
		C1 = NULL;
	}
	else
	{
		C1 = p->Left;
	}
	//�ж��Һ���
	if ( p->Right == NULL )
	{
		cout << "�ý��û���Һ���.";
		C2 = NULL;
	}
	else
	{
		C2 = p->Right;
	}
}

//*****************************************************
//�������ܣ����������ֵΪx�Ľ��ĸ��ڵ�
//�������������BT�����ֵx�������ӽڵ�ָ��c1��c2
//���������c1��c2
//����ֵ��	��
//*****************************************************
void GetFather( BiTree BT, ElementType &x, BiNode* &f )
{
	BiNode *p;
	stack<BiNode*> S;
	p = BT;
	while ( p || !S.empty( ))
	{
		if ( p->Left )
		{
			if ( p->Left->data == x ) //p�����ӵ���x
			{
				f = p->Left;
				break;
			}
			S.push( p );
			p = p->Left;
		}
		else if ( p->Right )
		{
			if ( p->Right->data == x )//p�Һ���ֵ����x
			{
				f = p->Right;
				break;
			}
			S.push( p );
			p = p->Left;
		}
		else
		{
			p = S.top();
			p = p->Right;
			S.pop();
		}
	}
	if ( p == NULL  )
	{
		cout << "�ö�����û��ֵΪ" << x << "�Ľ��" ;
	}
}

//*****************************************************
//�������ܣ����������ֵΪx�Ľ����ֵܽڵ�
//�������������BT�����ֵx�������ֵܽ�������
//����������ֵܽ��
//����ֵ��	��
//*****************************************************
void GetBro( BiTree BT, ElementType &x, BiNode* &Bro )
{
	BiNode *f, *p;
	p = GetNode( x, BT );	 //�ȵõ�ֵΪx�Ľ��
	if ( p == NULL )
	{
		cout << "�ö�������û��ֵΪ " << x << " �Ľ�㡣";
		return;
	}
	GetFather( BT, x, f );//���ҵ��ýڵ�ĸ��ڵ㣬Ȼ������ڵ����һ�����ӽڵ�
	if ( p == f->Left && f->Right == NULL )	  //p��f�����ӣ���f���ҽ��Ϊ��
	{
		cout << "�ý��û���ֵܽڵ�";
	}
	else if ( p == f->Left && f->Right )  //�ҽ�㲻Ϊ��
	{
		Bro = p->Right;
		cout << "�ҵ��ý����ֵܽڵ�.";
	}
	else if ( p == f->Right && f->Left == NULL )
	{
		cout << "�ýڵ�û���ֵܽڵ�.";
	}
	else
	{
		Bro = p->Left;
		cout << "�ҵ��ý����ֵܽڵ�.";
	}
}

//*****************************************************
//�������ܣ�����������ÿ���ڵ����������
//����������������
//�����������
//����ֵ��	��
//*****************************************************
void ExchangeRightLeft( BiTree BT )
{
	if(BT)
	{
		ExchangeRightLeft( BT->Left );//�ȵݹ鴦����������������
		ExchangeRightLeft( BT->Right );	//��Ҫ����߲�ε�������ʼ����
		BiNode *t;
		t = BT->Left;
		BT->Left = BT->Right;
		BT->Right = t;
	}

}

//*****************************************************
//�������ܣ�����ֵΪx�Ľ��
//���������������ֵx
//�����������
//����ֵ��	�ҵ����ؽ�㣬û�ҵ����ؿ�ָ��
//*****************************************************
BiNode* GetNode( ElementType x, BiTree BT )
{
	//���÷ǵݹ����������˼������
	BiNode *p = BT;
	stack<BiNode*> S;
	while ( p || !S.empty() )
	{
		if ( p )
		{
			if ( p->data == x )		//�ҵ�ֵΪx�Ľ���break��Ȼ�󷵻������㼴��
				break;
			S.push( p );
			p = p->Left;
		}
		else
		{
			p = S.top();
			S.pop();
			p = p->Right;
		}
	}
	if ( p == NULL )
	{
		cout << "û�������㡣\n";
		return NULL;
	}
	else
		return p;
}

//*****************************************************
//�������ܣ�����һ�Ŷ�����SourceT����һ����T
//��������������������
//�����������
//����ֵ��	��
//*****************************************************
void CopyTree( BiTree SourceT, BiTree &T )
{
	BiNode *p = SourceT;
	if ( p )  //��������㲻Ϊ��
	{
		T = new BiNode;  //�͸�T����һ���½ڵ�
		T->data = p->data;	  //Ȼ��p��ֵ���Ƹ�T
		T->Left = NULL;		  //�ú���T��left��rightָ���
		T->Right = NULL;

		CopyTree( p->Left, T->Left );	   //Ȼ��ݹ鴦��SourceT����������������
		CopyTree( p->Right, T->Right );
	}
}

//*****************************************************
//�������ܣ����������ÿ�����ڵ㵽Ҷ����·��
//����������������,һ����Ž��ֵ���ַ����飬����i
//�����������
//����ֵ��	��
//*****************************************************
void EachPathOfLeaf( BiTree BT, char* str, int &i )
{
	//�������������˼��,û��Ҷ���ʱ�Ͱѵ�ǰ���ֵ�����ַ������У�����Ҷ���ʱ������������������ݼ�Ϊ·��
	if ( BT )
	{
		if ( BT->Left == NULL && BT->Right == NULL ) //����������Ϊ�գ�������Ҷ���
		{
			str[ i ] = BT->data;	 //��Ҷ����ֵҲд��
			//cout << BT->data << " ����·��.\n";
			int j;
			cout << BT->data << ": ";
			for ( j = i; j >= 0; j-- )	  //Ȼ����������ַ������ֵ����ΪҶ��㵽����·��
				cout << str[ j ] << " ";
			cout << endl;
		}
		else
		{
			str[ i ] = BT->data;    //����Ҷ��㣬���������ŵ�ǰ����ֵ
			//cout << BT->data << " ����·��.\n";
			i++;    //i++������·������
			EachPathOfLeaf( BT->Left, str, i );//Ȼ���������������
			EachPathOfLeaf( BT->Right, str, i ); //���������ˣ���������������Ϊ������ͬһ�㣬����i����
			i--;  		//����������������󷵻���һ�㣬����iҪ��һ
		}
	}
}

//*****************************************************
//�������ܣ��ҵ�������������Ĺ�������
//������������ֵe1��e2,������BT
//�����������
//����ֵ��	�ɹ��������Ƚ��ָ�룬ʧ�ܷ��ؿ�ָ��
//*****************************************************
BiNode* FindCommonAnc( ElementType &e1, ElementType &e2, BiTree BT )
{
	BiNode *p1, *p2, *result;
	p1 = GetNode( e1, BT );  //�ҵ�ֵΪe1��e2�Ľ��
	p2 = GetNode( e2, BT );
	if ( NULL == p1 || NULL == p2 )
	{
		cout << "��������û�������㡣";
		system( "pause" );
		return NULL;
	}
	if ( p1 == BT || p2 == BT )		  //����֮һ�Ǹ����ͷ��ظ��ڵ�
	{
		return BT;
	}
	char path1[ MAXN ] = {0};		 //��Ž��1��·��
	char path2[ MAXN ] = {0};		 //���2��·��
	int i1, i2, j;
	bool flag = false;
	i1 = i2 = j = 0;
	PathOfNode( p1->data, BT, path1, i1, flag ); //��p1��·��
	flag = false;
	PathOfNode( p2->data, BT, path2, i2, flag); //��p2��·��
	while ( path1[ j ] == path2[ j ] )	   //�ҵ�·���е�һ����һ���Ľ��
	{
		j++;
	}
	j--;	 //ǰ���Ǹ����ǹ������Ƚ��
	result = GetNode( path1[ j ], BT );
	return result;
}

//*****************************************************
//�������ܣ��ҵ�������������Ĺ������ȣ�������
//������������ֵe1��e2,������BT
//�����������
//����ֵ��	�ɹ��������Ƚ��ָ�룬ʧ�ܷ��ؿ�ָ��
//*****************************************************
BiNode* FindComAnc2( BiNode *e1, BiNode *e2, BiTree BT )
{
	//�ú���������˼��
    if (BT == NULL || BT == e1 || BT == e2 )	//�����ǰ���Ϊ�ջ������������֮һ
		return  BT;			//�ͷ���������

	BiNode *le = FindComAnc2( e1, e2, BT->Left );		//���������Ƿ���Ŀ��ڵ�
	BiNode *ri = FindComAnc2( e1, e2, BT->Right );	//���������Ƿ���
	if ( le != NULL && ri != NULL ) return BT;	//�����գ�˵��Ŀ��������������

	return le == NULL ? ri : le;

}
//*****************************************************
//�������ܣ��ҵ�һ���Ӹ���㵽ֵΪx�Ľ���·��
//���������ֵx���������BT���ַ������ã�λ��i
//������������ַ�����ʽ��ʾ��·��
//����ֵ��	��
//*****************************************************
void PathOfNode( ElementType &x, BiTree BT, char* str, int &i, bool &flag )
{
	//���������������˼�룬��������Ҷ����·������
    if(BT)
	{
		if(BT->data == x)		//�ҵ�Ŀ���㣬�ͷ���
		{
			str[i] = BT->data;
			flag = true;
			//cout << BT->data << "д��·��\n";
			i++;
			str[i] = '\0';
			return ;
		}
		else				//û���ҵ�
		{
			str[i] = BT->data;				//����ǰ���ֵд��·
			//cout << BT->data << "д��·��\n";
			i++;
			if ( !flag )
			{
				PathOfNode(x,BT->Left,str,i,flag);
			}
			if ( !flag )
			{
				PathOfNode(x,BT->Right,str,i,flag);  	//����������ͬһ�㣬����i���ñ�
			}
			if( !flag )//��������ж������Ļ������ڵݹ飬���i�ᱻ����1����Ȼ��Ӱ��·�����飬
			{																					//���ǻ�Ӱ��·�����ȱ���
				i--;	//���������������ˣ�������һ�㣬i--
			}
		}
	}
}

//*****************************************************
//�������ܣ��ҵ���������һ�����·���������·���ϵ�ֵ
//�����������������BT
//�����������
//����ֵ��	�ɹ������·�����ȣ�ʧ�ܷ���0
//*****************************************************
int FindLongestPath( BiTree BT )
{
	int length = 0, leaf = 0, i;
	bool flag = false;
	NumOfLeaf( BT, leaf );	 //����Ҷ�������
	char path[MAXNODES] = {0};			//���Ľ��·��
	char Tpath[MAXNODES] = {0};		//ÿ�α���Ҷ���
	i = 0;
	length = i; 		//����i�����·������
	//Ȼ���÷ǵݹ����������˼�룬������Ҷ����ʱ��͵��ü�����·���ĺ���
	stack<BiNode*> S;
	BiNode *p = BT;
	while ( p || !S.empty() )
	{
		if ( p )
		{
			if ( p->Left == NULL && p->Right == NULL ) //����Ҷ�ڵ�͵�����·������
			{
				i = 0;
				PathOfNode(p->data,BT,Tpath,i,flag);
				//cout << "Ҷ���" << p->data << " ��·��  " << Tpath << ",����Ϊ " << i << endl;
				if ( i  > length )		//��iΪ�ǽ�β��������i-1����·����Ч����
				{
					length = i;				//�����ĳ��Ҷ����·����֮ǰ��·�������͸���length��·������
					strcpy(path,Tpath);
					//cout << "���³ɹ���Ŀǰpath ��" << path << endl;
				}
				flag = false;  //������flag
			}
			S.push( p );   //����Ҷ��㣬����ĳ�����ڵ㣬��ջ
			p = p->Left;   //����������
		}
		else
		{
			p = S.top();	  //p is null, let p point to front root node
			S.pop();
			p = p->Right;  //travel right sub tree
		}
	}
	cout << "�·��Ϊ�� " << path <<endl;
	return length;   //������󳤶�
}

//*****************************************************
//�������ܣ��������ļ��ж�ȡ���������ݵ�һ����ά�ַ�������
//�����������ά���飬��¼��ά����ʵ�ʴ�Сlen
//�����������ά����
//����ֵ��	��
//*****************************************************
void GetTreeData( char TreeData[ MAXNODES ][ 4 ], int &len )
{
	//����Ĳ����ȴ��ļ��������ݵ���Žڵ���Ϣ�Ķ�ά������
	char name[ 10 ];   //�ļ���
	char path[ 20 ] = "BTdata\\"; //�����ļ�·��
	char Tdata[ 10 ];
	len = 0;
	char strChoose[ 1000 ];//ÿ�δ��ļ������һ��
	int i = 0,j;
	bool tag = false;//�������ļ��ı�ʶ
	FILE *fp;		   //�ļ�ָ��
	cout << "������������ļ�����(����bt15.btr)��";
	cin >> name;
	strcat( path, name );			//��������·��
	fp = fopen( path, "r" );//����������ļ�
	if ( NULL == fp )
	{
		cout << "�ļ���ʧ��, ������." << endl;
		system( "pause" );
		return;
	}
	while ( !feof( fp ) ) //û���ļ�β����û�ҵ���ʶ
	{
		if ( tag == true )	//�ҵ���ǣ�break
		{
			//cout << "�ҵ���ǣ�break\n";
			break;
		}
		fgets( strChoose, 1000, fp );	   //����һ��
		if ( strChoose[ 0 ] == ' ' )   //ǰ���пո񣬾�ȥ���ո�
			RemoveSp( strChoose );
		if ( strChoose[ 0 ] == '\n' )//���У�������һ��
		{
			//cout << "���л��пո񣬼�������һ��";
			continue;
		}
		else if ( ( strChoose[ 0 ] == '/' ) && ( strChoose[ 1 ] == '/' ) )  //ע���У�����
		{
			//cout << "ע���У�����" << endl;
			continue;
		}
		else
		{
			tag = true;		//�Ȳ��ǿ��У��ո�Ҳ����ע���У��Ͱѱ�Ǳ�Ϊtrue
		}
	}
	//����while������strchoose��Ӧ���Ƕ��������ݱ�ʶ
	if ( strcmp( strChoose, "BinaryTree\n" ) != 0 )//����������ݱ�ʶ�����˳�
	{
		cout << "���ļ����Ƕ����������ļ��������������ļ�����\n";
		return;
	}
	else		//���ļ���ʶ�����Ŵӱ�ʶ����һ�ж������ݵ���ά������
	{
		while ( !feof( fp ) )
		{
			fgets( Tdata, 10, fp );	 //������һ�е�����
			i = 0;
			j = 0;
			while ( Tdata[ i ] != '\0' )   //�Կո�ָ����洢����
			{
				if ( Tdata[ i ] != ' ' )
				{
					TreeData[ len ][ j ] = Tdata[ i ];
					j++;
				}
				i++;
			}
			len++;
		}
	}
	fclose( fp );
	//����whileִ�����strdata��ά�����ڴ����ȫ���ڵ���Ϣ
	//strdata[ n ][0]��Ž��ֵ��
	//strdata[ n ][1]�����������Ϣ
	//strdata[ n ][2]�����������Ϣ
}
//*****************************************************
//�������ܣ��ļ���ʽ����һ��������
//��������������ڵ������
//��������������ڵ�
//����ֵ��	��
//*****************************************************
void CreateTreeUsingFile( BiTree &BT )
{
	char TreeData[ MAXNODES ][ 4 ];  //������ݶ�ά����
	int datalen,i;
	GetTreeData( TreeData, datalen );		//���ļ����������
	//Ȼ����ô�����㺯�����ݹ�Ĵ�����
	i = 0;
	CreateNode( BT, TreeData, datalen, i );
}

//*****************************************************
//�������ܣ�������������һ���ڵ㣬��CreateTreeUsingFile�������ʹ��
//��������������ڵ�����ã������������Ϣ��ά���飬������Ч���ȣ����鵱ǰλ��
//��������������ڵ�
//����ֵ��	false or true
//*****************************************************
void CreateNode( BiTree &pNode, char data[ MAXNODES ][ 4 ], int len, int &cur )
{
	//pNodeΪ���ָ�룬dataΪ��ά���ݣ���Ž����Ϣ
	//len��������Ч���ȣ�����������cur�ǵ�ǰ�õڼ������
	if ( (cur >= len) || (len == 0) ) //���ݴ�����ϻ�û������
	{
		return;
	}

	pNode = new BiNode;
	if(pNode == NULL)
	{
		cout << "memory allocate failed, exit.";
		return ;
	}
	pNode->data = data[ cur ][ 0 ];
	pNode->Left = NULL;
	pNode->Right = NULL;
	int precur = cur;		  //������ǰ�Ľ����
	if ( data[ precur ][ 1 ] == '1' )	//��ǰ����������� ,�ݹ鴴��������
	{
		cur++;
		//cout << "�ݹ鴴��������\n";
		CreateNode( pNode->Left, data, len, cur );
	}

	if ( data[ precur ][ 2 ] == '1' )  //��ǰ��������������ݹ鴴��������
	{
		cur++;
		//cout << "�ݹ鴴��������\n";
		CreateNode( pNode->Right, data, len, cur );
	}
}

//*****************************************************
//�������ܣ�ȥ�������ļ�һ����ǰ��Ŀո�
//����������ַ���
//����������ַ���
//����ֵ��	��
//*****************************************************
void RemoveSp( char *str )
{
	int i, cnt, n ,j;
	i = cnt = j = 0;
	n = strlen( str ) + 1;
	while ( str[ i ] == ' ' )	//��i�ƶ�����һ���ǿո��ַ�
	{
		i++;
		cnt++;
	}
	while ( j < n - cnt )	   //ȥ��cnt���ո��
	{
		str[ j ] = str[ i ];   //��ǰ��
		j++;
		i++;
	}
}

//*****************************************************
//�������ܣ����̽������뷽ʽ����һ��������
//��������������ڵ������
//��������������ڵ�
//����ֵ��	��
//*****************************************************
void CreateTreeInteractive( BiTree &BT )
{
	ElementType data;
	int left, right;
	cout << "�밴���������������������Ϣ��ÿ������ֵ���ÿո�ָ�\n";
	cout << "��һ���ǽ��ֵ���ڶ�������������������������������0�����ޣ�1�����У�\n";
	cout << "������#��ʾ������� ��\n";
	fflush( stdin );   //��ջ�����������֮ǰ��������Ļس�����ɵ�Ӱ��
	cout << "���ڵ㣺 ";
	cin >> data >> left >> right;
	cout << endl;//����
	AssistCreate( BT, data, left, right );	  //�ȴ������ڵ㣬Ȼ��ݹ鴴������
	cout << "�����ɹ���! �������������  \n";
}

//*****************************************************
//�������ܣ����̽������뷽ʽ����һ���������ĸ�������
//��������������ڵ�����ã����ֵx,����������Ϣ
//������������
//����ֵ��	��
//*****************************************************
void AssistCreate( BiNode* &p, ElementType &x, int left, int right )
{
	ElementType data;
	int l, r;
	p = new BiNode;	   //�ȴ�����ڵ�
	p->data = x;	   //���ֵ
	p->Left = NULL;	   //�Ƚ�������Ϊ��
	p->Right = NULL;
	fflush( stdin );
	if ( left == 1 )	//�ȿ���������������ݹ鴴��������
	{
		cout << "��һ����㣺";
		cin >> data >> l >> r;
		cout << endl;
		AssistCreate( p->Left, data, l, r );
	}
	if ( right == 1 )    //�ٿ������������,�ݹ鴴��������
	{
		cout << "��һ����㣺";
		cin >> data >> l >> r;
		cout << endl;
		AssistCreate( p->Right, data, l, r );
	}
}

//*****************************************************
//�������ܣ��������ö�����
//����������ڵ������
//��������������ڵ�
//����ֵ��	��
//*****************************************************
void DestoryBiTree( BiTree &BT )
{
	//���ú���������˼�룬��Ϊ����ͺ�����Ҫ�˷�һ��ָ������ס���ڵ�
	if ( BT )
	{
		DestoryBiTree( BT->Left );  //�ݹ�����������
		DestoryBiTree( BT->Right );	//�ݹ�����������
		delete BT;
		BT = NULL;
	}
}

//*****************************************************
//�������ܣ�ɾ���������е�ĳ������
//���������ĳ�����
//�����������
//����ֵ��	��
//*****************************************************
void DeleteSibTree( BiTree BT )
{
	ElementType x;
	BiNode *p;
	cout << "������Ҫɾ���������ĸ��ڵ�ֵ��";
	cin >> x;
	p = GetNode( x, BT );	   //���ҵ�Ŀ����
	if ( p == NULL )
	{
		cout << "�ý�㲻���ڣ�������ѡ��\n";
		system( "pause" );
		return;
	}
	DestoryBiTree( p );	  //Ȼ����Ŀ��ڵ�Ϊ���ڵ���������
	cout << "���ٳɹ���";
}
