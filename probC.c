#include<stdio.h>
#include<string.h>

int main(){
	
	
	
	
    FILE *op;
    
    op=fopen("testdata.in","r");
    
    
    int m;
    
    fscanf(op,"%d\n", &m);
    
    
    char r[m][44];
    char nama[m][44];
    int a[m];
    
    
    for(int i=0;i<m;i++){
        fscanf(op,"%[^,],%[^,],%d\n",r[i] ,nama[i] ,&a[i]);
    }
    
    char key[44];
    int total=0;
    int total2=0;
    
    fscanf(op,"%s\n" ,key);
    
    for(int j=0;j<m;j++){
    	
        if(strcmp(key, r[j])==0){
            printf("%s %s %d\n",r[j],nama[j],a[j]);
            total++;
            total2=total2+a[j];
        }
        
    }
    
    printf("Total Recipients: %d\n",total);
    printf("Total Amount: %d\n",total2);

    return 0;
}
