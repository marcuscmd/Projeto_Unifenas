# Projeto_Unifenas
#include <iostream>
#include <string.h>
#include <stdio.h>
#include "listastr.h"

struct reg
{
	char nome[30];
	char tel[20];
	char email[30];
	char cpf[12];
	char camp[20];
	char nome2[30];
	char status[15];
	char genero;
};

int tamanho(FILE *);
void cadastrar(FILE *);
void consultar(FILE *);
void gerararqtxt(FILE *);
void cancelar(FILE *);
void relatorioord(FILE *);

void cadastrar(FILE *arq)
{ 
	reg contato; 
	char confirma, rconfirma, iconfirma;
	int i,Tam;
	
	strcpy(contato.status,"MATRICULADO");
	strcpy(contato.camp,"***************");
	fflush(stdin);
	printf("Matriculando novo Aluno \n");
	printf("\nAlunos Registrados: %d\n", tamanho(arq) +1);
	printf("Nome do Aluno: ");
	gets(contato.nome);
	Tam = strlen(contato.nome);
	for (i = 0; i < Tam; i++)
	{
		contato.nome[i] = toupper(contato.nome[i]);
	}
	printf("Telefone: ");
	gets(contato.tel);
	printf("E-mail: ");
	gets(contato.email);
	printf ("CPF: ");
	gets(contato.cpf);
	printf("Sexo <M/F>: ");
	scanf(" %c",&contato.genero);
	contato.genero = toupper(contato.genero);
	fflush(stdin);
	printf ("Maior de idade? <s/n>: ");
	scanf (" %c",&iconfirma);
	if (toupper(iconfirma) == 'S' && toupper(contato.genero) == 'M')
		{
			fflush(stdin);
			printf ("Nome do(a) Pai/Mae: ");
			gets(contato.nome2);						
			printf ("Possui Documento Militar? <s/n>: ");
			scanf ("%c",&rconfirma);
			if (toupper(rconfirma) == 'S')
			{
				fflush(stdin);
				printf ("Numero do Documento Militar: ");
				gets(contato.camp);
				printf ("\n");
			}							
		}
	else
		{
			fflush(stdin);
			printf("Nome do(a) Pai/Mae: ");
			gets(contato.nome2);
			printf ("\n");
		}
	
	if (toupper(rconfirma) == 'S' || toupper(iconfirma) == 'N' || toupper(contato.genero )== 'F')
	{	
		fflush(stdin);	
		printf("\nConfirma Matricula? <s/n>:");
		scanf("%c", &confirma);
		if (toupper(confirma) == 'S')
		{
			printf("\nAluno Matriculado !!\n");
			fseek(arq, 0, SEEK_END);
			fwrite(&contato, sizeof(reg),1, arq);
			system ("pause");
		}
	}
	
	else
	{
		printf ("Impossivel realizar matricula, Nao possui Documento Militar!!\n");
		system ("pause");
	}
}

void consultar(FILE *arq)
{ 
	reg contato; 
	int nr; 
	printf("\nConsulta do Aluno pelo numero\n");
	printf("\nInforme o numero da Matricula: ");
	scanf("%d", &nr);
	if ((nr <= tamanho(arq)) && (nr > 0))
	{
		fseek(arq, (nr - 1) * sizeof(reg), SEEK_SET);
		fread(&contato, sizeof(reg), 1, arq);
		printf("\nNome.........................: %s", contato.nome);
		printf("\nTelefone.....................: %s", contato.tel);
		printf("\nE-mail.......................: %s", contato.email);
		printf("\nCPF..........................: %s", contato.cpf);
		printf("\nSexo.........................: %c", contato.genero);
		printf("\nNome do(a) Pai/Mae...........: %s", contato.nome2);
		printf("\nDocumento Militar............: %s", contato.camp);
		printf("\nSituacao Aluno...............: %s\n", contato.status);
	}
	else
	{ 
		printf("\nNumero de Matricula Invalida!\n");
	}
	system("pause");
}

void gerararqtxt(FILE *arq)
{
	FILE *arqtxt=fopen("Relatorio.txt","w");
	
	if (!arqtxt)
	{
		printf("\nNao foi possivel criar esse arquivo!\n");
		system("pause");
	}

	fprintf(arqtxt, "==================== MATRICULAS =========================\n");
	int nr; 
	reg contato;
	for (nr = 0; nr < tamanho(arq); nr++)
	{
		fseek(arq, nr * sizeof(reg), SEEK_SET);
		fread(&contato, sizeof(reg), 1, arq);
		fprintf(arqtxt, "Nome do Aluno..............: %s\n", contato.nome);
		fprintf(arqtxt, "Telefone contato...........: %s\n", contato.tel);
		fprintf(arqtxt, "E-mail.....................: %s\n", contato.email);
		fprintf(arqtxt, "CPF........................: %s\n", contato.cpf);
		fprintf(arqtxt, "Sexo.......................: %c\n", contato.genero);
		fprintf(arqtxt, "Nome do(a) Pai/Mae.........: %s\n", contato.nome2);
		fprintf(arqtxt, "Documento Militar..........: %s\n", contato.camp);
		fprintf(arqtxt, "Situacao Aluno.............: %s\n", contato.status);
		fprintf(arqtxt, "=========================================================\n\n");
	}
		fclose(arqtxt);
		printf ("Relatorio gerado com sucesso!!\n\n");
		system ("pause");
}

