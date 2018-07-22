#pragma once
#include <string.h>

const int N = 100;
int num = 0;

struct table
{
	char code[9];
	char name[20];
	int numb;
};

struct price
{
	char code[9];
	int val;
};

struct new_tab
{
	char code[9];
	char name[20];
	int numb;
	int val;
};

void dob(price *t, price x)		//прайс таблица
{
	strcpy(t[num].code, x.code);
	t[num].val = x.val;
	num++;
}

int find(price *t, table x)
{
	int i = 0;
	while (t[i].code != 0 && strcmp(t[i].code, x.code) < 0)
		i++;
	if (strcmp(t[i].code, x.code) == 0)
		return t[i].val;
	else
		return 0;
}

void  shell(new_tab *t)
{
	new_tab x;
	int l = 0, h[N], i = 0, j = 0, m, k;
	h[l] = 1;
	while (h[l] <= N / 9)
	{
		l++;
		h[l] = 3 * h[l - 1] + 1;
	}

	for (m = l; m >= 0; m--)
		for (k = 0; k < h[m]; k++)
		{
			i = h[m] + k;
			while (i <= num - 1)
			{
				strcpy(x.code, t[i].code);
				strcpy(x.name, t[i].name);
				x.numb = t[i].numb;
				x.val = t[i].val;
				j = i - h[m];
				
				while (j >= 0 && x.numb > t[j].numb)
				{
					t[j + h[m]] = t[j];
					j = j - h[m];
				}
				t[j + h[m]] = x;
				i = i + h[m];
			}
		}
}

void dopolnenie(new_tab *T, table x, price *R)
{
	int k = 0;
	strcpy(T[num].code, x.code);
	strcpy(T[num].name, x.name);
	T[num].numb = x.numb;
	k = find(R, x);
	if (k != 0)
		T[num].val = k;
	else
		T[num].val = 0;
	num++;
}

void print(new_tab *p, FILE *out)
{
	fprintf(out, "Шифр\t\tНаименование\tКоличество\tЦена за штуку\n");
	for (int i = 0; i < N; i++)
		if (p[i].code[0] != '\0')
		{
			fprintf(out, "%s\t", p[i].code);
			fprintf(out, " %s\t\t", p[i].name);
			fprintf(out, " %d\t\t", p[i].numb);
			fprintf(out, " %d\n", p[i].val);
			num++;
		}
}