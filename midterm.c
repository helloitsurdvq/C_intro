#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
void problem1();
void problem2();
void problem3();
void problem4();

int main(int argc, char** argv) {
  if (argc != 2) {
    printf("Invalid parameters!\n");
    return 0;
  }
  switch (atoi(argv[1])) {
  case 1:
    problem1(); break;
  case 2:
    problem2(); break;
  case 3:
    problem3(); break;
  case 4:
    problem4(); break;
  default:
    printf("Invalid parameters!\n");
    break;
  }
}

void problem1() {
  int a, b;
  printf("Enter a, b: ");
  scanf("%d%d", &a, &b); 
  if(a==0 && b==0) printf("Greatest common divisor does not exist.");
  else if(a==0 || b==0) printf("GCD = %d", (a == 0) ? b : a);
  else{
    while(a != 0){
        int x=a;
        a = b%a;
        b=x;
    } 
    printf("GCD = %d", b);
  }
}

void problem2() {
  int n;
  scanf("%d",&n);
  int i=1;
  while (i<=n*n){
	  for(int j=0;j<n;j++){
		  printf("+-----");
	  }
	  printf("+");
	  printf("\n");
	  for(int j=i;j<i+n;j++){
		  if(j<10) printf("|    %d",j);
		  if(j>=10) printf("|   %d",j);
	  }
	  printf("|");
    printf("\n");
	  i+=n;
  }
  for(int j=0;j<n;j++) printf("+-----");
  printf("+");
  printf("\n");
}

void problem3() {
  int n;
  printf("Input n: ");
  scanf("%d",&n);
  double arr[n], sum = 0, ans =0;
  printf("Input series :");
  for(int i=0 ; i<n; i++){
    scanf("%lf",&arr[i]);
    sum+=arr[i];
  }
  sum/=n;
  for(int i=0 ; i<n ; i++) ans+= pow((arr[i]-sum),2);
  ans/=n;
  ans=sqrt(ans);
  printf("Result : %lf",ans);
}

void problem4() {
  char str[100];  
  int i, temp[256]={0}; // 256 is the number of characters in ascii table
  printf("Enter the string : ");
  fflush(stdin);
  gets(str);
  for(i=0; str[i] != '\0'; i++){
    temp[str[i]]++;
  }
  for (i=0; i<256; i++){
    if(temp[i] != 0) printf("%c : %d\n", i, temp[i]);
  }
}
