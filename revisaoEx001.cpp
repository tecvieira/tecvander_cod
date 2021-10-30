#include <stdio.h>

struct endereco{
	char rua[100];
	int numero;
};

int main(void){
	char nome[30];
	int idade;
	float deposito=0;
	float saque=0;
	float saldo_final=0;	
	struct endereco cli;
	
	
	printf("\nInforme seu nome:");
	scanf("%s",&nome);
	printf("\nInforme sua idade:");
	scanf("%d",&idade);
	printf("\nNome da rua:");
	scanf("%s",&cli.rua);
	printf("\nNumero da residencia:");
	scanf("%d",&cli.numero);
	printf("\nValor do deposito R$ ");
	scanf("%f",&deposito);


	
	
	printf("\nCADASTRO DO CLIENTE");
	printf("\nNome: %s", nome);
	printf("\nIdade: %d", idade);
	printf("\nEndereco:");
	printf("\nRua: %s numero %d",cli.rua, cli.numero);
	printf("\n\nINFORME A OPÇÃO DESEJADA");
	printf("\nUltimo deposito: R$ %.2f",deposito);
	printf("\n\(1) para saque \n(2) para saldo final\n(3) para sair");
	
	return 0; 
}