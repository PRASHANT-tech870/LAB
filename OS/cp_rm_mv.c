#include<stdio.h>
#include<errno.h>
#include<fcntl.h>
#include<sys/types.h>
#include<unistd.h>
#include<stdlib.h>
#define BUF_SIZE 8192

int main(int argc, char *argv[]){
int input_fd,output_fd;
ssize_t ret_in, ret_out;

char buffer[BUF_SIZE];

if(argc!=3){
printf("Usaage cp file1 file 2");
return 1;
}

input_fd = open(argv[1], O_RDONLY);
if(input_fd ==-1){
perror("open");
return 2;
}

output_fd = open(argv[2], O_WRONLY || O_CREAT ,0644);
if(output_fd ==-1){
perror("open");
return 3;
}

while((ret_in = read(input_fd, &buffer, BUF_SIZE))>0 ){
ret_out = write(output_fd, &buffer, (ssize_t) ret_in);
if (ret_in != ret_out){
perror("wWrite");
return 4;
}

}

close(input_fd);
close(output_fd);

printf("DONE");
}







#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
int main(int argc, char *argv[]){
int input_fd, output_fd;

if(argc!=3){
printf("Usage mv file1 file20");
return 1;
}
input_fd = link(argv[1],argv[2]);
if(input_fd ==-1){
perror("Link error");
return 2;
}

output_fd = unlink(argv[1]);
if(output_fd ==-1){
printf("Unlink error");
return 3;
}

}














#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
#include<errno.h>
int main(int argc, char *argv[]){
int output_fd = unlink(argv[1]);
if(output_fd == -1){
perror("Unlink error");
return 3;
}
}



