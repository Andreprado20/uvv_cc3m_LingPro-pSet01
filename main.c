#include <stdio.h>

int main(void) {
  long int creditCard;
  int cardBrand;
  do{
    printf("Digite o número do seu cartão (Sem espaços nem hífens): ");
    scanf("%ld", &creditCard);
  } while (creditCard <= 0);
  

  long int digit02 = (creditCard % 100) / 10;

  long int digit04 = (creditCard % 10000) / 1000;

  long int digit06 = (creditCard % 1000000) / 100000;

  long int digit08 = (creditCard % 100000000) / 10000000;

  long int digit10 = (creditCard % 10000000000) / 1000000000;

  long int digit12 = (creditCard % 1000000000000) / 100000000000;

  long int digit14 = (creditCard % 100000000000000) / 10000000000000;

  long int digit16 = (creditCard % 10000000000000000) / 1000000000000000;

  int sumFromSecond = (digit02 * 2) % 10 + (digit02 * 2) / 10 + (digit04 * 2) % 10 + (digit04 * 2) / 10 + (digit06 * 2) % 10 + (digit06 * 2) / 10 + (digit08 * 2) % 10 + (digit08 * 2) / 10 + (digit10 * 2) % 10 + (digit10 * 2) / 10 + (digit12 * 2) % 10 + (digit12 * 2) / 10 + (digit14 * 2) % 10 + (digit14 * 2) / 10 + (digit16 * 2) % 10 + (digit16 * 2) / 10;

  long int digit01 = creditCard % 10;  

  long int digit03 = (creditCard % 1000) / 100;

  long int digit05 = (creditCard % 100000) / 10000;

  long int digit07 = (creditCard % 10000000) / 1000000;

  long int digit09 = (creditCard % 1000000000) / 100000000;

  long int digit11 = (creditCard % 100000000000) / 10000000000;

  long int digit13 = (creditCard % 10000000000000) / 1000000000000;

  long int digit15 = (creditCard % 1000000000000000) / 100000000000000;

  int sumFromFirst = digit01 + digit03 + digit05 + digit07 + digit09 + digit11 + digit13 + digit15;

  int LuhnSum = sumFromFirst + sumFromSecond;
 
    if (creditCard / 10000000000000 >= 37 && creditCard / 10000000000000 < 38 || creditCard / 10000000000000 >= 34 && creditCard / 10000000000000 < 35){
      cardBrand = 'A';
      }  else if (creditCard / 100000000000000 >= 51 && creditCard / 100000000000000 < 56) {
      cardBrand = 'M';
      } else if (creditCard / 1000000000000 >= 4 && creditCard / 1000000000000 <5 || (creditCard / 1000000000000000) < 5 && (creditCard / 1000000000000000) >= 4) {
      cardBrand = 'V';    
    } 

    int Count = 0;
    long int CC = creditCard;
    while (CC != 0){
      CC = CC / 10;
      Count++;
    }

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







