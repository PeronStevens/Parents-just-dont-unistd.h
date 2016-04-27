#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>

int spawn(void);

int main(int argc, char **argv){

  char str[5];
  int e = 0;

  printf("Parent process %d\n", getpid());
  printf("%d\n", e);

  while (1) {

      printf("\nEnter string: ");
      scanf("%s", str);

      if (strcmp(str, "print") == 0){
          printf("%d\n", e);
      }

      if (strcmp(str, "spawn") == 0){
                e = spawn();
      }
  }

  return 0;
}

int spawn(){

    int i;

    i = fork();

    if (i == 0){

        int j;

        printf("Child %d executing\n", getpid());

        for (j = 1; j <= 5; j++){
              sleep(1);
              printf("%d\n", j);
          }

        printf("\nChild %d done executing", getpid());

    }

    return rand() % 50;
}
