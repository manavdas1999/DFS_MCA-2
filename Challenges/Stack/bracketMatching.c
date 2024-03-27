// bracket matching using stack

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


struct Stack{
    int size;
    int top;
    char *s;
};

void createStack(struct Stack *st, int size){
    st->size = size;
    st->top = -1;
    st->s = (char*)malloc(sizeof(char) * st->size);
}

void push(struct Stack *st, char ch){
    if(st->top == st->size-1){
        printf("\nStack Overflow\n");
    }
    else{
        st->top++;
        st->s[st->top] = ch;
    }
}

char pop(struct Stack *st){
    if(st->top == -1){
        printf("\nStack Empty\n");
        return '\0';
    }
    else{
        return st->s[st->top--];
    }
}

char stackTop(struct Stack *st){
    if(st->top == -1){
        printf("\nStack empty\n");
        return '\0';
    }
    else{
        return st->s[st->top];
    }
}

int isEmpty(struct Stack *st){
    return st->top == -1 ? 1 : 0;
}


int main() {
   struct Stack st;
   char expn[] = "{([a+b] * [c-d]) / e}";
   createStack(&st, strlen(expn));
   
   for(int i = 0; expn[i] != '\0'; i++){
    //   opening brackets => push
       if((expn[i] == '(') || (expn[i] == '{') || (expn[i] == '[')) {
           push(&st, expn[i]);
       }
    //  closing brackets => check for mismatch and if not then pop
       else if((expn[i] == ')') || (expn[i] == '}') || (expn[i] == ']')){
           char topChar = stackTop(&st);
           if(topChar == '\0'){
            //   empty stack
            printf("\nBracket Mismatch at index %d \n", i);
            return 0;
           }
          else if((topChar == '(' && expn[i] == ')') || (topChar == '[' && expn[i] == ']') || (topChar == '{'&& expn[i] == '}')){
              pop(&st);
          }
          else{
            //  bracket mismatch
            printf("\nBracket Mismatch at index %d \n", i);
            return 0;
          }
       } 
   }
   
   if(isEmpty(&st) == 1) printf("\nBrackets are matching!\n");
   else printf("\nBrackets are NOT matching!\n");

    return 0;
    
}
