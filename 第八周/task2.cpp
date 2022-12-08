#include <stdio.h>
#include <string.h>
#include<iostream>
using namespace std;

#define MAXLENGTH   100007

//You can add or modify any code when needed
typedef struct Record
{
    char number[19];        // 身份证号
    int distance;           // 飞行距离
    int next;               // 同一个哈希值的链表里的指针
}Record;

Record records[MAXLENGTH];  // 当作链表用
int head[MAXLENGTH];        // 哈希表，存放链表头结点在records表中的下标
int count;                  // records表中已经插入的结点数目

int hash(char *number);                     // 哈希函数，对身份证号进行散列
int find(char *number);                     // 根据身份证号查找飞行记录
// 以下是本次任务要实现的函数，代码在main()之后 
void solution();
void insert(char *number, int distance);    // 将飞行记录信息插入到表中


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
 * @brief 哈希函数
 * @param number 身份证号
 * @return 哈希值 
 */
int hash1(char *number)
{
    long long res = 0;
    for (int i = 0; i < 17; i++) // 最后一位是前17位的校验值，可以不考虑，并不影响唯一性
        res = 10 * res + (number[i] - '0'); // 这里的实现是直接对前17位数都做了移位（计算机还可以handle~） 
    return res % MAXLENGTH;
}

/**
 * @brief 将飞行记录信息插入到哈希表中
 * @param number 身份证号
 * @param distance 飞行距离
 */
// Hint: 应该需要进行身份证号（字符串）的比较，可以用string.h中的 int strcmp(const char *str1, const char *str2)函数 https://www.runoob.com/cprogramming/c-function-strcmp.html 
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
