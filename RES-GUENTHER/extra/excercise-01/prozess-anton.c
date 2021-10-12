#include<stdio.h>

void active_wait(int cycles){
	for(int x=0; x < cycles; x++){
		for(int y=0; y < cycles; y++){
			y++; y--;
		}
	}
}

int main(){
	for(int i=0; i<100;i++) active_wait(10000);
	return 0;
}
