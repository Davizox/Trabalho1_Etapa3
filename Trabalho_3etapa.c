#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define NUM_FUNC 2
#define NUM_CLIENTES 1
#define NUM_CARAC 100
#define NUM_PIZZAS 5

void pausar()
{
    char c;
    fflush(stdin);
    printf("Digite ENTER para continuar.");
    scanf("%c", &c);
}

void lerStrings(char *stringAlvo)
{
    fflush(stdin);
    fgets(stringAlvo, NUM_CARAC, stdin);
    stringAlvo[strlen(stringAlvo) - 1] = '\0';
}

typedef struct PED
{
    char sabor[NUM_CARAC];
    char tamanho;
    char acrescimos[NUM_CARAC];
} Pedido;

typedef struct END
{
    char rua[NUM_CARAC];
    int numeroCasa;
    char cep[NUM_CARAC];
    char bairro[NUM_CARAC];
    char cidade[NUM_CARAC];
} Endereco;

typedef struct CLI
{
    char nome[NUM_CARAC];
    char telefone[NUM_CARAC];
    Endereco endereco;
    Pedido pedidos;
} Clientes;

int main()
{
    char saboresPizza[NUM_PIZZAS][NUM_CARAC];
    Clientes clientes[NUM_CLIENTES];
    int i, j, opMenuSaida, opMenu, opMenuCadastro, opMenuVoltar = 1, opAcrescimos, opAlteracoes, opAltCli, opAltPed;
    int opEndCli;
    char nomeAlter[NUM_CARAC], nome_mod [NUM_CARAC];
	char nomeCliAltPed[NUM_CARAC];

    do
    {
        switch (opMenuVoltar)
        {
        case 1:
            //Menu Principal
         
            printf("\n\nPizzaria 2001\n");
            printf("Opcoes\t\t\tID\n");
            printf("Cadastros\t\t1\n");
            printf("Pedidos por cliente\t2\n");
            printf("Alteracao de cadastro\t3\n");
            printf("Encerrar\t\t4\n\n");
            scanf("%d", &opMenu);
            switch (opMenu)
            {
            case 1:
                //Menu Cadastros
                printf("\n\nMenu Cadastros\n");
                printf("Opcoes\t\t\tID\n");
                printf("Cadastro de clientes(%d) 1\n", NUM_CLIENTES);
                printf("Cadastro de sabores(%d)  2\n", NUM_PIZZAS);
                printf("Voltar\t\t\t3\n");
                scanf("%d", &opMenuCadastro);
                switch (opMenuCadastro)
                {
                case 1:
                    //Cadastro Clientes
                    for (i = 0; i < NUM_CLIENTES; i++)
                    {
                        printf("Digite o nome do cliente %d: ", i + 1);
                        lerStrings(clientes[i].nome);
                        printf("Digite o telefone do cliente %d: ", i + 1);
                        lerStrings(clientes[i].telefone);
                        printf("Digite a rua do cliente %d: ", i + 1);
                        lerStrings(clientes[i].endereco.rua);
                        printf("Digite o numero da casa do cliente %d: ", i + 1);
                        scanf("%d", &clientes[i].endereco.numeroCasa);
                        printf("Digite o CEP do cliente %d: ", i + 1);
                        lerStrings(clientes[i].endereco.cep);
                        printf("Digite o bairro do cliente %d: ", i + 1);
                        lerStrings(clientes[i].endereco.bairro);
                        printf("Digite a cidade do cliente %d: ", i + 1);
                        lerStrings(clientes[i].endereco.cidade);
                    }
                    opMenuVoltar = 1;
                    break;
                case 2:
                    //Cadastro de Sabores
                    for (i = 0; i < NUM_PIZZAS; i++)
                    {
                        printf("Digite o sabor da pizza %d: ", i + 1);
                        lerStrings(saboresPizza[i]);
                    }
                    //opMenuVoltar = 1;
                    break;
                case 3:
                    //opMenuVoltar = 1;
                    break;
                }
                break;
                
                                
                                                
            case 2:
                //Pedido
                for (i = 0; i < NUM_CLIENTES; i++)
                {
                    //Menu Sabores
                    printf("\n\nSabores\n");
                    printf("Opcoes\t\n");
                    //Printf Pizzas
                    for (j = 0; j < NUM_PIZZAS; j++)
                    {
                        printf("%s\n", saboresPizza[j]);
                    }
                    lerStrings(clientes[i].pedidos.sabor);
                    printf("\n\nPreÃ§os por tamanho:\n");
                    printf("P    \tM    \tG    \n");
                    printf("19,90\t29,90\t39,90\n");
                    printf("\nDigite o tamanho (P/M/G):");                                       
                    scanf("%s", clientes[i].pedidos.tamanho);                   								
					printf("Deseja acrescimos? (0-Nao / 1-Sim)");
                    scanf("%d", &opAcrescimos);
                    if (opAcrescimos == 1)
                    {
                        printf("Digite os Acrescimos (separados por _): ");
                        lerStrings(clientes[i].pedidos.acrescimos);
                    }
                }
                //opMenuVoltar = 1;
                break;
                
                
                                                                
            case 3:
                //Menu de AlteraÃ§Ã£o
                printf("\n\nAlteracoes\n");
                printf("Opcoes\t\t\tID\n");
                printf("Cadastros\t\t1\n");
                printf("Pedidos cliente  \t2\n");
                scanf("%d", &opAlteracoes);
                if (opAlteracoes == 1)
                {
                    for (i = 0; i < NUM_CLIENTES; i++){	
                    printf("\nNome: %s, n° %d", clientes[i].nome, i);
					}
															
                    printf("\n\nDigite o nome do cliente cadastrado que deseja alterar\n ");
                    lerStrings(nomeAlter);
                    for (i = 0; i < NUM_CLIENTES; i++)
                    {
                        if (nomeAlter == clientes[i].nome)
                        {
                        	
                        	printf("\n Informe qual dado será alterado\n");
                        	printf("\n Nome - 1\n");
                        	printf("\n Endereço - 2\n");
                        	printf("\n Telefone do cliente- 3\n");
                        	scanf("%d", opAltCli); 
							                       	
                        	switch(opAltCli){
                        		case 1:	
                        		printf("\n\n Informe o novo nome do cliente %d \n ", i);
                        		lerStrings(nome_mod);
                        	
                        		break;
                        		case 2:
                        		printf("\n Informe qual dado do endereço será modificado\n");
								printf("\n Rua - 1\n");
								printf("\n Número da casa - 2\n");
								printf("\n CEP - 3\n");
								printf("\n Bairro - 4\n");
								printf("\n Cidade - 5\n");
								scanf("%d", opEndCli);
								
									switch(opEndCli){
										case 1:
										printf("\n Rua - \n");
										lerStrings(clientes[i].endereco.rua);
										break;
										
										case 2:
										printf(" \nNúmero da casa - \n");
										scanf("%d", clientes[i].endereco.numeroCasa);
										break;
										
										case 3:
										printf("\n CEP - \n");
										lerStrings(clientes[i].endereco.cep);
										break;
										
										case 4:
										printf("\n Bairro - \n");
										lerStrings(clientes[i].endereco.bairro);
										break;	
									
										case 5:
										printf("\n Cidade - \n");
										lerStrings(clientes[i].endereco.cidade);
										break;	
								}
								break;
								
								case 3:
								printf("\nInforme o novo telefone do cliente\n");
								lerStrings(clientes[i].telefone);
								break;
							}
                        	
                        }
                    }
					                                                                
                }
                else if (opAlteracoes == 2)
                {
                for (i = 0; i < NUM_CLIENTES; i++)
                {
                	
                	printf("\n Informe o nome do cliente que realizou o pedido\n");
                	lerStrings(nomeCliAltPed);
                	
                	for (j = 0; j < NUM_CLIENTES; j++)
                    {
                       if(clientes[j].nome == nomeCliAltPed){
                       	printf("\nAlterar sabor da pizza - 1\n");
                       	printf("\nAlterar o tamanho da pizza - 2\n");
                       	print("\nAlterar os acréscimos - 3\n");
                       	scanf("%d",opAltPed);
                       	
                       	switch(opAltPed){
                       		
                       		case 1:
                       		printf("\n Informe o novo sabor \n");
                       		lerStrings(clientes[i].pedidos.sabor);                     		                       		
							break;
                       		
                       		case 2:
                       		printf("\n Informe o novo tamanho \n");
                       		scanf("%s", clientes[i].pedidos.tamanho);                     		                       		
							break;
							
							case 3:
								printf("Informe o novo acréscimo");
								lerStrings(clientes[i].pedidos.acrescimos);

								break;
                       		
                       		
						   }
                       	
                       	
					   }
					   
                    }

                }	
                }

                break;
            default:
                break;
            }
            break;
        default:
            break;
        }
        //opMenuVoltar = 1;
        //For do Printf
        /*for (i = 0; i < NUM_CLIENTES; i++)
        {
            printf("\n\nDados cliente %d:\n", i + 1);
            printf("\nNome: %s", clientes[i].nome);
            printf("\nTelefone: %s", clientes[i].telefone);
            printf("\nRua: %s", clientes[i].endereco.rua);
            printf("\nNumero casa: %d", clientes[i].endereco.numeroCasa);
            printf("\nCEP: %s", clientes[i].endereco.cep);
            printf("\nBairro: %s", clientes[i].endereco.bairro);
            printf("\nCidade: %s", clientes[i].endereco.cidade);
        }*/

        printf("\n\nDeseja Continuar? (0-Nao/1-Sim)\n");
        scanf("%d", &opMenuSaida);
    } while (opMenuSaida != 0);
    return 0;
}
