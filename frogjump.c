#include<stdio.h>
#include<string.h>
char finalarr[50][50];
int finalindex=0;
char arr[20];
char rev[20];
int size;
int empty;
int count=0;
void swap(int x,int y){
      char temp;
      temp=arr[x];
      arr[x]=arr[y];
      arr[y]=temp;
}
void insert(){
      strcpy(finalarr[finalindex++],arr);
}
void pop(){
      finalindex--;
}
int frogjump(){
      count++;
      if(strcmp(arr,rev)==0)return 1;
      if (empty-1>-1 && arr[empty-1]=='L'){
            swap(empty,empty-1);
            empty-=1;
            insert();
            if(frogjump())return 1;
            pop();
            empty+=1;
            swap(empty,empty-1);
      }
      if (empty-2>-1 && arr[empty-2]=='L'){
            swap(empty,empty-2);
            empty-=2;
            insert();
            if(frogjump())return 1;
            pop();
            empty+=2;
            swap(empty,empty-2);
      }
      if(empty+1<size && arr[empty+1]=='R'){
            swap(empty,empty+1);
            empty+=1;
            insert();
            if(frogjump())return 1;
            pop();
            empty-=1;
            swap(empty,empty+1);
      }
      if(empty+2<size && arr[empty+2]=='R'){
            swap(empty,empty+2);
            empty+=2;
            insert();
            if(frogjump())return 1;
            pop();
            empty-=2;
            swap(empty,empty+2);
      }
      return 0;
}
int main(){
      printf("Enter the size of array\n ");
      scanf("%d",&size);
      empty=(size)/2;
      printf("Enter the array\n");
      for(int i =0;i<size;i++)
      scanf("%s",&arr[i]);
      for(int i=size-1;i>=0;i--){
            rev[size-1-i]=arr[i]; 
      }
      frogjump();
      for(int i=0;i<finalindex;i++){
            for(int j=0;j<size;j++)
                  printf("%c ",finalarr[i][j]);
            printf("\n");
      }
      
}