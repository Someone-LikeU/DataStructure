#ifndef _TreeAndForst
#define _TreeAndForst
#include <cstdlib>
#define MAXLEN 100			 //���ڵ���
typedef char TreeElement;
//**************************************************
//�����ֵܱ�ʾ��
typedef struct csnode* CsRoot;	 //����ָ��
struct csnode
{
    TreeElement data;
	CsRoot FirstSon, NextBro;
};
//**********************************************************
//˫�ױ�ʾ�������Ľ����Ϣ
typedef struct pnode ParentTree;
struct pnode
{
	TreeElement data;		   //����
	int parent;				//���ڵ���
};
typedef struct something Ptree;	  //	  ˫�ױ�ʾ��
struct something
{
	ParentTree Treenodes[ MAXLEN ];		//�������
	int n; //���������
};
//*************************************************************
//���������ʾ��
typedef struct balabala *ListNode;
struct balabala				   //�����൱��һ��������Ľ�㶨��
{
	int ChildIndex;		//�������,�������ӽڵ�������±�
	ListNode next;	//��������
};
typedef struct lalala		//������Ǻ��������ʾ�Ľṹ����
{
	TreeElement data;	  //����
	ListNode FirstChild;  //�׺���ָ�룬�൱�ڵ�����ı�ͷָ��
}ArrNode;
typedef struct total	   //��װ��һ������ ,�ܹ����������η�װ
{
	ArrNode NodeTable[ MAXLEN ];
	int len;
}ChildLink;

//bool IsVisited[ MAXLEN ];//����������һ���Ƿ񱻷��ʵ�ȫ�ֱ�������
//**************************************************************
//˫�ױ�ʾ����غ�������
void InitParentForm( Ptree &ParentTree );   //��ʼ��˫�ױ�ʾ��
//void InitVisit();
bool CreateTreeFromFile( Ptree &Ptree );
void ShowAllAncestor( Ptree &ParentTree, TreeElement x );  //��Ԫ��x���������Ƚ��ֵ
void ShowChildren( Ptree &ParentTree, TreeElement x );//��Ԫ��x�����к��ӽ��
void PreOrderTravel( Ptree &ParentTree, int v );   //˫�ױ�ʾ�����������,v��ʾ���ڵ�
void PreTraverse( Ptree &ParentTree );  //����������������
void LastOrderTravel( Ptree &ParentTree, int index );  //˫�ױ�ʾ���������
void LastTraverse( Ptree &ParentTree ); //����������
void LevelTravel( Ptree &ParentTree ); //�������
int GetTreeHeight( Ptree &ParentTree, int v ); //�����߶�
int TreeHeightEnter(Ptree &ParentTree );
int GetTreeNodes( Ptree &ParentTree );	 //�ܽ����
int NumOfLeaf( Ptree &ParentTree );	//Ҷ����� ����������ת��Ϊ���������ʾ������childrenָ��Ϊ�յĽ����
int DegOfTree( Ptree &ParentTree );  //˫�ױ�ʾ����Ҷ�����
void PreAndOrder( Ptree &ParentTree, int v, int level );//����������ֵ������
void PreAndOrderEnter( Ptree &ParentTree );//��һ����������ں���
bool GetNodeIndex( int &index, Ptree &Ptree, TreeElement &x );
//������������������ĸ�������
int GetFirstChildIndex( Ptree &ParentTree, int v );//���±�Ϊv�ĵ�һ�����ӽ����±�
int NextBroIndex( Ptree &ParentTree, int w ); //��v����w���ӵ��ֵ�
//*********************************************************************
//���������ʾ��غ���
bool CreateChildLink( Ptree &ParentTree, ChildLink &CL ); //��˫�ױ�ʾ���������������ʾ��
int GetLeafChildLink( ChildLink &CL );     //�ɺ��������ʾ����Ҷ���
int DegOfTreeChildLink( ChildLink &CL ); //�ɺ��������ʾ���������Ķ�
void DestoryCLtree( ChildLink &CL );
void RemoveSp( char *str );
//**********************************************************************
//�����ֵ������ʾ���
void ChangeCStoP( CsRoot &csT, Ptree &ParentTree,int &index ); //�������ֵܱ�ʾ����ת��Ϊ˫�ױ�ʾ
void AssistChange( CsRoot csT, Ptree &ParentTree, int &index, int &parent );  //��������
void Create( CsRoot &csT, Ptree &ParentTree, int v );//��˫�ױ�ʾ�����������ֵܱ�ʾ������
void CreateCS( CsRoot &csT, Ptree &ParentTree ); //��ں���
void CsPreOrder( CsRoot csT );	  //�����ֵܱ�ʾ�����������
void CsBreadthTable( CsRoot csT );//��������
void CsLastOrder( CsRoot csT );	   //�������
void CsMidOrder( CsRoot csT );	  //�������
void Csvisit( CsRoot csT );		  //���ʺ���
void DestoryCStree( CsRoot &csT );
#endif // _TreeAndForst
