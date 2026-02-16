#include <iostream>
#include <unistd.h>
#include <sys/wait.h>

int main() {
    int counter = 0;

    std::cout << "Start | PID: " << getpid()
              << " PPID: " << getppid()
              << " Counter: " << counter << std::endl;

    std::cout << "Before fork1 | PID: " << getpid()
              << " Counter: " << counter << std::endl;

    pid_t pid1 = fork();

    std::cout << "After fork1 | PID: " << getpid()
              << " PPID: " << getppid()
              << " pid1: " << pid1
              << " Counter: " << counter << std::endl;

    counter++;

    std::cout << "Before fork2 | PID: " << getpid()
              << " Counter: " << counter << std::endl;

    pid_t pid2 = fork();

    std::cout << "After fork2 | PID: " << getpid()
              << " PPID: " << getppid()
              << " pid2: " << pid2
              << " Counter: " << counter << std::endl;

    counter++;

    if (pid2 == 0) {
        sleep(2);
    }

    if (pid2 > 0) {
        waitpid(pid2, NULL, 0);
    }

    if (pid1 > 0) {
        waitpid(pid1, NULL, 0);
    }

    std::cout << "End | PID: " << getpid()
              << " PPID: " << getppid()
              << " Counter: " << counter << std::endl;

    return 0;
}
