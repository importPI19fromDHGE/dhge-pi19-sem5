#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<unistd.h>
#include<sys/types.h>

void active_wait(int cycles){
	for(int x=0; x < cycles; x++){
		for(int y=0; y < cycles; y++){
			y++; y--;
		}
	}
}

int main(int argc, const char* argv[]){
	srand(time(NULL) ^ getpid());
	for(int i = rand() % 55 + 2; i > 0; i--){
		printf("%d. Hallo, ich bin %s und ich melde mich gleich wieder.\n", i, argc >= 2 ? argv[1] : "Anton");
		active_wait(10000);
	}
	return 0;
}
