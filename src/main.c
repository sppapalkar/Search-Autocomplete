#include<stdio.h>
#include<stdlib.h>
#include "search/search.h"
#define MAX 128
void display(char *str, char** suggestions){
    int index = 0;
    printf("\nSuggested Phrases: ");
    while(*(suggestions+index)!=NULL){
        printf("\n%s%s",str,*(suggestions+index));
        index++;
    }
}

void menu(){
    trienode *trie;
    char **suggestions;
    int ch;int k, freq;
    char buf[MAX];
    trie = init_trienode('*');
    printf("\nEnter no Of suggestions(k): ");
    scanf("%d", &k);
    
    do{
        // Print main menu
        printf("\n\n   Menu");
        printf("\n1. Add new phrase");
        printf("\n2. Get Suggestions");
        printf("\n3. Quit");
        printf("\nEnter your choice: ");
        scanf("%d",&ch);

        switch (ch)
        {
        case 1: 
            printf("\nEnter new phrase: ");
            scanf("%[^\n]", buf);
            printf("\nEnter phrase frequency: ");
            scanf("%d",&freq);
            insert(trie, buf, freq);
            break;
        case 2:
            fflush (stdin); 
            printf("Enter input: ");
            scanf("%[^\n]", buf);
            suggestions = get_suggestions(trie, buf, k);
            display(buf, suggestions);
            break;
        case 3: // Free space on quit
            free(trie);
            break;
        default:
            printf("\nInvalid choice. Try again");
            break;
        }
    }while(ch!=3);
    
}    
    
int main(){
    menu();
}