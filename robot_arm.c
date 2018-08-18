#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#include "serial.h"

static unsigned int get_distance(int fd)
{
	int err;
	unsigned char buf[2] = { 0 };

	send_c(fd, 0x55);
	err = recv_s(fd, buf, 2);
	if (err < 0) {
		printf("send_s() ret %d\n", err);
		return -1;
	}

	return ((buf[0] << 8) + buf[1]) / 10;
}

static int is_say_hello_to_me(int fd)
{
	unsigned int distance = 0;

	clear_serial(fd);

	distance = get_distance(fd);
	clear_serial(fd);
	if (distance > 20 && distance < 70) {
		distance = get_distance(fd);
		clear_serial(fd);
		if (distance > 20 && distance < 70) {
			distance = get_distance(fd);
			clear_serial(fd);
			if (distance > 20 && distance < 70)
				return 1;
		}
	}

	return 0;
}

static int is_touch_me(int fd)
{
	unsigned int distance = 0;

	clear_serial(fd);

	distance = get_distance(fd);
	clear_serial(fd);
	if (distance > 2 && distance < 30) {
		distance = get_distance(fd);
		clear_serial(fd);
		if (distance > 2 && distance < 30) {
			distance = get_distance(fd);
			clear_serial(fd);
			if (distance > 2 && distance < 30)
				return 1;
		}
	}

	return 0;
}

int main(void)
{
	int fd, err;

	fd = serial_init("/dev/ttyS1", 9600, 8, 1, 'N');
	if (fd < 0) {
		printf("serial_init() ret %d\n", fd);
		return -1;
	}

	err = set_serial_opt(fd, 5, 2);
	if (err < 0) {
		printf("set_serial_opt() ret %d\n", err);
		return -2;
	}


	for (;;)
	{
		if (is_say_hello_to_me(fd))
			system("/usr/bin/swing.sh");
		if (is_touch_me(fd))
			system("/usr/bin/handshake.sh");
		usleep(200000);
	}

	serial_free(fd);

	return 0;
}
