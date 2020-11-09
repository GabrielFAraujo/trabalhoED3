#include <stdio.h>
#include <stdlib.h>

void binarioNaTela1(char *nomeArquivoBinario, char *nomeArquivoIndice) {

	/* Use essa fun��o para compara��o no run.codes. Lembre-se de ter fechado (fclose) o arquivo anteriormente.
	*  Ela vai abrir de novo para leitura e depois fechar (voc� n�o vai perder pontos por isso se usar ela). */

	unsigned long i, cs;
	unsigned char *mb;
	FILE *fs, *fi;
	size_t fl;
	if(nomeArquivoBinario == NULL || !(fs = fopen(nomeArquivoBinario, "rb"))) {
		fprintf(stderr, "ERRO NA FUN��O BINARIO NA TELA. N�o se esque�a do fclose e verifique se passou o argumento corretamente!\n");
		return;
	}
	if(nomeArquivoIndice == NULL || !(fi = fopen(nomeArquivoIndice, "rb"))) {
		fprintf(stderr, "ERRO NA FUN��O BINARIO NA TELA. N�o se esque�a do fclose e verifique se passou o argumento corretamente!\n");
		return;
	}
	fseek(fs, 0, SEEK_END);
	fl = ftell(fs);
	fseek(fs, 0, SEEK_SET);
	mb = (unsigned char *) malloc(fl);
	fread(mb, 1, fl, fs);
	fclose(fs);
	cs = fl;
	for(i = 0; i < fl; i++) {
		cs += (unsigned long) mb[i];
	}
	fseek(fi, 0, SEEK_END);
	fl = ftell(fi);
	fseek(fi, 0, SEEK_SET);
	mb = (unsigned char *) realloc(mb, fl);
	fread(mb, 1, fl, fi);
	fclose(fi);
	cs += fl;
	for(i = 0; i < fl; i++) {
		cs += (unsigned long) mb[i];
	}
	printf("%lf\n", (cs / (double) 100));
	free(mb);
}



void trim(char *str) {

	/*
	*	Essa fun��o arruma uma string de entrada "str".
	*	Manda pra ela uma string que tem '\r' e ela retorna sem.
	*	Ela remove do in�cio e do fim da string todo tipo de espa�amento (\r, \n, \t, espa�o, ...).
	*	Por exemplo:
	*
	*	char minhaString[] = "    \t TESTE  DE STRING COM BARRA R     \t  \r\n ";
	*	trim(minhaString);
	*	printf("[%s]", minhaString); // vai imprimir "[TESTE  DE STRING COM BARRA R]"
	*
	*/

	size_t len;
	char *p;

	// remove espa�amentos do fim
	for(len = strlen(str); len > 0 && isspace(str[len - 1]); len--);
	str[len] = '\0';

	// remove espa�amentos do come�o
	for(p = str; *p != '\0' && isspace(*p); p++);
	len = strlen(p);

	memmove(str, p, sizeof(char) * (len + 1));
}



void scan_quote_string(char *str) {

	/*
	*	Use essa fun��o para ler um campo string delimitado entre aspas (").
	*	Chame ela na hora que for ler tal campo. Por exemplo:
	*
	*	A entrada est� da seguinte forma:
	*		nomeDoCampo "MARIA DA SILVA"
	*
	*	Para ler isso para as strings j� alocadas str1 e str2 do seu programa, voc� faz:
	*		scanf("%s", str1); // Vai salvar nomeDoCampo em str1
	*		scan_quote_string(str2); // Vai salvar MARIA DA SILVA em str2 (sem as aspas)
	*
	*/

	char R;

	while((R = getchar()) != EOF && isspace(R)); // ignorar espa�os, \r, \n...

	if(R == 'N' || R == 'n') { // campo NULO
		getchar(); getchar(); getchar(); // ignorar o "ULO" de NULO.
		strcpy(str, ""); // copia string vazia
	} else if(R == '\"') {
		if(scanf("%[^\"]", str) != 1) { // ler at� o fechamento das aspas
			strcpy(str, "");
		}
		getchar(); // ignorar aspas fechando
	} else if(R != EOF){ // vc t� tentando ler uma string que n�o t� entre aspas! Fazer leitura normal %s ent�o...
		*str = R;
		str++;
		while((R = getchar()) != EOF && !isspace(R)) {
			*str = R;
			str++;
		}
		*str = '\0';
	} else { // EOF
		strcpy(str, "");
	}
}

int main()
{
    int indice;
    FILE *arqEnt, *arqP, *arqIndP;

    while(scanf("%d", &indice) != 0)
    {
        //Funcionalidades
        switch(indice)
        {
            case 1:
                arqEnt = fopen("arquivoEntrada.csv",r);

                if(arqEnt == NULL) {
                    printf("Arquivo invalido!");
                }

                arqP = fopen("arquivoPessoa.bin",wb);
                arqIndP = fopen("arquivoIndexaPessoa.bin",wb);


            case 2:
                break;
            case 3:
                break;
            case 4:
                break;
            case 5:
                break;
        }
    }
    return 0;
}
