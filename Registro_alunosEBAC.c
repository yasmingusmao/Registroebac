#include <stdio.h>  //biblioteca de comunica��o com o usu�rio
#include <stdlib.h>  //biblioteca de aloca��o de espa�o em mem�ria
#include <locale.h>  //biblioteca de aloca��es de texto por regi�o
#include <string.h>  //biblioteca para leitura de strings

int registrar() //cria fun��o de registro de usu�rio
{
	setlocale(LC_ALL, "Portuguese"); //indicando o idioma que deve ser lido
	
	char arquivo[40]; //criando as vari�veis/strings
	char cpf[11];
	char nome[40];
	char sobrenome[40];
	char datadenascimento[8];
	char cargo[40];
	
	printf("Voc� escolheu cadastrar nomes. \n\n"); 
	printf("Digite o CPF a ser cadastrado: "); //solicitando informa��es ao usu�rio
	scanf("%s", cpf); //lendo a informa��o e guardando na var�avel
	
	strcpy(arquivo, cpf); //copia os valores da vari�vel no arquivo
	
	FILE *file; //cria o arquivo para guardar as informa��es fornecidas
	file = fopen(arquivo, "w"); //abre arquivo e pede para escrever nele
	fprintf(file, cpf); //no arquivo, escreva o cpf informado
	fclose(file); //fecha o arquivo
	
	file = fopen(arquivo, "a"); //abra o arquivo e atualize
	fprintf(file, ","); //inclui a v�rgula entre as informa��es
	fclose(file); //fecha o arquivo
	
	printf("Digite o nome a ser cadastrado: "); //solicitando mais informa��es ao usu�rio
	scanf("%s", nome); //lendo e guardando a informa��o na var�avel correspondente
	
	file = fopen(arquivo, "a"); //abra o arquivo e atualize
	fprintf(file, nome); //inclui nova vari�vel no arquivo
	fclose(file); //fecha o arquivo
	
	file = fopen(arquivo, "a"); //abre o arquivo e atualiza
	fprintf(file, ","); //inclui a v�rgula
	fclose(file); //fecha o arquivo
	
	printf("Digite o sobrenome a ser cadastrado: "); //solicita informa��es ao usu�rio
	scanf("%s",sobrenome); //l� e guarda a informa��o na vari�vel
	
	file = fopen(arquivo, "a"); //abre o arquivo e atualiza
	fprintf(file,sobrenome); //inclui nova vari�vel
	fclose(file); //fecha o arquivo
	
	file = fopen(arquivo, "a"); //abre o arquivo e atualiza
	fprintf(file,","); //inclui a v�rgula
	fclose(file); //fecha o arquivo
	
	printf("Digite a data de nascimento a ser cadastrada: "); //solicita informa��es ao usu�rio
	scanf("%s",datadenascimento); //l� e guarda a informa��o na vari�vel
	
	file = fopen(arquivo, "a"); //abre o arquivo e atualiza
	fprintf(file,datadenascimento); //inclui nova vari�vel
	fclose(file); //fecha o arquivo
	
	file = fopen(arquivo, "a"); //abre o arquivo e atualiza
	fprintf(file,","); //inclui a v�rgula
	fclose(file); //fecha o arquivo
	
	printf("Digite o cargo a ser cadastrada: "); //solicita informa��es ao usu�rio
	scanf("%s",cargo); //l� e guarda a informa��o na vari�vel
	
	file = fopen(arquivo, "a"); //abre o arquivo e atualiza
	fprintf(file,cargo); //inclui nova vari�vel
	fclose(file); //fecha o arquivo
	
	file = fopen(arquivo, "a"); //abre o arquivo e atualiza
	fprintf(file,"."); //inclui o ponto final.
	fclose(file); //fecha o arquivo
	
	system("pause"); //pausa o sistema

}

int consultar() //cria fun��o de consulta
{
	setlocale(LC_ALL, "Portuguese"); //define idioma
	
	char cpf[11]; //cria vari�veis
	char conteudo[200];
	
	printf("Voc� escolheu fazer uma consulta no sistema. \n\n"); //solicita informa��es ao usu�rio
	printf("Informe o CPF a ser consultado: ");
	scanf("%s", cpf); //l� e salva a informa��o do usu�rio
	
	FILE *file; 
	file = fopen(cpf, "r");
	
	if(file == NULL) //Se o arquivo for nulo
	{
		printf("CPF n�o localizado! \n"); //informar ao usu�rio que n�o foi localizado
	}
	
	while(fgets(conteudo, 200, file) != NULL) //enquanto for buscar um arquivo que seja diferente de nulo, apresentar as informa��es
	{
		printf("\nEssas s�o as informa��es do usu�rio encontrado: "); //apresentando as informa��es ao usu�rio
		printf("%s", conteudo);
		printf("\n\n"); //pulando linhas
	}
	
	system("pause"); //pausa o sistema
	fclose(file);
}


int deletar()
{
	char cpf[11]; //definindo vari�vel
	
	printf("Digite cpf do usu�rio a ser deletado: "); //solicitando informa��es ao usu�rio
	scanf("%s", cpf); //l� e salva a informa��o na vari�vel
	
	remove(cpf);
	
	FILE *file; //abre o arquivo
	file = fopen(cpf, "r"); //l� o arquivo solicitado
	
	if (file == NULL) //se o arquivo for nulo
	{	
		printf("CPF n�o encontrado!\n"); //informe ao usu�rio
		system("pause");	
	}
	
	fclose(file);
}


int main ()
{
	int opcao=0; //definindo vari�veis
	int x=1;
	
	for (x=1; x=1;)
	{

		system("cls");
		
		setlocale(LC_ALL, "Portuguese"); //Definindo a linguagem
	
		printf("### Registro de Alunos da EBAC ### \n\n");  //in�cio do menu
		printf("Escolha a op��o desejada do menu: \n\n");
		printf("\t1 - Registrar nomes\n");
		printf("\t2 - Consultar nomes\n");
		printf("\t3 - Deletar nomes\n\n");
		printf("\t4 - Sair do sistema\n\n");
		printf("Op��o: "); //fim do menu
	
		scanf("%d", &opcao); //armazenando a escolha do usu�rio na vari�vel
		
		system("cls");
		
		switch(opcao) //inicio da sele��o
		{
			case 1:
			registrar();
			break;
				
			case 2:
			consultar();
			break;
			
			case 3:
			deletar();
			break;
			
			case 4:
			printf("Obrigada por utilizar nosso sistema!");
			return 0;
			break;
					
			default:
			printf("Essa op��o n�o est� dispon�vel! \n");
			system("pause");
			break; //fim da sele��o
		}
	}
}
