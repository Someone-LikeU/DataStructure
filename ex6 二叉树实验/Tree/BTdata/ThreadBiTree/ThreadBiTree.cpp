// ThreadBiTree.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include <iostream>
using namespace std;

#include "stdlib.h"
#include "..\ThreadBiTree.h"

#include "..\CreateBiTree.h"   //����������


#define _CRTDBG_MAP_ALLOC //�ڴ�й©�����
#include<stdlib.h> 
#include<crtdbg.h> 



int main(int argc, char* argv[])
{
	ThreadBiTree TBT;  //����������
	
	//BiTree BT;
	btNode* T=NULL; 
	btNode* last=NULL;
	int nChoice;
	

	char strLine[100][3]; //�ļ����ݶ��뵽����		
	int  nArrLen=0;  //���鳤��
	int  nR=0;
	int i;

	do
	{
		//�����˵�
		cout<<"******************** �������������Գ��� ********************"<<endl;
		cout<<"*  0--�˳�                    |  8--������������           *"<<endl;
		cout<<"*  1--����                    |  9--����������             *"<<endl;
		cout<<"*  2--�����������������ļ���  |  9--������������           *"<<endl;
		cout<<"*  3--���������������̽�����  | 10--����������             *"<<endl;
		cout<<"*  4--�������������ݹ飩      | 11--������������           *"<<endl;
		cout<<"*  5--���ٶ�����              | 12--          *"<<endl;
		cout<<"*  6--�ж�����      | 13--             *"<<endl;
		cout<<"*  7--����������                |           *"<<endl;
		cout<<"************************************************************"<<endl;
		cout<<"��ѡ�����(0-14)��";
		cin>>nChoice;
		switch(nChoice)
		{
		case 0:  //�˳�����
			system("cls");  //�����Ļ
			cout<<"<-- �����˳� -->"<<endl;  //ѡ���˳�
			break;
		case 1:
			system("cls");  //�����Ļ
			cout<<"<-- ���� -->"<<endl;  //ѡ���˳�
			cout<<"�������У���������BiTree��ֻ������Ա���������Բ�����������"<<endl;  
			cout<<"�����������Ϣ����Ϊ��ĳ�Ա��"<<endl;  			
			break;
		case 2:  //���ļ�����������
			system("cls");  //�����Ļ
			if(TBT.root!=NULL)  //��ֹ�ظ�����������ڴ�й¶
			{
				cout<<"�������Ѿ����ڣ��������´��������������ٴ�����"<<endl;
				break;
			}
			char strFileName[100];
			cout<<"����������������ļ���(i.e. bt3.btr)��";
			cin>>strFileName;  //����̨���������ļ���			
			
			nArrLen=0;  //���鳤��
			nR=0;
			if(!ReadFileToArray(strFileName, strLine, nArrLen))
			{
				cout<<"<--���ļ�����������ʧ�ܡ�-->"<<endl;
				break;  //�ļ��򿪴��󣬷���
			}
			
			if(nArrLen==0)
			{
				printf("<--�����ļ���û�н�����ݡ�-->\n");
				break;
			}   

			//for(i=0; i<nArrLen;i++)
			//	cout<<strLine[i][0]<<"-"<<strLine[i][1]<<"-"<<strLine[i][2]<<endl;

			if(CreateBiTreeFromFile(TBT.root, strLine,nArrLen, nR)) //�ӵ�1�п�ʼ
			{
				TBT.IniTag(TBT.root);  //��ʼ��lTag��rTagΪ0
				cout<<"<--�����������ɹ���-->"<<endl;
			}
			else
				cout<<"<--���ļ�����������ʧ�ܡ�-->"<<endl;	
			break;
		
		
		case 3:  //�������봴��������
			if(TBT.root!=NULL)  //��ֹ�ظ�����������ڴ�й¶
			{
				cout<<"�������Ѿ����ڣ��������´��������������ٴ�����"<<endl;
				break;
			}

			TBT.CreateBtConsole(TBT.root);
			
			TBT.IniTag(TBT.root);  //��ʼ��lTag��rTagΪ0
			cout<<"<--�����������ɹ���-->"<<endl;
			
			break;		
		case 4:  //����������--�ݹ�
			system("cls");  //�����Ļ
			cout<<"���������������"<<endl;
			if(TBT.Empty(TBT.root))
			{
				cout<<"<--������Ϊ������-->"<<endl;
				break;
			}
			cout<<"�������";
			TBT.PreOrder(TBT.root);   //�ݹ��������
			cout<<endl;
			cout<<"�������";
			TBT.InOrder(TBT.root);    //�ݹ��������
			cout<<endl;
			cout<<"�������";
			TBT.PostOrder(TBT.root);  //�ݹ�������
			cout<<endl;
			break;
		case 5:  //���ٶ�����
			system("cls");  //�����Ļ
			if (T!=NULL)
				TBT.Destroy(T);  //���ٶ�����			
			cout<<"<-- �������Ѿ����٣�-->"<<endl;
			break;
		case 6:  //�ж��Ƿ����
			system("cls");  //�����Ļ
			if(TBT.Empty(T))
				cout<<"<-- ������Ϊ������-->"<<endl;			
			else
				cout<<"<-- �ǿն�������-->"<<endl;			
			break;

		case 7:  //����������
			system("cls");  //�����Ļ			
			TBT.PreThreading(TBT.root, last);
			TBT.isTBT=1;  //��Ƕ���������������������
			cout<<"�����������������"<<endl;
			TBT.PreTraverseThr(TBT.root);
			cout<<endl;
			break;

/*	
		case 6:  //��Ԫ��ֵ�����ڵ㣬���ؽڵ�ָ��
			if(IsEmpty(BT))
			{
				cout<<"<--������Ϊ������-->"<<endl;
				break;
			}
			cout<<"������Ҫ�����Ľڵ�Ԫ��ֵ(x)��";
			cin>>x;

			BiTreeSearch(BT, x, P);			
			if(P!=NULL)
				cout<<"Ԫ�� x="<<x<<" �ڵ��ҵ���"<<endl;
			else
				cout<<"Ԫ�� x="<<x<<" �������ϡ�"<<endl;
			P=NULL;  //�ָ���ָ��
			break;

		case 7:  //ȡ��ǰ�ڵ�ĺ��ӽڵ�	
			if(IsEmpty(BT))
			{
				cout<<"<--������Ϊ������-->"<<endl;
				break;
			}			
			cout<<"�����뵱ǰ�ڵ�Ԫ�أ�";
			cin>>x;
			P=NULL;
			nR=GetLeftChild(BT,x,P);	//ȡ���ӽڵ�
			switch(nR)
			{
			case 0:
				cout<<"��ǰ����������ȡ��������"<<endl;
				break;
			case 1:
				cout<<"Ŀ��Ԫ�ز������ϣ�����ȡ������"<<endl;
				break;
			case 2:
				cout<<"Ԫ��x="<<x<<"��Ӧ�����Ӵ��ڣ�ֵΪ��"<<P->data<<endl;
				break;
			case 3:
				cout<<"Ԫ��x="<<x<<"��Ӧ��������������(��)��"<<endl;
				break;
			}			
			
			P=NULL;
			nR=GetRightChild(BT,x,P);	//ȡ�Һ��ӽڵ�
			switch(nR)
			{
			case 0:
				cout<<"��ǰ����������ȡ��������"<<endl;
				break;
			case 1:
				cout<<"Ŀ��Ԫ�ز������ϣ�����ȡ������"<<endl;
				break;
			case 2:
				cout<<"Ԫ��x="<<x<<"��Ӧ���Һ��Ӵ��ڣ�ֵΪ��"<<P->data<<endl;
				break;
			case 3:
				cout<<"Ԫ��x="<<x<<"��Ӧ��������������(��)��"<<endl;
				break;
			}
			break;

		case 8:  //ȡ���ڵ�
			if(IsEmpty(BT))
			{
				cout<<"<--������Ϊ������-->"<<endl;
				break;
			}			
			cout<<"�����뵱ǰ�ڵ�Ԫ�أ�x=";
			cin>>x;
			P=NULL;
			GetParent(BT, x, P);  //����˫�׽ڵ�
			if(P)
				cout<<"x="<<x<<"��˫�׽ڵ�Ϊ��"<<P->data<<endl;
			else
				cout<<"x="<<x<<"��˫�׽ڵ㲻���ڡ�"<<endl;
			break;

        case 9:  //��Ҷ������
			nR=0;
			LeafCount(BT,nR);
			cout<<"Ҷ��������"<<nR<<endl;
			break;
		case 10:  //ȡ�ֵܽڵ�
			if(IsEmpty(BT))
			{
				cout<<"<--������Ϊ������-->"<<endl;
				break;
			}			
			cout<<"�����뵱ǰ�ڵ�Ԫ�أ�x=";
			cin>>x;
			GetLeftSibling(BT,x);   //ȡ���ֵ�
			GetRightSibling(BT,x);  //ȡ���ֵ�
			break;

		case 11:  //��ڵ���
			nR=0;
			num=0;
			GetNodeNumber(BT,nR);  //���÷���
			cout<<"�������ڵ�����"<<nR<<endl;
			GetNodeNumber1(BT);
			cout<<"�������ڵ�����"<<num<<endl;  //ȫ�ֱ������
			break;
		case 12: //�����Ϊ2�Ľڵ�
			nR=0;
			GetNodeNumBiDegree(BT,nR);
			cout<<"��Ϊ2�Ľڵ�����"<<nR<<endl;

			num=0;
			GetNodeNumDegreeOne(BT);
			cout<<"��Ϊ1�Ľ������"<<num<<endl;

			break;

		case 13:  //��Ԫ��x��Ӧ�ڵ��Σ�����ӡ�����Ƚڵ�
			if(IsEmpty(BT))
			{
				cout<<"<--������Ϊ������-->"<<endl;
				break;
			}			
			cout<<"�����뵱ǰ�ڵ�Ԫ�أ�x=";
			cin>>x;
			cout<<"�ڵ� x="<<x<<" �����Ƚڵ㣺";
			GetNodeLevel(BT,  x, nR, 1);
			cout<<endl;
			if(nR>0)				
				cout<<"�ڵ� x="<<x<<" �Ĳ���Ϊ��"<<nR<<endl;
			else
				cout<<"�ڵ� x="<<x<<" �������ϡ�"<<endl;
			break;


*/
		default:
			cout<<"����ѡ���������0��5֮��ѡ��==>"<<endl;
			break;
		}
	
	}while(nChoice!=0);  //ѭ����ʾ�˵���nMenu==0�˳�

	if (TBT.root!=NULL)
	   TBT.Destroy(TBT.root);    //���ٶ�����
	
	_CrtDumpMemoryLeaks();  //debug ģʽ�¼���Ƿ��ڴ�й©	

	return 0;
}
