/* UDP client in the internet domain */
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

#define HEIGHT 2
#define WIDTH  3

void error(const char *);
int main(int argc, char *argv[])
{
   int sock, n;
   unsigned int length;
   struct sockaddr_in server, from;
   struct hostent *hp;
   char buffer[32];
   FILE *myfile;
   float myvariable;
   float *ptrmyvariable = &myvariable;
   int i;
   int j;

   
   if (argc != 3) { printf("Usage: server port\n");
                    exit(1);
   }
   sock= socket(AF_INET, SOCK_DGRAM, 0);
   if (sock < 0) error("socket");

   server.sin_family = AF_INET;
   hp = gethostbyname(argv[1]);
   if (hp==0) error("Unknown host");

   bcopy((char *)hp->h_addr, 
        (char *)&server.sin_addr,
         hp->h_length);
   server.sin_port = htons(atoi(argv[2]));
   length=sizeof(struct sockaddr_in);

   myfile=fopen("sound.txt", "r");
 /*  while(1)
   {
       printf("Please enter the message: ");
       bzero(buffer,256);
       fgets(buffer,255,stdin);
       n=sendto(sock,buffer,
                strlen(buffer),0,(const struct sockaddr *)&server,length);
       if (n < 0) error("Sendto");

    }*/


  //for(i = 0; i < HEIGHT; i++)
  //{
   // for (j = 0 ; j < WIDTH; j++)
while(i=fread(buffer,sizeof(buffer), 1, myfile))
//while (fscanf(myfile, "%f", &myvariable) != EOF)
{
      //fscanf(myfile,"%f",&myvariable);
      n=sendto(sock,buffer,
                sizeof(buffer),0,(const struct sockaddr *)&server,length);
       if (n < 0) error("Sendto");
      printf("%s ",buffer);
    //}
    printf("\n");
}

  fclose(myfile);

}

void error(const char *msg)
{
    perror(msg);
    exit(0);
}


  //double myvariable;
  
  
