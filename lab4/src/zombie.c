#include <stdio.h>
#include <unistd.h>

#include <sys/types.h>

int main() {
  pid_t child_pid = fork();
  if (child_pid < 0) {
    printf("Fork failed\n");
    return 1;
  }

  if (child_pid == 0) {
    // ребенок сразу завершается
    return 0;
  }

  printf("Parent PID: %d, child PID: %d\n", getpid(), child_pid);
  sleep(30);

  return 0;
}
