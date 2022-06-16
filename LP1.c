#include <stdlib.h>
#include <stdio.h>
#include <locale.h>
#include <string.h>

/* Define o tipo cImovel, com as caracter�sticas gerais de um im�vel */
typedef struct caracteristicas_imoveis{
    char titulo[300];
    char logradouro[100];
    int numero;
    char bairro[50];
    char cep[9];
    char cidade[50];
    char valorImovel[20];
    int tipoOferta;
    int tipoImovel;

}cImovel;

cImovel imoveis;

/* Define o tipo cCasa, com as caracter�sticas gerais de uma casa */
typedef struct caracteristicas_casa{
	int numeroPavimentos;
    int numeroQuartos;
    char areaTerreno[20];
    char areaConstruida[20];
}cCasa;

cCasa casa;

/* Define o tipo cApartamento, com as caracter�sticas gerais de um apartamento */
typedef struct caracteristicas_apartamento{
	char area[20];
	int numeroQuartos;
	char posicao[50];
	int andar;
	char valorCondominio[20];
	int numeroVagas;
}cApartamento;

cApartamento apartamento;

/* Define o tipo cTerreno, com as caracter�sticas gerais de um terreno */
typedef struct caracteristicas_terreno{
	char area[20];
}cTerreno;

cTerreno terreno;

void ConsultaCasa(int tipoOferta){ // Cont�m a descri��o de todas as casas

    int flag=0;

	FILE *arq;
    arq = fopen("casa.txt", "r");

    printf("\n\n-----------------------CASA(S)------------------------\n\n");

    while(fscanf(arq, "%d ; %[^;] ; %[^;] ; %[^;] ; %[^;] ; %[^;]; %d ; %[^;] ; %d ; %d ; %d ; %[^;]; %[^\n]\n", &imoveis.tipoImovel, &imoveis.titulo, &imoveis.cep, &imoveis.cidade, &imoveis.bairro, &imoveis.logradouro,
             &imoveis.numero, &imoveis.valorImovel, &imoveis.tipoOferta, &casa.numeroPavimentos, &casa.numeroQuartos, &casa.areaTerreno, &casa.areaConstruida)!=EOF){

				if((tipoOferta == 1 && imoveis.tipoOferta == 1) || (tipoOferta == 2 && imoveis.tipoOferta == 2) || tipoOferta == 100){
					flag=1;
					printf("Tipo do im�vel: Casa");

	                if(imoveis.tipoOferta==1)
                        printf(" (Aluguel)\t");

	                else if(imoveis.tipoOferta==2)
                        printf(" (Venda)\t");

	                printf("Valor: R$%s\n",imoveis.valorImovel);
	                printf("Rua: %s, %d\t",imoveis.logradouro,imoveis.numero);
	                printf("CEP: %c%c%c%c%c-%c%c%c\n",imoveis.cep[0],imoveis.cep[1],imoveis.cep[2],imoveis.cep[3],imoveis.cep[4],imoveis.cep[5],imoveis.cep[6],imoveis.cep[7]);
	                printf("Cidade: %s\t",imoveis.cidade);
	                printf("Bairro: %s\n",imoveis.bairro);
	                printf("�rea do terreno: %sm�\t",casa.areaTerreno);
	                printf("�rea constru�da: %sm�\n",casa.areaConstruida);
	                printf("Numero de pavimentos: %d Andar(es)\n",casa.numeroPavimentos);
	                printf("Numero de quartos: %d Quarto(s)\n",casa.numeroQuartos);
	                printf("-----------------------------------------------------\n\n");
					}
    }

    if(flag==0)
        puts("Nenhuma casa encontrada.\n\n");


    fclose(arq);
}

