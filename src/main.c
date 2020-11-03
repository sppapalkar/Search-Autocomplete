#include<stdio.h>
#include<stdlib.h>
#include "search/search.h"

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
    int ch;int k;
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
            char str[128];
            int freq;
            printf("Enter new phrase: ");
            scanf("%s",str);
            printf("Enter phrase frequency: ");
            scanf("%d",&freq);
            insert(trie, str, freq);
            break;
        case 2: 
            char str[128];
            char **suggestions;
            printf("Enter input: ");
            scanf("%s",str);
            suggestions = get_suggestions(trie, str, k);
            display(str, suggestions);
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