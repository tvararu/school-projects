#include <iostream>
#include <cstdio>
#include <cstdlib>
using namespace std;

void printeff ( char *format, ... ) {
  va_list argptr;             

  va_start( argptr, format );          

  while( *format != '\0' ) {
    // string
    if( *format == 's' ) {
      char* s = va_arg( argptr, char * );
      printf( "Printing a string: %s\n", s );
    }
    // character
    else if( *format == 'c' ) {
      char c = (char) va_arg( argptr, int );
      printf( "Printing a character: %c\n", c );
      break;
    }
    // integer
    else if( *format == 'd' ) {
      int d = va_arg( argptr, int );
      printf( "Printing an integer: %d\n", d );
    }          

    *format++;
  }            
	f
  va_end( argptr );
}

int main (int argc, char const *argv[])
{
	printeff ("sdc", "This is a string", 29, 'X');
	
	return 0;
}
