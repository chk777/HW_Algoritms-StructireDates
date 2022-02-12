#include <stdio.h>

//Функция копирующая односвязный список
Node *copyList(Node *head)
{
    for (Node* cur = head; cur != NULL; cur = cur->next) {
        Node* dup = (Node*)malloc(sizeof(Node));
        dup->data = cur->data;
        dup->next = cur->random;
        cur->random = dup;
    }
    Node* result = head->random;
    for (Node* cur = head; cur != NULL; cur = cur->next) {
        Node* dup = cur->random;
        dup->random = dup->next->random;
    }
    for (Node* cur = head; cur != NULL; cur = cur->next) {
        Node* dup = cur->random;
        cur->random = dup->next;
        dup->next = cur->next ? cur->next->random : NULL;
    }
    return result;
}

//Алгоритм проверяющий отсортирован ли связный список

bool isSorted = true;
for(int i = 0;i < cglist.Count; i++)
{
   if( i == cglist.Count - 1)
   {
      break;
   }

   if(cglist[i] > cglist[i + 1])
   {
      isSorted = false;
   }
}
 //программа которая определяет, является ли введенная скобочная последовательность правильной.
char * brackets_check(const char * s) {
    switch ( *s ) {
        case '\0' :
        case ')' :
        case '}' :
        case ']' :
            return (char*)s;
        case '(' : {
            char * ret = brackets_check(s + 1);
            return ( *ret == ')' ) ? brackets_check(ret + 1) : (char*)s;
        }
        case '{' : {
            char * ret = brackets_check(s + 1);
            return ( *ret == '}' ) ? brackets_check(ret + 1) : (char*)s;
        }
        case '[' : {
            char * ret = brackets_check(s + 1);
            return ( *ret == ']' ) ? brackets_check(ret + 1) : (char*)s;
        }
        default :
            return brackets_check(s + 1);
    }
}
 
int main(void) {
    char buf[BUFSIZ];
    
    while ( printf("String: ") && fgets(buf, BUFSIZ, stdin) && *buf != '\n' )
        printf("%s\n", ( *brackets_check(buf) ) ? "FAIL" : "OK");
    
    return 0;
}
