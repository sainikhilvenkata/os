
#include <iostream> 
#include <sys/ipc.h> 
#include <sys/shm.h> 
#include <stdio.h> 
using namespace std; 
  
int main() 
{ 
  
  int msgqid,i=0;
 msgqid=msgget(42L, 0666|IPC_CREAT);
 printf("Message queue id:%d\n",msgqid);
 printf("Enter the messages....\n");
 for(i=1;;i++)
	{
	scanf("%s",buff.text); 	 
	buff.msgid=i;
	int len=strlen(buff.text);		 
	msgsnd(msgqid,&buff,len+1,0);
 	if(!strcmp(buff.text,"bye") )
 		{break;}
	}
 msgctl(msgqid,IPC_RMID,NULL);
return 0;
}
