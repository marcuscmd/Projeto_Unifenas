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


//int lconta(Lista *l, elem x)
//{
//	int cont = 0;
//	int i = 0;
//	while (i < l->fim && strcmp(x,l->m[i])>0)
//		i++;
//	while (i < l->fim && !strcmp(x,l->m[i]))
//	{
//		cont++;
//		i++;
//	}	
//	return cont;
//}
//
//void lmostra_intervalo (Lista *l, elem xi, elem xf)
//{
//    int i = 0;
//    printf ("[");
//    while (i<l->fim && strcmp(xi,l->m[i])>0)
//        i++;
//    while (i < l->fim && strcmp(xf,l->m[i])>=0)
//    {
//        printf("%s",l->m[i]);
//        if (strcmp(xf,l->m[i])>0)
//            printf(",");
//        i++;
//    }
//    printf ("]");
//}
//
//char lrem (Lista *l, elem x)
//{
//	int i = 0;
//	
//	while (i < l->fim && strcmp(x,l->m[i])>0)
//		i++;
//	if (i < l->fim && !strcmp(x,l->m[i]))
//	{
//		while (i < l->fim-1)
//		{
//			strcpy(l->m[i],l->m[i+1]);
//			i++;
//		}
//		l->fim--;
//		return 1;
//	}
//	else
//		return 0;	
//}
