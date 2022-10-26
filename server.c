#include "common.h"


int main()
{

  struct sockaddr_in address;

  // configures network information
  address.sin_family = AF_INET;
  address.sin_addr.s_addr = htonl(INADDR_ANY);
  address.sin_port = htons(PORT);

  int sockid;

  // creates socket and returns error if fails
  if ((sockid = socket(AF_INET, SOCK_STREAM, 0)) < 0) 
  {
    perror("cannot create socket"); 
    return -1; 
  }  

  // binds socket to ip and throws error if fails
  if (bind(sockid, (struct sockaddr *)&address, sizeof(address)) < 0)
  {
    perror("failed to bind socket");
    return -1;
  }

}
