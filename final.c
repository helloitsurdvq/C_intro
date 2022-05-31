#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<string.h>
#include<conio.h>
#include<stdbool.h>
typedef struct {
    long ID;
    int chapter;
    char content[50]; 
} Question;

void Read(Question thongtin[], int *n){
    do{
      	printf("\nEnter the number of question: ");
      	scanf("%d", n);
      	if(*n<=0 || *n > 100) printf("Must be > 0 and <= 100");
    } while(*n<=0 || *n > 100);
    for(int i=0; i<*n; i++){
     	printf("Enter the chapter and content: ");
      	scanf("%ld%[^\n]s",&thongtin[i].chapter,thongtin[i].content);
      	thongtin[i].ID+= i+1;
    }
  }

void printlistcol(){
    printf("LIST\n");
    printf("%-15s %-15s %-15s\n", "ID","Chap", "Content");
}
void printinfo(Question thongtin[], int n){
    printlistcol();
    for(int i=0; i<n; i++){
      	printf("%-15ld %-15d %-15s\n", thongtin[i].ID, 
      	thongtin[i].chapter, thongtin[i].content);
    }
}

void findid(Question thongtin[], int n){
    int i=0, ma, tim = 0;
    printf("Enter the Id question you are looking for: ");
    scanf("%d", &ma);
    for(i=0; i<n; i++){
        if(thongtin[i].ID == ma){
            printf("Question with the Id\n");
            printlistcol();
            printf("%-15ld %-15d %-15s\n", thongtin[i].ID, 
		thongtin[i].chapter, thongtin[i].content);
            tim = 1;
        }
    }
    if(tim == 0) printf("The question with Id %d does not exist.\n", ma);
}

Question addinfo(){// may update this function asap
    Question thongtin;
    printf("Enter the chapter and content: ");
    scanf("%ld%[^\n]s",&thongtin.chapter, thongtin.content);
    thongtin.ID += 1;
    return thongtin;
}

void printcountcol(){
    printf("%-15s %-15s\n","Chap", "Count");
}
void count(Question thongtin[],int n){
    int dem[100]={0};
    for(int i=0; i< n; i++) dem[thongtin[i].chapter]++;
    printcountcol();
    for(int i=1; i<100; i++){
        if(dem[i]) printf("%-15d %-15d\n", i, dem[i]);
    }
}

bool CheckUpper (char c){
    return c >= 'A' && c <= 'Z';
}
void check(Question thongtin[],int n){
    int dem[100]={0};
    for(int i=0; i< n; i++){
        if(!CheckUpper(thongtin[i].content[2])){
            dem[i]++;
            continue;
        }
        for(int j=1 ;j<strlen(thongtin[i].content);j++){
            if(thongtin[i].content[j] == '*' ||
               thongtin[i].content[j] == '$' || 
               thongtin[i].content[j] == '\\' ){
                dem[i]++;
                break;
            }
		}
    }
    printlistcol();
    for(int i=0; i<n; i++){
        if(dem[i] == 0){
            printf("%-15ld %-15d %-15s\n", thongtin[i].ID, 
		thongtin[i].chapter, thongtin[i].content);
        }
    }
}

int main(){
    int luaChon, i = 0, n=0;

    while(1){
        printf("\n1. Read");
        printf("\n2. Search");
        printf("\n3. Add");
        printf("\n4. Count");
        printf("\n5. Check");
        printf("\n6. Exit");
        printf("\nYour choice? ");
        Question thongtin[1000];
        Question info;
        scanf("%d", &luaChon);
        switch(luaChon) {
          case 1:
            Read(thongtin, &n);
            printinfo(thongtin, n);
            break;				
          case 2:
            if (n>0) findid(thongtin, n);				
            else printf("The question list is empty");
            break;				
          case 3:
            info = addinfo();
            thongtin[n++] = info;
            printinfo(thongtin, n);
            break;				
          case 4:	
            count(thongtin, n);
            break;
          case 5:
            check(thongtin, n);
            break;	
          case 6:
            return 0; 
            break;			
          default: 
            printf("Invalid choice, please try again.");
            break;
        }
    } 
}
