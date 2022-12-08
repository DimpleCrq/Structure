#include <stdio.h>
#include <string.h>
#include<iostream>
using namespace std;

#define MAXLENGTH   100007

//You can add or modify any code when needed
typedef struct Record
{
    char number[19];        // ���֤��
    int distance;           // ���о���
    int next;               // ͬһ����ϣֵ���������ָ��
}Record;

Record records[MAXLENGTH];  // ����������
int head[MAXLENGTH];        // ��ϣ���������ͷ�����records���е��±�
int count;                  // records�����Ѿ�����Ľ����Ŀ

int hash(char *number);                     // ��ϣ�����������֤�Ž���ɢ��
int find(char *number);                     // �������֤�Ų��ҷ��м�¼
// �����Ǳ�������Ҫʵ�ֵĺ�����������main()֮�� 
void solution();
void insert(char *number, int distance);    // �����м�¼��Ϣ���뵽����


int main()
{
    solution();
}

void solution()
{
    for(int i=0;i<MAXLENGTH;i++)
        records[i].distance=0;
    memset(head, -1, sizeof head);
    int n, k;
    cin>>n>>k;
    char number[19];
    int distance;
    for (int i = 0; i < n; i++)
    {
        scanf("%s %d", number, &distance);
        if (distance < k) distance = k;
        insert(number, distance);
    }
    int m;
    scanf("%d", &m);
    int pos = -1;
    int a[m];
    for (int i = 0; i < m; i++)
    {
        scanf("%s", number);
        a[i] = find(number);
    }
    for (int i = 0; i < m; i++){
        if (a[i] == -1) printf("No Info\n");
        else printf("%d\n", records[a[i]].distance);
    }

}

/**
 * @brief ��ϣ����
 * @param number ���֤��
 * @return ��ϣֵ 
 */
int hash1(char *number)
{
    long long res = 0;
    for (int i = 0; i < 17; i++) // ���һλ��ǰ17λ��У��ֵ�����Բ����ǣ�����Ӱ��Ψһ��
        res = 10 * res + (number[i] - '0'); // �����ʵ����ֱ�Ӷ�ǰ17λ����������λ�������������handle~�� 
    return res % MAXLENGTH;
}

/**
 * @brief �����м�¼��Ϣ���뵽��ϣ����
 * @param number ���֤��
 * @param distance ���о���
 */
// Hint: Ӧ����Ҫ�������֤�ţ��ַ������ıȽϣ�������string.h�е� int strcmp(const char *str1, const char *str2)���� https://www.runoob.com/cprogramming/c-function-strcmp.html 
void insert(char *number, int distance)
{   
    if(count<MAXLENGTH){
        int k=hash1(number);
        int h=head[k];
        while(records[k].distance>0){
            records[k].next=k+1;
            k++;
        }
        for(int i=0;i<19;i++)
            records[k].number[i]=number[i];
        records[k].distance=distance;
        count++;
    }
}

int find(char *number)
{
    int k=hash1(number);
    int h=head[k];
    int t=0;
    while(k<MAXLENGTH && records[k].distance){
        for(int i=0;i<19;i++){
            if(records[k].number[i]!=number[i])
                t=1;
        }
        if(t==0)
            return k;
        t=0;
        k=records[k].next;
    }
    return -1;
}
/*
5 360
18239047518293471x 360
145623849102394520 359
188329457691023457 500
18284049572934512x 1500
328841092309457613 890
3
17732495891293794x
18239047518293471x
145623849102394520

4 300
523129857234104861 0
533123891283984571 301
758392095736123518 5102
13317512389562138x 3092
3
52312985723410486x
523129857234104861
758392095736123518


6 555
356183920456182911 599
15671855122983457x 8153
520103578391209571 12
66618204927512951x 3937
651239384756661233 1059
522578192857264231 2092
4
520103578391209571
520103578391209571
520103578391209561
651239384756661233
*/
