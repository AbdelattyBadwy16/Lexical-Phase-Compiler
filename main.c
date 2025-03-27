#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>

typedef enum{
    INT,
}TypeLiteral;

typedef enum{
    EXIT,
}TypeKeyword;

typedef enum{
    SEMI,
    OPEN_PAREN,
    CLOSE_PAREN,
}TypeSeparator;

typedef struct{
    TypeKeyword type;
}TokenKeyword;

typedef struct{
    TypeSeparator type;
    int value;
}TokenLiteral;

typedef struct{
    TypeLiteral type;
}TokenSeparator;



// Generate Numbers

TokenLiteral generate_number(char current,FILE *file){
    TokenLiteral token;
    token.type = INT;
    int value = 0;
    while(current != EOF){
        if(!isdigit(current)){
            break;
        }
        value = (value * 10) + (int) current - '0';
        current = fgetc(file);
    }
    token.value = value;
    return token;
}


// Lexer 
void lexer(FILE *file){
    char current = fgetc(file);

    while(current != EOF){
        if(current == ';'){
            printf("Found Semicolon");
        }
        else if(current == '{'){
            printf("Found Open Paren");
        }else if(current == '}'){
            printf("Found Close Paren");
        }else if(isdigit(current)){
            TokenLiteral test_token = generate_number(current,file);
            printf("%d\n",test_token.value);
        }else if(isalpha(current)){
            printf("Found Char : %c \n",current);
        }
        current = fgetc(file);
    }
}

int main(){
    FILE *file;
    file = fopen("test.mol","r");
    lexer(file);
}