void ConsultaApartamento(int tipoOferta){ // Cont�m a descri��o de todos os apartamentos

    int flag=0;

	FILE *arq;
	arq=fopen("apartamento.txt","r");

    printf("\n\n-------------------APARTAMENTO(S)---------------------\n\n");

    while(fscanf(arq, "%d ; %[^;] ; %[^;] ; %[^;] ; %[^;] ; %[^;]; %d ; %[^;] ; %d ; %[^;] ; %d ; %[^;] ; %d ; %[^;] ; %d\n", &imoveis.tipoImovel, &imoveis.titulo, &imoveis.cep, &imoveis.cidade, &imoveis.bairro,
             &imoveis.logradouro,&imoveis.numero, &imoveis.valorImovel, &imoveis.tipoOferta, &apartamento.area, &apartamento.numeroQuartos, &apartamento.posicao, &apartamento.andar,
            &apartamento.valorCondominio, &apartamento.numeroVagas)!=EOF){

				if((tipoOferta == 1 && imoveis.tipoOferta == 1) || (tipoOferta == 2 && imoveis.tipoOferta == 2) || tipoOferta == 100){
                    flag=1;
                    printf("Tipo do im�vel: Apartamento");

                    if(imoveis.tipoOferta==1)
                        printf(" (Aluguel)\t");

                    else if(imoveis.tipoOferta==2)
                        printf(" (Venda)\t");

                    printf("Valor: R$%s\n",imoveis.valorImovel);
                    printf("Rua: %s, %d\t",imoveis.logradouro,imoveis.numero);
                    printf("CEP: %c%c%c%c%c-%c%c%c\n",imoveis.cep[0],imoveis.cep[1],imoveis.cep[2],imoveis.cep[3],imoveis.cep[4],imoveis.cep[5],imoveis.cep[6],imoveis.cep[7]);
                    printf("Cidade: %s\t",imoveis.cidade);
                    printf("Bairro: %s\n",imoveis.bairro);
                    printf("�rea do apartamento: %sm�\t",apartamento.area);
                    printf("N�mero de quartos: %d\n",apartamento.numeroQuartos);
                    printf("Posi��o do apartamento: %s\t",apartamento.posicao);
                    printf("Andar: %d Andar\n",apartamento.andar);
                    printf("Taxa de condom�nio: R$%s\t",apartamento.valorCondominio);
                    printf("%d vaga(s) na garagem\n", apartamento.numeroVagas);
                    printf("----------------------------------------------------\n\n");
                    }
    }

    if(flag==0)
        puts("Nenhum apartamento encontrado.\n\n");

    fclose(arq);
}

void ConsultaTerreno(int tipoOferta){ // Cont�m a descri��o de todos os terrenos

    int flag=0;

	FILE *arq;
    arq=fopen("terreno.txt","r");

    printf("\n\n----------------------TERRENO(S)----------------------\n\n");

    while(fscanf(arq, "%d ; %[^;] ; %[^;] ; %[^;] ; %[^;] ; %[^;]; %d ; %[^;] ; %d ; %[^\n]\n", &imoveis.tipoImovel, &imoveis.titulo, &imoveis.cep, &imoveis.cidade, &imoveis.bairro, &imoveis.logradouro,
             &imoveis.numero, &imoveis.valorImovel, &imoveis.tipoOferta, &terreno.area)!=EOF){

             	if((tipoOferta == 1 && imoveis.tipoOferta == 1) || (tipoOferta == 2 && imoveis.tipoOferta == 2) || tipoOferta == 100){
                    flag=1;
                    printf("Tipo do im�vel: Terreno");

                    if(imoveis.tipoOferta==1)
                        printf(" (Aluguel)\t");

                    else if(imoveis.tipoOferta==2)
                        printf(" (Venda)\t");

                    printf("Valor: R$%s\n",imoveis.valorImovel);
                    printf("Rua: %s, %d\t",imoveis.logradouro,imoveis.numero);
                    printf("CEP: %c%c%c%c%c-%c%c%c\n",imoveis.cep[0],imoveis.cep[1],imoveis.cep[2],imoveis.cep[3],imoveis.cep[4],imoveis.cep[5],imoveis.cep[6],imoveis.cep[7]);
                    printf("Cidade: %s\t",imoveis.cidade);
                    printf("Bairro: %s\n",imoveis.bairro);
                    printf("�rea do terreno: %sm�\n",terreno.area);
                    printf("------------------------------------------------------\n\n");
                    }
    }

    if(flag==0)
        puts("Nenhum terreno encontrado.\n\n");

    fclose(arq);
}

