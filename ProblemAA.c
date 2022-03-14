#include <stdio.h>
#include <string.h>
#include<stdlib.h>

void swap2(char *str1, char *str2) 
{ 
  char *temp = (char *)malloc((strlen(str1) + 1) * sizeof(char)); 
  strcpy(temp, str1); 
  strcpy(str1, str2); 
  strcpy(str2, temp); 
  free(temp); 
}


int main(){

    int cases1, cases2;
    int id[1000], kaki[1000], inc[1000];
    double cm[1000];
    char nama[1000][1000];
    int minimal;
    int counto=0;
    int temp;
    double temp2;

    scanf("%d", &cases1);

    for(int i=0; i<cases1; i++){
        scanf("%d,%[^,],%d %d", &id[i], nama[i], &kaki[i], &inc[i]);
    }

    for(int i=0; i<cases1; i++){
        cm[i] = (kaki[i] * 12 * 2.54) + (inc[i] * 2.54);
    }

    for (int x = 0; x < cases1; x++)
    {
        for (int y = 0; y < cases1; y++)
        {
            if (cm[y] < cm[x])
            {
                temp2 = cm[x];
                cm[x] = cm[y];
                cm[y] = temp2;

                temp = id[x];
                id[x] = id[y];
                id[y] = temp;

                swap2(nama[x], nama[y]);
            }
            else if(cm[y] == cm[x] && strcmp(nama[y], nama[x]) > 0){
                temp = id[x];
                id[x] = id[y];
                id[y] = temp;

                swap2(nama[x], nama[y]);
            }
        }
    }

    scanf("%d", &cases2);

    for(int i=0; i<cases2; i++){
        scanf("%d", &minimal);
        printf("Q#%d:\n", i+1);
        for(int m=0; m<cases1; m++){
            if(cm[m]<minimal){
                printf("%d %s %.2lf\n", id[m], nama[m], cm[m]);
                counto++;
            }
        }
        if(counto==0){
            printf("-1\n");
        }
        else if (counto!=0){
            counto=0;
        }
    }

    return 0;

}
