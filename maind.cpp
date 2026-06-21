#include "drohne.h"
#include <string>
#include <iostream>

int main(){
  drohne *d[3];
  d[0] = new drohne("na", 271);
  d[1] = new drohne("ni", 51);
  d[2] = new drohne("nis", 333);

  for (int i = 0; i < 3; i++)
  {
    d[i]->laden(5);
    d[i]->fliegen(5);
    d[i]->getakku();
    d[i]->ausgeben();
  }
  for (int i = 0; i < 3; i++)
  {
    delete d[i];
    d[i] = nullptr;

  }

  return 0;
  
  
  
 
}