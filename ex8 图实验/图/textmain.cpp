#include "graph2.h"
#include <iostream>
#include <cstdlib>
#include <cstdio>
using namespace std;
#ifdef DEBUG
int deBug1(void);
#else

void text1( char *str );
void text2( char *str );
void text3( char *str );
void text4( char *str );
void text5( char *str );
void text6( char *str );
void text7( char *str );
void text8( char *str );
void text9( char *str );
void text10( char *str );
int menu(const char *str, graph &G);
int c_graph(char str[64], graph &G);
int menu_c_graph(void);
#endif // DEBUG

int main()
{
	int ch;
	char str[64];
	graph G;
	bool exit  = false;
	#ifdef DEBUG
	std::cin >> ch;
	deBug1();
	#else
	while ( !exit )
	{
	    cout << "**********************************************************\n";
        cout << "************ͼ���Գ���********************************* \n";
        cout << "* 1.���������������   ||    2.�����ͼ�ı���\n";
        cout << "* 3.�Ӹ��������ȱ���   ||    4.�Ӹ�������ȱ���\n";
        cout << "* 5.prim�õ���С������   ||    6.Kruskal��С������\n";
        cout << "* 7.Dijkstra�����·��   ||    8.Floyd���·��\n";
        cout << "* 9.��������             ||    10.��AOE���Ĺؼ�·��\n";
        cout << "*11.�˳�                 ||    12.�ո�ʽ\n";
        cout << "***********************************************************\n";
        cout << "��ѡ�� ";
	    cin >> ch;
	    switch(ch)
	    {
	        case 1:  //pass
            system("CLS");
            cout << "��1����ԣ�udg8.grp\n";
            strcpy(str,"udg8.grp");
            text1( str );
            cout << "\n��2����ԣ�udg115.grp\n";
            strcpy(str,"udg115.grp");
            text1( str );
            cout << "\n��3����ԣ�dg6.grp\n";
            strcpy(str,"dg6.grp");
            text1( str );
            cout << "\n��4����ԣ�f14.grp\n";
            strcpy(str,"f14.grp");
            text1( str );
            break;

        case 2:   //pass
            system("CLS");
            cout << "��1����ԣ�udg115.grp";
            strcpy(str,"udg115.grp");
            text2(str);
            cout << "\n��2����ԣ�dg6.grp";
            strcpy(str,"dg6.grp");
            text2(str);
            cout << "\n��3����ԣ�f14.grp";
            strcpy(str,"f14.grp");;
            text2(str);
            break;

        case 3:             //pass
            system("CLS");
            cout << "��1����ԣ�udg8.grp";
            strcpy(str,"udg8.grp");;
            text3(str);
            cout << "\n��2����ԣ�dg6.grp";
            strcpy(str,"dg6.grp");;
            text3(str);
           // cout << "\n��3����ԣ�un8.grp";
            //strcpy(str,"un8.grp");;
            //text3(str);
            cout << "��4����ԣ�dn10.grp";
            strcpy(str,"dn10.grp");;
            text3(str);
            break;

        case 4:  //pass
            system("CLS");
            cout << "��1����ԣ�udg8.grp";
            strcpy(str,"udg8.grp");;
            text4(str);
            cout << "\n��2����ԣ�dg6.grp";
            strcpy(str,"dg6.grp");;
            text4(str);
           /* cout << "\n��3����ԣ�un8.grp";
            strcpy(str,"un8.grp");;
            text4(str);*/
            cout << "��4����ԣ�dn10.grp";
            strcpy(str,"dn10.grp");;
            text4(str);
            break;

        case 5:
            system("CLS");
            cout << "��1����ԣ�udn6.grp";
            strcpy(str,"udn6.grp");;
            text5(str);
            cout << "��2����ԣ�un8.grp";
            strcpy(str,"un8.grp");;
            text5(str);
            break;
        case 6:
            system("CLS");
            cout << "��1����ԣ�udn6.grp";
            strcpy(str,"udn6.grp");;
            text6(str);
            /*cout << "��2����ԣ�un8.grp";
            strcpy(str,"un8.grp");;
            text6(str);*/
            break;
        case 7:    //pass
            system("CLS");
            cout << "��1����ԣ�udn6.grp";
            strcpy(str,"udn6.grp");;
            text7(str);
            cout << "��2����ԣ�un8.grp";
            strcpy(str,"un8.grp");;
            text7(str);
            cout << "��3����ԣ�dn8.grp";
            strcpy(str,"dn8.grp");;
            text7(str);
            cout << "��4����ԣ�dn10.grp";
            strcpy(str,"dn10.grp");;
            text7(str);
            break;
        case 8:         //pass
            system("CLS");
            cout << "��1����ԣ�udn6.grp";
            strcpy(str,"udn6.grp");;
            text8(str);
            cout << "��2����ԣ�un8.grp";
            strcpy(str,"un8.grp");;
            text8(str);
            cout << "��3����ԣ�dn8.grp";
            strcpy(str,"dn8.grp");;
            text8(str);
            cout << "��4����ԣ�dn10.grp";
            strcpy(str,"dn10.grp");;
            text8(str);
            break;

         case 9:                //pass
            system("CLS");
            cout << "��1����ԣ�top6dg1.grp";
            strcpy(str,"top6dg1.grp");;
            text9(str);
            cout << "��2����ԣ�top7dg1.grp";
            strcpy(str,"top7dg1.grp");;
            text9(str);
            cout << "��3����ԣ�dn8.grp";
            strcpy(str,"dn8.grp");;
            text9(str);
            cout << "��4����ԣ�dn10.grp";
            strcpy(str,"dn10.grp");;
            text9(str);
            break;

        case 10: //pass
            system("CLS");
            cout << "��1����ԣ�dn8.grp";
            strcpy(str,"dn8.grp");;
            text10(str);
            cout << "��2����ԣ�dn10.grp";
            strcpy(str,"dn10.grp");;
            text10(str);
            break;

        case 11:
            exit = true;
            break;
	    }
	fflush(stdin);
	system("pause");
	system("CLS");
	}
	#endif // DEBUG
	return 0;
}

