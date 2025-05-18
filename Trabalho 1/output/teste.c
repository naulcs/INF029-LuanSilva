#include <stdio.h>
#include <string.h>

typedef struct DQ
{
    int iDia; 
    int iMes;
    int iAno;
    int valido; // 0 se inválido, e 1 se válido 

} DataQuebrada;

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


        printf("%d \n%d \n%d \n", dq.iDia, dq.iMes, dq.iAno);

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

    printf("%d\n", datavalida);

    if (datavalida)
        return 1;
    else
        return 0;
}

int main()
{
    char data[11];

    // quebrar a string data em strings sDia, sMes, sAno
    printf("Digite a data (DD/MM/AAAA): ");
    fgets(data, sizeof(data), stdin);

    q1(data);
}



	


