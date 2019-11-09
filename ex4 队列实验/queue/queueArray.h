#ifndef _seqQueue
#define _seqQueue
#define MAXLEN 100
typedef int ElementType;
typedef struct sQueue  //˳���Ķ���
{
    ElementType data[MAXLEN];
    int Front;
    int Rear;
}seqQueue;
typedef seqQueue* Queue;

void InitialQueue(  seqQueue &Q );   //��ʼ������
bool IsQueueEmpty( seqQueue &Q );   //�ж϶ӿ�
bool IsQueueFull( seqQueue &Q );    //�ж϶���
int GetQueueFront( seqQueue &Q,ElementType &x );    //ȡ��ͷ
int EnQueue( Queue Q, ElementType &x ); //���
int DeQueue( Queue Q ); //����
int TravelQueue( seqQueue &Q ); //��������Ԫ��
int CoutElement( seqQueue &Q ); //��������Ԫ��
#endif // _seqQueue

