#include <iostream.h>
#include <string.h>

using namespace std;
struct nod
{
	char info[255];
	nod *left;
	nod *right;	
	
};


void srd(nod *x)
{
	if(x)
	{
		srd(x->left);
		cout<<x->info<<" ";
		srd(x->right);
	}
}
void insert2(nod *&t,char z[])
{
	nod *y = NULL;
	nod *x = t;
	nod *k = new nod;
	strcpy(k->info,z);
	k->left = 0;
	k->right = 0;

	while(x)
	{
		y = x;
		if(strcmp(k->info,x->info) > 0) x = x->left;
		else
		if(strcmp(k->info,x->info) < 0) x = x->right;
		else
		if(strcmp(k->info,x->info) == 0) break;
	}
	
	if(y==NULL) t= k;
	else
    {
	    if(strcmp(k->info,y->info) > 0)  y->left = k;
        if(strcmp(k->info,y->info) < 0)	 y->right = k;
    }
}


int main()
{
    
	nod *t = new nod;
	t = NULL;
	int n;
	cout<<"citeste numarul de cuvinte: "; cin>>n;
	cout<<"Citeste cuvintele: ";
	for(int i=0;i<n;i++)
	{
	    char x[255];
	    cin>>x;
	    insert2(t,x);
	}
	srd(t);
	return 0;
}
