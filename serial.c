/*
============================================================================
Name : serial.c
Author : tsuibin
Version : 0.0.1
Date:  2018-08-19 
Copyright : WSYU Linux Group
Description : serial test code
============================================================================
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <termios.h>
#include <errno.h>

#include "serial.h"

#define FALSE	(-1)
#define TRUE	(0)

#define IS_TEST	(0)

static int speed_arr[] = { B38400, B19200, B9600, B4800, B2400, B1200, B300, B38400, B19200, B9600, B4800, B2400, B1200, B300, };  
static int name_arr[] = {38400,  19200,  9600,  4800,  2400,  1200,  300, 38400, 19200,  9600, 4800, 2400, 1200,  300, };  

static int set_speed(int fd, int speed)
{
	int i;
	int status;
	struct termios options;

	tcgetattr(fd, &options);

	for (i= 0; i < sizeof(speed_arr) / sizeof(int); i++)
	{
		if  (speed == name_arr[i]) {
			tcflush(fd, TCIOFLUSH);
			cfsetispeed(&options, speed_arr[i]);
			cfsetospeed(&options, speed_arr[i]);
			status = tcsetattr(fd, TCSANOW, &options);
			if  (status != 0) {
				perror("tcsetattr() set_speed");
				return -1;
			}
			tcflush(fd, TCIOFLUSH);
		}
	}

	return 0;
}

static int set_parity(int fd, int databits,int stopbits,int parity)  
{   
	struct termios options;   

	tcflush(fd,TCIFLUSH);

	if (tcgetattr(fd, &options)  !=  0) {
		perror("SetupSerial 1");
		return -1;
	}

	cfmakeraw(&options);

	switch (databits)
	{
		case 7:
			options.c_cflag |= CS7;
			break;
		case 8:
			options.c_cflag |= CS8;
			break;
		default:
			fprintf(stderr,"Unsupported data size\n");
			return -1;
	}

	switch (parity)
	{
		case 'n':
		case 'N':
			options.c_cflag &= ~PARENB;   /* Clear parity enable */
			options.c_iflag &= ~INPCK;     /* Enable parity checking */
			break;
		case 'o':
		case 'O':
			options.c_cflag |= (PARODD | PARENB);
			options.c_iflag |= INPCK;             /* Disnable parity checking */   
			break;
		case 'e':
		case 'E':
			options.c_cflag |= PARENB;     /* Enable parity */
			options.c_cflag &= ~PARODD;
			options.c_iflag |= INPCK;      /* Disnable parity checking */
			break;
		case 'S':
		case 's':  /*as no parity*/
			options.c_cflag &= ~PARENB;
			options.c_cflag &= ~CSTOPB;
			break;
		default:
			fprintf(stderr,"Unsupported parity\n");
			return -1;
	}

	switch (stopbits)  
	{     
		case 1:      
			options.c_cflag &= ~CSTOPB;    
			break;    
		case 2:      
			options.c_cflag |= CSTOPB;    
			break;  
		default:      
			fprintf(stderr,"Unsupported stop bits\n");    
			return -1;
	}

	options.c_cc[VTIME] = 0;
	options.c_cc[VMIN] = 1; /* Update the options and do it NOW */

	if (tcsetattr(fd, TCSANOW, &options) != 0)     
	{
		perror("tcsetattr()");
		return -1;
	}

	tcflush(fd,TCIFLUSH);

	return 0;
}

int set_serial_opt(int fd, unsigned int vtime, unsigned int vmin)
{
	struct termios options;

	tcflush(fd, TCIOFLUSH);
	if (tcgetattr(fd, &options) == -1) {
		perror("tcgetattr()");
		return -1;
	}

	options.c_cc[VTIME] = vtime;
	options.c_cc[VMIN] = vmin;

	if (tcsetattr(fd, TCSANOW, &options) == -1)
	{
		perror("tcsetattr()");
		return -1;
	}
	tcflush(fd, TCIOFLUSH);

	return 0;
}

int serial_init(const char *serial_path, int speed, int databits, int stopbits, int parity)
{
	int fd;

	fd = open(serial_path, O_RDWR);
	if (fd == -1) {
		perror("open() serial");
		return -1;
	}

	if (set_speed(fd, speed) == FALSE) {
		fprintf(stderr, "Set Speed Error\n");
		close(fd);
		return -2;
	}

	if (set_parity(fd, databits, stopbits, parity) == FALSE) {
		fprintf(stderr, "Set Parity Error\n");
		close(fd);
		return -3;
	}

	return fd;
}

int serial_free(int fd)
{
	if (close(fd) == -1) {
		perror("close() serial");
		return -1;
	}

	return 0;
}

int send_c(int fd, unsigned char c)
{
	int ret;

	ret = write(fd, &c, 1);
	if (ret == -1) {
		perror("write() serial");
		return -1;
	}

	return 0;
}

int send_s(int fd, const unsigned char *buf, unsigned int len)
{
	int ret;

	if (fd <= 0 || !buf || !len)
		return -1;

	ret = write(fd, buf, len);
	if (ret == -1) {
		perror("write() serial");
		return -1;
	}

	return ret;
}

int recv_c(int fd, unsigned char *c)
{
	int ret;

	ret = read(fd, c, 1);
	if (ret == -1) {
		perror("read() serial");
		return -1;
	}

	return 0;
}

int recv_s(int fd, unsigned char *buf, unsigned int len)
{
	int ret;

	if (fd <= 0 || !buf || !len)
		return -1;

	ret = read(fd, buf, len);
	if (ret == -1) {
		perror("read() serial");
		return -1;
	}

	return ret;
}

int clear_serial(int fd)
{
	return tcflush(fd, TCIOFLUSH);
}
