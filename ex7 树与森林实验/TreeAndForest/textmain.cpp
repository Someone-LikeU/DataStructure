#include "Tree.h"
#include <iostream>
#include <cstdlib>
#include <cstdio>

using namespace std;

int main()
{
	int choose, leaves, deg, nodes, height, index, parent,i;
	bool exit = false;
	Ptree PTree; //����һ��˫�ױ�ʾ������
	ChildLink CLtree; //���������ʾ������
	CsRoot CStree,t; //�����ֵ������ʾ
	InitParentForm( PTree ); //first init it
	while ( !exit )
	{
		cout << "*********************************************\n";
		cout << "***************���㷨���Գ���************\n";
		cout << "*1.��������ɭ�֣�    || 2.�����������ɭ�֣�\n";
		cout << "*3.�����������ɭ�֣�|| 4.��α�������ɭ�֣�\n";
		cout << "*5.������ɭ�֣��߶�  || 6.������ɭ�֣��ܽ����\n";
		cout << "*7.������ɭ�֣���    || 8.�����������κš� \n";
		cout << "*9.�������ʽ���    || 10.��Ҷ�����\n";
		cout << "*11. �˳�            || 12.�����ֵ���˫���໥ת��.\n";
		cout << "************************************************\n";
		cout << "��ѡ��";
		cin >> choose;
		while ( choose > 12 || choose < 1 )
		{
			cout << "Error chioce.Please enter again.";
			cin >> choose;
		}
		fflush( stdin );
		switch ( choose )
		{
			case 1:														//pass
				system( "CLS" );
				if ( CreateTreeFromFile( PTree ) )//judge wether success or not to output information
				{
					cout << "�����ɹ������������������\n";
				}
				else
				{
					cout << "����ʧ�ܣ�������\n";
				}
				break;

			case 2:				//pass
				system( "CLS" );
				if ( PTree.n == 0 )	//judge if there is a tree
				{
					cout << "������Ϊ����������ִ�д���������";
					break;
				}
				PreTraverse( PTree );
				break;

			case 3:											//pass
				system( "CLS" );
				if ( PTree.n == 0 )	//judge if there is a tree
				{
					cout << "������Ϊ����������ִ�д���������";
					break;
				}
				LastTraverse( PTree );
				break;

			case 4:									//pass
				system( "CLS" );
				if ( PTree.n == 0 )	//judge if there is a tree
				{
					cout << "������Ϊ����������ִ�д���������";
					break;
				}
				LevelTravel( PTree );
				break;

			case 5:												//pass
				system( "CLS" );
				if ( PTree.n == 0 )	//judge if there is a tree
				{
					cout << "������Ϊ����������ִ�д���������";
					break;
				}
				height = TreeHeightEnter( PTree );
				cout << "����Ϊ��" << height << endl;
				break;

			case 6:											//pass
				system( "CLS" );
				if ( PTree.n == 0 )	//judge if there is a tree
				{
					cout << "������Ϊ����������ִ�д���������";
					break;
				}
				nodes = GetTreeNodes( PTree );
				cout << "���ܽ����Ϊ�� " << nodes << endl;
				break;

			case 7:														//pass
				system( "CLS" );
				if ( PTree.n == 0 )	//judge if there is a tree
				{
					cout << "������Ϊ����������ִ�д���������";
					break;
				}
				cout << "��һ��˫�׷������,���Ϊ ";
				deg = DegOfTree( PTree ); //˫�׷������
				cout << deg << endl;
				cout << "���������������ʾ����ȣ����Ϊ ";
				CreateChildLink( PTree, CLtree );
				deg = DegOfTreeChildLink( CLtree );
				cout << deg << endl;
				DestoryCLtree( CLtree );
				break;

			case 8:									//pass
				system( "CLS" );
				if ( PTree.n == 0 )	//judge if there is a tree
				{
					cout << "������Ϊ����������ִ�д���������";
					break;
				}
				PreAndOrderEnter( PTree);
				break;

			case 9:
				system( "CLS" );
				if ( PTree.n == 0 )	//judge if there is a tree
				{
					cout << "������Ϊ����������ִ�д���������";
					break;
				}
				CreateCS( CStree, PTree ); 	//�ȴ��� �����ֵܱ�ʾ������
				CsBreadthTable( CStree );	 //Ȼ���ú����ֵܱ�ʾ����
				break;

			case 10:
				system( "CLS" );
				if ( PTree.n == 0 )	//judge if there is a tree
				{
					cout << "������Ϊ����������ִ�д���������";
					break;
				}
				leaves = NumOfLeaf( PTree );
				cout << "��һ��˫�ױ�ʾ���󣬽��Ϊ ";
				cout << leaves << endl;
				cout << "���������������ʾ���󣬽��Ϊ�� ";
				CreateChildLink( PTree, CLtree );
				leaves = GetLeafChildLink( CLtree );
				DestoryCLtree( CLtree );
				cout << leaves << endl;
				break;

			case 12:
				system( "CLS" );
				if ( PTree.n == 0 )	//judge if there is a tree
				{
					cout << "������Ϊ����������ִ�д���������";
					break;
				}
				CreateCS( CStree, PTree );
				cout << "��˫�ױ�ʾת���ɺ����ֵܱ��ʾ�ɹ��������������£�\n";
				CsBreadthTable( CStree );
				DestoryCStree(CStree);
				break;

			case 11:
				exit = true;
				break;
		}
		system( "pause" );
		system("CLS");
		fflush( stdin );
	}
	return 0;
}
