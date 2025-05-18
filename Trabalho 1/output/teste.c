#include <stdio.h>
#include <string.h>

typedef struct DQ
{
    int iDia; 
    int iMes;
    int iAno;
    int valido; // 0 se inválido, e 1 se válido 

} DataQuebrada;

typedef struct Qtd
{
    int qtdDias;
    int qtdMeses;
    int qtdAnos;
    int retorno;

} DiasMesesAnos;

DataQuebrada quebraData(char data[]){
  DataQuebrada dq;
  char sDia[3];
	char sMes[3];
	char sAno[5];
	int i; 

	for (i = 0; data[i] != '/'; i++){
		sDia[i] = data[i];	
	}
	if(i == 1 || i == 2){ // testa se tem 1 ou dois digitos
		sDia[i] = '\0';  // coloca o barra zero no final
	}else {
		dq.valido = 0;
    return dq;
  }  
	

	int j = i + 1; //anda 1 cada para pular a barra
	i = 0;

	for (; data[j] != '/'; j++){
		sMes[i] = data[j];
		i++;
	}

	if(i == 1 || i == 2){ // testa se tem 1 ou dois digitos
		sMes[i] = '\0';  // coloca o barra zero no final
	}else {
		dq.valido = 0;
    return dq;
  }
	j = j + 1; //anda 1 cada para pular a barra
	i = 0;
	
	for(; data[j] != '\0'; j++){
	 	sAno[i] = data[j];
	 	i++;
	}

	if(i == 2 || i == 4){ // testa se tem 2 ou 4 digitos
		sAno[i] = '\0';  // coloca o barra zero no final
	}else {
		dq.valido = 0;
    return dq;
  }

  dq.iDia = atoi(sDia);
  dq.iMes = atoi(sMes);
  dq.iAno = atoi(sAno); 

	dq.valido = 1;
    
  return dq;
}

int q1(char data[])
{
    int datavalida = 1;
 
DataQuebrada dq = quebraData (data);


 int diasMes[] = { 0,31,28,31,30,31,30,31,31,30,31,30,31 };

        if (dq.iAno <= 0 || dq.iAno > 2025 || dq.iMes < 1 || dq.iMes > 12)
            datavalida = 0;

        // Bissexto
        if (dq.iMes == 2) {
            if ((dq.iAno % 4 == 0 && dq.iAno % 100 != 0) || (dq.iAno % 400 == 0)) {
                diasMes[2] = 29;
            }
        }

        if (dq.iDia < 1 || dq.iDia > diasMes[dq.iMes])
            datavalida = 0;

    if (datavalida)
        return 1;
    else
        return 0;
}

DiasMesesAnos q2(char datainicial[], char datafinal[]) {
    DiasMesesAnos dma;

    if (q1(datainicial) == 0) {
        dma.retorno = 2;
        return dma;
    } else if (q1(datafinal) == 0) {
        dma.retorno = 3;
        return dma;
    } else {
        DataQuebrada inicio = quebraData(datainicial);
        DataQuebrada fim = quebraData(datafinal);

        // Verifica se a data final é anterior à inicial
        if (
            fim.iAno < inicio.iAno ||
            (fim.iAno == inicio.iAno && fim.iMes < inicio.iMes) ||
            (fim.iAno == inicio.iAno && fim.iMes == inicio.iMes && fim.iDia < inicio.iDia)
        ) {
            dma.retorno = 3;
            return dma;
        }

        // Calcular diferença
        int anos = fim.iAno - inicio.iAno;
        int meses = fim.iMes - inicio.iMes;
        int dias = fim.iDia - inicio.iDia;

        if (dias < 0) {
            // Descobrir quantos dias teve o mês anterior a fim.iMes
            int mesAnterior = fim.iMes - 1;
            int anoAux = fim.iAno;

            if (mesAnterior == 0) {
                mesAnterior = 12;
                anoAux--;
            }

            int diasMesAnterior;
            if (mesAnterior == 2) {
                if ((anoAux % 4 == 0 && anoAux % 100 != 0) || (anoAux % 400 == 0)) {
                    diasMesAnterior = 29;
                } else {
                    diasMesAnterior = 28;
                }
            } else if (mesAnterior == 4 || mesAnterior == 6 || mesAnterior == 9 || mesAnterior == 11) {
                diasMesAnterior = 30;
            } else {
                diasMesAnterior = 31;
            }

            dias += diasMesAnterior;
            meses--;
        }

        if (meses < 0) {
            meses += 12;
            anos--;
        }

        dma.qtdAnos = anos;
        dma.qtdMeses = meses;
        dma.qtdDias = dias;
        dma.retorno = 1;

        return dma;
    }
}

int main()
{
    char data1[11], data2[11];

    printf("Digite a data inicial: ");
    fgets(data1, sizeof(data1), stdin);
    data1[strcspn(data1, "\n")] = '\0';  // REMOVE \n

    printf("Digite a data final: ");
    fgets(data2, sizeof(data2), stdin);
    data2[strcspn(data2, "\n")] = '\0';  // REMOVE \n

    DiasMesesAnos resultado = q2(data1, data2);

    if (resultado.retorno == 1)
    {
        printf("Diferença: %d anos, %d meses, %d dias.\n",
               resultado.qtdAnos, resultado.qtdMeses, resultado.qtdDias);
    }
    else if (resultado.retorno == 2)
    {
        printf("Data inicial inválida.\n");
    }
    else if (resultado.retorno == 3)
    {
        printf("Data final inválida ou anterior à data inicial.\n");
    }

    return 0;
}


	


