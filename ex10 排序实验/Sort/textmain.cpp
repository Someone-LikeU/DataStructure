#include "sort.h"
#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <iomanip>
#include <ctime>
#include <Windows.h>
#include <graphics.h>
#include <conio.h>
#if _MSC_VER
#define snprintf _snprintf
#endif

using namespace std;

void GetDh1( int *dh, int &dhlen, int &scale );
void GetDh2( int *dh, int &dhlen, int &scale );
void GetDh3( int *dh, int &dhlen, int &scale );
void GetDh4( int *dh, int &dhlen, int &scale );
int main()
{
	int choose, cntCom, cntExch, i, j, dhlen;
	int datas[ 6 ] = { SCALE1, SCALE2, SCALE3, SCALE4, SCALE5, SCALE6 };
	clock_t begin, end;
	int text21[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26 };
	int text22[] = { 11, 12, 13, 14, 15, 1, 2, 3, 4, 5, 6, 10, 16, 1, 22, 23, 2, 17, 18, 19, 20, 24, 7, 8, 9, 25, 26 };
	int text23[] = { 5, 6, 7, 1, 2, 3, 4, 8, 9, 10, 11, 12, 13, 16, 17, 18, 14, 25, 26, 15, 19, 20, 21, 22, 23, 24 };
	int text3[] = { 180, 203, 32, 46, 25, 76, 17, 58, 99, 100, 11, 102, 13, 54, 75, 6, 27, 18, 19, 29, 2, 82 };
	int text4[ 40 ] = { 0 };
	int text[] = { 106, 213, 325, 446, 579, 654, 721, 870, 917, 510, 21, 632, 73, 14, 815, 316, 412, 18, 619, 720, 21, 808, 923, 25, 26 };
	int *text1 = NULL;
	int *temp = NULL;
	int *dh = NULL,len;
	HWND hwnd;		//���ھ��
	bool exit = false, re = false, show;
	while ( !exit )
	{
		cout << "*********************************************\n";
		cout << "***************�����㷨���Գ���************\n";
		cout << "* 1.��������  ||   2.�ؼ�������\n";
		cout << "* 3.ϣ������  ||   5.��������ʾ\n";
		cout << "* 4.�鲢����  ||   6.����������ʾ��\n";
		cout << "* 7.�˳�";
		cout << "************************************************\n";
		cout << "��ѡ��";
		cin >> choose;
		while ( choose > 7 || choose < 1 )
		{
			cout << "ѡ�����������ѡ��: ";
			cin >> choose;
		}
		switch ( choose )
		{
			case 1:						//��������	,pass
				system( "CLS" );
				show = false;  //�����ô�ӡ���Ϊfalse
				srand( time( NULL ) );				   //�������������
				re = false;
				for ( i = 0; i < 6; i++ )
				{
					cout << "�� " << i + 1 << " �����," << datas[ i ] << "������:\n";
					text1 = new int[ datas[ i ] + 1 ]; //ÿ�η����Ӧ�������ռ�
					if ( text1 == NULL )			  //�����ڴ�ʧ�ܣ����˳�
					{
						cout << "Memory allocate failed.exit.\n";
						exit = true;
						break;
					}
					for ( j = 0; j < datas[ i ]; j++ )	   //�����ֵ
					{
						text1[ j ] = rand();
					}
					len = datas[ i ];  //ÿ�εĲ���������
					cntCom = cntExch = 0;	  //��ʼ��������
					begin = clock();		  //��ʱÿһ�ο���������ʱ
					QuickSort( text1, len, 0, len, re, cntCom, cntExch );
					end = clock();
					cout << "Ԫ�ؽ������� " << cntExch << " ���Ƚϴ��� " << cntCom;
					cout << " ������������ʱ" << ( double ) ( end - begin ) / CLK_TCK << "��\n";
					delete[] text1;//�ǵû���ǰ�����Ŀռ�
				   	system( "pause" );	 //��ͣ���ȴ�����س���
					system( "CLS" );	 //������Ȼ�������
				}
				break;

			case 2:					 //�ؼ�������pass
				system( "CLS" );	 //������Ȼ�������
				cout << "��һ����ԣ�\n";
				cout << "����ǰ��\n";
				len = sizeof( text21 ) / sizeof( ElementType );
				ShowResult( text21, len );
				cout << "�����\n";
				ChooseSort( text21, len );
				ShowResult( text21, len );
				system( "pause" );	 //��ͣһ���
				system( "CLS" );	 //������Ȼ�������

				cout << "�ڶ������:\n";
				len = sizeof( text22 ) / sizeof( ElementType );
				ShowResult( text22, len );
				cout << "�����\n";
				ChooseSort( text22, len );
				ShowResult( text22, len );
				system( "pause" );	 //��ͣһ���
				system( "CLS" );	 //������Ȼ�������

				cout << "��������ԣ�\n";
				len = sizeof( text23 ) / sizeof( ElementType );
				ShowResult( text23, len );
				cout << "�����\n";
				ChooseSort( text23, len );
				ShowResult( text23, len );
				break;

			case 3:					 //ϣ������
				system( "CLS" );	 //������Ȼ�������
				cout << "��Ŀ���ԣ����򲽳�1��2��4����������\n";
				i = 0;
				j = 1;
				len = sizeof( text3 ) / sizeof( ElementType );	  //������������
				dh = new int[ len / 2 ];		 //����һ����������
				if ( dh == NULL )
				{
					cout << "Memory allocate failed.exit.\n";
					exit = true;
					break;
				}
				while ( j < len )  //�������ܳ������鳤�ȣ�����j С��len
				{
					dh[ i ] = j;   //������д�벽������
					i++;		   //�����±�ָʾ��i
					j = 1 << i;	   //1����iλ��ʵ��2��ָ��
				}
				show = false;
				cout << "ϣ������ǰ������Ϊ��\n";
				ShowResult( text3, len );
				cout << "��ʼ����.\n";
				begin = clock();
				ShellSort( text3, len, show, dh, i );
				end = clock();
				cout << "\n��ʱ " << ( double ) ( end - begin ) / CLK_TCK << " �룬���������Ϊ��\n";
				ShowResult( text3, len );
				delete[] dh;
				cout << "��չ����:\n";
				system( "pause" );
				system( "CLS" );

				//��Ŀ������ϣ���������չ���ԣ�
				dh = new int[ 100 ];
				show = false;
				for ( i = 0; i < 6; i++ )
				{
					cout << "��չ���� " << i + 1 << ":" << datas[ i ] << "�����ݣ�\n";
					text1 = new int[ datas[ i ] + 1 ]; //ÿ�η����Ӧ����ռ�
					temp = new int[ datas[ i ] + 1 ] ;
					if ( text1 == NULL )
					{
						cout << "Memory allocate failed.exit.\n";
						exit = true;
						break;
					}
					//Ȼ�������
					for ( j = 0; j < datas[i]; j++ )
					{
						text1[ j ] = rand();
					}
					memcpy( temp, text1, sizeof( text1 ) );//�ȸ��Ƶ�temp������
					//then begin to text
					len = datas[ i ];		  //ÿ�β��Ե�������
					cout << "��һ����������1.5.19.�������� 4^i - 3 * 2 ^ i + 1:\n";
					GetDh1( dh, dhlen, len );		//���Ե�һ�ֲ���
					begin = clock();
					ShellSort( text1, len, show, dh, dhlen );
					end = clock();
					cout << "��ʱ " << ( double ) ( end - begin ) / CLK_TCK << "��\n";
					system( "pause" );
					system( "CLS" );		//���������Եڶ�������
					
					//memcpy( text1, temp, sizeof( temp ) );  //��temp����ȥ��������һ������
					cout << "�ڶ����������� 1 4 13 40 121 364 1093 3280...h = 1 h = 3 * h + 1:\n";
					GetDh2( dh, dhlen, len );		//���Ե�2�ֲ���
					begin = clock();
					ShellSort( text1, len, show, dh, dhlen );
					end = clock();
					cout << "��ʱ " << ( double ) ( end - begin ) / CLK_TCK << "��\n";
					system( "pause" );
					system( "CLS" );		//���������Ե�3������

					memcpy( text1, temp, sizeof( temp ) );  //��temp����ȥ��������һ������
					cout << "��3���������� 1.3.7......2 ^ k - 1 :\n";
					GetDh3( dh, dhlen, len );		//���Ե�3�ֲ���
					begin = clock();
					ShellSort( text1, len, show, dh, dhlen );
					end = clock();
					cout << "��ʱ " << ( double ) ( end - begin ) / CLK_TCK << "��\n";
					system( "pause" );
					system( "CLS" );		//���������Ե�4������

					memcpy( text1, temp, sizeof( temp ) );  //��temp����ȥ��������һ������
					cout << "��4���������� 1.4.13........����3^k - 1) / 2:\n";
					GetDh4( dh, dhlen, len );		//���Ե�3�ֲ���
					begin = clock();
					ShellSort( text1, len, show, dh, dhlen );
					end = clock();
					cout << "��ʱ " << ( double ) ( end - begin ) / CLK_TCK << "��\n";
					system( "pause" );
					system( "CLS" );		//����

					delete[] text1; 		//һ�����ݲ����꣬���տռ䣬����Ϻ�������
					delete[] temp;
				}
				break;

			case 4:	   				  //�鲢���� ,pass
				system( "CLS" );
				cout << "����ǰ,����Ԫ�أ�\n";
				len = sizeof( text ) / sizeof( ElementType );
				ShowResult( text, len );
				cout << "��ʼ����\n";
				cntCom = 0;
				MergeSort( text, len, cntCom );
				cout << "���������Ԫ��:\n";
				ShowResult( text, len );
				cout << "�Ƚ���" << cntCom << "��\n";
				system( "pause" );
				cout << "������6����ԣ�\n";
				for ( i = 0; i < 6; i++ )
				{
					cout << "�� " << i + 1 << "�飬" << datas[ i ] << "�����ݡ�\n";
					cntCom = 0;
					text1 = new int[ datas[ i ] ]; //ÿ�η����Ӧ����ռ�
					if ( text1 == NULL )
					{
						cout << "Memory allocate failed.exit.\n";
						exit = true;
						break;
					}
					//Ȼ�������
					for ( j = 0; j < datas[ i ]; j++ )
					{
						text1[ j ] = rand( );
					}
					//then begin to text
					len = datas[ i ];		  //ÿ�β��Ե�������
					begin = clock( );
					MergeSort( text1, len, cntCom );
					end = clock( );
					cout << "��ʱ " << ( double ) ( end - begin ) / CLK_TCK << "��\n";
					cout << "�Ƚϴ���Ϊ " << cntCom << "\n";
					system( "pause" );
					system( "CLS" );		//������������һ������
					delete[ ] text1; 		//һ�����ݲ����꣬���տռ䣬����Ϻ�������
				}
				break;

			case 5:	   //��������ʾ ,pass
				system( "CLS" );
				srand( time( NULL ) );
				initgraph( 1000,600, SHOWCONSOLE ); //����һ��2000 * 1000�Ĵ���
				setbkcolor( WHITE );
				hwnd = GetHWnd( ); //�ô�����ǰ
				len = sizeof( text4 ) / sizeof( int );
				show = true;
				cout << "before heap sort.\n";
				for ( i = 0; i < len; i++ )
				{
					text4[ i ] = rand() % 450 + 50;
				}
				ShowResult( text4, len );
				HeapSort( text4, len, show );
				DrawResult( text4, len, 0 );
				MessageBox( hwnd, "Sort succeed!", "Information", MB_OK );
				closegraph();
				system( "pause" );
				break;

			case 6:					 //������ʾ	,pass
				system( "CLS" );
				srand( time( NULL ) );
				initgraph( 1000,600, SHOWCONSOLE ); //����һ��2000 * 1000�Ĵ���
				setbkcolor( WHITE );
				hwnd = GetHWnd( ); //�ô�����ǰ
				len = sizeof( text4 ) / sizeof( int );
				show = true;
				cout << "before heap sort.\n";
				for ( i = 0; i < len; i++ )
				{
					text4[ i ] = rand() % 450 + 50;
				}
				ShowResult( text4, len );
				cntCom = cntExch = 0;
				QuickShow( text4, len, 0, len, re, cntCom, cntExch );
				DrawResult( text4, len, 0 );
				MessageBox( hwnd, "Sort succeed!", "Information", MB_OK );
				closegraph();
				system( "pause" );
				break;

			case 7:
				exit = true;
				break;
		}
		fflush( stdin );
		system( "CLS" );
	}
}

