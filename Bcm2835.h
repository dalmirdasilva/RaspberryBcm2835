/**
 * Bcm2835.h
 * 
 * @author Dalmir da Silva <dalmirdasilva@gmail.com>
 */

#ifndef __RASPBERRY_BCM2835_H__
#define __RASPBERRY_BCM2835_H__ 1

#define IOBASE          0x20000000

#define PAGESIZE        4096
#define BLOCK_SIZE      4096

class Bcm2835 {
    
public:
    
    
    struct Peripheral {
        
        /**
         * Memory file descriptor.
         */
        int fd;
        
        /**
         * Mapeed memory pointer
         */
        void *map;
        
        /**
         * Address in physical map that we want this memory block to expose
         */
        unsigned int address;
        
        /**
         * Mapped address
         */
        volatile unsigned int *mem;
    };

    static int mapPeripheral(Peripheral *peripheral);

    static void unmapPeripheral(Peripheral *peripheral);
};

#endif /* __RASPBERRY_BCM2835_H__ */
