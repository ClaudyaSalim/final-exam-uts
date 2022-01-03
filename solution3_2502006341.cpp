#include<stdio.h> 
#include<stdlib.h> 
#include<string.h>

struct data { 
    char value[100]; 
    struct data *next; 
};

struct data *hashTables[31]; 
int hash(const char *str) { 
    int length = strlen(str); 
    int base = 11; 
    int MOD = 31; 
    int key = 0; 
    for(int i = 0; i < length; i++) { 
        key = (key * base) + (str[i] - 'a' + 1); 
        key = key % MOD; 
    } 
    return (key * base) % MOD; 
}

void chaining(int idx,const char *str) { 
    struct data *newData = (struct data *) malloc(sizeof(struct data)); 
    strcpy(newData->value, str); 
    newData->next = NULL; 
    struct data *curr = hashTables[idx];
    //INSERT YOUR CODE HERE, Insert Data into Hashtable with chaining
    if(!hashTables[idx]) { 
        hashTables[idx]= newData;
        curr = hashTables[idx];
    } 
    else {
        while (curr->next != NULL){
            curr = curr->next;
        }
        curr->next = newData;
    } 
    
}

void viewAll() { 
 //INSERT YOUR CODE HERE, View Data if the index have Data 
    for(int i = 0; i < 31; i++) {
        if(hashTables[i]) {
            printf("Index %d: ", i);
            struct data *curr = hashTables[i];
            while(curr) {
                if (curr->next == NULL){
                    printf("%s\n", curr->value);
                }
                else{
                    printf("%s -> ", curr->value);
                }
                curr = curr->next;
            }
        }
        // else {
        //     puts ("NULL");
        // }
    }
}

void popAll() { 
 //INSERT YOUR CODE HERE, Pop All the hashtable
    for (int i=0; i<31 ;i++){
        struct data *curr = hashTables[i];
        while (hashTables[i]){
            curr = hashTables[i]->next;
            free(hashTables[i]);
            hashTables[i] = curr;
        }
    }
}

void init() { 
    for(int i = 0 ; i < 31 ; i++) { 
        hashTables[i] = NULL; 
    } 
}

int main() { 
    char data[][100] = 
    { 
        "roti", 
        "keju", 
        "coklat", 
        "durian", 
        "nasi", 
        "buncis", 
        "ayam", 
        "air", 
        "mie", 
        "tahu", 
        "tempe", 
        "susu", 
        "sapi", 
        "telur", 
        "biskuit", 
        "wortel", 
        "steak", 
        "kentang", 
        "apel", 
        "melon", 
        "ikan" 
    }; 
 
    init(); 
 
    int count = sizeof(data) / sizeof(data[0]); 
 
    for(int i = 0 ; i < count ; i++) { 
        int idx = hash(data[i]); 
        chaining(idx,data[i]); 
    } 
 
    viewAll(); 
    popAll();
    // viewAll(); 

    return 0; 
} 
