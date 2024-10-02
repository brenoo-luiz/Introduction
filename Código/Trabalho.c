#include<stdio.h>
#include<locale.h>

float clientes[10], tiposervico[10], valor[10], servicos[10][3];
int clientesTotais = 0;

void lerCodigoClientes(){
	int i;
	printf("Informe os códigos do cliente, e, caso deseje encerrar, digite o número -1.\n");
	for(i=0; i<10; i++){
		scanf("%f", &clientes[i]);
		clientesTotais = i;
		servicos[i][0] = clientes[i];
		if (clientes[i] == -1){
		  	break;
		} 
	}
}

void lerCodigosTipoServico(){
	int i;
	printf("Informe os códigos do tipo de servico. \n");
	for(i=0; i<clientesTotais; i++){
		scanf("%f", &tiposervico[i]);
		servicos[i][1] = tiposervico[i];
	}
}

void lerValor(){
	int i;
	printf("Informe o valor de cada serviço. \n");
	for (i=0; i<clientesTotais; i++) {
		scanf("%f", &valor[i]);
		servicos[i][2] = valor[i];
	}
}

void valorCliente() {
	float cliente, valorTotal;
	int i;
	printf("Digite o código do cliente a ser analisado. \n");
	scanf("%f", &cliente);
	for (i=0; i<clientesTotais; i++) {
		if (cliente==servicos[i][0]) {
			valorTotal += servicos[i][2];
		}
	}
	printf("Valor total gasto pelo cliente %.0f: %.2f \n", cliente, valorTotal);
}

void valorMedioCliente() {
	int i;
	float total = 0, media = 0;
	for(i=0; i<clientesTotais; i++) {
		total = total + servicos[i][2];	
	}
	media = total/clientesTotais; 
	printf("O valor médio gasto por cliente foi de %.2f\n", media);
}

void valorTodosServicos() {
    int i, j;
    float matrizValores[10][2] = {0};
    for (i = 0; i < clientesTotais; i++) {
        int encontrado = 0;
        for (j = 0; j < clientesTotais; j++) {
            if (servicos[i][1] == matrizValores[j][0]) {
                matrizValores[j][1] += servicos[i][2];
                encontrado = 1;
                break;
            }
        }
        if (!encontrado) {
            for (j = 0; j < clientesTotais; j++) {
                if (matrizValores[j][0] == 0) {
                    matrizValores[j][0] = servicos[i][1];
                    matrizValores[j][1] = servicos[i][2];
                    break;
                }
            }
        }
    }
    for (i = 0; i < clientesTotais; i++) {
        if (matrizValores[i][0] != 0) {
            printf("Tipo de serviço: %.0f, Faturamento: %.2f\n", matrizValores[i][0], matrizValores[i][1]);
        }
    }
}

void maiorFaturamento() {
	int tipoServico = -1;
	int i, j;
	float maiorValor = 0;
	float faturamentoTotal[10] = {0};
	float matrizValores[10][2] = {0};
	for (i = 0; i < clientesTotais; i++) {
		faturamentoTotal[i] += servicos[i][2];
	}
	for (i = 0; i < clientesTotais; i++) {
		if (faturamentoTotal[i] > 0) {
			for (j = 0; j < clientesTotais; j++) {
				if (matrizValores[j][0] == 0) {
					matrizValores[j][0] = servicos[i][1];
					matrizValores[j][1] += faturamentoTotal[i];
					break;
				} else if (matrizValores[j][0] == servicos[i][1]) {
					matrizValores[j][1] += faturamentoTotal[i];
					break;
				}
			}
		}
	}
	for (i = 0; i < clientesTotais; i++) {
		if (matrizValores[i][1] > maiorValor) {
			maiorValor = matrizValores[i][1];
			tipoServico = matrizValores[i][0];
		}
	}
	printf("O serviço que obteve maior faturamento foi o %i, com um faturamento total de %.2f\n", tipoServico, maiorValor);
}

int main(){
	setlocale(LC_ALL, "Portuguese");
	int i, j;
	lerCodigoClientes();
	lerCodigosTipoServico();
	lerValor();
	valorCliente();
	valorMedioCliente();
	valorTodosServicos();
	maiorFaturamento();
	for (i=0; i<clientesTotais; i++) {
		for (j=0; j<3; j++) {
			printf("%.1f ", servicos[i][j]);	
		}
		printf("\n");
	}
 	return 0;
}
