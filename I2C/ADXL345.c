#include <stdio.h>
#include <stdlib.h>
#include <linux/i2c-dev.h>
#include <sys/ioctl.h>
#include <fcntl.h>

void main() 
{
	  int file;
    file = open("/dev/i2c-1", O_RDWR)
	  ioctl(file, I2C_SLAVE, 0x53);

	  char config[2]={0};
	  config[0] = 0x2C;
	  config[1] = 0x0A;
	  write(file, config, 2);
	
    config[0] = 0x2D;
	  config[1] = 0x08;
	  write(file, config, 2);
	
    config[0] = 0x31;
	  config[1] = 0x08;
	  write(file, config, 2);
	  sleep(1);

	  char reg[1] = {0x32};
	  write(file, reg, 1);
	  char data[6] ={0};
	  while(true)
    {
		    int xAccl = ((data[1] & 0x03) * 256 + (data[0] & 0xFF));
		    if(xAccl > 511)
			      xAccl -= 1024;

		    int yAccl = ((data[3] & 0x03) * 256 + (data[2] & 0xFF));
		    if(yAccl > 511)
			      yAccl -= 1024;

		    int zAccl = ((data[5] & 0x03) * 256 + (data[4] & 0xFF));
        if(zAccl > 511)
			      zAccl -= 1024;

		    printf("X : %d \n", xAccl);
		    printf("Y : %d \n", yAccl);
		    printf("Z : %d \n", zAccl);
	  }
}
