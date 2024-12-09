#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>
#include "register_helper.h"

uint32_t read_register(uint32_t *address){
	if(address==NULL){
		return 0;
	}
	return *address;
}

void write_register(uint32_t *address, uint32_t value){
	if(address==NULL){
		return;
	}
	*address=value;
}

void set_bits(uint32_t *address, uint32_t mask){
	if(address==NULL){
		return;
	}
	uint32_t reg=read_register(address);
	reg |= mask;
	write_register(address,reg);
}
void clear_bits(uint32_t *address, uint32_t mask){
	if(address==NULL){
		return;
	}
	uint32_t reg=read_register(address);
	reg &= ~mask;
	write_register(address,reg);
}
bool check_bits(uint32_t *address, uint32_t mask){
	if(*address & mask) return true;
	if(address==NULL) return false;	
  else return false;
}


