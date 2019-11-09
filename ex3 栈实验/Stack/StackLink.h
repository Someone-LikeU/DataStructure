#ifndef _StackLink
#define _StackLink

typedef char ElementType;
struct node                         //������
{
    ElementType data;
    node* Next;
};
class LinkStack         //������ջ��
{
private :
    node *Head;          //ͷ���
public:
    void InitiStack();
    void Push(ElementType &x);
    bool Pop();
    bool Top(ElementType &x);
    bool StackEmpty();
    void TravelStack();
    void DestoryStack();        //����ջ
};

void LinkChangeScale(int n, int mode );     //����ת��
bool LinkIsmatch( char *str );                      //�ж�������ʽ�����Ƿ�ƥ��
#endif // _StackLink
