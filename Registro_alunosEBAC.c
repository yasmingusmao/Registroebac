#include <stdio.h>  //biblioteca de comunicação com o usuário
#include <stdlib.h>  //biblioteca de alocação de espaço em memória
#include <locale.h>  //biblioteca de alocações de texto por região
#include <string.h>  //biblioteca para leitura de strings

int registrar() //cria função de registro de usuário
{
	setlocale(LC_ALL, "Portuguese"); //indicando o idioma que deve ser lido
	
	char arquivo[40]; //criando as variáveis/strings
	char cpf[11];
	char nome[40];
	char sobrenome[40];
	char datadenascimento[8];
	char cargo[40];
	
	printf("Você escolheu cadastrar nomes. \n\n"); 
	printf("Digite o CPF a ser cadastrado: "); //solicitando informações ao usuário
	scanf("%s", cpf); //lendo a informação e guardando na varíavel
	
	strcpy(arquivo, cpf); //copia os valores da variável no arquivo
	
	FILE *file; //cria o arquivo para guardar as informações fornecidas
	file = fopen(arquivo, "w"); //abre arquivo e pede para escrever nele
	fprintf(file, cpf); //no arquivo, escreva o cpf informado
	fclose(file); //fecha o arquivo
	
	file = fopen(arquivo, "a"); //abra o arquivo e atualize
	fprintf(file, ","); //inclui a vírgula entre as informações
	fclose(file); //fecha o arquivo
	
	printf("Digite o nome a ser cadastrado: "); //solicitando mais informações ao usuário
	scanf("%s", nome); //lendo e guardando a informação na varíavel correspondente
	
	file = fopen(arquivo, "a"); //abra o arquivo e atualize
	fprintf(file, nome); //inclui nova variável no arquivo
	fclose(file); //fecha o arquivo
	
	file = fopen(arquivo, "a"); //abre o arquivo e atualiza
	fprintf(file, ","); //inclui a vírgula
	fclose(file); //fecha o arquivo
	
	printf("Digite o sobrenome a ser cadastrado: "); //solicita informações ao usuário
	scanf("%s",sobrenome); //lê e guarda a informação na variável
	
	file = fopen(arquivo, "a"); //abre o arquivo e atualiza
	fprintf(file,sobrenome); //inclui nova variável
	fclose(file); //fecha o arquivo
	
	file = fopen(arquivo, "a"); //abre o arquivo e atualiza
	fprintf(file,","); //inclui a vírgula
	fclose(file); //fecha o arquivo
	
	printf("Digite a data de nascimento a ser cadastrada: "); //solicita informações ao usuário
	scanf("%s",datadenascimento); //lê e guarda a informação na variável
	
	file = fopen(arquivo, "a"); //abre o arquivo e atualiza
	fprintf(file,datadenascimento); //inclui nova variável
	fclose(file); //fecha o arquivo
	
	file = fopen(arquivo, "a"); //abre o arquivo e atualiza
	fprintf(file,","); //inclui a vírgula
	fclose(file); //fecha o arquivo
	
	printf("Digite o cargo a ser cadastrada: "); //solicita informações ao usuário
	scanf("%s",cargo); //lê e guarda a informação na variável
	
	file = fopen(arquivo, "a"); //abre o arquivo e atualiza
	fprintf(file,cargo); //inclui nova variável
	fclose(file); //fecha o arquivo
	
	file = fopen(arquivo, "a"); //abre o arquivo e atualiza
	fprintf(file,"."); //inclui o ponto final.
	fclose(file); //fecha o arquivo
	
	system("pause"); //pausa o sistema

}

int consultar() //cria função de consulta
{
	setlocale(LC_ALL, "Portuguese"); //define idioma
	
	char cpf[11]; //cria variáveis
	char conteudo[200];
	
	printf("Você escolheu fazer uma consulta no sistema. \n\n"); //solicita informações ao usuário
	printf("Informe o CPF a ser consultado: ");
	scanf("%s", cpf); //lê e salva a informação do usuário
	
	FILE *file; 
	file = fopen(cpf, "r");
	
	if(file == NULL) //Se o arquivo for nulo
	{
		printf("CPF não localizado! \n"); //informar ao usuário que não foi localizado
	}
	
	while(fgets(conteudo, 200, file) != NULL) //enquanto for buscar um arquivo que seja diferente de nulo, apresentar as informações
	{
		printf("\nEssas são as informações do usuário encontrado: "); //apresentando as informações ao usuário
		printf("%s", conteudo);
		printf("\n\n"); //pulando linhas
	}
	
	system("pause"); //pausa o sistema
	fclose(file);
}


int deletar()
{
	char cpf[11]; //definindo variável
	
	printf("Digite cpf do usuário a ser deletado: "); //solicitando informações ao usuário
	scanf("%s", cpf); //lê e salva a informação na variável
	
	remove(cpf);
	
	FILE *file; //abre o arquivo
	file = fopen(cpf, "r"); //lê o arquivo solicitado
	
	if (file == NULL) //se o arquivo for nulo
	{	
		printf("CPF não encontrado!\n"); //informe ao usuário
		system("pause");	
	}
	
	fclose(file);
}


int main ()
{
	int opcao=0; //definindo variáveis
	int x=1;
	
	for (x=1; x=1;)
	{

		system("cls");
		
		setlocale(LC_ALL, "Portuguese"); //Definindo a linguagem
	
		printf("### Registro de Alunos da EBAC ### \n\n");  //início do menu
		printf("Escolha a opção desejada do menu: \n\n");
		printf("\t1 - Registrar nomes\n");
		printf("\t2 - Consultar nomes\n");
		printf("\t3 - Deletar nomes\n\n");
		printf("\t4 - Sair do sistema\n\n");
		printf("Opção: "); //fim do menu
	
		scanf("%d", &opcao); //armazenando a escolha do usuário na variável
		
		system("cls");
		
		switch(opcao) //inicio da seleção
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
			printf("Essa opção não está disponível! \n");
			system("pause");
			break; //fim da seleção
		}
	}
}