void DrawResult( ElementType *arr, int len, int j )
{
	int  i;
	char s[ 5 ] = { 0 };			   //�����ַ���
	cleardevice();					  //ÿ�λ�֮ǰ�Ȱ�֮ǰ�����Ĳ���
	setbkcolor( WHITE );			  //���ñ���ɫΪ��ɫ
	settextcolor( BLACK );			 //����������ɫΪ��ɫ
	for ( i = 0; i < len; i++ )
	{
		if ( j <= i )//������������jλ��Ϊ���֣�j����߶�����С��������ɫ���ұ߱����󣬻��ɺ�ɫ
		{
			setfillcolor( GREEN );
		}					//�������У�j�ͳ���ÿ�ε�������ѵ�����Ǹ�Ԫ�أ������źõ��Ǹ�
		else
		{
			setfillcolor( RED );
		}
		fillrectangle( 10 + i * 24, 600 - arr[ i ], 10 + ( i + 1 ) * 24, 570 ); //������
		snprintf(s, sizeof(s), "%d", arr[i]);
		outtextxy( 13 + i * 24, 560 - arr[ i ], s );	   //д����
	}
}

void GetDh1( int *dh, int &dhlen, int &scale )
{
	int a, b ,t;		   //��һ������1.5.19.�������� 4^i - 3 * 2 ^ i + 1
	int i;
	b = 2;
	a = 4;
	i = 0;
	t = a - 3 * b + 1;
	while ( t < scale )	//�Ѳ�������д������������
	{
		dh[ i ] = t;
		i++;
		b *= 2;
		a *= 4;
		t = a - b * 3 + 1;
	}
	dhlen = i;  //�������鳤�ȸ���
}


