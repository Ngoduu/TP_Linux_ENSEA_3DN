#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>

char path[] = "/sys/class/leds/fpga_led1/brightness";


int main(void){
    int fd[10];
    

    for(int i=0;i<=10;i++){
        sprintf(path, "/sys/class/leds/fpga_led%d/brightness", i);
        fd[i] = open(path,O_RDWR);

    }

    while(1){
        for(int i = 0; i < 10; i++) {
            write(fd[i], "1", 1);
            usleep(100000);
            write(fd[i], "0", 1);
        }

    }

    for(int i=0;i<=10;i++){
        close(fd[i]);
    }

}