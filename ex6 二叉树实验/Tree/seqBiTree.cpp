#include "seqBiTree.h"
#include <iostream>
#include <cstdlib>
#include <cstdbool>
#include <cstdio>
#include <cstring>
using namespace std;

//*****************************************************
//�������ܣ���ʼ��˳�������
//�����������
//�����������
//����ֵ��	˳�����������ָ��
//*****************************************************
void InitialTree( SeqBiTree &seqTree )
{
	int i;
	for ( i = 0; i < MAXN; i++ )  //Ĭ�ϳ�ʼ��ȫΪ�ո�
	{
		seqTree.data[ i ] = ' ';
	}
	seqTree.len = 0;//˳��洢����������Ϊ0
}

//*****************************************************
//�������ܣ�ȥ�������ļ���ĳ��ǰ��Ŀո�
//����������ַ�����
//����������������
//����ֵ��	��
//*****************************************************
void removeSpace( char *str )
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
//�������ܣ�����̨����ʽ����˳�������
//�������������ָ�룬���鳤��
//����������������
//����ֵ��	0 represents success, 1 represents failure
//*****************************************************
int CreateSeqTreeInteract( SeqBiTree &seqTree )
{
	if ( seqTree.data[ 0 ] != ' ' )	   //�ȼ���ʼ��������û��ִ��
	{
		cout << "δ��ʼ��������ִ�г�ʼ��������\n";
		system( "pause" );
		return 1;
	}
	elementType data;
	int i = 1;
	cout << "�밴���˳��������ȫ�����������Ϣ,�н��������ֵ���޽������*\n";
	cout << "����#����.\n";
	cout << "��� " << i << " :";
	cin >> data;
	while ( data != '#' )
	{
		seqTree.data[ i ] = data;
		seqTree.len++;
		i++;
		getchar();
		cout << "��� " << i << " :";
		cin >> data;
	}
	cout << "�����ɹ�����ִ����һ��������\n";
	return 0;
}

//*****************************************************
//�������ܣ�������ʽ�����������ĸ�������
//������������������ã���ά�����Ϣ���飬������cur,
//����������ý��
//����ֵ��	��
//*****************************************************
void HelpCreate( SeqBiTree &ST, char data[ MAXN ][ 4 ], int &cur, int node ,int len )
{
	if ( (cur >= len) || (len == 0) ) //���ݴ�����ϻ�û������
	{
		return;
	}
	ST.data[node] = data[ cur ][ 0 ];
	int precur = cur;
	if ( data[ precur ][ 1 ] == '1' ) //��������,�ݹ鴴����������data������Ϣ�ǰ�����������е�
	{
		cur++;									  //����ÿ��ֻ��cur+1������
		HelpCreate( ST, data, cur, node * 2, len );
	}
	else	//û�����������ͰѶ�Ӧ����λ�õ�ֵ��Ϊ*
	{
		ST.data[ node * 2 ] = '*';
	}

	if ( data[ precur ][ 2 ] == '2' ) //��������
	{
		cur++;
		HelpCreate( ST, data, cur, node * 2 + 1 ,len );	 //�ݹ鴴��������
	}
	else
	{
		ST.data[ node * 2 + 1 ] = '*';
	}
}

//*****************************************************
//�������ܣ��ļ���ʽ����������
//������������������ã���ά�����Ϣ���飬������cur,
//����������ý��
//����ֵ��	 ��
//*****************************************************
void CreateSeqTreeUsingFile( SeqBiTree &seqTree )
{
	InitialTree( seqTree );
	char TreeData[ MAXN ][ 4 ];  //������ݶ�ά����
	int datalen, i ,j;
	GetData( TreeData, datalen );
	i = 0;
	j = 1;
	Assist( seqTree, TreeData, datalen, i, j);
}

