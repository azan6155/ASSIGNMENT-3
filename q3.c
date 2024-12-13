#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int validateEmail(char* email);


int main(){
    char *email = malloc(sizeof(char) * 30);
    char *email_without_space = malloc(sizeof(char) * 30);
    int i;
    for(i=0;i<30;i++){
        email[i] = '\0';
        email_without_space[i] = '\0';
    }
    printf("Enter email: ");
    gets(email);
    i=0;
    int j = 0;
    while(email[i] != '\0'){
        if(email[i] == ' '){
            i++;
            continue;
        }
        email_without_space[j] = email[i];
        j++;
        i++;
    }
    email_without_space[j + 1] = '\0';
    int is_email_valid = validateEmail(email_without_space);
    if(is_email_valid)
        printf("Valid Email\n");
    else
        printf("Invalid Email\n");

    free(email);
    free(email_without_space);
}


int validateEmail(char* email) {
    int at_count = 0;
    int at_index;
    int dot_count = 0;
    int i = 0;
    if(strlen(email) == 0)
        return 0;

    while(email[i] != '\0'){
        if(email[i] = '@'){
            at_count++;
            at_index = i;
            break;
        }
        i++;
    }
    if (at_count != 1)
        return 0;
    // Starting from @ position 
    i = at_index;
    while(email[i] != '\0'){
        if(email[i] == '.')
            dot_count++;
        i++;
    }

    if(dot_count < 1)
        return 0;
    else
        return 1;
}