/* Permite o cadastro de um im�vel em geral */
void Cadastrar(void){

    setlocale(LC_ALL, "Portuguese");

    system("cls");

    FILE *arq;
    arq = fopen("geral.txt", "a");
	imoveis.tipoImovel = 0;
    imoveis.tipoOferta = 0;

	while(imoveis.tipoImovel != 1 && imoveis.tipoImovel != 2 && imoveis.tipoImovel != 3){

        puts("Digite o n�mero referente ao tipo de im�vel:\n(1) Casa\n(2) Apartamento\n(3) Terreno");
        printf("Op��o: ");
        scanf("%d", &imoveis.tipoImovel);
	}

	system("cls");

    puts("Crie um an�ncio para seu im�vel (at� 300 caracteres): ");
	scanf(" %[^\n]s", &imoveis.titulo);

	puts("Digite o CEP do im�vel: ");
	scanf(" %[^\n]s", &imoveis.cep);

    puts("Digite a cidade do im�vel: ");
    scanf(" %[^\n]s", imoveis.cidade);

    puts("Digite o bairro do im�vel: ");
    scanf(" %[^\n]s", imoveis.bairro);

    puts("Digite o logradouro do im�vel: ");
    scanf(" %[^\n]s", imoveis.logradouro);

    puts("Digite o n�mero do im�vel: ");
    scanf("%d", &imoveis.numero);

    puts("Digite o valor do im�vel (N�o � necess�rio pontua��o): ");
    scanf(" %[^\n]s", &imoveis.valorImovel);

    while(imoveis.tipoOferta != 1 && imoveis.tipoOferta != 2){
    	puts("O im�vel est� dispon�vel para aluguel (1) ou venda (2)?: ");
    	scanf("%d", &imoveis.tipoOferta);
	}

	fprintf(arq, "%d; %s; %s; %s; %s; %s; %d; %s; %d\n", imoveis.tipoImovel, imoveis.titulo, imoveis.cep,
          imoveis.cidade, imoveis.bairro, imoveis.logradouro, imoveis.numero, imoveis.valorImovel, imoveis.tipoOferta);

    fclose(arq);

	/* Cadastro adicional referente ao tipo do im�vel escolhido */
	switch(imoveis.tipoImovel){
		case 1:; // Caso o tipo do im�vel seja do tipo "Casa"

                arq = fopen("casa.txt", "a");

				puts("Digite o n�mero de pavimentos da casa: ");
				scanf("%d", &casa.numeroPavimentos);
				puts("Digite o n�mero de quartos da casa: ");
				scanf("%d", &casa.numeroQuartos);
				puts("Digite o valor da �rea do terreno: (N�o � necess�rio m�)");
				scanf(" %[^\n]s", &casa.areaTerreno);
				puts("Digite o valor da �rea total constru�da: (N�o � necess�rio m�)");
				scanf(" %[^\n]s", &casa.areaConstruida);

				fprintf(arq, "%d; %s; %s; %s; %s; %s; %d; %s; %d; %d; %d; %s; %s\n",  imoveis.tipoImovel,
				imoveis.titulo, imoveis.cep, imoveis.cidade, imoveis.bairro, imoveis.logradouro,imoveis.numero,
				imoveis.valorImovel, imoveis.tipoOferta, casa.numeroPavimentos, casa.numeroQuartos,casa.areaTerreno, casa.areaConstruida);

                fclose(arq);

				break;

		case 2:; // Caso o tipo do im�vel seja do tipo "Apartamento"

                arq = fopen("apartamento.txt", "a");

				puts("Digite o valor da �rea do apartamento: (N�o � necess�rio m�)");
				scanf(" %[^\n]s", &apartamento.area);
				puts("Digite o n�mero de quartos do apartamento:");
				scanf("%d", &apartamento.numeroQuartos);
				puts("Digite a posi��o do apartamento:");
				scanf(" %[^\n]s", apartamento.posicao);
				puts("Digite o andar do apartamento:");
				scanf("%d", &apartamento.andar);
				puts("Digite o valor do condom�nio: (N�o � necess�rio pontua��o)");
				scanf(" %[^\n]s", &apartamento.valorCondominio);
				puts("Digite o n�mero de vagas de garagem:");
				scanf("%d", &apartamento.numeroVagas);

				fprintf(arq, "%d; %s; %s; %s; %s; %s; %d; %s; %d; %s ; %d; %s; %d; %s; %d\n", imoveis.tipoImovel, imoveis.titulo, imoveis.cep, imoveis.cidade, imoveis.bairro,
             imoveis.logradouro,imoveis.numero, imoveis.valorImovel, imoveis.tipoOferta, apartamento.area, apartamento.numeroQuartos, apartamento.posicao, apartamento.andar,
             apartamento.valorCondominio, apartamento.numeroVagas);

                fclose(arq);

				break;

		case 3:; // Caso o tipo do im�vel seja do tipo "Terreno"

                arq = fopen("terreno.txt", "a");

				puts("Digite o valor da �rea do terreno: (N�o � necess�rio m�)");
				scanf(" %[^\n]s", &terreno.area);

				fprintf(arq, "%d; %s; %s; %s; %s; %s; %d; %s; %d; %s\n", imoveis.tipoImovel, imoveis.titulo, imoveis.cep, imoveis.cidade, imoveis.bairro,
             imoveis.logradouro,imoveis.numero, imoveis.valorImovel, imoveis.tipoOferta, terreno.area);

                fclose(arq);

                break;
	}

	printf("Cadastro realizado com sucesso\n\n\n");
    system("Pause");

    system("cls");
} // Fim da fun��o cadastrar

