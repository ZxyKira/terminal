#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>
#include <conio.h>

extern void te_init(void);
extern void te_start(void);
extern void command_info_init();

int main(){
	te_init();
	command_info_init();
	te_start();
}
