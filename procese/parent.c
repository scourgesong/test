/*Să se realizeze în limbajul C un program numit parent0 care să creeze trei procese (inclusiv părintele).
Fiecare proces își afișează PID-ul, primul proces fiu numără de la 1- 50000, al doilea proces fiu de la 50000-
100000, iar procesul părinte așteaptă terminarea fiecăruia dintre cele două procese, afișează câte un mesaj
apoi se încheie la rândul sau*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

//parinte-fiu-nepot
int main(){
int pid, fiu2, p[2], status=0;
pipe(p);

pid=fork();
if(pid==0){
	printf("[f pid=%d, p pid=%d]",getpid(),getppid());
	close(p[0]);
	int k=0;
	char* s=(char*)malloc(10);
	for(int i=0; i<10; i++)	{
		sprintf(s,"%d ",i);
		write(p[1],s,2);
		sleep(1);
	}
	status=1;
	exit(0);
} else {
    fiu2=fork();
    if(fiu2==0){
    	printf("[f2 pid=%d, p pid=%d]",getpid(),getppid());
    	close(p[0]);
    	int k=0;
    	char* s=(char*)malloc(10);
    	for(int i=10; i<20; i++){
    		sprintf(s,"%d ",i);
    		write(p[1],s,3);
    		sleep(1);
    	}
	exit(0);
    }
}



close(p[1]);
char* c;
c=(char*)malloc(10);
while(read(p[0], c, 1)==1){
	write(1,c,3);
	sleep(1);
}

return 0;
}
