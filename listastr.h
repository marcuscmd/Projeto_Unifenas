#Projeto_Unifenas
#include <string.h>

#define tam 8
typedef struct
{
	char nome[30];
	int nr;
	
} elem;

typedef struct
{
	elem m[tam];
	int fim;	
} Lista;

void linit(Lista *l)
{
	l->fim = 0;
}

void lins(Lista *l, elem x)
{
	if (l->fim<tam)
	{
		int i = l->fim;

		while (i>0 && strcmp(x.nome,l->m[i-1].nome)<0)
		{
			strcpy(l->m[i].nome,l->m[i-1].nome);
			l->m[i].nr = l->m[i-1].nr;
			i--;
		}
		strcpy(l->m[i].nome,x.nome);
		l->m[i].nr = x.nr;
		l->fim++;
	}
}
