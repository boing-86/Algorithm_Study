#include <stdio.h>


/*
조건문(심화)
* 10 이상, 20 미만인 수에 대해서 검사하는 조건문을 만들고 싶을때?
ㄴ 논리 연산자 : AND(&&), OR(||), NOT(!=)

반복문(기본) for(초기식; 조건식; 증감식){명령어}
*/
/*
break문 : 가장 가까운 반복문을 탈출함
continue문 : 이번 반복을 탈출함
이중for문 : 
*/

int main(void) {

  int i;
  int X;
  int N;
  int a;
  int b;
  int sum = 0;

  scanf("%d", &X);
  scanf("%d", &N);
  
  for(i=0; i < N; i++){
    scanf("%d %d", &a, &b);
    sum = sum + a*b;
  }

  if (sum == X)
    printf("Yes");

  else 
    printf("No");
  
  return 0;
}