int tamanho(FILE *arq)
{
	fseek(arq, 0, SEEK_END);
	return ftell(arq) / sizeof(reg);
}

void cancelar(FILE *arq)
{
	reg contato; 
	int nr;
	char confirma; 
	printf("\nConsulta do Aluno pelo numero\n");
	printf("\nInforme o numero da matricula: ");
	scanf("%d", &nr);
	if ((nr <= tamanho(arq)) && (nr > 0))
	{
			fseek(arq, (nr - 1) * sizeof(reg), SEEK_SET);
			fread(&contato, sizeof(reg), 1, arq);
		if (!strcmp(contato.status,"MATRICULADO"))
		{
			printf("\nNome.........................: %s", contato.nome);
			printf("\nTelefone.....................: %s", contato.tel);
			printf("\nE-mail.......................: %s", contato.email);
			printf("\nCPF..........................: %s", contato.cpf);
			printf("\nSexo.........................: %c", contato.genero);
			printf("\nNome do(a) Pai/Mae...........: %s", contato.nome2);
			printf("\nDocumento Militar............: %s", contato.camp);
			printf("\nSituacao Aluno...............: %s\n\n", contato.status);
			
			printf("Confirmar Cancelamento? <s/n>: ");
			scanf(" %c",&confirma);
		}
		else
			printf ("Matricula ja cancelada!\n");
		
		if (toupper(confirma) == 'S')
		{
			printf ("Matricula cancelada com sucesso!!\n");
			fseek(arq, (nr - 1) * sizeof(reg), SEEK_SET);
			strcpy(contato.status,"CANCELADO");
			fwrite(&contato, sizeof(reg), 1, arq);
		}
		
	}
	else
	{ 
		printf("\nNumero de Matricula Invalida!\n");
	}
	system("pause");
}

void relatorioord(FILE *arq)
{
	Lista l;
	linit (&l);
	reg contato;
	elem x;
	int nr;
	for (nr = 0;nr < tamanho(arq); nr++)
	{
		fseek(arq,nr*sizeof(reg),SEEK_SET);
		fread(&contato,sizeof(reg),1,arq);
		strcpy(x.nome,contato.nome);
		x.nr = nr;
		lins(&l,x);
	}
	FILE *arqtxt=fopen("RelatorioOrdenado.txt","w");
	fprintf (arqtxt,"ALUNOS UNIFENAS\n");
	fprintf (arqtxt,"============================================================\n");
	int c;
	for (c = 0; c < tamanho(arq); c++)
	{
		nr = l.m[c].nr;
		fseek(arq,nr*sizeof(reg),SEEK_SET);
		fread(&contato,sizeof(reg),1,arq);
		fprintf(arqtxt,"\nNome.........................: %s", contato.nome);
		fprintf(arqtxt,"\nTelefone.....................: %s", contato.tel);
		fprintf(arqtxt,"\nE-mail.......................: %s", contato.email);
		fprintf(arqtxt,"\nCPF..........................: %s", contato.cpf);
		fprintf(arqtxt,"\nSexo.........................: %c", contato.genero);
		fprintf(arqtxt,"\nNome do(a) Pai/Mae...........: %s", contato.nome2);
		fprintf(arqtxt,"\nDocumento Militar............: %s", contato.camp);
		fprintf(arqtxt,"\nSituacao Aluno...............: %s\n", contato.status);
		fprintf (arqtxt,"============================================================\n");		
	}
	fclose(arqtxt);
	printf ("Relatorio gerado com sucesso!!\n");
	system ("pause");

}

int main()
{

	int op;
	FILE *arq;

	if ((arq = fopen("alunos.dat", "rb+")) == NULL)
	{
		if ((arq = fopen("alunos.dat", "wb+")) == NULL)
		{
			printf("\nFalha ao abrir o arquivo!\n");
			system("pause");
		}
	}

	do
	{
		system("CLS");
		printf("========== UNIFENAS - REGISTRO ALUNO ==========\n");
		printf("1. Cadastrar\n");
		printf("2. Consultar matricula\n");
		printf("3. Cancelar Matricula\n");
		printf("4. Gerar arquivo\n");
		printf("5. Gerar arquivo ordenado\n");
		printf("6. Sair\n");
		printf("===================ALUNOS: %d\n", tamanho(arq));
		printf("Opcao: ");
		scanf("%d", &op);
		switch (op)
		{
		case 1:
			cadastrar(arq);
			break;
		case 2:
			consultar(arq);
			break;
		case 4:
			gerararqtxt(arq);
			break;
		case 3:
			cancelar(arq);
			break;
		case 5:
			relatorioord(arq);
			break;		
		case 6: fclose(arq);
		}
	} while (op != 6);
	system ("pause");
}
