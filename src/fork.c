#include <stdio.h>  // printf(), perror()
#include <stdlib.h> // EXIT_SUCCESS, EXIT_FAILURE
#include <unistd.h> // fork()

int main(void) {

  pid_t pid;

  switch (pid = fork()) {

  case -1:

    // On error fork() returns -1.

    perror("fork failed");
    exit(EXIT_FAILURE);

  case 0:

    // On success fork() returns 0 in the child.

    printf(" CHILD: My PID = %ld and PPID = %ld!\n", (long) getpid(), (long) getppid());

    exit(EXIT_SUCCESS);

  default:

    // On success fork() returns the pid of the child to the parent.

    printf("PARENT: My PID = %ld and the PID of my child = %ld!\n", (long) getpid(), (long) pid);

    exit(EXIT_SUCCESS);
  }
}
