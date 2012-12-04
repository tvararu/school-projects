#include<iostream.h>

struct nod
{
    int info;
    nod *left;
    nod *right;
    nod *parent;
};

struct bst
{
    nod *root;
};

void preordine(nod *x)
{
    if(x!=NULL)
    {
        cout<<x->info<<" ";
        preordine(x->left);
        preordine(x->right);
    }
}

void preordine(bst *t)
{
	cout<<"\npreordine: ";
    preordine(t->root);
}

void inordine(nod *x)
{
    if(x!=NULL)
    {
		inordine(x->left);
        cout<<x->info<<" ";        
        inordine(x->right);
    }
}

void inordine(bst *t)
{
	cout<<"\nindordine: ";
    inordine(t->root);
}
void postordine(nod *x)
{
    if(x!=NULL)
    {        
        postordine(x->left);
        postordine(x->right);
		cout<<x->info<<" ";
    }
}

void postordine(bst *t)
{
	cout<<"\npostordine: ";
    postordine(t->root);
}

nod *reeSearch(nod *x, int k)
{
    if(x==NULL)    return NULL;
    if(x->info==k)    return x;
    if(x->info>k)    return reeSearch(x->left,k);
    else    return reeSearch(x->right,k);
}

bool cautare( bst *t, int k)
{
    if(reeSearch(t->root,k)==NULL)    return false;
    else
        return true;
    
}



nod *minim(nod *x)
{
    if(x==NULL)return NULL;
    while(x->left!=NULL)
    {
        x=x->left;
    }
	
    return x;
}

int getMin(nod *x)
{
    nod *y=minim(x);
    if(y!=NULL)    return y->info;
    return -1;
}
nod *maxim(nod *x)
{
    if(x==NULL)	return NULL;
    while(x->right!=NULL)
    {
        x=x->right;
    }
    return x;
}

int getMax(nod *x)
{
    nod *y=maxim(x);
    if(y!=NULL)    return y->info;
    return -1;
}
void inserare(bst *&t,nod *&z)
{    
    nod *x,*y=new nod;
    y=NULL;
    x=t->root;
    while(x)
    {
        y=x;
        if(z->info<x->info)
            x=x->left;
        else
            x=x->right;
    }
    z->parent=y;
    if(y==NULL)t->root=z;
    else
        if(z->info<y->info)    y->left=z;
        else    y->right=z;
    
    
}
void inserare(bst *&t, int &x)
{
    nod *z=new nod;
        z->info=x;
        z->left=NULL;
        z->right=NULL;
        z->parent=NULL;

    inserare(t,z);
}

void cmd(nod* &c,nod* &f)
{nod *aux;
 if(f->left)
    cmd(c,f->right);
 else
     {c->info=f->info;
      aux=f;
      f=f->left;
      delete aux;
      }
}

void sterg(nod *&c,int k)
{nod *aux,*f;
 if(c)
   if(c->info==k)
       if(c->left==0&&c->right==0)  //daca e nod terminal
               {delete c;
                c=0;
                }
            else
               if(c->left==0)      //are numai subordonat drept
                 {aux=c->right;
                  delete c;
                  c=aux;}
                else
                   if(c->right==0)    //are numai subordonat drept
                          {aux=c->left;
                           delete c;
                           c=aux;}
                   else
                           cmd(c,c->left);  //are ambii subordonati
 
   else
     if(c->info<k)
            sterg(c->right,k);
     else
            sterg(c->left,k);
 
 else
      cout<<"valoarea de sters nu se gaseste in arbore ";
}

int main()
{
    bst *t=new bst;
    t->root=NULL;
    int n,i,x;
	cout<<"\nciteste numerul de noduri: ";
    cin>>n;
	cout<<"\nelementele arborelui:";
    for(i=0;i<n;i++)
    {
        cin>>x;
        inserare(t,x);
    }
    preordine(t);
	inordine(t);
	postordine(t);
	cout<<"\nminimul este: "<<getMin(t->root);
	cout<<"\nMaximul este: "<<getMax(t->root);
	
	int a;
	cout<<"\nciteste elementul cautat: ";	cin>>a;
	int k=cautare(t,a);
	if (k)	cout<<"\ngasit";
	else	cout<<"\nElm "<<a<<" nu este in arbore";
	
	cout<<"\nciteste nodul dorit sters: "; cin>>a;
	
	sterg(t->root,x);
	inordine(t);
	
    cout<<"\n";	system("pause");
    return 0;
}
