#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "fields.h"
#include "jrb.h"
#include "jval.h"
#include <fcntl.h>

int main(int argc, char **argv)
{
  Jval jv;
  JRB t,tmp;
  IS is;
  int i;
  int size = 500;
  char *kilit[size];
  
  IS is2;

  if (argc != 2) { fprintf(stderr, "usage: printwords filename\n"); exit(1); }
  
  
  for(i=0;i<size;i++)
  {
	kilit[i] = NULL;
  }
  
  /* Open the file as an inputstruct.  Error check. */

  is = new_inputstruct("data/.kilit");
  if (is == NULL) {
	perror(argv[1]);
	exit(1);
  }
  
  is2 = new_inputstruct(argv[1]);
  if (is2 == NULL) {
    perror(argv[1]);
    exit(1);
  }
  
  t = make_jrb();

  /* Read each line with get_line().  Print out each word. */
  int len = 0;
  char *acp;char *kapap;
  while(get_line(is) >= 0) {
    for (i = 0; i < is->NF; i++) {
	acp = strchr(is->fields[i],'{');kapap = strchr(is->fields[i],'}');
	if(acp == NULL && kapap == NULL){
		kilit[len] = strdup(is->fields[i]);
		//printf("%d: %s\n", is->line, is->fields[i]);
		len++;
        }
    }
  }


//parsing kilit
  int x=0; int y=0;
  while(kilit[x] != NULL)
  {
    while(kilit[x][y] != '\0')
    {
      kilit[x][y] = kilit[x][y+1];
      if(kilit[x][y]=='"' || kilit[x][y]==',' || kilit[x][y]==':')
      {
        kilit[x][y]='\0';
      }
      y++;
    }
    x++;
    y=0;
  }
 
//çift elemanlar kelime, tek elemanlar şifrelenmiş hal
  int k=0;
  while(k < len)
  {
  //Encrypt işlemi için aşağıdaki satırla değiştirip programı bin/odev data/decripted şeklinde çalıştırabiliriz

  //jrb_insert_str(t,kilit[k],new_jval_s((char *)kilit[k+1])); 
	jrb_insert_str(t,kilit[k+1],new_jval_s((char *)kilit[k]));
	k+=2;
  }
  k=0;
  
  while(k < len)
  {
	//printf("%s\n", kilit[k]);
	k++;
  }
  int j;
  while(get_line(is2) >= 0) {
    for (i = 0; i < is2->NF; i++) {
    	if(tmp = jrb_find_str(t,is2->fields[i])){
  	  printf("%s ", tmp->val.s);
  	}

    }
  }
  
jettison_inputstruct(is2);
jettison_inputstruct(is);
  
  return 0;
}
