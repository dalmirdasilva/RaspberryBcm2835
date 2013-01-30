/**
 * Bcm2835.c
 * 
 * @author Dalmir da Silva <dalmirdasilva@gmail.com>
 */

#ifndef __RASPBERRY_BCM2835_CPP__
#define __RASPBERRY_BCM2835_CPP__ 1

#include <stdio.h>
#include <time.h>
#include <fcntl.h>
#include <sys/mman.h>
#include <unistd.h>
#include <stdlib.h>

#include "Bcm2835.h"

int Bcm2835::mapPeripheral(Peripheral *peripheral) {

    if ((peripheral->fd = open("/dev/mem", O_RDWR|O_SYNC) ) < 0) {
        perror("Bcm2835#mapPeripheral: Failed to open /dev/mem, try checking permissions.\n");
        exit(1);
    }

    peripheral->map = mmap(
        NULL,
        BLOCK_SIZE,
        PROT_READ | PROT_WRITE,
        MAP_SHARED,
        peripheral->fd,
        (unsigned long) IOBASE + peripheral->address
    );
    if (peripheral->map == MAP_FAILED) {
        perror("Bcm2835#mapPeripheral: Cannot map.");
        exit(1);
    }
    peripheral->mem = (volatile unsigned int *)peripheral->map;
    return 0;
}

void Bcm2835::unmapPeripheral(Peripheral *peripheral) {
    munmap(peripheral->map, BLOCK_SIZE);
    close(peripheral->fd);
}

#endif /* __RASPBERRY_BCM2835_CPP__ */
