#include <sys/types.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <string.h>


int commandLineArg;
int main(int argc, char const *argv[]) {
  int t1 = 0 , t2 = 1, nextTerm;
  // Pass argument to integer a;
  commandLineArg = atoi(argv[1]); // AlphanumericToInteger C lib. method;

  pid_t pid; // Creates variable 'pid' of type 'pid_t'
  pid = fork(); // Forks new child process;

  if(pid == 0){
    // till specified argv from comm. line;
    for (size_t i = 0; i < commandLineArg; i++) {
        printf("%d ", t1);
        nextTerm = t1 + t2;
        t1 = t2;
        t2 = nextTerm;
      }
  }
  else {
    wait(NULL); // Parent invokes sysCall, waits till child terminates;
  }
  return 0;
}
