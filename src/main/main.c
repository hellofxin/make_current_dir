#include "main.h"
#include "moduleA.h"
#include "moduleB.h"


int main(){
	printf("from main: hello makefile\n");
	moduleA(1);
	moduleB(2);
	return 0;
}


