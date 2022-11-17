#include <stdio.h>
#include <stdint.h>
#define page_length 12
struct exmap_iov {
	union{
		uint64_t value;
		struct{
			uint64_t page	:64- page_length;
			uint64_t len	: page_length;
			};
		struct{
		int32_t res;
		int16_t pages;
		};
	};
};

int main(){
struct exmap_iov iov [512];
printf("%ld",sizeof(iov));
return 0;
}

