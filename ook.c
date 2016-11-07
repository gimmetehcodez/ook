#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

int getook(char *,FILE *);
int ook(char*);
void bf_interpret(char*);

int main(int argc, char **argv)
{
    if (argc != 2)
        return fprintf(stderr,"Usage: ook <ookfile>\n");

    FILE *in = fopen(argv[1],"r");

    if (!in)
        return fprintf(stderr,"Error opening file %s: %s\n",argv[1],strerror(errno));

    int i = 0;
    char buf[100] = {0}, bf[100000] = {0};
    while (getook(buf,in))
        bf[i++] = " ><+-.,[]"[ook(buf)];

    bf_interpret(bf);
}

int getook(char *buf, FILE *in)
{
    if (!fgets(buf,11,in))
        return 0;
    buf[9] = 0;
}

int ook(char *buf)
{
    if (!strcmp(buf,"Ook. Ook?"))
        return 1;
    else if (!strcmp(buf,"Ook? Ook."))
        return 2;
    else if (!strcmp(buf,"Ook. Ook."))
        return 3;
    else if (!strcmp(buf,"Ook! Ook!"))
        return 4;
    else if (!strcmp(buf,"Ook! Ook."))
        return 5;
    else if (!strcmp(buf,"Ook. Ook!"))
        return 6;
    else if (!strcmp(buf,"Ook! Ook?"))
        return 7;
    else if (!strcmp(buf,"Ook? Ook!"))
        return 8;
    else
        return 0;
}

// initialize the tape with 30,000 zeroes
unsigned char tape[30000] = {0};

// set the pointer to point at the left-most cell of the tape
unsigned char* ptr = tape;

void bf_interpret(char* input) {
    char current_char;
    size_t i;
    size_t loop;

    for (i = 0; input[i] != 0; i++) {
        current_char = input[i];
        if (current_char == '>') {
            ++ptr;
        } else if (current_char == '<') {
            --ptr;
        } else if (current_char == '+') {
            ++*ptr;
        } else if (current_char == '-') {
            --*ptr;
        } else if (current_char == '.' ) {
            putchar(*ptr);
        } else if (current_char == ',') {
            *ptr = getchar();
        } else if (current_char == '[') {
            continue;
        } else if (current_char == ']' && *ptr) {
            loop = 1;
            while (loop > 0) {
                current_char = input[--i];
                if (current_char == '[') {
                    loop--;
                } else if (current_char == ']') {
                    loop++;
                }
            }
        }
    }
}
