#include <cstdio>

int x[10];

void ex(int I, int J){
if(I<=J){
   x[I] = I; x[J] = J; ex(I+1, J-1);
   if(I % 2 != 0) {
      x[I]=J; x[J] = 9-x[I];}
   }
}

int main (int argc, char const *argv[])
{
	// char a[20], b[20];
	// 	strcpy(a,"examen20");
	// 	strcpy(b,"08");
	// 	printf("%s%s\n", strcat(a,"*"), b);
	ex(0, 9);
	
	for (int i = 0; i < 10; i++)
		printf("%d\n", x[i]);
	return 0;
}