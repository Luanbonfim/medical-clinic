/*1.Faça um programa para auxiliar uma clinica médica. O seu programa deve marcar consultas,
sabendo que a clinica permite no máximo 10000 consultas e para cada consulta são necessários os seguintes campos:
Nome Paciente, Sexo Paciente, Data de Nascimento (Dia, Mês e Ano), Data da Consulta (Dia, Mês, Ano e Hora). Detalhe,
o seu programa deve evitar que duas consultas sejam marcadas para a mesma data e hora.

AUTORIA:
Luan Vitor Mantelo do Bonfim  
Jogos Digitais.*/

//Inclusão das bibliotecas necessárias
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#define  TAM 10000

//Declaração das structs necessárias
typedef struct {
    int dia, mes, ano;
} data;

typedef struct{
    int minuto;
    int horas;
} horario;

typedef struct{
    char nome[50];
    char sexo;
    data dtnascimento, dtconsulta;
    horario horarioconsulta;
} consulta;


int main(){
//Declaração das variáveis necessárias
setlocale(LC_ALL, "portuguese");
consulta agendar[TAM];
int i=0,j=0,cont=0, aux=0;
char opc=' ', opc2=' ', opc3=' ';

while (strchr("sSnN", opc) ==NULL){ //Este 1º while é responsável pela condição da 1º opção "opc", caso a resposta seja sim o programa continua.
    printf("\n (\\_/)     -----------------------------------");
    printf("\n (°.°)     | PROGRAMA PARA AGENDAR CONSULTAS |");
    printf("\n c(”)(”)   -----------------------------------");
    printf("\n\n          Há %d agendamento(s) disponível(eis)", TAM);
    printf("\n          --------------------------------------");
	printf("\n\n\n            Agendar nova consulta? (S/N): ");
	fflush(stdin);
	scanf("%c",&opc);

	if (opc=='s'||opc=='S'){ // if responsável pelo caso da resposta ser sim (sS).
        for (i=0;i<TAM;i++){ // repetição responsável por incrementar o i (e demais variáveis) a cada agendamento efetuado.
	        system("CLS");
	        fflush(stdin);
	        printf("\n    AGENDAR CONSULTA %d/%d", i+1, TAM);
	        printf("\n ----------------------------\n");
	        printf("\n DADOS PESSOAIS:");
	        printf("\n\n\n Nome: ");
	        gets(agendar[i].nome);
	        printf("\n Sexo(m/f): ");
	        scanf("%c", &agendar[i].sexo);
            fflush(stdin);
	        printf("\n Data de Nascimento");
	        printf("\n\n Dia: ");
	        scanf("%d", &agendar[i].dtnascimento.dia);
	        printf("\n Mês: ");
	        scanf("%d", &agendar[i].dtnascimento.mes);
	        printf("\n Ano: ");
	        scanf("%d", &agendar[i].dtnascimento.ano);
	        system("CLS");
            printf("\n    AGENDAR CONSULTA %d/%d", i+1, TAM);
	        printf("\n ----------------------------\n");
	        printf("\n DADOS DA CONSULTA:");
	        printf("\n\n Dia: ");
	        scanf("%d", &agendar[i].dtconsulta.dia);
	        printf("\n Mês: ");
	        scanf("%d", &agendar[i].dtconsulta.mes);
	        printf("\n Ano: ");
	        scanf("%d", &agendar[i].dtconsulta.ano);
	        printf("\n Hora: ");
	        scanf("%d", &agendar[i].horarioconsulta.horas);
	        printf("\n Minuto: ");
	        scanf("%d", &agendar[i].horarioconsulta.minuto);
	        aux++;

			for(j=0;j<cont;j++){ //"For" responsável pela repetição que irá comparar os dados armazenados nas structs


	        if (agendar[i].dtconsulta.dia==agendar[j].dtconsulta.dia && //if responsável por determinar a condição em caso de agendamentos efetuados na mesma data/horário
	            agendar[i].dtconsulta.mes==agendar[j].dtconsulta.mes &&
	            agendar[i].dtconsulta.ano==agendar[j].dtconsulta.ano &&
	            agendar[i].horarioconsulta.horas==agendar[j].horarioconsulta.horas &&
	            agendar[i].horarioconsulta.minuto==agendar[j].horarioconsulta.minuto){
				system ("CLS");
				printf("\n Agendamento indisponível nesta data e horario!!!");
	            printf("\n\n\n");
			    i--;
	            cont--;
	            aux--;
	            system("PAUSE");
	        }

	 	 }
cont++;
system("CLS");
opc2=' ';

while(strchr("SsNn", opc2)==NULL && i<TAM){ /*Este 2º while é responsável pela condição da resposta da 2º opção "opc2", caso a resposta seja sim e o usuário
											ainda não tenha alcançado o limite de agendamentos, o programa continua.*/

	if (i<TAM){ //if responsável por determinar o que ocorrerá caso o usuário não tenha alcançado ainda o limite de agendamentos
	    printf("\n\n Deseja efetuar um novo agendamento? (S/N): ");
	    fflush(stdin);
	    scanf("%c", &opc2);
	    printf("\n\n");

	    if(opc2=='s'||opc2=='S'){ //if responsável por deterinar o que ocorrerá caso o usuário responda sim na "opc2" mas já tenha alcançado o limite de agendamentos

			if(i<=TAM-1){
	        	system("PAUSE");
	    }

//ATÉ AQUI É O QUE FOI EXIGIDO NO ENUNCIADO.

//O RESTO A PARTIR DAQUI FOI ADICIONADO POR PREFERÊNCIA.

	    if(i==TAM-1){ //Caso o usuário já tenha acançado o limite de agendamentos, o mesmo será redirecionado para outra pergunta
			system("CLS");
			while(strchr("SsNn", opc3)==NULL){//Este 3º while é responsável pela condição da resposta da 3º opção, "opc3".
				printf("\n Você já alcançou o limite de agendamentos (%d/%d).", i+1, TAM);
				printf("\n ------------------------------------------------\n");
				printf("\n\n Deseja ver os agendamentos efetuados? (S/N): ");
				fflush(stdin);
			    scanf("%c", &opc3); //Caso a resposta seja sim o programa mostrará na tela todos os agendamentos efetuados.

				if(opc3=='s'||opc3=='S'){//if responsável pelo que ocorrerá em caso de resposta sim (s ou S) na "opc3".
					system("CLS");
				 	printf("\n (\\_/)     -----------------------------------");
   				 	printf("\n (°.°)     |       CONSULTAS AGENDADAS       |");
    			 	printf("\n c(”)(”)   -----------------------------------");
					i=0;
					j=0;
                	while (i!=aux){//while responsável por mostrar na tela os agendamentos efetuados
					printf("\n\n----------------------------\n");
	                printf(" PACIENTE %d", j+1);
					printf("\n\n");
					printf(" DADOS PESSOAIS");
					printf("\n\n");
					printf(" Nome: %s", agendar[i].nome);
					printf("\n Sexo: %c", agendar[i].sexo);
					printf("\n Data de Nascimento: %d/%d/%d", agendar[i].dtnascimento.dia, agendar[i].dtnascimento.mes, agendar[i].dtnascimento.ano);
					printf("\n\n DADOS DA CONSULTA");
					printf("\n\n Data da consulta: %d/%d/%d", agendar[i].dtconsulta.dia, agendar[i].dtconsulta.mes, agendar[i].dtconsulta.ano);
					printf("\n Horario da consulta: %d:%d", agendar[i].horarioconsulta.horas, agendar[i].horarioconsulta.minuto);
					printf("\n\n");

                    j++;
					i++;
	                }


                return 0;
                }

				if(opc3=='n'||opc3=='N'){ //if responsável pelo que ocorrerá em caso de resposta não (n ou N) na "opc3".
					printf("\n\n SESSAO ENCERRADA.\n\n");
					return 0;
			    }

	        }//fim do 3º while ("opc3").

		}//fim do if (limite de agendamentos ALCANÇADO).

	    }//fim do if ("opc2" s/S).

	    if(opc2=='n'||opc2=='N'){// if responsável por deterinar o que ocorrerá caso o usuário responda NÃO na opc2.
			system("CLS");
			while(strchr("SsNn", opc3)==NULL){//Este 3º while só valerá caso o usuário responda NÃO (n ou N) na "opc2" e é responsável pela condição da resposta da 3º opção "opc3".
			printf("\n\n Pronto. Deseja ver os agendamentos efetuados? (S/N): ");
			fflush(stdin);
			scanf("%c", &opc3);

			if(opc3=='s'||opc3=='S'){//Caso a resposta da 'opc3" seja Sim (S ou s), o programa mostrará na tela os agendamentos efetuados
				system("CLS");
				 printf("\n (\\_/)     -----------------------------------");
   				 printf("\n (°.°)     |       CONSULTAS AGENDADAS       |");
    			 printf("\n c(”)(”)   -----------------------------------");
				i=0;
				j=0;
                while (i!=aux){
					printf("\n\n----------------------------\n");
	                printf(" PACIENTE %d", j+1);
					printf("\n\n");
					printf(" DADOS PESSOAIS");
					printf("\n\n");
					printf(" Nome: %s", agendar[i].nome);
					printf("\n Sexo: %c", agendar[i].sexo);
					printf("\n Data de Nascimento: %d/%d/%d", agendar[i].dtnascimento.dia, agendar[i].dtnascimento.mes, agendar[i].dtnascimento.ano);
					printf("\n\n DADOS DA CONSULTA");
					printf("\n\n Data da consulta: %d/%d/%d", agendar[i].dtconsulta.dia, agendar[i].dtconsulta.mes, agendar[i].dtconsulta.ano);
					printf("\n Horario da consulta: %d:%d", agendar[i].horarioconsulta.horas, agendar[i].horarioconsulta.minuto);
					printf("\n\n");

                    j++;
					i++;
	                }


                return 0;
            }//fim do if ("opc3" s/S) **CASO O USUÁRIO NÃO TENHA ALCANÇADO O LIMITE DE AGENDAMENTOS.

		if(opc3=='n'||opc3=='N'){//Caso a resposta da "opc3" seja não, o programa encerra.
			system("CLS");
			printf("\n\n SESSÃO ENCERRADA.\n\n");
			return 0;
		}

			}//fim do 3º while ("opc3") **SÓ VALERÁ CASO A RESPOSTA DA "opc2" SEJA NÃO (n/N).

	    }//fim do if ("opc2" n/N).

	}//fim do if (limite de agendamentos NÃO ALCANÇADO).

}//fim do 2º while ("opc2").

        }//fim do 1º for (incrementador de agendamentos).

    } //fim do 1º if "opc" (s/S).

	if (opc=='n'||opc=='N'){ //Caso a resposta da 1ª opcão "opc" seja não, o programa encerra.
		printf("\n\n SESSÃO ENCERRADA.\n\n");
	    return 0;
    }

}//fim do 1º while("opc").


return 0;
} //FIM DO PROGRAMA.


