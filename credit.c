#include <stdio.h>

//Código em C que executa o algoritmo de Luhn para validar número de cartão de crédito

int main(void) {
 
  long int creditCard;    // Variável que armazena o número do cartão de crédito, informado pelo usuário e lido pelo programa;
  char cardBrand;         // Variável que armazena a identificação da bandeira do cartão informado em uma char.
  
  /*
  O loop a seguir foi feito para garantir que o número digitado não seja igual a zero, 
  fazendo com que o input se repita até que um valor diferente de 0 seja colocado
  */
 
  do{
    printf("Digite o número do seu cartão (Sem espaços nem hífens): ");
    scanf("%ld", &creditCard);
  } while (creditCard <= 0);
  
  // A seguir são coletados os dígitos com número de posição par, começando pelo penúltimo e indo da direita para a esquerda
  
  long int digit02 = (creditCard % 100) / 10;

  long int digit04 = (creditCard % 10000) / 1000;

  long int digit06 = (creditCard % 1000000) / 100000;

  long int digit08 = (creditCard % 100000000) / 10000000;

  long int digit10 = (creditCard % 10000000000) / 1000000000;

  long int digit12 = (creditCard % 1000000000000) / 100000000000;

  long int digit14 = (creditCard % 100000000000000) / 10000000000000;

  long int digit16 = (creditCard % 10000000000000000) / 1000000000000000;
  
  /* A variável sumFromSecond aplica a primeira parte do algoritmo de Luhn, pegando os dígitos acima, multiplicando cada um por 2 e depois 
  separando os dígitos de cada produto e no final somando todos eles */  
  
  int sumFromSecond = (digit02 * 2) % 10 + (digit02 * 2) / 10 + (digit04 * 2) % 10 + (digit04 * 2) / 10 + (digit06 * 2) % 10 + (digit06 * 2) / 10 + (digit08 * 2) % 10 + (digit08 * 2) / 10 + (digit10 * 2) % 10 + (digit10 * 2) / 10 + (digit12 * 2) % 10 + (digit12 * 2) / 10 + (digit14 * 2) % 10 + (digit14 * 2) / 10 + (digit16 * 2) % 10 + (digit16 * 2) / 10;
  
  // A seguir são coletados os dígitos restantes (que não foram multiplicados por 2)
  
  long int digit01 = creditCard % 10;  

  long int digit03 = (creditCard % 1000) / 100;

  long int digit05 = (creditCard % 100000) / 10000;

  long int digit07 = (creditCard % 10000000) / 1000000;

  long int digit09 = (creditCard % 1000000000) / 100000000;

  long int digit11 = (creditCard % 100000000000) / 10000000000;

  long int digit13 = (creditCard % 10000000000000) / 1000000000000;

  long int digit15 = (creditCard % 1000000000000000) / 100000000000000;
  
  // A variável sumFromFirst soma todos os dígitos coletados anteriormente (que não foram multiplicados por 2), completando a segunda etapa de Luhn.

  int sumFromFirst = digit01 + digit03 + digit05 + digit07 + digit09 + digit11 + digit13 + digit15;
  
  //A variável LuhnSum completa a terceira etapa do algoritmo, somando os resultados das duas somas anteriores
  
  int LuhnSum = sumFromFirst + sumFromSecond;
  
  // A seguir, tem-se uma estrutura condicional de verificação da bandeira do cartão de acordo com  os dígitos iniciais do número total.
  
 
    if (creditCard / 10000000000000 >= 37 && creditCard / 10000000000000 < 38 || creditCard / 10000000000000 >= 34 && creditCard / 10000000000000 < 35){
      cardBrand = 'A';
      }  else if (creditCard / 100000000000000 >= 51 && creditCard / 100000000000000 < 56) {
      cardBrand = 'M';
      } else if (creditCard / 1000000000000 >= 4 && creditCard / 1000000000000 <5 || (creditCard / 1000000000000000) < 5 && (creditCard / 1000000000000000) >= 4) {
      cardBrand = 'V';    
    } 

    /* 
    O Loop a seguir foi a solução encontrada para contar a quantidade de dígitos que o número do cartão informado tem.
    Ele conta em quantas vezes foram necessárias dividir o número total do cartão por 10 até que o resultado da divisão fosse zero (pois quando o resultado é zero
    significa que ele já andou com a vírgula para a esquerda todas as casas possíveis dentro do número de dígitos do cartão);
    */
    
    int Count = 0;
    long int CC = creditCard;     //Variável que coleta o número do cartão de crédito para a operação a seguir, sem alterar o valor original do cartão.
    while (CC != 0){
      CC = CC / 10;
      Count++;
    }

    /*
     Após se obter a quantidade de dígitos do cartão, faz-se um tratamento de erro para o casos de invalidez do número informado.
     Se o número de dígitos for diferente de 13 (padrão Visa), 15 (padrão American Express) ou 16 (padrão Mastercard e também Visa), significa que 
     não é compatível com nenhuma das bandeiras identificáveis pelo programa, logo é inválido.
     E também, se o resto da divisão da soma LuhnSum for diferente de zero (etapa final do algoritmo) significa que o padrão dele não é compatível, 
     logo também é inválido.
    */
  
    /*
    Caso o número do cartão não se encaixe em nenhuma dessas violações, 
    a estrutura condicional pega o valor da variável cardBrand e de acordo com seu valor, imprime qual é a bandeira do cartão já validado.
    */
  
    if (Count!=13 && Count!=15 && Count!=16 || LuhnSum % 10 != 0) {
        printf("INVALID\n");
      } else if (cardBrand == 'A'){
        printf("AMEX\n");
      }  else if (cardBrand == 'M'){
        printf("MASTERCARD\n");
      } else if (cardBrand == 'V'){
        printf("VISA\n");
      } else {
        printf("Error!\n");
      }
  
  return 0;
}







