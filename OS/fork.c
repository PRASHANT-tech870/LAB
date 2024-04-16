#include<stdio.h>
#include<wait.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<sys/types.h>

int main(int argc, char *argv[]){

pid_t pid = fork();
int retval = 1;
if(pid <0){
printf("Error forking\n");
}

if(pid==0){
printf("Id of child process is %d\n", getpid());
printf("Id of parent of child process is %d\n", getppid());
execl("./pattern", argv[1], NULL);

}
else{
printf("Id of parent process is %d\n", getpid());
wait(&retval);
if(WIFEXITED(retval)==1){
printf("Child terminated success\n");
}
else{
printf("Abnormal child termination\n");
exit(0);
}
}
return 0;
}





#include<stdio.h>
#include<unistd.h>


int main(){
printf("Executing the program of child process\n Pattern loading...\n");
int n =5;

sleep(2);
for(int i=0;i<n;i++){
for(int k=1;k<n-i;k++){
printf(" ");
}
for(int j=1; j<=2*i+1;j++){

printf("*");
}
printf("\n");
}
return 0;
}
