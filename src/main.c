#include <stdio.h>

#include "freertos/FreeRTOS.h"
#include "freertos/task.h"

#include "driver/spi_master.h"

#define PIN_MOSI 23
#define PIN_MISO 19
#define PIN_SCLK 18
#define PIN_CS   5

spi_device_handle_t spi;
volatile int n;
void spi_init(void)
{
    spi_bus_config_t buscfg = {

        .mosi_io_num = PIN_MOSI,

        .miso_io_num = PIN_MISO,

        .sclk_io_num = PIN_SCLK
    };

    spi_bus_initialize(
        SPI2_HOST,
        &buscfg,
        SPI_DMA_CH_AUTO
    );

    spi_device_interface_config_t devcfg = {

        .clock_speed_hz = 1000000,

        .mode = 0,

        .spics_io_num = PIN_CS,

        .queue_size = 1
    };

    spi_bus_add_device(
        SPI2_HOST,
        &devcfg,
        &spi
    );
}
void mcp4132_write_register(uint8_t value){
    uint8_t vn = value;
    uint16_t tx_data = 0X0C  vn;

        spi_transaction_t t = {

            .length = 8,

            .tx_buffer = &tx_data
        };

        spi_device_transmit(
            spi,
            &t
        );

        printf("Byte enviado\n");
}
void mcp4132_read_register(){

}
void mcp4132_set_wiper(int value){

    mcp4132_write_register(value);
}
void mcp4132_read_register(int *value){
    int f = *value;
    int rb=0;
    rb=1/((2.0*3.1416*f*100*10^-9));
     n= ((10000-75)*128)/rb;



}
void app_main(void)
{
    spi_init();

    while(1)
    {
        
    }
}