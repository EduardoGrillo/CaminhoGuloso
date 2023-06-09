#include "verifica.h"

void leitura(int**m, int t) {
	FILE *file = fopen("matriz/leitura.txt", "r");

	char *result, linha[100];
    
    int cont = 0;
    int convert, coluna;
    int aux = 0;
    int aux2 = 0;

	if (file == NULL) {
		printf("Nao foi possivel abrir o arquivo\n");
	} else {
		while (!feof(file)) {
			result = fgets(linha, sizeof(linha), file);

			if (result && aux == 1) {
                if(strlen(linha) > 1){
                    const char sep[] = " ";
                    char *tokens;
                    coluna = 0;

                    tokens = strtok(linha, sep);

                    while (tokens != NULL) {
                        convert = atoi(tokens);
                        m[cont][coluna] = convert;
                        tokens = strtok(NULL, sep);

                        coluna++;
                    }
                    cont++;

                    if(cont == t){
                        for(int i = 0;i < t;i++){
                            for(int j = 0;j < t;j++){
                                printf("%d ", m[i][j]);
                            }
                            printf("\n");
                        }
                        printf("\n");
                        verifica(t, m);

                        for(int i = 0;i < t;i++){
                            for(int j = 0;j < t;j++){
                                printf("%d ", m[i][j]);
                            }
                            printf("\n");
                        }
                        printf("\n");
                    }
                } else {
                    cont = 0;
                }
			}
            aux = 1;
		}
	}
	fclose(file);
}

int tamanho(){
    FILE *file = fopen("matriz/leitura.txt", "r");
    int cont = 0;
	char *result, linha[100];

	if (file == NULL) {
		printf("Nao foi possivel abrir o arquivo\n");
	} else {
		while (!feof(file)) {
			result = fgets(linha, sizeof(linha), file);

			if (result) {
                const char sep[] = " ";
                char *tokens;

                tokens = strtok(linha, sep);

                while (tokens != NULL) {
                    fclose(file);
                    return atoi(tokens);
                }
			}
		}
	}
	fclose(file);
    return 0;
}