/* Fun��o que exibe os an�ncios de todos os im�veis */
void Consultar(void){

	setlocale(LC_ALL, "Portuguese");

	system("cls");

    int i=1;
	FILE *arq;
	arq = fopen("geral.txt", "r");

	while(fscanf(arq, "%d ; %[^;] ; %[^;] ; %[^;] ; %[^;] ; %[^;] ; %d ; %[^;] ; %d\n", &imoveis.tipoImovel, &imoveis.titulo, &imoveis.cep,
          &imoveis.cidade, &imoveis.bairro, &imoveis.logradouro, &imoveis.numero, &imoveis.valorImovel, &imoveis.tipoOferta) !=EOF){

        printf("%d. ", i++);
        printf("%s\n", imoveis.titulo);
    }

    printf("\n\n\n");

    system("Pause");

    system("cls");
}

/* Fun��o que exibe todas as caracter�sticas de todos os im�veis */
void ConsultarDescricao(void){

    system("cls");

    FILE *arq;

    ConsultaCasa(100);
    ConsultaApartamento(100);
    ConsultaTerreno(100);

    system("pause");

    system("cls");
}

/* Fun��o que mostra um tipo de im�vel escolhido, por tipo de oferta */
int ImoveisTipo(int tipoOferta){

    system("cls");

	int selecao=0;
    FILE *arq;

	puts("Qual tipo de im�vel gostaria de ver?\n"
	"(1) - Casa\n(2) - Apartamento\n(3) - Terreno\n");

	scanf("%d", &selecao);

	system("cls");

	switch(selecao){
		case 1:

			if(tipoOferta == 2){
                ConsultaCasa(2);

                system("pause");
                system("cls");
			}
			else if(tipoOferta == 1){
                ConsultaCasa(1);

                system("pause");
                system("cls");
			}
			break;

	    case 2:

			if(tipoOferta == 2){
                ConsultaApartamento(2);

                system("pause");
                system("cls");
			}
			else if(tipoOferta == 1){
                ConsultaApartamento(1);

                system("pause");
                system("cls");
			}
			break;

		case 3:

			if(tipoOferta == 2){
                ConsultaTerreno(2);

                system("pause");
                system("cls");
			}
			else if(tipoOferta == 1){
                ConsultaTerreno(1);

                system("pause");
                system("cls");
			}
			break;

		default:
			puts("Por favor digite um n�mero v�lido!");

			return 0;
	}
}
/* Fun��o que mostra um tipo de im�vel escolhido, por bairro/cidade */
void ConsultaPersonalizada(int tipoOferta){

    system("cls");

    char bairro[50],cidade[50];
    int flag=0;

    if(tipoOferta==1||tipoOferta==2){
        puts("\nQual bairro voc� deseja procurar?: ");
        scanf(" %[^\n]s", &bairro);

        system("cls");

    }else{
        puts("\nQual cidade voc� deseja procurar?: ");
        scanf(" %[^\n]s", &cidade);

        system("cls");
    }

    FILE *arq;
    arq = fopen("casa.txt", "r");

    printf("\n\n-----------------------CASA(S)------------------------\n\n");

    while(fscanf(arq, "%d ; %[^;] ; %[^;] ; %[^;] ; %[^;] ; %[^;]; %d ; %[^;] ; %d ; %d ; %d ; %[^;] ; %[^\n]\n", &imoveis.tipoImovel, &imoveis.titulo, &imoveis.cep, &imoveis.cidade, &imoveis.bairro, &imoveis.logradouro,
             &imoveis.numero, &imoveis.valorImovel, &imoveis.tipoOferta, &casa.numeroPavimentos, &casa.numeroQuartos, &casa.areaTerreno, &casa.areaConstruida)!=EOF){

				if((tipoOferta == 1 && imoveis.tipoOferta == 1) || (tipoOferta == 2 && imoveis.tipoOferta == 2) || tipoOferta == 100){

                    if(stricmp(bairro,imoveis.bairro)==0 || stricmp(cidade,imoveis.cidade)==0){
                        flag=1;
                        printf("Tipo do im�vel: Casa");

                        if(imoveis.tipoOferta==1)
                            printf(" (Aluguel)\t");

                        else if(imoveis.tipoOferta==2)
                            printf(" (Venda)\t");

                        printf("Valor: R$%s\n",imoveis.valorImovel);
                        printf("Rua: %s, %d\t",imoveis.logradouro,imoveis.numero);
                        printf("CEP: %c%c%c%c%c-%c%c%c\n",imoveis.cep[0],imoveis.cep[1],imoveis.cep[2],imoveis.cep[3],imoveis.cep[4],imoveis.cep[5],imoveis.cep[6],imoveis.cep[7]);
                        printf("Cidade: %s\t",imoveis.cidade);
                        printf("Bairro: %s\n",imoveis.bairro);
                        printf("�rea do terreno: %sm�\t",casa.areaTerreno);
                        printf("�rea constru�da: %sm�\n",casa.areaConstruida);
                        printf("Numero de pavimentos: %d Andar(es)\n",casa.numeroPavimentos);
                        printf("Numero de quartos: %d Quarto(s)\n",casa.numeroQuartos);
                        printf("-----------------------------------------------------\n\n");
                    }
				}
    }

    if(flag==0)
        puts("Nenhuma casa encontrada.");

    flag=0;

    fclose(arq);
    arq=fopen("apartamento.txt","r");

    printf("\n\n-------------------APARTAMENTO(S)---------------------\n\n");

    while(fscanf(arq, "%d ; %[^;] ; %[^;] ; %[^;] ; %[^;] ; %[^;]; %d ; %[^;] ; %d ; %[^;] ; %d ; %[^;] ; %d ; %[^;] ; %d\n", &imoveis.tipoImovel, &imoveis.titulo, &imoveis.cep, &imoveis.cidade, &imoveis.bairro,
             &imoveis.logradouro,&imoveis.numero, &imoveis.valorImovel, &imoveis.tipoOferta, &apartamento.area, &apartamento.numeroQuartos, &apartamento.posicao, &apartamento.andar,
            &apartamento.valorCondominio, &apartamento.numeroVagas)!=EOF){

				if((tipoOferta == 1 && imoveis.tipoOferta == 1) || (tipoOferta == 2 && imoveis.tipoOferta == 2) || tipoOferta == 100){

                    if(stricmp(bairro,imoveis.bairro)==0 || stricmp(cidade,imoveis.cidade)==0){
                        flag=1;
                        printf("Tipo do im�vel: Apartamento");

                        if(imoveis.tipoOferta==1)
                            printf(" (Aluguel)\t");

                        else if(imoveis.tipoOferta==2)
                            printf(" (Venda)\t");

                        printf("Valor: R$%s\n",imoveis.valorImovel);
                        printf("Rua: %s, %d\t",imoveis.logradouro,imoveis.numero);
                        printf("CEP: %c%c%c%c%c-%c%c%c\n",imoveis.cep[0],imoveis.cep[1],imoveis.cep[2],imoveis.cep[3],imoveis.cep[4],imoveis.cep[5],imoveis.cep[6],imoveis.cep[7]);
                        printf("Cidade: %s\t",imoveis.cidade);
                        printf("Bairro: %s\n",imoveis.bairro);
                        printf("�rea do apartamento: %sm�\t",apartamento.area);
                        printf("N�mero de quartos: %d\n",apartamento.numeroQuartos);
                        printf("Posi��o do apartamento: %s\t",apartamento.posicao);
                        printf("Andar: %d Andar\n",apartamento.andar);
                        printf("Taxa de condom�nio: R$%s\t",apartamento.valorCondominio);
                        printf("%d vaga(s) na garagem\n", apartamento.numeroVagas);
                        printf("----------------------------------------------------\n\n");
                    }
                }
    }

    if(flag==0)
        puts("Nenhum apartamento encontrado.");

    flag=0;

    fclose(arq);
    arq=fopen("terreno.txt","r");

    printf("\n\n----------------------TERRENO(S)----------------------\n\n");

    while(fscanf(arq, "%d ; %[^;] ; %[^;] ; %[^;] ; %[^;] ; %[^;]; %d ; %[^;] ; %d ; %[^\n]\n", &imoveis.tipoImovel, &imoveis.titulo, &imoveis.cep, &imoveis.cidade, &imoveis.bairro, &imoveis.logradouro,
             &imoveis.numero, &imoveis.valorImovel, &imoveis.tipoOferta, &terreno.area)!=EOF){

             	if((tipoOferta == 1 && imoveis.tipoOferta == 1) || (tipoOferta == 2 && imoveis.tipoOferta == 2) || tipoOferta == 100){

                    if(strcmp(bairro,imoveis.bairro)==0 || stricmp(cidade,imoveis.cidade)==0){
                        flag=1;
                        printf("Tipo do im�vel: Terreno");

                        if(imoveis.tipoOferta==1)
                            printf(" (Aluguel)\t");

                        else if(imoveis.tipoOferta==2)
                            printf(" (Venda)\t");

                        printf("Valor: R$%s\n",imoveis.valorImovel);
                        printf("Rua: %s, %d\t",imoveis.logradouro,imoveis.numero);
                        printf("CEP: %c%c%c%c%c-%c%c%c\n",imoveis.cep[0],imoveis.cep[1],imoveis.cep[2],imoveis.cep[3],imoveis.cep[4],imoveis.cep[5],imoveis.cep[6],imoveis.cep[7]);
                        printf("Cidade: %s\t",imoveis.cidade);
                        printf("Bairro: %s\n",imoveis.bairro);
                        printf("�rea do terreno: %sm�\n",terreno.area);
                        printf("------------------------------------------------------\n\n");
                    }
                }
    }

    if(flag==0)
        puts("Nenhum terreno encontrado.\n\n");

    flag=0;

    system("pause");
    system("cls");

    fclose(arq);
}


