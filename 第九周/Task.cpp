#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define Maxsize 10000
typedef char * ElementType;
struct word
{
	char *str;
	struct word *Next;
};
typedef struct word *Word;
struct hashtable
{
	Word file;
	int tablesize;
	int num;
};
typedef struct hashtable * HashTable;
void Scan(HashTable H);
void Insert(HashTable H, ElementType s);
int Find(HashTable H, ElementType s);
int Hash(ElementType s, int tablesize);
void createhash();
void Scan(HashTable H)
{
	ElementType s, sw;
	s = (ElementType)malloc(5000 * sizeof(char));
	sw = (ElementType)malloc(5000 * sizeof(char));
	gets(s);
	while (strcmp(s, "#") != 0) 
	{
		int i = 0, j = 0;
		int flag = 0;
		while (1)
		{
			if (s[i] >= 'A'&&s[i] <= 'Z' || s[i] >= 'a'&&s[i] <= 'z')
			{
				flag = 1;
				if (s[i] >= 'A'&&s[i] <= 'Z')
				{
					s[i] = s[i] - 'A' + 'a';
				}
				sw[j] = s[i];
				j++;
			}
			else
			{
				if (flag == 1)
				{
					flag = 0;
					sw[j] = '\0';
					if (strlen(sw) > 10) { sw[10] = '\0'; }
					if (strlen(sw) >= 3)
					{
						Insert(H, sw);
					}
					j = 0;
					if (s[i] == '\0') { break; }
				}
				else { 
					if (s[i] == '\0') { sw[j] = '\0'; break; }
				}
			}
			i++;
		}
		gets(s);
	}
}
void Insert(HashTable H, ElementType s)
{
	int r;
	r = Find(H, s);
	int index = Hash(s, H->tablesize);
	if (r == 1);
	else
	{
		Word p, q;
		p = (Word)malloc(sizeof(struct word));
		p->str = (ElementType)malloc(12 * sizeof(char));
		strcpy(p->str, s);
		q = H->file[index].Next;
		p->Next = q;
		H->file[index].Next = p;
		H->num++;
	}
}
int Find(HashTable H, ElementType s)
{
	int i;
	int index = Hash(s, H->tablesize);
	Word p;
	p = H->file[index].Next;
	while (p != NULL)
	{
		if (strcmp(p->str, s) == 0)
		{
			return 1;
		}
		p = p->Next;
	}
	return 0;
}
int Hash(ElementType s, int tablesize)
{
	unsigned int h = 0;
	int i = 0;
	while (s[i] != '\0')
	{
		h = h * 32 + s[i] - 'a';
		i++;
	}
	return h % tablesize;
}
int main()
{
	int N, M;
	scanf("%d\n", &N);
	int i, j;
	HashTable * H; 
	H = (HashTable *)malloc(N * sizeof(HashTable));
	for (i = 0; i < N; i++)
	{
		H[i] = (HashTable)malloc(sizeof(struct hashtable));
		H[i]->file = (Word)malloc(Maxsize * sizeof(struct word));
		H[i]->tablesize = 101;
		H[i]->num = 0;
		for (j = 0; j < Maxsize; j++)
		{
			(H[i]->file)[j].str = (char *)malloc(11 * sizeof(char));
			(H[i]->file)[j].str[0] = '\0';
			(H[i]->file)[j].Next = NULL;
		}
	}
	for (i = 0; i < N; i++)
	{
		Scan(H[i]);
	}
	int f1, f2;
	int ret;
	scanf("%d\n", &M);
	Word w;
	int sumsame = 0;
	int t;
	for (i = 0; i < M; i++)
	{
		sumsame = 0;
		scanf("%d %d", &f1, &f2);
		if (H[f1 - 1]->num > H[f2 - 1]->num) { t = f1; f1 = f2; f2 = t; }
		for (j = 0; j < H[f1 - 1]->tablesize; j++)
		{
			w = H[f1 - 1]->file[j].Next;
			while (w != NULL)
			{
				ret = Find(H[f2 - 1], w->str);
				if (ret == 1) { sumsame++; }
				w = w->Next;
			}
		}
		printf("%.1f%%\n", 100.0*sumsame / (double)(H[f1 - 1]->num + H[f2 - 1]->num - sumsame));
	}
	return 0;
}