void GetDh2( int *dh, int &dhlen, int &scale )
{
	int a;					 // 1 4 13 40 121 364 1093 3280...h = 1 h = 3 * h + 1
	int i;
	a = 1;
	i = 0;
	while ( a < scale )   //Ȼ��Ѳ���д�벽������
	{
		dh[ i ] = a;
		i++;
		a = a * 3 + 1;		 //a,b�����Գˣ�ʵ��ָ������
	}
	dhlen = i;  //�������鳤�ȸ���
}

void GetDh3( int *dh, int &dhlen, int &scale )
{
	int a;					 // 1.3.7......2 ^ k - 1
	int i;
	a = 1;
	i = 0;
	while ( a < scale )	//�Ѳ�������д������������
	{
		dh[ i ] = a;
		i++;
		a = (1 << ( i + 1 )) - 1;
	}
	dhlen = i;  //�������鳤�ȸ���
}

void GetDh4( int *dh, int &dhlen, int &scale )
{
	int a, b;			 //1.4.13........����3^k - 1) / 2
	int i;
	b = 3;
	a = 1;
	i = 0;
	while ( a < scale )	//�Ѳ�������д������������
	{
		dh[ i ] = a;
		i++;
		b *= 3;
		a = ( b - 1 ) / 2;
	}
	dhlen = i;  //�������鳤�ȸ���
}

