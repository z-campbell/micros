#include "io.h"
#define FB_GREEN 2
#define FB_DARK_GREY 8 
#define FB_COMMAND_PORT 0x3D4
#define FB_DATA_PORT 0x3D5
#define FB_HIGH_BYTE_COMMAND 14
#define FB_LOW_BYTE_COMMAND 15
unsigned short fb_pos = 0;
unsigned short cursor_pos = 0;

void fb_move_cursor(unsigned short pos) 
{
	outb(FB_COMMAND_PORT, FB_HIGH_BYTE_COMMAND);
	outb(FB_DATA_PORT, ((pos >> 8) & 0x00FF));
	outb(FB_COMMAND_PORT, FB_LOW_BYTE_COMMAND);
	outb(FB_DATA_PORT, pos & 0x00FF);
}
void fbMove(void)
{
	fb_move_cursor(5);
}
int sum_of_three(int arg1, int arg2, int arg3)
{
	return arg1 + arg2 + arg3;
}

void fb_write_cell(unsigned int i, char c, unsigned char fg, unsigned char bg)
{	
	char *fb = (char *)0x000B8000;
	fb[i] = c;
	fb[i+1] = ((fg & 0x0F) << 4) | (bg & 0x0f);
}
void fbWrite1(char *buffer,int length)
{
        while(*buffer != '\0')
        {
                fb_write_cell(2*fb_pos, *buffer, FB_GREEN, FB_DARK_GREY);
                fb_pos++;
                fb_move_cursor(fb_pos);
                buffer++;
                cursor_pos++;
		length--;
        } 
	while(1);
}

void fbWrite(void)
{	
//	int i = 0;
	char *buff;
	char message[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	buff = (char *)message;
//	while(message[i] != '\0')
//	{
//		fb_write_cell((2*i),message[i], FB_GREEN, FB_DARK_GREY);
//		i++;
//	}
	fbWrite1(buff,25);
	//fb_write_cell(0, 'A', FB_GREEN, FB_DARK_GREY);
}


/*
struct example {
	unsigned char config;
	unsigned short address;
	unsigned char index;
}__attribute__((packed));

int main (void) 
{
	return 0;
}*/
