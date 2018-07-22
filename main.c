#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <locale.h>
#include "Header.h"

void main()
{
	setlocale(LC_ALL, "Russian");

	table x;
	new_tab tab[N];
	price pr[N], y;

	for (int i = 0; i < N; i++)
	{
		tab[i].code[0] = '\0';
		tab[i].name[0] = '\0';
		tab[i].numb = 0;
		tab[i].val = 0;
	}

	for (int i = 0; i < N; i++)
	{
		pr[i].code[0] = '\0';
		pr[i].val = 0;
	}

	FILE *f = fopen("price.txt", "r");
	FILE *fp = fopen("table.txt", "r");

	while (fscanf(f, "%s %d", y.code, &y.val) != EOF && num < N)
		dob(pr, y);
	while (fscanf(fp, "%s %s %d", x.code, x.name, &x.numb) != EOF && num < N)
		dopolnenie(tab, x, pr);
	shell(tab);
	fclose(f);
	fclose(fp);

	f = fopen("new table.txt", "w");
	print(tab, f);
	fclose(f);
}
