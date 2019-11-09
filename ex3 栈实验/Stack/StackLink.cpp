#include "StackLink.h"
#include <iostream>
#include <cstdio>
using namespace std;

//*********************************************************
//�������ܣ���ʼ����ջ
//�����������
//�����������
//����ֵ�� ��
//*********************************************************
void LinkStack::InitiStack()
{
    LinkStack::Head = new node; //�ȷ���ͷ���
    LinkStack::Head->Next = NULL;//Ȼ������ָ��
}

//*********************************************************
//�������ܣ���ջ
//���������elementype������x
//�����������
//����ֵ�� ��
//*********************************************************
void LinkStack::Push(ElementType &x)
{
    node *s = new node;
    if ( NULL == s )  //����ʧ�ܣ����ص���������
    {
        cout << "memory allocate failed. please try again.\n" ;
        return;
    }
    s->data = x;
    s->Next = LinkStack::Head->Next;//ͷ�巨������
    LinkStack::Head->Next = s;
}

//*********************************************************
//�������ܣ�ȡջ��Ԫ��
//���������elementype������x
//�����������
//����ֵ�� true or false
//*********************************************************
bool LinkStack::Top(ElementType &x)
{
    if(LinkStack::StackEmpty())     //ջ�գ�����false
        return false;
    x = LinkStack::Head->Next->data;        //��x��ֵ�����سɹ�
    return true;
}

//*********************************************************
//�������ܣ���ջ��
//�����������
//�����������
//����ֵ�� true or false
//*********************************************************
bool LinkStack::Pop()
{
    if (LinkStack::StackEmpty())        //վΪ�գ�����false
        return false;
    node *t = LinkStack::Head->Next; //��ɾ���Ľ�㣬��һ����ʱָ��ָ����
    LinkStack::Head->Next = t->Next; //����ͷ����ָ��
    delete t;                                              //�ͷ��ڴ�
    t = NULL;
    return true;
}

//*********************************************************
//�������ܣ� �ж�ջ�Ƿ�Ϊ��
//�����������
//�����������
//����ֵ�� true or false
//*********************************************************
bool LinkStack::StackEmpty()
{
    return LinkStack::Head->Next == NULL;
}

//*********************************************************
//�������ܣ���ջ�׿�ʼ����ջԪ��
//�����������
//�����������
//����ֵ��     ��
//*********************************************************
void LinkStack::TravelStack()
{
    node *t = LinkStack::Head->Next;
    while (t != NULL)
    {
        cout << t->data;
        t = t->Next;
    }
    cout << endl;
}
//*********************************************************
//�������ܣ�������ջ
//�����������
//�����������
//����ֵ��    ��
//*********************************************************
void LinkStack::DestoryStack()
{
    bool Notdone;
    do
    {
        Notdone = LinkStack::Pop(); //��Pop�����ķ���ֵ���ж�ջ��
    }while(Notdone == true);
    delete LinkStack::Head;     //���ͷ�ͷ���
    LinkStack::Head = NULL;
}

//*********************************************************
//�������ܣ� ������ջ������ת��
//��������� ʮ���ƴ�ת����n��Ŀ�����mode
//�����������
//����ֵ�� true or false
//*********************************************************
void LinkChangeScale(int n, int mode )
{
    LinkStack S;        //����һ����ջ����
    S.InitiStack();     //Ȼ���ʼ��
    int m,t = n;
    char characters[16] = {'0', '1', '2', '3', '4', '5', '6', '7', '8','9', 'A', 'B', 'C', 'D', 'E', 'F'};//16���Ƶĸ��ַ�
    while (n != 0)                  //�̳���
    {
        m = n % mode;
        S.Push(characters[m]);//��ջ��Ӧ�ַ�
        n /= mode;
    }
    printf("\n%d��%d���Ʊ�ʾΪ: ",t, mode);
    S.TravelStack();
    S.DestoryStack();
    cout << endl;
}

//*********************************************************
//�������ܣ��ж�һ�����ʽ�е������Ƿ�ƥ��
//������������ʽ�ַ���
//�����������
//����ֵ�� 	  true or false
//*********************************************************
bool LinkIsmatch( char *str )       //done at 11.20  20.55
{
    bool ismatch = true;    //�ȼ��� ��ƥ��
    int i = 0, j = -1;        //i�����������ʽ�ַ�����j����ѡ����������
    LinkStack S;            //һ����ջ����
    S.InitiStack();         //�ȳ�ʼ��
    ElementType t;      //���ջ��Ԫ��
    char brac[3] = {'(', '[', '{'};
    while (str[i] != '\0' && ismatch)      //���ʽδ���������ismatchΪ��
    {
        if(str[i] == '(' || str[i] == '[' || str[i] == '{')         //����������������ţ�����ջ
        {
            S.Push(str[i]);
        }
        else        //���������ţ����������������
        {
            switch (str[i])         //������ж�
            {
            case ')':                   //�����������ţ�Ȼ���j��ֵ��������j������
                j = 0;
                break;

            case ']':
                j = 1;
                break;

            case '}':
                j = 2;
                 break;

            default :           //������������֣��ͼ����������
                break;
            }
            //switch���˺�j
            if ( j < 0 || j > 2 )   //������������ţ��������жϲ�������������
            {
                i++;
                continue;
            }
            else        //��������֮һ���ж��Ƿ�ƥ��
            {
                if(S.StackEmpty())     //���ջ��Ϊ�գ���ǰ��û����������ջ,��ƥ��
                    ismatch = false;
                else        //ջ��Ϊ�գ���ȡջ��Ԫ��
                {
                    S.Top(t);
                    if (t != brac[j] )  //��ƥ����Ӧ������
                        ismatch = false;        //�Ͱ�ismatch��Ϊfalse
                    else        //ջ������ƥ��
                        S.Pop();  //�Ͱ������Ÿ�����ջ�������жϺ���
                }
            }
        }
        i++;
    }                               //ǰ��������ƥ��Ļ����ᵯջ��
    if (!S.StackEmpty())    //ִ��������ջ��Ϊ��˵����һ�����Ų�ƥ��
    {
         ismatch = false;
    }
    return ismatch;     //��󷵻�ismatch
}
