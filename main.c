#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int menu()
{
    printf("\n\n1 - SOMA");
    printf("\n2 - SUBTRAÇÃO");
    printf("\n3 - MULTIPLICAÇÃO");
    printf("\n4 - DIVISÃO");
    printf("\n5 - SAIR");
}

enum menu{
    MENU_SOMA = 1,
    MENU_SUBTRACAO,
    MENU_MULTIPLICACAO,
    MENU_DIVISAO,
};

void soma(char bin1[], char bin2[], int l1, int l2)
{
    int carry = 0, temp, num1, num2, i;
    char resultado[100];

    resultado[l1 + 1] = '\0';

    while (l2 > 0) {
        num1 = bin1[l1 - 1] - '0';
        num2 = bin2[l2 - 1] - '0';
        temp = num1 + num2 + carry;
        if (temp >= 2) {
            carry = 1;
            temp = temp % 2;
        }
        resultado[l1] = temp + '0';
        l1--;
        l2--;
    }

    while (l1 - 1 >= 0) {
        temp = bin1[l1 - 1] + carry - '0';
        if (temp >= 2) {
            carry = 1;
            temp = temp % 2;
        }
        resultado[l1] = temp + '0';
        l1--;
    }

    if (carry) {
        resultado[0] = '1';
    }
    else {
        for (i = 0; i < strlen(resultado) - 1; i++) {
            resultado[i] = resultado[i + 1];
        }
        resultado[strlen(resultado) - 1] = '\0';
    }

    printf("%s + %s = %s\n", bin1, bin2, resultado);
}

void sub(char bin1[], char bin2[], int l1, int l2)
{
    int carry = 0, temp, num1, num2, i;
    char resultado[100];

    resultado[l1 + 1] = '\0';

    while (l2 > 0) {
        num1 = bin1[l1 - 1] - '0';
        num2 = bin2[l2 - 1] - '0';
        temp = num1 - num2 - carry;
        if (temp >= 2) {
            carry = 1;
            temp = temp % 2;
        }
        resultado[l1] = temp + '0';
        l1--;
        l2--;
    }

    while (l1 - 1 >= 0) {
        temp = bin1[l1 - 1] + carry - '0';
        if (temp >= 2) {
            carry = 1;
            temp = temp % 2;
        }
        resultado[l1] = temp + '0';
        l1--;
    }

    if (carry) {
        resultado[0] = '1';
    }
    else {
        for (i = 0; i < strlen(resultado) - 1; i++) {
            resultado[i] = resultado[i + 1];
        }
        resultado[strlen(resultado) - 1] = '\0';
    }

    printf("%s - %s = %s\n", bin1, bin2, resultado);
}

int binaryProduct(int binario1, int binario2)
{
    int i = 0;
    int rem = 0;
    int product = 0;
    int sum[20] = { 0 };

    while (binario1 != 0 || binario2 != 0) {

        sum[i] = (binario1 % 10 + binario2 % 10 + rem) % 2;
        rem = (binario1 % 10 + binario2 % 10 + rem) / 2;

        binario1 = binario1 / 10;
        binario2 = binario2 / 10;

        i = i + 1;
    }

    if (rem != 0)
        sum[i] = rem;

    while (i >= 0) {
        product = product * 10 + sum[i];
        i = i - 1;
    }

    return product;
}

