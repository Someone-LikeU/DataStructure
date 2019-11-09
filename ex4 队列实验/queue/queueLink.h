#ifndef _LinkQueue
#define _LinkQueue
#define LMAXLEN 100
typedef int ElementType;
typedef struct  LNode                        //������Ľ�㶨��һ������˼
{
    ElementType data;           //����Ԫ��
    struct LNode *Next;          //��һ�����
}node;
typedef struct                       //��Front��Rear��װ����ʾһ�����нṹ
{
    node *Front;                    //��ͷ
    node *Rear;                     //��β
    int Length;                        //���г���
}LinkQueue;

void InitLinkQueue( LinkQueue &Q );
bool IsLinkQueueEmpty( LinkQueue &Q );
bool IsLinkQueueFull( LinkQueue &Q );
int GetLinkQFront( LinkQueue &Q, ElementType &x );
int EnLinkQueue( LinkQueue &Q, ElementType &x );
int DeLinkQueue(LinkQueue &Q );
int TravelLinkQueue( LinkQueue &Q );
int CountLinkQ( LinkQueue &Q );
#endif // _LinkQueue
