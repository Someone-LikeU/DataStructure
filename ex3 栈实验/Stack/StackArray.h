#ifndef _StackArray
#define _StackArray
#define MAXN 100            //ջ�������
#include <queue>
#include <stack>
using namespace std;
typedef char ElementType;
class seqStack
{
private:
    ElementType data[MAXN];
    int top;
public:
    void InitiStack();      //��ʼ��
    bool IsEmpty();         //�ж��Ƿ�ջ��
    bool IsFull();          //ջ��
    bool Top( ElementType &x );   //ȡջ��Ԫ��
    bool Pop();             //��ջ
    bool  Push( ElementType &x ); //��ջ
    void travel();
};
void ChangeScale( int n, int mode );      //ת������
bool IsMatch( char *s );                        //�жϱ��ʽ�������Ƿ�Ϸ�
bool IsSeqValid( int *arr, int len );   //�ж�һ����ջ�����Ƿ�Ϸ�
void AllValidSeq(queue<int> &Q1  ,stack<int> &S1,  queue<int> &Q2);        //ջ�ĺϷ��������
double CalculateExpression(char *str); //������ʽ
#endif // _StackArrary
