#include <stdio.h>
#include <math.h>

int unidade(int);
int dezena(int, int);
int centena(int, int, int, int);

int main(){
    float valor;
    int valorInteiro, unidadeInteiro, dezenaInteiro, centenaInteiro, milharInteiro, centavosInteiro, centavo1, centavo2;

    printf("Informe um valor numerico em reais entre 0 e 9999.99 (0 para finalizar): R$");
    scanf("%f", &valor);

    while (valor != 0){
        //Separando os digitos inteiros
        valorInteiro = (int) floorf(valor);
        unidadeInteiro = valorInteiro % 10;
        dezenaInteiro = (valorInteiro % 100) / 10;
        centenaInteiro = (valorInteiro % 1000) / 100;
        milharInteiro = (valorInteiro % 10000) / 1000;

        //Separando os centavos
        centavosInteiro = (roundf(valor * 100));
        centavo1 = (centavosInteiro % 100) / 10;
        centavo2 = centavosInteiro % 10;

       //Escrevendo a parte inteira do numero
        if (milharInteiro != 0){
            unidade(milharInteiro);
            printf(" mil");}
        centena(milharInteiro, centenaInteiro, dezenaInteiro, unidadeInteiro);

        if ((dezenaInteiro != 0) && ((centenaInteiro != 0) || (milharInteiro != 0)))
            printf(" e ");
        dezena(dezenaInteiro, unidadeInteiro);

        if ((unidadeInteiro != 0) && ((milharInteiro != 0) || (centenaInteiro != 0) || (dezenaInteiro >= 2)))
                printf(" e ");
        if (dezenaInteiro != 1)
            unidade(unidadeInteiro);
        if (valorInteiro > 1)
            printf(" reais");
        if (valorInteiro == 1)
            printf(" real");

        //Escrevendo a parte fracionaria do numero
        if((centavo1 != 0) || (centavo2 != 0)){
            if (valorInteiro != 0){
                printf(" e ");}
            dezena(centavo1, centavo2);
            if((centavo2 != 0) && ((centavo1 != 1) && (centavo1 != 0))){
                printf(" e ");
                unidade(centavo2);}
            if((centavo2 != 0) && (centavo1 == 0)){
                unidade(centavo2);}
            if((centavo1 == 0) && (centavo2 == 1))
                printf(" centavo");
            else
                printf(" centavos");}
        printf("\n");
        printf("\nInforme um valor numerico em reais entre 0 e 9999.99 (0 para finalizar): R$");
        scanf("%f", &valor);
    }
    printf("Fim do programa. Volte sempre!\n");
    return 0;}

int unidade(int a){
    switch(a){
        case 1:
            printf("um");
            break;
        case 2:
            printf("dois");
            break;
        case 3:
            printf("tres");
            break;
        case 4:
            printf("quatro");
            break;
        case 5:
            printf("cinco");
            break;
        case 6:
            printf("seis");
            break;
        case 7:
            printf("sete");
            break;
        case 8:
            printf("oito");
            break;
        case 9:
            printf("nove");
            break;}
    return 0;}

int dezena(int z, int j){
    if (z == 1){
    switch(j){
    case 0:
        printf("dez");
        break;
    case 1:
        printf("onze");
        break;
    case 2:
        printf("doze");
        break;
    case 3:
        printf("treze");
        break;
    case 4:
        printf("quatorze");
        break;
    case 5:
        printf("quinze");
        break;
    case 6:
        printf("dezesseis");
        break;
    case 7:
        printf("dezessete");
        break;
    case 8:
        printf("dezoito");
        break;
    case 9:
        printf("dezenove");
        break;}
    }else{
        switch(z){
        case 2:
            printf("vinte");
            break;
        case 3:
            printf("trinta");
            break;
        case 4:
            printf("quarenta");
            break;
        case 5:
            printf("cinquenta");
            break;
        case 6:
            printf("sessenta");
            break;
        case 7:
            printf("setenta");
            break;
        case 8:
            printf("oitenta");
            break;
        case 9:
            printf("noventa");
            break;}   }
    return 0;}

int centena(int m, int w, int p, int q){
    if ((w == 1) && (p == 0) && (q == 0)){
        printf("cem");}
    if ((w == 1) && ((p != 0) || (q != 0))){
        printf("cento");}
    if ((m != 0) && (w != 0)){
        printf(" e ");}
    if (w > 1){
        switch(w){
        case 2:
            printf("duzentos");
            break;
        case 3:
            printf("trezentos");
            break;
        case 4:
            printf("quatrocentos");
            break;
        case 5:
            printf("quinhentos");
            break;
        case 6:
            printf("seiscentos");
            break;
        case 7:
            printf("setecentos");
            break;
        case 8:
            printf("oitocentos");
            break;
        case 9:
            printf("novecentos");
            break;}   }
    return 0;}
