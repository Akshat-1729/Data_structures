#include<stdio.h>
void add(int arr[][100],int i,int j){
    arr[i][j]=1;
    arr[j][i]=1;
}
void display(int arr[][100],int n){
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }
}
int main(){
    int n;
    printf("Enter number of vertices in graph: ");
    scanf("%d",&n);
    int arr[100][100]={0};
    add(arr,0,1);
    add(arr,0,2);
    add(arr,1,2);
    add(arr,2,0);
    add(arr,2,3);
    display(arr,n);
    return 0;
}