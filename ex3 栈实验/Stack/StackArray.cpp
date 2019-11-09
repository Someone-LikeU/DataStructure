#include "StackArray.h"
#include <iostream>
#include <cstdio>
#include <queue>
#include <stack>
#include <map>
using namespace std;
//********************************
//�������ܣ���ʼ��˳��ջ
//�����������
//�����������
//����ֵ�� ��
//********************************
void seqStack::InitiStack()
{
    seqStack::top = -1;
}

//********************************
//�������ܣ��ж�ջ�Ƿ�Ϊ��
//�����������
//�����������
//����ֵ�� ����
//********************************
bool seqStack::IsEmpty()
{
    return seqStack::top == -1;
}

//********************************
//�������ܣ��ж�ջ�Ƿ���
//�����������
//�����������
//����ֵ�� ����
//********************************
bool seqStack::IsFull()
{
    return seqStack::top == MAXN - 1;
}

//********************************
//�������ܣ�ȡջ��Ԫ��
//�����������
//�����������
//����ֵ��  true or false
//********************************
bool seqStack::Top(ElementType &x)
{
    if (seqStack::IsEmpty())
    {
        return false;
    }
    x = seqStack::data[seqStack::top];
    return true;
}

//********************************
//�������ܣ���ջ
//�����������
//�����������
//����ֵ��  true or false
//********************************
bool seqStack::Pop()
{
    if(seqStack::IsEmpty())
    {
        return false;
    }
    seqStack::top--;
    return true;
}

//********************************
//�������ܣ���ջ
//�����������
//�����������
//����ֵ��  true or false
//********************************
bool seqStack::Push( ElementType &x )
{
    if(seqStack::IsFull())
    {
        return false;
    }
    seqStack::top++;
    seqStack::data[seqStack::top] = x;
    return true;
}

//********************************
//�������ܣ�����ջ
//�����������
//�����������
//����ֵ��  ��
//********************************
void seqStack::travel()
{
    int t = seqStack::top;
    while (t != -1)
    {
        cout << seqStack::data[t--] << " ";
    }
}

//*********************************************************
//�������ܣ���һ����ת��Ϊ��Ӧn����
//�����������ת����n������mode
//�����������
//����ֵ�� 	  wu
//*********************************************************
void ChangeScale( int n, int mode )
{
    seqStack S;         //ջ����
    S.InitiStack();     //��ʼ����
    int m ,t = n;         //����
    char s;                 //���ʱҪ�õ����ַ�
    char characters[16] = {'0', '1', '2', '3', '4', '5', '6', '7', '8','9', 'A', 'B', 'C', 'D', 'E', 'F'};     //16���Ƶ����Ҫ�õ�
    while (n != 0)
    {
        m = n % mode;
        S.Push(characters[m]);//��ջ��Ӧ�ַ�
        n /= mode;
    }
    printf("\n%d��%d���Ʊ�ʾΪ: ",t, mode);
    while( !S.IsEmpty() )
    {
        S.Top(s);
        printf("%c",s);
        S.Pop();
    }
    cout << endl;
}

//*********************************************************
//�������ܣ��ж�һ�����ʽ�е������Ƿ�ƥ��
//������������ʽ�ַ���
//�����������
//����ֵ�� 	  true or false
//*********************************************************
bool IsMatch( char *str )
{
    bool ismatch = true;    //�ȼ��� ��ƥ��
    int i = 0, j = -1;        //i�����������ʽ�ַ�����j����ѡ����������
    seqStack S;     //˳��ջ����
    S.InitiStack(); //�ȳ�ʼ��
    ElementType t;      //ջ��Ԫ�ظ���t
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
                if(S.IsEmpty())     //���ջ��Ϊ�գ���ǰ��û����������ջ,��ƥ��
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
    if (!S.IsEmpty())    //ִ��������ջ��Ϊ��˵����һ�����Ų�ƥ��
    {
         ismatch = false;
    }
    return ismatch;     //��󷵻�ismatch
}

//*********************************************************
//�������ܣ��ж�һ����ս�����Ƿ�Ϸ�
//���������һ���������飬��ʾ��ջ����
//�����������
//����ֵ�� 	  true or false
//*********************************************************
bool IsSeqValid( int *arr, int len )
{
    bool isValid = true;    //��Ĭ�ϺϷ�
    int i = 0, j;    //i���Ʊ������У�j
    while( i < len && isValid )  //true ����ûԽ��
    {
        j = i + 1;  //��i�ĺ�һ����ʼ���ұ�a[i]С��
        while ( j < len && arr[j] < arr[i] )    //��Ҫȷ��j����Խ��
        {
            j++;
        }
        for ( i = i + 1 ; j < len && i < j && isValid ; i++ )  //��i+1λ�õ�j - 1���ж��Ƿ��ǽ���
        {
            if( arr[i + 1] > arr[i] )
            {
                isValid = false;        //�����ģ�������
            }
        }
        i = j;      //��i = j���ִ�jλ�ÿ�ʼ�ж�
    }
    return isValid;     //���return isValid ����
}

