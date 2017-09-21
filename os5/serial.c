#include "io.h"

/* All io ports are calculated relative to the dataport. */

#define SERIAL_COM1_BASE 0x3F8

#define SERIAL_DATA_PORT(base) (base)
#define SERIAL_FIFO_COMMAND_PORT(base) (base + 2)
#define SERIAL_LINE_COMMAND_PORT(base) (base + 3)
#define SERIAL_MODEM_COMMAND_PORT(base) (base + 4)
#define SERIAL_LINE_STATUS_PORT(base) (base + 5)

/* SERIAL_LINE_ENABLE_DLAB:
Tells serial port to expect first highest 8 bits on data port 
followed by the next lowest 8 bits.*/

#define SERIAL_LINE_ENABLE_DLAB 0x80

/** serial_configure_baud_rate
 *Sets speed of data being sent. Default is 115,200 bits/s
 * @param com	   COM port to configure
 * @param divisor  Baud divisor (baud = 115200/divisor)
*/

void serial_configure_baud_rate(unsigned short com, unsigned short devisor)
{
	outb(SERIAL_LINE_COMMAND_PORT(com), SERIAL_LINE_ENABLE_DLAB);
	
}
 
