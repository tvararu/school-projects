#include <iostream>
using namespace std;

struct node
{
  char info;
  node *next;
  node()
  {
    info = 0;
    next = 0;
  }
};

bool isEmpty (node *queue)
{
  return !queue->next;
}

void push (const char &a, node *queue, node *&back)
{
  node *add = new node;
  add->info = a;
  
  back->next = add;
  back = add;
}


void print (node *queue)
{
  node *conductor = queue;
  cout << "Coada: ";
  while (conductor->next)
  {
    conductor = conductor->next;
    cout << conductor->info << ' ';
  }
  cout << '\n';
}

char pop (node *queue, node *&back)
{
  if (isEmpty (queue))
    return 0;
  
  char info = queue->next->info;
  queue->next = queue->next->next;
  delete queue->next;
  
  if (isEmpty (queue))
    back = queue;
  
  return info;
}

char top (node *queue)
{
  if (isEmpty (queue))
    return 0;
  
  return queue->next->info;
}

int main (int argc, char const *argv[])
{
  node *coada = new node, *back = coada;
  print (coada);
  
  push ('a', coada, back);
  push ('b', coada, back);
  push ('c', coada, back);
  push ('d', coada, back);
  print (coada);
  
  cout << pop (coada, back) << endl;
  cout << pop (coada, back) << endl;
  print (coada);
  
  cout << top (coada) << endl;
  print (coada);
  
  cout << isEmpty (coada) << endl;
  pop (coada, back);
  pop (coada, back);
  cout << isEmpty (coada) << endl;
  
  push ('a', coada, back);
  push ('b', coada, back);
  push ('c', coada, back);
  push ('d', coada, back);
  print (coada);
  
  return 0;
}
