#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <dirent.h>

int main() {
    pid_t pid = fork();

    if (pid == 0) {
        printf("Child PID: %d\n", getpid());

        struct stat s;
        stat("sample.txt", &s);
        printf("Size: %ld bytes\n", s.st_size);

        DIR *d = opendir(".");
        struct dirent *e;

        while ((e = readdir(d)))
            printf("%s\n", e->d_name);

        close(dirfd(d));

        execlp("date", "date", NULL);

        exit(1);
    }
    else {
        printf("Parent PID: %d\n", getpid());
        wait(NULL);
        exit(0);
    }
}
