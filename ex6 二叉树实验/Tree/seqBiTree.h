#ifndef _SeqBiTree
#define _SeqBiTree
#define MAXN 100
typedef char elementType;
typedef struct TriNode			   //���������ṹ
{
	elementType data[MAXN];	//������,Լ�����ֵΪ*��ʾ�ս��
	int len;
}SeqBiTree;

void InitialTree( SeqBiTree &seqTree );
void removeSpace( char *str );
void createSubtree( SeqBiTree &seqTree, int locate,char element );
void CreateSeqTreeUsingFile( SeqBiTree &seqTree );
void GetData( char TreeData[ MAXN ][ 4 ], int &datalen );
void Assist( SeqBiTree &seqTree, char TreeData[ MAXN ][ 4 ], int &datalen, int &cur,int treeIndex );
int CreateSeqTreeInteract(SeqBiTree &seqTree );//����ʽ����˳�������
void HelpCreate(  SeqBiTree &ST, char data[ MAXN ][ 4 ], int &cur, int node ,int len  );//�ļ�������������������
void PreTravel( SeqBiTree &seqTree, int i );
void MidTravel( SeqBiTree &seqTtree, int i );
void LastTravel( SeqBiTree &seqTree, int i );
void LevelTravel( SeqBiTree &seqTree );
#endif
