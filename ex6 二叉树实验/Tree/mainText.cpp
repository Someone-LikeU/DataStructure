#include <iostream>
#include <cstdio>
#include <cstdlib>
#include "LinkBiTree.h"
#include "seqBiTree.h"
using namespace std;

int main()
{
    int choose, num, nodes, leaves, i, length, level;
    num = nodes = leaves = length = 0;
    bool flag;
	ElementType t, s1, s2;
	BiTree BT = NULL, BT2 = NULL;
	BiNode *p, *c1, *c2;
	SeqBiTree seqBT;
	char path[ MAXN ];			// ��Žڵ�·��������
	i = 0;
	p = c1 = c2 = NULL;  //�ȳ�ʼ��ȫ���ÿ�
    bool Exit = false;
    while(!Exit)
    {
        cout << "*********************************************\n";
        cout << "***************�������㷨���Գ���************\n";
        cout << "*******************��������******************\n";
        cout << "* 1. ���̽���ʽ���� ||  2. �ļ���ʽ����\n";
        cout << "*******************���ٲ���******************\n";
        cout << "* 3.���ٶ�������\n";
		cout << "*******************Ӧ�ò���******************\n";
        cout << "* 4.�������������  ||   5.����ǵݹ����\n";
		cout << "* 6.�������������  ||   7.����ǵݹ����\n";
		cout << "* 8.�������������  ||   9.�ո�ʽ��������\n";
		cout << "*10.�������������  ||  11.�����������������\n";
		cout << "*12.��������ĸ߶�  ||  13.��������ܽ����\n";
		cout << "*14.������Ҷ�����  ||  15.��ӡ����Ҷ���ֵ\n";
		cout << "*16.���������Ƚ��  ||  17.ֵΪx�Ľ������ݽ��\n";
        cout << "*18.�������ڲ��  ||  19.ת��˳�������Ϊ��������\n";
		cout << "*20.������������    ||  21.���ƶ�����T��T1\n";
        cout << "*22.����Ҷ���·��  ||  23.��������������������\n";
        cout << "*24.��һ���·��  ||  25.ת˳�����������\n";
        cout << "*26.�˳�    	    ||  27.�ո�ʽ\n";
		cout << "************************************************\n";
		cout << "��ѡ��";
		cin >> choose;
		while( choose > 26 || choose < 1 )
		{
			cout << "ѡ�����������ѡ��: ";
			cin >> choose;
		}
		fflush( stdin );
		switch ( choose )
		{
			case 1:	  //��������������					//PASS
				system("CLS");   //����
				if ( BT )   		//��ֹ�ظ�����������ڴ�й©
				{
					cout << "�Ѿ�������һ�ö������ˣ���ѡ����������.\n";
					break;
				}
				CreateTreeInteractive( BT );
				if ( BT )
				{
					cout << "�����ɹ������������������\n";
				}
				else
				{
					cout << "����ʧ��.������\n";
				}
				break;

			case 2:			   				//�ļ���ʽ����,pass
				system("CLS");
				if ( BT  )
				{
					cout << "�Ѿ�������һ�ö������ˣ���ѡ����������.\n";
					break;

				}
				CreateTreeUsingFile( BT );
				if (BT)
				{
					cout << "�����ɹ������������������\n";
				}
				else
				{
					cout << "����ʧ��.������\n";
				}
				break;

			case 3:			//���ٲ���,pass
				system("CLS");
				if ( BT == NULL )  //���ж��Ƿ�Ϊ����
				{
					cout << "����Ϊ�գ��������٣����������������" << endl;
				}
				else
				{
					DestoryBiTree( BT );
					cout << "���ٳɹ������������������\n";
				}
				break;

			case 4:		    //travel,pass
				system("CLS");
				if ( BT )   //������ʱ��
				{
					cout << "������������Ϊ��";
					PreOrderTravel( BT );
					cout << endl;
				}
				else
				{
					cout << "�ö�����Ϊ�գ����ȴ�����" << endl;
				}
				if ( BT2 )  //���ƵĶ�����
				{
					cout << "\n˳���ղŸ��ƵĶ�������";
					PreOrderTravel(BT2);
					cout << endl;
				}
				break;

			case 5: 						//pass
				system("CLS");
				if ( BT )
				{
					cout << "����ǵݹ���������Ϊ��";
					PreTravelNoRec( BT );
					cout << endl;
				}
				else
				{
					cout << "�ö�����Ϊ�գ����ȴ�����" << endl;
				}
				if ( BT2 )  //���ƵĶ�����
				{
					cout << "\n˳���ղŸ��ƵĶ�������";
					PreTravelNoRec(BT2);
					cout << endl;
				}
				break;

			case 6:                           //pass
				system("CLS");
				if ( BT )
				{
					cout << "������������Ϊ��";
					MidOrderTravel( BT );
					cout << endl;
				}
				else
				{
					cout << "�ö�����Ϊ�գ����ȴ�����" << endl;
				}
				if ( BT2 )  //���ƵĶ�����
				{
					cout << "\n˳���ղŸ��ƵĶ�������";
					MidOrderTravel(BT2);
					cout << endl;
				}
				break;

			case 7:              //pass
				system("CLS");
                if( BT)
				{
					cout << "����ǵݹ���������Ϊ��";
					MidTravelNoRec( BT );
					cout << endl;
				}
				else
				{
					cout << "�ö�����Ϊ�գ����ȴ�����" << endl;
				}
				if ( BT2 )  //���ƵĶ�����
				{
					cout << "\n˳���ղŸ��ƵĶ�������";
					MidTravelNoRec(BT2);
					cout << endl;
				}
				break;

			case 8:										//pass
				system("CLS");
				if( BT)
				{
					cout << "������������Ϊ��";
					LastOrderTravel( BT );
					cout << endl;
				}
				else
				{
					cout << "�ö�����Ϊ�գ����ȴ�����";
				}
				if ( BT2 )  //���ƵĶ�����
				{
					cout << "˳���ղŸ��ƵĶ�������";
					LastOrderTravel(BT2);
					cout << endl;
				}
				break;

			case 9:
				system("CLS");
				break;

			case 10:		   //level travel,  pass
				system("CLS");
				if(BT)
				{
					cout << "������������Ϊ��";
					LevelOrderTravel( BT );
					cout << endl;
				}
				else
				{
					cout << "�ö�����Ϊ�գ����ȴ�����";
				}
				if ( BT2 )  //���ƵĶ�����
				{
					cout << "˳���ղŸ��ƵĶ�������";
					LevelOrderTravel(BT2);
					cout << endl;
				}
				break;

			case 11:		   //mid order travel and level of nodes     //pass
				system("CLS");
				if ( !BT )
				{
					cout << "�����������ڣ����ȴ�����\n";
					break;
				}
				cout << "����������Ϊ��\n";
				MidTravelAndLevel( BT, 1 );//Ĭ�ϸ��ڵ�Ϊ��1��
				break;

			case 12:		 //height of tree     //pass
				system("CLS");
				if ( !BT )
				{
					cout << "�����������ڣ����ȴ�����\n";
					break;
				}
				cout << "�������ĸ߶�Ϊ��" << GetTreeHeight( BT ) << endl;
				break;

			case 13:		//�ܽ����			//pass
				system("CLS");
				if ( !BT )
				{
					cout << "�����������ڣ����ȴ�����\n";
					break;
				}
				nodes = 0;
				TotalNodes( BT, nodes );
				cout << "��������һ���� " << nodes << " �����.\n";
				nodes = 0;	//ǰ�������ã���������Ҫ����0�������´ε��øú���ʱ�ظ�����
				break;

			case 14:		 //total leaf				//pass
				system("CLS");
				if ( !BT )
				{
					cout << "�����������ڣ����ȴ�����\n";
					break;
				}
				leaves = 0;
				NumOfLeaf( BT, leaves );
				cout << "��������һ���� " << leaves << " ��Ҷ���.\n";
				leaves = 0;
				break;

			case 15:						//pass
				system("CLS");
				if ( !BT )
				{
					cout << "�����������ڣ����ȴ�����\n";
					break;
				}
				cout << "����Ҷ����ֵΪ��";
				ShowLeaves( BT );
				cout << endl;
				break;

			case 16:					//pass
				system("CLS");
				if ( !BT )
				{
					cout << "�����������ڣ����ȴ�����\n";
					break;
				}
				cout << "���Ƚ�����£�\n";
				num = 0;
				NumOfDeg2( BT, num );
				cout << "�� " << num << " ��" << endl;
				num = 0;
				break;

			case 17:						//pass
				system("CLS");
				if ( !BT )
				{
					cout << "�����������ڣ����ȴ�����\n";
					break;
				}
				cout << "������һ��Ԫ�أ�";
				cin >> t;
				RelativeOfNode( BT, t );
				break;

			case 18:									//pass
				system("CLS");
				if ( !BT )
				{
					cout << "�����������ڣ����ȴ�����\n";
					break;
				}
				cout << "������һ��Ԫ�أ�";
				cin >> t;
				level = 1;
				flag = false;
				LevelOfNode( BT, t, level, flag);
				if(flag == false)
				{
					cout << "�������в����ڸýڵ�,������ѡ��\n";
				}
				break;

			case 19:								//pass
				system("CLS");
				num = 1;
				if (seqBT.len == 0)
				{
					cout << "���ȴ���˳�������" << endl;
					break;
				}
				else
				{
					ChangeArrIntoLink( BT, seqBT, num );
				}
				cout << "ת���ɹ������������������\n";
				break;

			case 20:							//pass
				system("CLS");
				ExchangeRightLeft( BT );
				cout << "�����ɹ����������������\n";
				break;

			case 21:							//pass
				system("CLS");
				CopyTree( BT, BT2 );
				if ( BT2 == NULL )
				{
					cout << "����ǰ��BT2Ϊ������\n";
				}
				cout << "���Ƴɹ�������BT2�����½�㣺";
				PreOrderTravel( BT2 );
				cout << endl;
				break;

			case 22:							//pass
				system("CLS");
				cout << "����Ҷ���·�����£�\n";
				EachPathOfLeaf( BT, path, i );
				break;

			case 23:					//pass
				system("CLS");
				cout << "��������������Ԫ��ֵ���ÿո�ָ� ��";
				cin >> s1 >> s2;
				p = FindCommonAnc( s1, s2, BT );
				if ( p == NULL )
				{
					cout << "��Ǹ��û�ҵ������Ĺ������ȡ� \n";
					break;
				}
				else
				{
					cout << "��������ֵΪ��" << p->data << endl;
				}

				cout << "������ "<<endl;
				c1 = GetNode(s1, BT);
				c2 = GetNode(s2,BT);
				p = FindComAnc2(c1,c2,BT);
				if ( p == NULL )
				{
					cout << "��Ǹ��û�ҵ������Ĺ������ȡ� \n";
				}
				else
				{
					cout << "��������ֵΪ��" << p->data << endl;
				}
				break;

			case 24:						//pass
				system("CLS");
				cout << "�������е�";
				length = FindLongestPath( BT );
				cout << "����·����Ϊ��" << length << endl;
				break;

			case 25:							//pass
				system("CLS");
                cout << "**********************************************\n";
                cout << "*************˳�����������****************\n";
                cout << "*1.������ʽ����     ||     2.�������" << endl;
                cout << "*3.�������         ||     4.�������"  <<endl;
                cout << "*5.��α���	    || 	   6.�ļ���ʽ����" << endl;
                cout << "*7.�˳�\n";
				cout << "**********************************************\n";
				cout << "��ѡ��";
				cin >> choose;
				while( choose > 7 || choose < 1 )
				{
					cout << "ѡ�����������ѡ��: ";
					cin >> choose;
				}

				switch(choose)
				{
				case 1:							//pass
					system("CLS");
					InitialTree( seqBT ); //�ȳ�ʼ��
					CreateSeqTreeInteract( seqBT );
					system("pause");
					break;

				case 2:						//pass
					system("CLS");
					cout << "����������£�";
					i = 1;
					PreTravel(seqBT, i);
					cout << endl;
					break;

				case 3:								//pass
					system("CLS");
					cout << "�����������: " ;
					i = 1;
					MidTravel(seqBT,i);
					cout << endl;
					break;

				case 4:								//pass
					system("CLS");
					cout << "����������£� ";
					i = 1;
					LastTravel(seqBT,i);
					cout << endl;
					break;

				case 5:					//pass
					system("CLS");
					cout << "����������£�";
					LevelTravel(seqBT);
					cout << endl;
					break;

				case 6:
					system("CLS");
					CreateSeqTreeUsingFile(seqBT);
                    for ( i = seqBT.len ; i > 0 ; i-- )				//��������м仹��Щ�յ�λ�ã�Ҫ������ȫ������
					{
						if(seqBT.data[i] == ' ')
							seqBT.data[i] = '*';
					}
					cout << "�����ɹ�\n";
					cout << "�� "  << seqBT.len << "����㡣\n";
					cout << endl;
					break;
				case 7:
					break;
				}

				break;

			case 26:
				system("CLS");
				DestoryBiTree( BT );   //��ֹ�û��˳�ǰûִ�����ٲ�����
				DestoryBiTree( BT2 );
				Exit = true;
				break;

			default:
				break;
		}
		system( "pause" );
		system( "CLS" );
		fflush(stdin);
    }
    return 0;
}
