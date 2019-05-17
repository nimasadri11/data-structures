#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>






char* reverse_string(char *s) {
    int size = strlen(s);
    
    char temp;
    
    for(int i = 0; i < size-i; i++) {
        temp = s[i];
        s[i] = s[size-(i+1)];
        printf("%c\n", s[size-i-1]);
        s[size-i-1] = temp;
    }
    return s;
} 


char *rm_extra_white_space(char *s) {
    int size = strlen(s);
    char* res = malloc(sizeof(char) + 1);
    char c;
    int j = 0;
    int cond = 0;
    for(int i = 0; i < size; i++) {
        c = s[i];
        if(isspace(c)) {
            if(cond == 0) {
                res[j] = c;
                j++;  
                cond = 1;
            }
        }
        else {
            cond = 0;
            res[j] = c;
            j++;  
        }
    }
    return res;
}



int main() {
    // char *ex = malloc(sizeof(char) * 10);
    char *ex = "this is a test";
    // int b = malloc();
    // ex[0] = 'r';ex[1] =' ';ex[2] = ' ';ex[3] = 'a';ex[4] = '\0';
    ex = rm_extra_white_space(ex);
    printf("%s\n", ex);
    
    return 0;
}

