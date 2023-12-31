#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

void UserName() {
	char name[10];

	//Prompt name from user
	printf("Please enter your name: ");
	fgets(name, 10, stdin);

	//Print user's name
	printf("Hi %s :)", name);
	printf("\n");
}

int main(void) {
	for(int i=0; i<4; i++) {
        	pid_t pid = fork();

		if(pid == 0) {
			//printf("%d",pid);
			//printf("Child process => PPID=%d, PID=%d\n", getppid(), getpid());
			//Prompt name from user
			UserName();
			exit(0);
		}
		else if(pid > 0) {
			//printf("%d",pid);
			//printf("Parent process => PID=%d\n", getpid());
			printf("Waiting for child processes to finish...\n");
			wait(NULL);
			//printf("Job is done.\n");
		}
		else {
			printf("Unable to create child process.");
		}

	}
	printf("Job is done.\n");

	return EXIT_SUCCESS;
}