//*********************************************************
//�������ܣ���һ��ջ�����кϷ��������
//�������������˳��ջ������
//�����������
//����ֵ�� 	  ��
//*********************************************************
void AllValidSeq( queue<int> &Q1 ,stack<int> &S1,  queue<int> &Q2)
{                                   //���㷨�ο���CSDN����
    int t;
    if( Q1.empty() )    //����������Ϊ��
    {
        if( S1.empty())  //����м�ջΪ��
        {
            while(!Q2.empty())      //���������������Ԫ��
            {
                cout << Q2.front() << " ";
                Q2.pop();
            }
            printf("\n");
        }
        else        //�м�ջ���գ��Ͱ�ջ����������push�����������
        {
            t = S1.top();
            S1.pop();
            Q2.push(t);
            AllValidSeq(Q1, S1, Q2);    //�ٵݹ����
        }
    }
    else            //������в�Ϊ��
    {
        if ( !S1.empty() )      //�м�ջ����
        {
            queue<int> newQ;        //�����µĶ��к�ջ
            queue<int> newQ2;
            stack<int> newS;
            newQ = Q1;
            newQ2 = Q2;
            newS = S1;
            t = newS.top(); //����ջ��ջ
            newS.pop();
            newQ2.push(t);  //ջ��Ԫ��push�����������
            AllValidSeq(newQ, newS, newQ2 );    //�ݹ���ñ�����
        }
        t = Q1.front();         //�������ȡ��ͷԪ��
        S1.push(t);               //���м�ջ
        Q1.pop();
        AllValidSeq(Q1, S1, Q2);    //�ٵ��ñ�����
    }
}

//*********************************************************
//�������ܣ�������ʽ��ֵ
//����������ַ�����ʽ�ı��ʽ
//�����������
//����ֵ�� 	  ������
//*********************************************************
double CalculateExpression(char *str) //ע�����д���ǰ�����޸�ͷ�ļ���elementtpe�Ķ���
{
    //���þ����ŷ��ŵ����ȼ��Ƚ�
                                         //+    -     *     /    (     )    #
    char Priority[7][7] = {{'>', '>', '<', '<', '<', '>', '>'},
                                           {'>', '>', '<', '<', '<', '>', '>'},
                                           {'>', '>', '>', '>', '<', '>', '>'},
                                           {'>', '>', '>', '>', '<', '>', '>'},
                                           {'<', '<', '<', '<', '<', '=', ' '},
                                           {'>', '>', '>', '>', ' ', '>', '>'},
                                           {'<', '<', '<', '<', '<', ' ', '='}
                                            };
    //����map����һ���ֵ䣬���������ȼ��ıȽ�
    map<char, int> chars;
    chars.insert(pair<char, int>('+', 0));  //ÿ�����ŷֱ��Ӧ������
    chars.insert(pair<char, int>('-',1));
    chars.insert(pair<char, int>('*',2));
    chars.insert(pair<char, int>('/',3));
    chars.insert(pair<char, int>('(',4));
    chars.insert(pair<char, int>(')',5));
    chars.insert(pair<char, int>('#',6));
    int row, col, i;
    double t1, t2, T, num;       //����������������������Ȼֻ���ֵ�Ļ����ÿ�
    char TopS, CurrentS;       //TopS��ʾ����ջջ���������CurrentS��ʾ��ɨ�赽�������
    i = num = 0;                //numΪɨ�赽�Ĳ�������i��������
    seqStack OpS;         //˳��ջ��ŷ���
    stack<double> numS;    //����ģ��
    OpS.InitiStack();     //��ʼ��
    TopS = '#';
    OpS.Push(TopS);    //�Ƚ������ѹ�����ջ
    row = chars[TopS];
    while(str[i] != '#' || TopS != '#')
    {
        if(str[i] >= '0' && str[i] <= '9')  //ɨ�赽������
        {
            while(str[i] >= '0' && str[i] <= '9')
            {
                num = num * 10.0 + (str[i] - '0') * 1.0;
                cout << "num is " << num << endl;
                i++;
            }
            numS.push(num); //�������������ջ
            num = 0.0;    //Ȼ������numΪ0 ,����ɨ����������
        }
        else        //���ǲ�����
        {
            CurrentS = str[i];  //��ǰɨ�赽�Ĳ�����
            col = chars[CurrentS];
            if ( '<' == Priority[row][col] )    //ջ����������ȼ��ȵ�ǰɨ��������С
            {
                OpS.Push(CurrentS);     //�������㣬push������ջ
                OpS.Top(TopS);              //Ȼ�����TopS������Ӧ���ȼ�������
                row = chars[TopS];
            }
            else if ('>' == Priority[row][col] )//����
            {
                OpS.Top(TopS);  //��ȡ����ȡ����������
                row = chars[TopS];
                OpS.Pop();      //�Ȱ���������pop��
                t2 = numS.top();    //�������t2
                numS.pop();
                t1 = numS.top();    //�Ƚ�����t1�������Ļ������Ų������
                numS.pop();
                switch(TopS)        //������������������󽫽��ѹջ
                {
                    case '+':
                        T = t1 + t2;
                        numS.push(T);
                        cout << "push " << T << " into stack\n";
                        break;

                    case '-':
                        T = t1 - t2;
                        numS.push(T);
                        cout << "push " << T << " into stack\n";
                        break;

                    case '*':
                        T = t1 * t2;
                        numS.push(T);
                        cout << "push " << T << " into stack\n";
                        break;

                    case '/':
                        T = t1 / t2;
                        numS.push(T);
                        cout << "push " << T << " into stack\n";
                        break;

                    default :
                        break;
                }
                if(!OpS.IsEmpty())  //���������������ջ���գ���Ҫ�����õ�ǰ��
                {                                       //ջ�������������ɨ���������Ƚ�
                    OpS.Top(TopS);
                    row = chars[TopS];
                    continue;
                }
            }
            else if( '=' == Priority[row][col])//���ȼ���ȣ�������ƥ��ʱ���Ͱ�������pop��
            {
                OpS.Pop();
                OpS.Top(TopS);
                row = chars[TopS];
            }
            i++;
        }
    }
    T = numS.top();   //���ջ��Ԫ�ؾ��Ǵ�
    return T;
}
