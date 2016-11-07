#include <stdio.h>

int main(void)
{
    int c;
    while ((c = getchar()) != EOF)
    {
        switch (c) {
          case '>': printf("Ook. Ook? "); break;
          case '<': printf("Ook? Ook. "); break;
          case '+': printf("Ook. Ook. "); break;
          case '-': printf("Ook! Ook! "); break;
          case '.': printf("Ook! Ook. "); break;
          case ',': printf("Ook. Ook! "); break;
          case '[': printf("Ook! Ook? "); break;
          case ']': printf("Ook? Ook! "); break;
        }
    }
}
