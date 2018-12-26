/*1.Fa�a um programa para auxiliar uma clinica m�dica. O seu programa deve marcar consultas,
sabendo que a clinica permite no m�ximo 10000 consultas e para cada consulta s�o necess�rios os seguintes campos:
Nome Paciente, Sexo Paciente, Data de Nascimento (Dia, M�s e Ano), Data da Consulta (Dia, M�s, Ano e Hora). Detalhe,
o seu programa deve evitar que duas consultas sejam marcadas para a mesma data e hora.

AUTORIA:
Luan Vitor Mantelo do Bonfim  
Jogos Digitais.*/

//Inclus�o das bibliotecas necess�rias
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#define  TAM 10000

//Declara��o das structs necess�rias
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
//Declara��o das vari�veis necess�rias
setlocale(LC_ALL, "portuguese");
consulta agendar[TAM];
int i=0,j=0,cont=0, aux=0;
char opc=' ', opc2=' ', opc3=' ';

while (strchr("sSnN", opc) ==NULL){ //Este 1� while � respons�vel pela condi��o da 1� op��o "opc", caso a resposta seja sim o programa continua.
    printf("\n (\\_/)     -----------------------------------");
    printf("\n (�.�)     | PROGRAMA PARA AGENDAR CONSULTAS |");
    printf("\n c(�)(�)   -----------------------------------");
    printf("\n\n          H� %d agendamento(s) dispon�vel(eis)", TAM);
    printf("\n          --------------------------------------");
	printf("\n\n\n            Agendar nova consulta? (S/N): ");
	fflush(stdin);
	scanf("%c",&opc);

	if (opc=='s'||opc=='S'){ // if respons�vel pelo caso da resposta ser sim (sS).
        for (i=0;i<TAM;i++){ // repeti��o respons�vel por incrementar o i (e demais vari�veis) a cada agendamento efetuado.
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
	        printf("\n M�s: ");
	        scanf("%d", &agendar[i].dtnascimento.mes);
	        printf("\n Ano: ");
	        scanf("%d", &agendar[i].dtnascimento.ano);
	        system("CLS");
            printf("\n    AGENDAR CONSULTA %d/%d", i+1, TAM);
	        printf("\n ----------------------------\n");
	        printf("\n DADOS DA CONSULTA:");
	        printf("\n\n Dia: ");
	        scanf("%d", &agendar[i].dtconsulta.dia);
	        printf("\n M�s: ");
	        scanf("%d", &agendar[i].dtconsulta.mes);
	        printf("\n Ano: ");
	        scanf("%d", &agendar[i].dtconsulta.ano);
	        printf("\n Hora: ");
	        scanf("%d", &agendar[i].horarioconsulta.horas);
	        printf("\n Minuto: ");
	        scanf("%d", &agendar[i].horarioconsulta.minuto);
	        aux++;

			for(j=0;j<cont;j++){ //"For" respons�vel pela repeti��o que ir� comparar os dados armazenados nas structs


	        if (agendar[i].dtconsulta.dia==agendar[j].dtconsulta.dia && //if respons�vel por determinar a condi��o em caso de agendamentos efetuados na mesma data/hor�rio
	            agendar[i].dtconsulta.mes==agendar[j].dtconsulta.mes &&
	            agendar[i].dtconsulta.ano==agendar[j].dtconsulta.ano &&
	            agendar[i].horarioconsulta.horas==agendar[j].horarioconsulta.horas &&
	            agendar[i].horarioconsulta.minuto==agendar[j].horarioconsulta.minuto){
				system ("CLS");
				printf("\n Agendamento indispon�vel nesta data e horario!!!");
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

while(strchr("SsNn", opc2)==NULL && i<TAM){ /*Este 2� while � respons�vel pela condi��o da resposta da 2� op��o "opc2", caso a resposta seja sim e o usu�rio
											ainda n�o tenha alcan�ado o limite de agendamentos, o programa continua.*/

	if (i<TAM){ //if respons�vel por determinar o que ocorrer� caso o usu�rio n�o tenha alcan�ado ainda o limite de agendamentos
	    printf("\n\n Deseja efetuar um novo agendamento? (S/N): ");
	    fflush(stdin);
	    scanf("%c", &opc2);
	    printf("\n\n");

	    if(opc2=='s'||opc2=='S'){ //if respons�vel por deterinar o que ocorrer� caso o usu�rio responda sim na "opc2" mas j� tenha alcan�ado o limite de agendamentos

			if(i<=TAM-1){
	        	system("PAUSE");
	    }

//AT� AQUI � O QUE FOI EXIGIDO NO ENUNCIADO.

//O RESTO A PARTIR DAQUI FOI ADICIONADO POR PREFER�NCIA.

	    if(i==TAM-1){ //Caso o usu�rio j� tenha acan�ado o limite de agendamentos, o mesmo ser� redirecionado para outra pergunta
			system("CLS");
			while(strchr("SsNn", opc3)==NULL){//Este 3� while � respons�vel pela condi��o da resposta da 3� op��o, "opc3".
				printf("\n Voc� j� alcan�ou o limite de agendamentos (%d/%d).", i+1, TAM);
				printf("\n ------------------------------------------------\n");
				printf("\n\n Deseja ver os agendamentos efetuados? (S/N): ");
				fflush(stdin);
			    scanf("%c", &opc3); //Caso a resposta seja sim o programa mostrar� na tela todos os agendamentos efetuados.

				if(opc3=='s'||opc3=='S'){//if respons�vel pelo que ocorrer� em caso de resposta sim (s ou S) na "opc3".
					system("CLS");
				 	printf("\n (\\_/)     -----------------------------------");
   				 	printf("\n (�.�)     |       CONSULTAS AGENDADAS       |");
    			 	printf("\n c(�)(�)   -----------------------------------");
					i=0;
					j=0;
                	while (i!=aux){//while respons�vel por mostrar na tela os agendamentos efetuados
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

				if(opc3=='n'||opc3=='N'){ //if respons�vel pelo que ocorrer� em caso de resposta n�o (n ou N) na "opc3".
					printf("\n\n SESSAO ENCERRADA.\n\n");
					return 0;
			    }

	        }//fim do 3� while ("opc3").

		}//fim do if (limite de agendamentos ALCAN�ADO).

	    }//fim do if ("opc2" s/S).

	    if(opc2=='n'||opc2=='N'){// if respons�vel por deterinar o que ocorrer� caso o usu�rio responda N�O na opc2.
			system("CLS");
			while(strchr("SsNn", opc3)==NULL){//Este 3� while s� valer� caso o usu�rio responda N�O (n ou N) na "opc2" e � respons�vel pela condi��o da resposta da 3� op��o "opc3".
			printf("\n\n Pronto. Deseja ver os agendamentos efetuados? (S/N): ");
			fflush(stdin);
			scanf("%c", &opc3);

			if(opc3=='s'||opc3=='S'){//Caso a resposta da 'opc3" seja Sim (S ou s), o programa mostrar� na tela os agendamentos efetuados
				system("CLS");
				 printf("\n (\\_/)     -----------------------------------");
   				 printf("\n (�.�)     |       CONSULTAS AGENDADAS       |");
    			 printf("\n c(�)(�)   -----------------------------------");
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
            }//fim do if ("opc3" s/S) **CASO O USU�RIO N�O TENHA ALCAN�ADO O LIMITE DE AGENDAMENTOS.

		if(opc3=='n'||opc3=='N'){//Caso a resposta da "opc3" seja n�o, o programa encerra.
			system("CLS");
			printf("\n\n SESS�O ENCERRADA.\n\n");
			return 0;
		}

			}//fim do 3� while ("opc3") **S� VALER� CASO A RESPOSTA DA "opc2" SEJA N�O (n/N).

	    }//fim do if ("opc2" n/N).

	}//fim do if (limite de agendamentos N�O ALCAN�ADO).

}//fim do 2� while ("opc2").

        }//fim do 1� for (incrementador de agendamentos).

    } //fim do 1� if "opc" (s/S).

	if (opc=='n'||opc=='N'){ //Caso a resposta da 1� opc�o "opc" seja n�o, o programa encerra.
		printf("\n\n SESS�O ENCERRADA.\n\n");
	    return 0;
    }

}//fim do 1� while("opc").


return 0;
} //FIM DO PROGRAMA.