//*****************************************************
//�������ܣ����ļ���ȡ�������
//�����������ά�ַ����飬��¼���鳤��len
//����������ö�ά����
//����ֵ��	��
//*****************************************************
void GetData( char TreeData[ MAXN ][ 4 ], int &datalen )
{
	//����Ĳ����ȴ��ļ��������ݵ���Žڵ���Ϣ�Ķ�ά������
	char name[ 10 ];   //�ļ���
	char path[ 20 ] = "BTdata\\"; //�����ļ�·��
	char Tdata[ 10 ];
	datalen = 0;
	char strChoose[ 1000 ];//ÿ�δ��ļ������һ��
	int i = 0, j;
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
			removeSpace( strChoose );
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
					TreeData[ datalen ][ j ] = Tdata[ i ];
					j++;
				}
				i++;
			}
			datalen++;
		}
	}
	fclose( fp );
}

//*****************************************************
//�������ܣ�������������
//���������˳�������ã����������飬������Ч���ȣ������±�cur��˳�����±�treeindex
//����������ö�ά����
//����ֵ��	��
//*****************************************************
void Assist( SeqBiTree &seqTree, char TreeData[ MAXN ][ 4 ], int &datalen, int &cur, int treeIndex )
{
	if ( ( cur > datalen ) || ( datalen == 0 ) ) //���ݴ�����ϻ�û������
	{
		return;
	}
	seqTree.data[ treeIndex ] = TreeData[ cur ][ 0 ];		//д���ڵ�����
	seqTree.len = treeIndex + 1;			//����˳��������
	int precur = cur;			//���浱ǰ��������λ��
	if ( TreeData[ precur ][ 1 ] == '1' )		//�����������ݹ鴦��������
	{
		cur++;
		//cout << TreeData[ cur ][ 0 ] << "��������\n";
		Assist( seqTree, TreeData, datalen, cur, treeIndex * 2 );
	}

	if ( TreeData[ precur ][ 2 ] == '1' )			//�����������ݹ鴦��
	{
		cur++;
		//cout << TreeData[ cur ][ 0 ] << "  ��right����\n";
		Assist( seqTree, TreeData, datalen, cur, treeIndex * 2 + 1 );
	}
}

//*****************************************************
//�������ܣ��������
//���������һ��seqbitree������ location i
//���������none
//����ֵ��	none
//*****************************************************
void PreTravel( SeqBiTree &seqTree, int i )
{
	if (  seqTree.data[i] != ' ' && i <= seqTree.len )
	{
		if (seqTree.data[i] != '*')
			cout << seqTree.data[ i ] << " ";
		PreTravel( seqTree, i * 2 ); //�������������
		PreTravel( seqTree, i * 2 + 1 );//right sub tree
	}
}

//*****************************************************
//�������ܣ��������˳�������
//���������һ��seqbitree������ location i
//���������none
//����ֵ��	none
//*****************************************************
void MidTravel( SeqBiTree &seqTree, int i )
{
	if (  seqTree.data[i] != ' ' && i <= seqTree.len)
	{
		MidTravel( seqTree, i * 2 );//left sub tree
		if (seqTree.data[i] != '*')
			cout << seqTree.data[ i ] << " ";
		MidTravel( seqTree, i * 2 + 1 );//right sub tree
	}
}

//*****************************************************
//�������ܣ��������˳�������
//���������һ��seqbitree������ location i
//���������none
//����ֵ��	none
//*****************************************************
void LastTravel( SeqBiTree &seqTree, int i )
{
	if ( seqTree.data[i] != ' '  && i <= seqTree.len)
	{
		LastTravel( seqTree, i * 2 );
		LastTravel( seqTree, i * 2 + 1 );
		if (seqTree.data[i] != '*')
			cout << seqTree.data[ i ] << " ";
	}
}
//*****************************************************
//�������ܣ���α���˳�������
//���������һ��seqbitree������ location i
//���������none
//����ֵ��	none
//*****************************************************
void LevelTravel( SeqBiTree &seqTree )
{
	int i;
	for ( i = 1;  seqTree.data[ i ] != ' '  && i <= seqTree.len ; i++ )
	{
		if ( seqTree.data[ i ] != '*' )
			cout << seqTree.data[ i ] << " ";
	}
}
