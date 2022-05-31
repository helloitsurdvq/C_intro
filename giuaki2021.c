#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<string.h>
#include<conio.h>
#include<stdbool.h>

//ma tran don vi
void input(int a[50][50], int *n){
    *n =0;
    while (*n <= 0){
        scanf("%d", n); 
    }
    for(int i=0; i < *n; i++){
        for(int j=0; j < *n; j++){
            scanf("%d", &a[i][j]);
        }
    }
}
// void display(int a[50][50], int n){
//     for(int i=0; i < n; i++){
//         for (int j=0; j < n; j++) printf("%4d", a[i][j]);
//         printf("\n");
//     }
// }
int donvi(int a[50][50], int n){
    int i, j;
    for(i=0; i<n; i++){
        if(a[i][i] !=1) return 0;
        for(i=0; i<n; i++){
            for(j=i+1; j<n; j++){
                if((a[i][j] !=0) || (a[j][i] !=0)){
                    return 0;
                }
            }
        }
    }
    return 1;
}
void matran(){
    int a[50][50], n;
    input(a, &n);  
    //display(a, n); 
    if(donvi(a, n) == 1) printf("Yes"); // kiem tra ma tran don vi 
    else printf("No");
}

// tam giac deu
void xuoi(int n){
    for(int i = 1; i <= n; i++){
        for(int j = 1; j<= n-i; j++) printf(" ");
        for(int j = 1; j<= i; j++) printf("* ");
        printf("\n");
   }
}
void nguoc(int n){
    for(int i =1; i <= n; i++){
        for(int j=1; j<i; j++) printf(" ");
        for(int j=i; j<=n; j++) printf("* ");
        printf("\n");
    }
}
void tamgiac(){
    int n; // kich thuoc tam giac
    char c; // chieu xuoi hoac nguoc
    scanf("%d %c", &n, &c); //do dai canh tam giac
    if (c == 'X') xuoi(n);
    else if (c == 'N') nguoc(n);
    else printf("INVALID");
}

//Chuyen so
void chuyenso(){
    char phone[20], newphone[20];
    scanf("%s", phone); // nhap so dien thoai
    int p=strlen(phone), np = strlen(newphone);
    if(p == 10) printf("%s", phone);
    if(p == 11){
        if(phone[0] != '1' || phone[1] != '6') printf("Khac nha mang");
        else{
            phone[0] = ' ';
            phone[1] = '3';
            printf("%s", phone);
        }
    }
    if(p > 11) phone[11] = '\0';
    if(phone[0] == '0'){
        strcpy(newphone, &phone[1]); // copy tu phan tu 1 cua phone
        if (np == 10) printf("%s", newphone);
        if (np == 11){
            if(newphone[0] != '1' || newphone[1] != '6') printf("Khac nha mang");
            else{
                newphone[0] = ' ';
                newphone[1] = '3';
                printf("%s", newphone);
            }
        }
    }
} 

//ban do bit
void bitmap(){
    char s[101];
    int n;
    printf("Nhap ban do bit: ");
    scanf("%s", s);
    printf("Nhap kich Thuoc: ");
    scanf("%d", &n);
    int MinSize = 105, MinPos = -1, m = strlen(s);
    for(int i =0; i < m; ++i){
        if(s[i] == '1') continue;
        int CurPos = i;
        int CurSize = 0;
        while(s[i] == '0'){
            CurSize++;
            i++;
        }
        if(CurSize >= n && CurSize < MinSize){
            MinSize = CurSize;
            MinPos = CurPos;
        }
        if(MinSize == n) break;
    }
    if(MinPos != -1){
        int Count = 0;
        for(int i = MinPos; Count < n; ++i){
            Count++;
            s[i] = '1';
        }
    }
    printf("Vi Tri Tim Thay: %d\n", MinPos);
    printf("Ban do bit hien tai la: %s", s);
}

int main(){
	int luaChon, chon, i, n=0;
	while (1){
		printf("\n1. Ma tran");
		printf("\n2. Tam giac");
		printf("\n3. Chuyen so");
		printf("\n4. Ban do bit");
		printf("\n5. Exit");
		printf("\nYour choice? ");
		scanf("%d", &luaChon);
		switch(luaChon) {
			case 1:
			    matran();
			    break;				
			case 2:
			    tamgiac();
			    break;				
			case 3:
                	    chuyenso();
			    break;				
			case 4:	
			    bitmap();
			    break;	
		    	case 5:
			    return 0; 
			    break;			
		    	default: 
			    printf("Invalid choice, please try again.");
			    break;
		}
	} 
}
