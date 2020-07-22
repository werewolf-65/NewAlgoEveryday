#include <stdio.h>
#include <stdlib.h>
#include <string.h>


#define MAX_NAME 256
#define TABLE_SIZE 10 

typedef struct{
  char name[MAX_NAME];
  int age;
} person;

person* hash_table[TABLE_SIZE];

unsigned int hash(char* name){
  //always returns the same value for a name entered 
  int length=strnlen(name,MAX_NAME);
  unsigned int hash_value=0;
  int i;
  //in this case calc the sum of all the characters in the input string
  //and multiply it by the character's value 
  for(i=0;i<length;i++){
    hash_value=hash_value+name[i];
    hash_value=(hash_value*name[i])%TABLE_SIZE;// modulo to keep the value under size 
  }
  return hash_value;
}

void init_hash_table(){
/*initializes the hash table */
  int i;
  for(i=0;i<TABLE_SIZE;i++){
    hash_table[i]=NULL;
  }
  //table is null at init
}

void print_hash_table(){
/* prints the hash table */
  int i;
  printf("Start:\n");
  for(i=0;i<TABLE_SIZE;i++){
    if(hash_table[i] == NULL){
      printf("%d\t-----\n",i);
    }
    else{
      printf("%d\t%s\n",i,hash_table[i]->name);
    }
  }
  printf("End:\n");
}

int hash_table_insert(person* p){
  if(p==NULL) return 0; //return false for null entries 
  int index=hash(p->name);
  if(hash_table[index]!=NULL){
    //if the index is already taken 
    return 0;
  }
  hash_table[index]=p;
  return 1;
}

person *hash_table_lookup(char* name){
/*looks for the input name in the hash table 
and returns the corresponding struct pointer if there is
else returns null */
  int index=hash(name);
  if(hash_table[index] !=NULL &&
    strncmp(hash_table[index]->name,name,MAX_NAME)==0){
      return hash_table[index];
  }
  else{
    return NULL;
  }
}

int hash_table_delete(char* name){
/*deletes the input struct */
  int index=hash(name);
  if(hash_table[index]!=NULL &&
      strncmp(hash_table[index]->name,name,MAX_NAME)==0){
    //if the index is already taken 
       hash_table[index]=NULL;
       return 1;
  }
  else{
    return 0;
  } 
}


int main(){
  int t;
  init_hash_table();
  print_hash_table();

  person prayana={.name="Prayana",.age=22};
  person moonshadowolf={.name="Moonshadowolf",.age=21};
  person subodh={.name="Subodh",.age=21};
  person saurav={.name="Saurav",.age=21};
  person samip={.name="Samip",.age=21};
  person mandeep={.name="Mandeep",.age=21};
  person manish={.name="Manish",.age=21};
  person omkar={.name="Omkar",.age=21};


  hash_table_insert(&prayana);
  hash_table_insert(&moonshadowolf);

  hash_table_insert(&subodh);
  hash_table_insert(&saurav);
  hash_table_insert(&samip);
  hash_table_insert(&mandeep);
  hash_table_insert(&manish);
  hash_table_insert(&omkar);
  print_hash_table();
//  printf("Prayana -> %u\n",hash("Prayana"));
//  printf("moonshadowolf->%u\n",hash("Moonshadowolf"));
  person* temp=hash_table_lookup("samidare");
  if(temp->name==NULL){
    printf("Not found\n");
  }
  else{
    printf("Found:%s\n",temp->name);
  }

 temp=hash_table_lookup("Prayana");
  if(temp->name==NULL){
    printf("Not found\n");
  }
  else{
    printf("Found\n");
  }


  hash_table_delete("Prayana");
  temp=hash_table_lookup("Prayana");
  if(temp->name==NULL){
    printf("Not found\n");
  }
  else{
    printf("Found\n");
  }
  
  print_hash_table();

  return 0;


}
