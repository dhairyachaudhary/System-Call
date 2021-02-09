/* 
	Name: Dhairya
	Roll_Number: 2019035
*/

#include <stdio.h>
#include <linux/kernel.h>
#include <stdlib.h>
#include <sys/syscall.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>
#include <sys/types.h>

int main(){

	pid_t pid;
	scanf("%d", &pid);
	char filename[256];
	scanf("%s", filename);

	if (filename==NULL){
		//If too few arguments are passed
		errno=61;
		perror("Error");
		exit(EXIT_FAILURE);
	}

	if (pid<=0){
		//If invalid PID is passed
		errno=22;
		perror("Error");
		exit(EXIT_FAILURE);
	}

	
	//System call
	long int retval = syscall(441, pid, filename);


	if (retval==-1){
		//If an invalid argument is passed (non-existent PID) or file cannot be opened or created or written to
		errno=22;
		perror("Error");
		exit(EXIT_FAILURE);
	} else if (retval==-14){
		//If string cannot be copied from user space to kernel space (Unexpected page faults etc.)
		errno=14;
		perror("Error");
		exit(EXIT_FAILURE);
	} else {
		//To denote successful execution of system call
		printf("System call sh_task_info returned %ld\n", retval);
	}

  exit(EXIT_SUCCESS);

}
