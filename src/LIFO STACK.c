/*
 ============================================================================
 Name        : LIFO.c
 Author      : kero
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#define LIFO_Buffer_length 5
typedef struct {
	unsigned int length;
	unsigned char *base;
	unsigned char *head;  // as a stack pointer
	unsigned int count;
}LIFO_BUF_t;

typedef enum {
	LIFO_NO_ERROR,
	LIFO_FULL,
	LIFO_NOT_FULL,
	LIFO_EMPUTY,
	LIFO_NOT_EMPUTY,
	LIFO_NULL
}Buffer_status;

//define to function to Add and pop from the memory as a stack
Buffer_status LIFO_Add_item (LIFO_BUF_t * LBUF , unsigned char item);
Buffer_status LIFO_Pop_item (LIFO_BUF_t * LBUF , unsigned char * item);

int main(void)
{
	LIFO_BUF_t first_Buffer;
	unsigned char i,temp=0;
	unsigned char static_Buffer[LIFO_Buffer_length];
	first_Buffer.length = LIFO_Buffer_length;
	first_Buffer.base = &static_Buffer[0];
	first_Buffer.head = first_Buffer.base;

	for(i=0; i<LIFO_Buffer_length; i++)
	{
		printf("%d, ",i);
		LIFO_Add_item(&first_Buffer,i);
	}
	printf("\n");
	for(i=0; i<LIFO_Buffer_length; i++)
	{
		LIFO_Pop_item(&first_Buffer,&temp);
		printf("%d, ",temp);
	}

	return 0;
}
Buffer_status LIFO_Add_item (LIFO_BUF_t * LBUF , unsigned char item)
{
	if(!LBUF || !LBUF->head || !LBUF->base)
	{
		return LIFO_NULL;
	}
	if(LBUF->head >= LBUF->length + LBUF->base)
	{
		return LIFO_FULL;
	}
	*(LBUF->head) = item;
	LBUF->head++;
	LBUF->count++;
	return LIFO_NO_ERROR;
}



Buffer_status LIFO_Pop_item (LIFO_BUF_t * LBUF , unsigned char * item)
{
	if(!LBUF || !LBUF->head || !LBUF->base)
		{
			return LIFO_NULL;
		}
	if(LBUF->base == LBUF->head)
	{
		return LIFO_EMPUTY;
	}
	LBUF->head--;
	*item = *(LBUF->head);
	LBUF->count--;
	return LIFO_NO_ERROR;
}





