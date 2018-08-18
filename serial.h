#ifndef	__SERIAL_H
#define __SERIAL_H

//serial_init("/dev/ttyUSB0", 115200, 8, 1, 'N');

int serial_init(const char *serial_path, int speed, int databits, int stopbits, int parity);
int serial_free(int serial);
int send_c(int fd, unsigned char c);
int send_s(int fd, const unsigned char *s, unsigned int len);
int recv_c(int fd, unsigned char *c);
int recv_s(int fd, unsigned char *s, unsigned int len);
int clear_serial(int fd);
int set_serial_opt(int fd, unsigned int vtime, unsigned int vmin);

#endif
