#include <stdio.h>
#include <stdlib.h>
#define TAM_NOME_CLIENTE 100

struct cliente{
	char nome[TAM_NOME_CLIENTE];
	int idade;
};

struct filme{
int classif_filme;
int esta_disponivel;	
};

int main(int argc, char *argv[]) {
	
	struct cliente cli;
	struct filme fil;
	
	printf("\n Nome do cliente:");
	fflush(stdin); // limpa o buferr antes de fazer leitura
	fgets(cli.nome, TAM_NOME_CLIENTE, stdin);
	printf("\n Idade do cliente:");
	scanf("%d",&cli.idade);
	printf("\n Informe (0) para filme indisponivel e (1) para filme disponivel: ");	
	scanf("%d", &fil.esta_disponivel);
	printf("\n Indique classificacao_do filme: ");
	scanf("%d",&fil.classif_filme);
	printf("--------------------------------------");
	printf("\n Cliente: %s",cli.nome);
	printf("\n Idade: %d",cli.idade);
	printf("\n Disponibilidade de filme: (0) nao disponivel (1) disponivel: %d ", fil.esta_disponivel);	
	printf("\n classificacao do filme, %d anos.",fil.classif_filme);
	printf("\n O filme pode ser alocado pelo cliente, 0-NAO 1-SIM:  %d",(fil.esta_disponivel)&&(cli.idade>=fil.classif_filme));
	printf("\n Anos restante: %d",(cli.idade<fil.classif_filme)-(fil.classif_filme-cli.idade));
		
	return 0;
}