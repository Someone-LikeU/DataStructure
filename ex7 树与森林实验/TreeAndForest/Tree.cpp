//**************************************************************
//Filename	         : Tree.cpp
//Abstract           : ���ļ�����(ɭ��)������㷨ʵ���ļ�
//Author  	         : �ܽ���
//Accomplished Date  : 2018.12.
//Beginning Date     : 2018.12.16
//Student ID         : 2017217866
//**************************************************************
#include "Tree.h"
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <queue>
#include <cstring>
#include <windows.h>
using namespace std;

//*****************************************************
//�������ܣ�
//���������
//���������
//����ֵ��
//*****************************************************

//*****************************************************
//�������ܣ���ʼ��˫�ױ�ʾ������
//���������˫�ױ�ʾ��������
//�����������˫�ױ�ʾ��
//����ֵ��	��
//*****************************************************
void InitParentForm( Ptree &Ptree )
{
	Ptree.n = 0;  //�����������0����
}

/*void InitVisit()	 //��ʼ������������
{
	int i;
	for ( i = 0; i < MAXLEN; i++ )
	{
		IsVisited[ i ] = false;
	}
}*/
//*****************************************************
//�������ܣ����ļ�����˫�ױ�ʾ����
//���������˫�ױ�ʾ��
//���������˫�ױ�ʾ��
//����ֵ��  �ɹ�����true��ʧ�ܷ���false
//*****************************************************
bool CreateTreeFromFile( Ptree &Ptree )
{
	//����Ĳ����ȴ��ļ��������ݵ���Žڵ���Ϣ�Ķ�ά������
	char name[ 10 ];   //�ļ���
	char path[ 20 ] = "tData\\"; //�����ļ�·��
	char strChoose[ 500 ];//ÿ�δ��ļ������һ��
	int i = 0, j;
	bool tag = false;//�������ļ��ı�ʶ
	FILE *fp;		   //�ļ�ָ��
	cout << "���������ļ�����(����tree10.tre)��";
	cin >> name;
	strcat( path, name );			//��������·��
	fp = fopen( path, "r" );//����������ļ�
	if ( NULL == fp )
	{
		cout << "�ļ���ʧ��, ������." << endl;
		system( "pause" );
		return false;
	}
	while ( !feof( fp ) ) //û���ļ�β����û�ҵ���ʶ
	{
		if ( tag == true )	//�ҵ���ǣ�break
		{
			//cout << "�ҵ���ǣ�break\n";
			break;
		}
		fgets( strChoose, 500, fp );	   //����һ��
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
	//����while������strchoose��Ӧ���������ݱ�ʶ
	if ( strcmp( strChoose, "Tree or Forest\n" ) != 0 )//����������ݱ�ʶ���ͷ���ʧ��
	{
		cout << "���ļ������������ļ��������������ļ�����\n";
		return false;
	}
	else		//���ļ���ʶ�����Ŵӱ�ʶ����һ�ж������ݵ���ά������
	{
		while ( fgets( strChoose, 500, fp ) != NULL )
		{
			if ( strChoose[ 0 ] == '\n' )  //���У���������һ��
				continue;
			else if ( strChoose[ 0 ] == '/' && strChoose[ 1 ] == '/' ) //ע����,Ҳ����
				continue;
			else          //�ǿ��л�ע���У��Ǿ͵��˽���б���һ�У�Ȼ���˳����ѭ���������ֵ��������
				break;
		}
		i = 0;	   //i���������Ϣ����
		j = 0;	   //j����˫�ױ�ʾ�������±�
		while ( strChoose[ i ] != '\0' )   //�����ո����洢����
		{
			if ( strChoose[ i ] != ' ' )
			{
				Ptree.Treenodes[ j ].data = strChoose[ i ];  //��j������ֵ
				Ptree.Treenodes[ j ].parent = -1;  //��j�����ĸ��ڵ��ȳ�ʼ��Ϊ-1
				j++;
			}
			i++;
		}
		//�˳��󣬸��½�������ʵ�ʴ�С
		Ptree.n = j-1;
		cout << "Ptree.n = " << Ptree.n << endl;
		//Ȼ������������
		int indexP;  //������±�
		int indexC;  //�ӽ���±�
		TreeElement eF, eC;//���ӽ���Ӧ��ֵ
		while ( fgets( strChoose, 500, fp ) != NULL )
		{
			if ( strChoose[ 0 ] == '\n' )  //���У���������һ��
				continue;
			else if ( strChoose[ 0 ] == '/' && strChoose[ 1 ] == '/' ) //ע����,Ҳ����
				continue;
			else          //�ǿ��л�ע���У��Ǿ͵��˸��ӽ����Ϣ��һ�У����½����Ϣ
			{
				eF = strChoose[ 0 ];	//���ڵ�ֵ
				eC = strChoose[ 2 ];	//�ӽڵ�ֵ
				GetNodeIndex( indexP, Ptree, eF );	//��ȡ���ڵ�ֵ�������е��±�
				GetNodeIndex( indexC, Ptree, eC );//��ȡ�ӽڵ�ֵ�������е��±�
				Ptree.Treenodes[ indexC ].parent = indexP;//Ȼ���ӽڵ�ĸ��ڵ����indexP
			}
		}
	}
	fclose( fp ); //������ϣ��ر��ļ�
	return true; //���سɹ�
}

//*****************************************************
//�������ܣ���ȡ�������������±�
//���������index���ã�˫�ױ�ʾ������������Ԫ��x
//���������index
//����ֵ��	��
//*****************************************************
bool GetNodeIndex( int &index, Ptree &Ptree, TreeElement &x )
{
	for ( index = 0; index < Ptree.n; index++ )
	{
		if ( Ptree.Treenodes[ index ].data == x )
		{
			return true;	 //������ȣ��ͷ���true,��index�Բ�����ʽ����
		}
	}
	return false;	  //���򣬷���ʧ��
}

//*****************************************************
//�������ܣ�ȥ�������ļ�һ����ǰ��Ŀո�
//����������ַ���
//����������ַ���
//����ֵ��	��
//*****************************************************
void RemoveSp( char *str )
{
	int i, cnt, n, j;
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
//�������ܣ���Ԫ��x���������Ƚ��ֵ
//�����������
//�����������
//����ֵ��	��
//*****************************************************
void ShowAllAncestor( Ptree &Ptree, TreeElement x )
{
	int indexNow, indexP; //��ǰ�����±꣬���ڵ��±�
	if ( !GetNodeIndex( indexNow, Ptree, x ) ) //��ȡ�õ�ǰ�����±�
	{
		cout << "�ý�㲻���������У�������ѡ��.\n";	//�Ҳ������ͷ���
		return;
	}
	if ( indexNow == 0 )	//������������Ǹ��ڵ�ֵ������ʾ������Ϣ��������
	{
		cout << "�ý��Ϊ���ڵ㣬û�����Ƚ�㣬������ѡ��\n";
		return;
	}
	cout << "��� " << x << "���������Ƚ��ֵ���� ��\n";
	do	  //ǰ��û���صĻ�������Ҫִ��һ�飬������do-while��ǰ������Ѿ��ҵ��˵�ǰ�����±�
	{
		indexP = Ptree.Treenodes[ indexNow ].parent;//Ȼ���ȡ��ǰ���ĸ��ڵ���±�
		cout << Ptree.Treenodes[ indexP ].data << " ";	   //Ȼ��������ڵ�ֵ
		indexNow = indexP;  //Ȼ���ø��ڵ��Ϊ��ǰ��㣬�����Ҹ��ڵ�ĸ��ڵ�
	} while ( indexP != 0 );   //�����ڵ�Ϊֹ
}

//*****************************************************
//�������ܣ���Ԫ��x�������ӽ��ֵ
//�����������
//�����������
//����ֵ��	��
//*****************************************************
void ShowChildren( Ptree &Ptree, TreeElement x )
{
	int indexPar, indexCd;//��ǰ����±꣬�ӽڵ��±�
	if ( !GetNodeIndex( indexPar, Ptree, x ) )	  //���Ի�ȡ��ǰԪ�ص��±�
	{
		cout << "�ý�㲻���������У�������ѡ��.\n";	//�Ҳ������ͷ���
		return;
	}
	cout << "�ý����ӽڵ�ֵ���£�\n";
	for (  indexCd = indexPar + 1 ; indexCd < Ptree.n ; indexCd++ ) //�ӵ�ǰ�±꿪ʼ�������
	{
		if ( Ptree.Treenodes[ indexCd ].parent == indexPar )  //�������ڵ���indexPar�ľ��������ӽڵ㣬Ȼ�����
		{
			cout << Ptree.Treenodes[ indexCd ].data << " ";
		}
	}
}

//*****************************************************
//�������ܣ����������ں���
//���������˫�ױ�ʾ��������
//�����������
//����ֵ��	��
//*****************************************************
void PreTraverse( Ptree &Ptree )
{
	int i;
	cout << "����������£�\n";
	for ( i = 0 ; i < Ptree.n ; i++ )		 //�������ڵ㣬��Ϊ������ɭ�֣�Ӵ��������
	{
		if ( Ptree.Treenodes[ i ].parent == -1 )
		{
			PreOrderTravel( Ptree, i );
		}
	}
}

//*****************************************************
//�������ܣ������������
//���������˫�ױ�ʾ�������ã���ʼ�±꣨���ڵ㣩index
//�����������
//����ֵ��	��
//*****************************************************
void PreOrderTravel( Ptree &ParentTree, int v )
{
	int w;
	cout << ParentTree.Treenodes[ v ].data << " ";  //�������߶�ʮһ����������ڵ�ֵ
	w = GetFirstChildIndex( ParentTree, v );//Ȼ��㵽�ý��ĵ�һ���ӽڵ���±�
	while ( w != -1 )   //ֱ��û���ӽڵ�
	{
		PreOrderTravel( ParentTree, w );//�ݹ���������ӽڵ���ӽڵ�
		w = NextBroIndex( ParentTree, w ); //Ȼ����ǰ�����ֵܽڵ�
	}
}

//*****************************************************
//�������ܣ������������
//���������˫�ױ�ʾ�������ã���ʼ�±꣨���ڵ㣩index
//�����������
//����ֵ��	��
//*****************************************************
void LastOrderTravel( Ptree &ParentTree, int index )
{
	int w;  //��һ�����ӽ���±�
	w = GetFirstChildIndex( ParentTree, index );  //��ȡ�õ�һ�����ӽ����±�
	while ( w != -1 )  //һֱȡ�׺����±ֱ꣬������ȡΪֹ
	{
		LastOrderTravel( ParentTree, w ); //�ݹ鴦���ӽڵ�
		w = NextBroIndex( ParentTree, w );//ȡ�ֵܽ�㣬�����ֵܽ��
	}
	cout << ParentTree.Treenodes[ index ].data << " "; //���ŷ��ʸ���㣬ʵ�ֺ������
}

//*****************************************************
//�������ܣ���������������
//���������˫�ױ�ʾ��������
//�����������
//����ֵ��	��
//*****************************************************
void LastTraverse( Ptree &ParentTree )
{
	int i; //ͬ���������еĸ��ڵ㣬������ɭ�֣��ж�����ڵ�
	cout << "����������£�\n";
	for ( i = 0; i < ParentTree.n; i++ )
	{
		if ( ParentTree.Treenodes[ i ].parent == -1 ) //���ڵ�
		{
			LastOrderTravel( ParentTree, i );
		}
	}
}

//*****************************************************
//�������ܣ������������ɭ�֣�
//���������˫�ױ�ʾ����ɭ�֣�
//�����������
//����ֵ��	��
//*****************************************************
void LevelTravel( Ptree &ParentTree )
{
	//˫�ױ�ʾ���н�㶼�ǰ�˳��洢������ֱ��˳��������鼴��
	int i;
	cout << "����������£�\n";
	for ( i = 0; i < ParentTree.n; i++ )
	{
		cout << ParentTree.Treenodes[ i ].data << " ";
	}
}

//*****************************************************
//�������ܣ���ɭ�֣������߶�
//���������˫�ױ�ʾ������ɭ�֣�
//�����������
//����ֵ��	��
//*****************************************************
int GetTreeHeight( Ptree &ParentTree, int v )
{
	//�±������Ŀ϶�λ������һ�㣬���������ж������Ƚ�㣬�ټ����������������߶�
	int index, height;
	index = v;
	height = 0;
	do
	{
		height++;
		index = ParentTree.Treenodes[ index ].parent;
	} while ( index != -1 );
	return height;
}

int TreeHeightEnter(Ptree &ParentTree )
{
	int i,height = 0,t;
	for (i = 1 ; i < ParentTree.n;i++)
	{
		if(ParentTree.Treenodes[i].parent == -1)
		{
			t = GetTreeHeight(ParentTree,i - 1);
			if(height < t)
			height = t;
		}
	}
	return height;
}
//*****************************************************
//�������ܣ���ɭ�֣������ܽ����
//���������˫�ױ�ʾ������ɭ�֣�
//�����������
//����ֵ��	��
//*****************************************************
int GetTreeNodes( Ptree &ParentTree )
{
	return ParentTree.n;
}

//*****************************************************
//�������ܣ���Ҷ�����
//���������˫�ױ�ʾ��
//�����������
//����ֵ��	��
//*****************************************************
int NumOfLeaf( Ptree &ParentTree )
{
	int i, numOfP;
	numOfP = 1;		//������һ�����ڵ�
	for ( i = 0; i < ParentTree.n - 1; i++ )
	{
		if(ParentTree.Treenodes[i].parent == -1)
			continue;
		if ( ParentTree.Treenodes[ i ].parent == ParentTree.Treenodes[ i + 1 ].parent )	//���������ĸ��ڵ�һ��
		{
			continue;  //�ͼ���
		}
		else
		{
			numOfP++; //���򣬸��ڵ�����һ
		}
	}
	return ParentTree.n - numOfP;  //�ܽ���������ڵ�������Ҷ�����������
}

//*****************************************************
//�������ܣ���˫�ױ�ʾ���������������ʾ��
//���������˫�ױ�ʾ���ṹ�����������ʾ�ṹ
//�����������������ṹ
//����ֵ��	true or false
//*****************************************************
bool CreateChildLink( Ptree &ParentTree, ChildLink &CL )
{
	if ( ParentTree.n == 0 )
	{
		return false;
	}
	int i, par,j;  //��ǰ����±꣬���ڵ��±�
	ListNode t = NULL;
	CL.len = ParentTree.n;	  //�Ȱѳ��ȸ���CL
	for ( i = 0; i < ParentTree.n; i++ )   //Ȼ�󽫸����ֵ����CL�Ķ�Ӧλ��
	{
		CL.NodeTable[ i ].data = ParentTree.Treenodes[ i ].data;
		CL.NodeTable[ i ].FirstChild = new balabala; //firstchild�൱�ڵ������ͷָ�룬���Ը�������һ�����
		CL.NodeTable[ i ].FirstChild->next = CL.NodeTable[i].FirstChild;//�Ѹ�����Ū�ɴ�βָ��ĵ�ѭ������
		//�����CL.NodeTable[ i ].FirstChild ���൱��һ���βָ�뵥ѭ�������Rָ��
	}
	//Ȼ����һ��ѭ��������ÿ�����ĺ�������
	i = 0;
	while(i < ParentTree.n )
	{
		if(ParentTree.Treenodes[i].parent == -1)
		{
			i++;
			continue;
		}
		for ( j = i;j < ParentTree.n && ParentTree.Treenodes[j].parent != -1 ; j++ )	//���ڵ�û�и��ڵ㣬���Դ�1�±꿪ʼ
		{
			par = ParentTree.Treenodes[ j ].parent;  //�ҵ���ǰ���ĸ��ڵ��±�
			t = new balabala;//��������һ����㣬�ӵ���Ӧ���ڵ�ĺ���������
			t->ChildIndex = j;
			t->next = CL.NodeTable[ par ].FirstChild->next;
			CL.NodeTable[ par ].FirstChild->next = t;
			CL.NodeTable[ par ].FirstChild = t;
		}
		i = j;
	}

	return true;
}

//*****************************************************
//�������ܣ�����֮ǰ�����ĺ��������ʾ����
//������������������ʾ�ṹ
//�����������
//����ֵ��	��
//*****************************************************
void DestoryCLtree( ChildLink &CL )
{
	ListNode p, t;
	int i;
	for ( i = 0; i < CL.len; i++ )	   //firstchild �����Ǵ�βָ��ĵ�ѭ���������Ծʹ�����ʼ����
	{
		p = CL.NodeTable[ i ].FirstChild->next;
		while ( p != CL.NodeTable[ i ].FirstChild )	  //��ͷ��ʼɾ��
		{
			t = p->next;
			delete p;
			p = t;
		}
		delete CL.NodeTable[ i ].FirstChild;	 //���ɾ��β��㱾��
	}
}

//*****************************************************
//�������ܣ��ɺ��������ʾ����Ҷ�����
//������������������ʾ�ṹ
//�����������
//����ֵ��	�����
//*****************************************************
int GetLeafChildLink( ChildLink &CL )
{
	int n = 0, i;
	for ( i = 0; i < CL.len; i++ )
	{
		if ( CL.NodeTable[ i ].FirstChild->next == CL.NodeTable[ i ].FirstChild )
		{
			n++;
		}
	}
	return n;
}

//*****************************************************
//�������ܣ���˫�ױ�ʾ�������Ķ�
//���������˫�ױ�ʾ���ṹ
//�����������
//����ֵ��	��deg
//*****************************************************
int DegOfTree( Ptree &ParentTree )
{
	//������˳�����ȥ�صĲ�����˫�ױ�ʾ��parent�����ظ��������ı����������Ķ�
	int deg = 0, i, j;
	i = 1, j = 2; //0���±������������Դ�1�ſ�ʼ
	while ( j < ParentTree.n )
	{
		//������i��jλ���ϵ�parent��ͬ��j+1����
		if ( ParentTree.Treenodes[ i ].parent == ParentTree.Treenodes[ j ].parent )
		{
			j++;	 //����
			continue;
		}
		if ( deg < j - i )	//j-i�����±�֮����ǵ�ǰĳ���ڵ�Ķȣ��жϺ�֮ǰ��deg��С���Ӷ�����deg
		{
			deg = j - i;
		}
		i = j;	  //Ȼ���ԭ��j�Ǹ�λ�ü�������
		j++;
	}
	return deg;  //���return�������
}

//*****************************************************
//�������ܣ��ɺ��������ʾ�������Ķ�
//������������������ʾ����
//�����������
//����ֵ��	��deg
//*****************************************************
int DegOfTreeChildLink( ChildLink &CL )
{
	int i, deg, cnt;  //cnt��¼ÿ�η��ʽ��ĺ��ӽ����
	deg = 0;
	ListNode p = NULL;
	for ( i = 0; i < CL.len; i++ )
	{
		cnt = 1;	//ÿ�η���ǰ��ʼΪ1
		if ( CL.NodeTable[ i ].FirstChild->next != CL.NodeTable[ i ].FirstChild )	//�ý��ĺ��������ǿձ�
		{
			//�Ǿͽ��������ĺ���������м���
			p = CL.NodeTable[ i ].FirstChild->next->next; //next->next ���ǵ�һ���ӽ��
			while ( p != CL.NodeTable[ i ].FirstChild )
			{
				cnt++;
				p = p->next;
			}
		}
		if ( deg < cnt )	   //��ǰ���ĺ��ӱ��������֮ǰdegҪ��
		{
			deg = cnt; //�͸���deg
		}
	}
	return deg;
}

//*****************************************************
//�������ܣ�˫�ױ�ʾ�������±�Ϊv�Ľ��ĵ�һ�����ӽ���±�
//���������˫�ױ�ʾ��������±�v
//�����������
//����ֵ��	�ӽڵ���ڷ����ӽڵ��±꣬���򷵻�-1
//*****************************************************
int GetFirstChildIndex( Ptree &ParentTree, int v )
{
	int w;
	//cout << " v is " << v << endl;
	for ( w = v + 1; w < ParentTree.n; w++ ) //���ӽ���±�϶���v֮�����Դ�v+1��ʼ����
	{
		//cout << "w is " << w << endl;
		if ( ParentTree.Treenodes[ w ].parent == v ) //find the first child
		{
			return w;
		}
	}
	return -1;
}

//*****************************************************
//�������ܣ���˫�ױ�ʾ���ֽ��v��λ��w�ӽڵ�ĺ�һ���ӽڵ��±�
//���������˫�ױ�ʾ�������ӽڵ�w
//�����������
//����ֵ��	�ӽڵ���ڷ����ӽڵ��±꣬���򷵻�-1
//*****************************************************
int NextBroIndex( Ptree &ParentTree, int w )
{
	int i;
	for ( i = w + 1; i < ParentTree.n; i++ )   //�ֵܽ��϶���w֮�����Դ�w+1��ʼ
	{
		if ( ParentTree.Treenodes[ i ].parent == ParentTree.Treenodes[ w ].parent )
		{
			//cout << "return " << i << endl;
			return i;		//��������ͬ�����ȣ��ͷ���i
		}
	}
	return -1;			//���򷵻�-1
}

//*****************************************************
//�������ܣ��ݹ鴴��һ�����������ʾ����
//������������������ʾ����㣬˫�ױ�ʾ��������±�
//������������������ʾ�����
//����ֵ��	��
//*****************************************************
void Create( CsRoot &csT, Ptree &ParentTree, int v )
{
	//�ݹ�Ĵ��������ֵܱ�ʾ���������������ʾ������ִ��˼���ǰ����������˳�򴴽�
	int w; //���v�ĵ�һ�����ӽ����±�
	csT = new csnode;
	if ( csT == NULL )
	{
		cout << "memory allocate failed, please try again.\n";
		return;
	}
	csT->data = ParentTree.Treenodes[ v ].data;
	csT->FirstSon = NULL;
	csT->NextBro = NULL;
	w = GetFirstChildIndex( ParentTree, v ); //ȡ��һ�����ӽ����±�
	if ( w != -1 )
	{
		Create( csT->FirstSon, ParentTree, w );	  //�ݹ鴴����һ�����ӽ�����
	}
	w = NextBroIndex( ParentTree, v );	   //ȡ��v���ֵܽڵ㣬�����ݹ鴴���ֵܽ�����
	if ( w != -1 )
	{
		Create( csT->NextBro, ParentTree, w );
	}
}

//*****************************************************
//�������ܣ��������������ʾ������ں���
//������������������ʾ����㣬˫�ױ�ʾ��
//������������������ʾ�����
//����ֵ��	��
//*****************************************************
void CreateCS( CsRoot &csT, Ptree &ParentTree )
{
	int i;
	for ( i = 0; i < ParentTree.n; i++ ) //������һ�����ڵ�
	{
		if ( ParentTree.Treenodes[ i ].parent == -1 ) //�ҵ����ڵ���˳�
		{
			break;
		}
	}
	if ( i < ParentTree.n )//��ֹԽ��
	{
		Create( csT, ParentTree, i );
	}
}

//*****************************************************
//�������ܣ����ٺ��������ʾ��
//������������������ʾ�����
//�����������
//����ֵ��	��
//*****************************************************
void DestoryCStree( CsRoot &csT )
{
	//������������������������ú�������ķ���
	if ( csT )
	{
		DestoryCStree( csT->FirstSon );
		DestoryCStree( csT->NextBro );
		delete csT;
		csT = NULL;
	}
}

//*****************************************************
//�������ܣ����������������
//���������˫�ױ�ʾ�������level
//�����������
//����ֵ��	��
//*****************************************************
void PreAndOrder( Ptree &ParentTree, int v, int level )
{
	int w;
	cout << "(" << ParentTree.Treenodes[ v ].data << "," << level << ") ";
	w = GetFirstChildIndex( ParentTree, v );//the find the first child's index recursively travel it

	while ( w != -1 )
	{
		PreAndOrder( ParentTree, w, level + 1 );
		w = NextBroIndex( ParentTree, w );	   //find w's next bro, and travel it
	}
}

//*****************************************************
//�������ܣ���������������κ������
//���������˫�ױ�ʾ�������level
//�����������
//����ֵ��	��
//*****************************************************
void PreAndOrderEnter( Ptree &ParentTree)
{
	int i;
	int level = 1;
	for ( i = 0; i < ParentTree.n; i++ )
	{
		if ( ParentTree.Treenodes[ i ].parent == -1 )  //������ɭ�֣��ж�����ڵ㣬������������
		{
			PreAndOrder( ParentTree, i, level );
		}
	}
}

//*****************************************************
//�������ܣ������ֵܱ�ʾ����������
//������������
//�����������
//����ֵ��	��
//*****************************************************
void CsBreadthTable( CsRoot csT )
{
	CsRoot t;
	cout << csT->data;
	if(csT->FirstSon)
	{
		cout << "(";
		for(t = csT->FirstSon ; t->NextBro ; t = t->NextBro)
		{
			CsBreadthTable(t);
			cout << ",";
		}
		CsBreadthTable(t);
		cout << ")";
	}

}

//*****************************************************
//�������ܣ������ֵܱ�ʾ���������
//������������
//�����������
//����ֵ��	��
//*****************************************************
void CsPreOrder( CsRoot csT )
{
	if ( csT )
	{
		Csvisit( csT );
		CsPreOrder( csT->FirstSon );
		CsPreOrder( csT->NextBro );
	}
}
void Csvisit( CsRoot csT )
{
	cout << csT->data << " ";
}

void CsMidOrder( CsRoot csT )
{
	if ( csT )
	{
		CsPreOrder( csT->FirstSon );
		Csvisit( csT );
		CsPreOrder( csT->NextBro );
	}
}

//*****************************************************
//�������ܣ������ֵܱ�ʾ���������
//������������
//�����������
//����ֵ��	��
//*****************************************************
void CsLastOrder( CsRoot csT )
{
	if ( csT )
	{
		CsLastOrder( csT->FirstSon );
		CsLastOrder( csT->NextBro );
		Csvisit( csT );
	}
}

//*****************************************************
//�������ܣ�ת�������ֵܱ�ʾ��Ϊ˫�ױ�ʾ
//��������������ֵ�����㣬˫���� ,�±꣬���ڵ��±�
//���������˫����
//����ֵ��	��
//*****************************************************

void ChangeCStoP( CsRoot &csT, Ptree &PTree, int &index )
{
	queue<CsRoot> Q;
	int parent = -1;
	CsRoot t, root;
	root = csT;
	Q.push( root ); //�ȰѸ�������
	PTree.Treenodes[ index ].data = root->data;//д�������Ϣ
	PTree.Treenodes[ index ].parent = parent;
	index++; //�±�������һ
	parent = index - 2;  //ɭ�ֵ�ʱ�򣬺���Ľ���parent�������ڵ�
	PTree.n++;//���������һ
	Q.pop();//��������
	do
	{
		t = root->FirstSon;	 //tָ����ĵ�һ������
		parent++;			 //���¸��ڵ��±�
		while ( t )			//t���գ���ѭ�����ֵ�д��PT
		{
			Q.push( t );
			PTree.Treenodes[ index ].data = t->data;
			PTree.Treenodes[ index ].parent = parent;
			PTree.n++;
			index++;
			t = t->NextBro;
			//cnt++;
		}
		root = Q.front();	   //Ȼ��ȡ��һ�����ӣ�������������������
		Q.pop();
	}while ( root->FirstSon != NULL || !Q.empty() );  //���һ�������߶��в���Ϊֹ
}
/*void ChangeCStoP( CsRoot csT, Ptree &ParentTree, int &index, int parent )
{
	CsRoot t;
	t = csT->FirstSon;
	while ( t != NULL )
	{
		while ( csT->FirstSon != NULL )
		{
			AssistChange( csT->FirstSon, ParentTree, ++index, parent );
			csT = csT->FirstSon;
			parent++;
		}
		csT = t->NextBro;
		t = t->NextBro;

	}
}

void AssistChange( CsRoot csT, Ptree &ParentTree, int &index, int &parent )
{
	while ( csT )
	{
		ParentTree.Treenodes[ index ].data = csT->data;
		ParentTree.n++;
		ParentTree.Treenodes[ index ].parent = parent;
		index++;
		csT = csT->NextBro;
	}
}	  */
//*****************************************************
//�������ܣ�
//���������
//���������
//����ֵ��
//*****************************************************