int Opcoes(void){ // Exibe todas as op��es de tarefas poss�veis ao usu�rio

    int selecao=0; // Vari�vel referente � escolha do usu�rio
    puts(".................................................");
    puts(".\t\t\t\t\t\t.\n.\t\t\t\t\t\t.\n. Bem-vindo(a) ao site da Imobili�ria LP1!\t.\n.\t\t\t\t\t\t.\n"
	". Selecione o que deseja fazer:\t\t\t.\n.\t\t\t\t\t\t.\t\t\t\t.\t\t\t\t\t\t.");

    puts(". 1. Cadastrar im�veis\t\t\t\t.\n"
   		". 2. Consultar im�veis\t\t\t\t.\n"
    	". 3. Consultar descri��o de im�veis\t\t.\n"
    	". 4. Im�veis dispon�veis para vender por tipo\t.\n"
   	 	". 5. Im�veis dispon�veis para alugar por tipo\t.\n"
   	 	". 6. Im�veis dispon�veis para vender por bairro\t.\n"
   	 	". 7. Im�veis dispon�veis para alugar por bairro\t.\n"
   	 	". 8. Consultar descri��o de im�veis por cidade\t.\n"
   	 	". 9. Sair\t\t\t\t\t.\n.\t\t\t\t\t\t.\n.................................................");

    printf("\n\nOp��o: ");
    scanf("%d", &selecao);

    switch(selecao){

        case 1: // Caso a escolha seja cadastrar

            Cadastrar();

            break;

        case 2:

            Consultar();

            break;

        case 3:

            ConsultarDescricao();

            break;

        case 4:

        	ImoveisTipo(2); // Passa o par�metro "2" - Vender;

            break;

        case 5:

        	ImoveisTipo(1); // Passa o par�metro "1" - Alugar;

            break;

        case 6:

            ConsultaPersonalizada(2); // Passa o par�metro "2" - Vender;

            break;

        case 7:

            ConsultaPersonalizada(1); // Passa o par�metro "1" - Alugar;

            break;

        case 8:

            ConsultaPersonalizada(100); // // Passa o par�metro "100" - Geral/Cidade;

            break;

        case 9:

            return 9;

            break;
        default:

            printf("Por favor, digite um n�mero v�lido!\n\n");

            return 0;
    }
}

int main(void){

    setlocale(LC_ALL, "Portuguese"); // Adiciona suporte � l�ngua portuguesa

    while(1){

        if(Opcoes()==9) // Faz a chamada da fun��o "Op�oes"

            break;
        }

    return 0;
}
