#include<stdio.h> 
#include<string.h> 
#include<stdlib.h> 

//m = table size 
int m = 23; 

struct tnode{ 
    char value[10]; 
    int step; 
}*ND[25];

int hashing(char value[10]){ 
    int key;
    int len = strlen (value);
    for (int i=0; i<len; i++){
        key += value[i];
    }
    key = key%m;
 
    return key;
} 

struct tnode *newData(char value[10]){ 
    int step;
    tnode *ND = (tnode*)malloc(sizeof(tnode));
    strcpy(ND->value, value);
    ND->step = step;
    return ND; 
} 

void insert(char value[10]){ 
    struct tnode *N_Data =  newData(value); 
    int key = hashing(value);
    N_Data = ND[key];
    int step = 0;
    if(!ND[key]) { 
        strcpy(ND[key]->value, value);
        ND[key]->step = step;
    } 
    else {
        step++;
        for(int i=(key+1) % m; i != key; i = (i+1) % m) {
            if(!ND[i]) {
                strcpy(ND[i]->value, value);
                ND[i]->step = step;
                return;
            }
            else{
                step++;
            }
        }
        puts("TABLE IS FULL!!!");
        return;
    }
} 

void view(){ 
    for(int i=0;i<m;i++){ 
        if(ND[i]) printf("[%d]\t%s (%d step(s))\n", i, ND[i]->value, ND[i]->step+1); 
            else printf("[%d]\tNULL\n", i); 
    } 
}

int main(){ 
    for(int i=0;i<m;i++){ 
        ND[i] = NULL; 
    } 
    insert("AAAAA"); 
    insert("BBBBB"); 
    insert("CCCCC"); 
    insert("AAABB"); 
    insert("BABAA"); 
    insert("BAABA"); 
    insert("BBAAA"); 
    insert("ABBAA"); 
 
    view(); 
    return 0; 
}