int main()
{
    char hex1[17], bin1[65] = "", hex2[17], bin2[65] = "";
    int i = 0, opcao, running = 1, l1, l2, digit = 0, factor = 1;
    long binNum1 = 0, binNum2 = 0, product = 0;
    int binario1, binario2;

    printf("Digite qualquer número hexadecimal: ");
    gets(hex1);

    for(i=0; hex1[i]!='\0'; i++)
    {
        switch(hex1[i])
        {
            case '0':
                strcat(bin1, "0000");
                break;
            case '1':
                strcat(bin1, "0001");
                break;
            case '2':
                strcat(bin1, "0010");
                break;
            case '3':
                strcat(bin1, "0011");
                break;
            case '4':
                strcat(bin1, "0100");
                break;
            case '5':
                strcat(bin1, "0101");
                break;
            case '6':
                strcat(bin1, "0110");
                break;
            case '7':
                strcat(bin1, "0111");
                break;
            case '8':
                strcat(bin1, "1000");
                break;
            case '9':
                strcat(bin1, "1001");
                break;
            case 'a':
            case 'A':
                strcat(bin1, "1010");
                break;
            case 'b':
            case 'B':
                strcat(bin1, "1011");
                break;
            case 'c':
            case 'C':
                strcat(bin1, "1100");
                break;
            case 'd':
            case 'D':
                strcat(bin1, "1101");
                break;
            case 'e':
            case 'E':
                strcat(bin1, "1110");
                break;
            case 'f':
            case 'F':
                strcat(bin1, "1111");
                break;
            default:
                printf("Entrada hexadecimal inválida.");
        }
    }

    printf("Digite outro número hexadecimal: ");
    gets(hex2);

    for(i=0; hex2[i]!='\0'; i++)
    {
        switch(hex2[i])
        {
            case '0':
                strcat(bin2, "0000");
                break;
            case '1':
                strcat(bin2, "0001");
                break;
            case '2':
                strcat(bin2, "0010");
                break;
            case '3':
                strcat(bin2, "0011");
                break;
            case '4':
                strcat(bin2, "0100");
                break;
            case '5':
                strcat(bin2, "0101");
                break;
            case '6':
                strcat(bin2, "0110");
                break;
            case '7':
                strcat(bin2, "0111");
                break;
            case '8':
                strcat(bin2, "1000");
                break;
            case '9':
                strcat(bin2, "1001");
                break;
            case 'a':
            case 'A':
                strcat(bin2, "1010");
                break;
            case 'b':
            case 'B':
                strcat(bin2, "1011");
                break;
            case 'c':
            case 'C':
                strcat(bin2, "1100");
                break;
            case 'd':
            case 'D':
                strcat(bin2, "1101");
                break;
            case 'e':
            case 'E':
                strcat(bin2, "1110");
                break;
            case 'f':
            case 'F':
                strcat(bin2, "1111");
                break;
            default:
                printf("Entrada hexadecimal inválida.");
        }
    }


    while(running)
    {
        printf("\nNúmero binário = %s", bin1);
        printf("\nNúmero binário = %s", bin2);

        menu();

        printf("\n\nOPÇÃO SELECIONADA: ");
        scanf("%d", &opcao);
        switch(opcao)
        {
            case MENU_SOMA:
                system("cls");
                l1 = strlen(bin1);
                l2 = strlen(bin2);
                if (l1 > l2) {
                    soma(bin1, bin2, l1, l2);
                }
                else {
                    soma(bin2, bin1, l2, l1);
                }
                break;

            case MENU_SUBTRACAO:
                system("cls");
                l1 = strlen(bin1);
                l2 = strlen(bin2);
                if (l1 > l2) {
                    sub(bin1, bin2, l1, l2);
                }
                else {
                    sub(bin2, bin1, l2, l1);
                }
                break;

            case MENU_MULTIPLICACAO:
                system("cls");

                binario1 = atoi(bin1);
                binario2 = atoi(bin2);

                while (binario2 != 0) {
                    digit = binario2 % 10;

                    if (digit == 1) {
                        binario1 = binario1 * factor;
                        product = binaryProduct(binario1, product);
                    }
                    else {
                        binario1 = binario1 * factor;
                    }

                    binario2 = binario2 / 10;
                    factor = 10;
                }

                printf("Product of numbers: %ld", product);

                break;
            case MENU_DIVISAO:
                system("cls");
                printf("divisao\n");
                break;
            default:
                return 0;
        }
    }
}

