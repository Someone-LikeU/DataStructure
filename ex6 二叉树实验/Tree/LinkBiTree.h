#ifndef _LinkBiTree
#define _LinkBiTree
#define MAXNODES 100        //�涨���100�����
#include "AVLTree.h"
#include "seqBiTree.h"
typedef char ElementType;   //�ȶ�Ϊ�ַ�����
typedef struct TreeNode *BiTree;    //�����ָ��
typedef struct TreeNode BiNode;     //�����
struct TreeNode
{
    ElementType data;
    BiTree Left;               //����
	BiTree Right;            //�Һ���
};
//�����㷨����Ӧ��
void Visit( BiTree BT );                                                                        //��������������ʵ���������
void PreOrderTravel( BiTree BT );           //���������������
void MidOrderTravel( BiTree BT);          //�������������
void LastOrderTravel( BiTree BT);          //�������������
void PreTravelNoRec( BiTree BT);            //�ǵݹ��������
void MidTravelNoRec( BiTree BT);     //�ǵݹ��������
void LastTravelNoRec( BiTree BT );       //�ǵݹ�������
void LevelOrderTravel( BiTree BT );             //��α���
void MidTravelAndLevel( BiTree BT, int Level );  //������������������ڲ��
int GetTreeHeight( BiTree BT );                       //��������߶�
void TotalNodes( BiTree BT, int &cnt );            //���ܽ����
void NumOfLeaf( BiTree BT, int &cnt );           //�������Ҷ�����
void ShowLeaves( BiTree BT );            //��ӡ����Ҷ����ֵ
void NumOfDeg2( BiTree BT, int &cnt );                     //�������2�Ƚ����
void RelativeOfNode( BiTree BT, ElementType &x );     //��Ԫ��Ϊx�Ľ������ݽ��
void LevelOfNode( BiTree BT, ElementType &x, int level, bool &flag );          //��Ԫ��Ϊx�Ľ��Ĳ��
void ChangeArrIntoLink( BiTree &BT, SeqBiTree &Tree,int i );  //��˳�������ת������������
void GetChild( BiTree BT, ElementType &x, BiNode* &C1, BiNode* &C2);  //ȡֵΪx�Ľ����ӽ��
void GetFather( BiTree BT, ElementType &x, BiNode* &S );                    //�󸸽ڵ�
void GetBro( BiTree BT,ElementType &x, BiNode* &Bro );        //���ֵܽڵ�
//��չ
BiNode* GetNode( ElementType x, BiTree BT ); //�ڶ��������ҽ��ֵΪx�Ľ��
void PathOfNode( ElementType &x, BiTree BT, char* str, int &i, bool &flag ); //ֵΪx�Ľ���·��
void CopyTree( BiTree SourceT, BiTree &T );                //����һ�ö�����
void EachPathOfLeaf( BiTree BT, char* str,int &i );            //��ÿ��Ҷ����·��
BiNode* FindCommonAnc( ElementType &e1, ElementType &e2, BiTree BT );   //�������������Ĺ�ͬ����
BiNode* FindComAnc2( BiNode *e1, BiNode *e2, BiTree BT ); //������
int FindLongestPath( BiTree BT );//���������һ���·�����Ȳ����·���ϵ�ֵ

//�����������㷨
void CreateTreeUsingFile( BiTree &BT ); //�ļ���ʽ����������
void CreateTreeInteractive( BiTree &BT ); //������ʽ����������
void GetTreeData( char TreeData[ MAXNODES ][ 4 ], int &len );
void CreateNode( BiTree &pNode , char data[MAXNODES][4], int len, int &cur ); //�ļ���ʽ����Э������
void AssistCreate( BiNode* &p, ElementType &x,int left, int right );	//������ʽ����Э������
void RemoveSp( char *str );

//������������
void DestoryBiTree( BiTree &BT );

//���������޸�
void ExchangeRightLeft( BiTree BT );    //������������
void DeleteSibTree( BiTree BT );    //ɾ������
#endif // _LinkBiTree