void text1( char *str )
{
	graph G;
	G.coverGraph(str);
	G.dfsTraversal_l();
	G.bfsTraversal_l();
}

void text2(char *str)
{
	graph G;
	G.coverGraph(str);
	cout << "��ͼ�б�(��)������Ϊ:" << G.get_Enum_l() << endl;
}

void text3(char *str)
{
	graph G;
	G.coverGraph(str);
	cout << "��ȱ�����������\n";
	G.dfsTraversal_t_l();
}

void text4(char *str)
{
	graph G;
	G.coverGraph(str);
	cout << "��ȱ�����������\n";
	G.bfsTraversal_t_l();
}

void text5(char *str)
{
	graph G;
	G.coverGraph(str);
	cout<<"\n prim  �㷨����: ";
    G.Prim_l(G.getNode_for_ID(0)) ;
}

void text6(char *str)
{
	graph G;
	G.coverGraph(str);
	cout<<"\nKruskal�㷨: ";
	G.Kruskal_l();
}

void text7(char *str)
{
	graph G;
	G.coverGraph(str);
	cout<<"Dijkstra�㷨:"<<endl;
	G.Dijkstra_l(G.getNode_for_ID(0));
}

void text8(char *str)
{
	graph G;
	G.coverGraph(str);
	cout<<"Floyd�㷨:\n";
	G.Floyd_l();
}

void text9(char *str)
{
	graph G;
	G.coverGraph(str);
	cout << "��������\n";
	G.AOV_l();
}

void text10(char *str)
{
	graph G;
	G.coverGraph(str);
	cout << "AOE���ؼ�·����\n";
	G.AOE_l();
}

int menu(const char * str, graph & G)
{
	if(!G.empty())
	{
		std::cout << str << std::endl;
	}
	else
	{
		std::cout << "δ����ͼ!" << std::endl;
	}
	cout << "**********************************************************\n";
    cout << "************ͼ���Գ���********************************* \n";
    cout << "* a.�������޸�ͼ       ||   b.����ͼ\n";
    cout << "* 1.���������������   ||    2.�����ͼ�ı���\n";
    cout << "* 3.�Ӹ��������ȱ���   ||    4.�Ӹ�������ȱ���\n";
    cout << "* 5.prim�õ���С������   ||    6.Kruskal��С������\n";
    cout << "* 7.Dijkstra�����·��   ||    8.Floyd���·��\n";
    cout << "* 9.��������             ||    10.��AOE���Ĺؼ�·��\n";
    cout << "*11.�˳�                 ||    12.�ո�ʽ\n";
    cout << "***********************************************************\n";
    cout << "��ѡ�� ";
	return 0;
}
