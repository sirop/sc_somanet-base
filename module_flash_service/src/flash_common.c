/**
 * @file flash_common.c
 * @brief Flash device access
 * @author Synapticon GmbH <support@synapticon.com>
 */

#include <flash_common.h>
#include <flash.h>
#include <print.h>


fl_SPIPorts *SPI_port;

/**
 * @brief Saves the spi port in a global variable.
 * @param SPI   Struct with the port definitions.
 */
void flash_init(fl_SPIPorts *SPI) {
    SPI_port = SPI;
}

/**
 * @brief Connect to the flash. Should be called before any accessing the flash memory.
 * @return  0 if connecting was successful.
 */
int connect_to_flash(void) {
    int result = fl_connect(SPI_port);
    if (result != 0) {
        printstrln("Could not connect to flash memory");
    }
    return result;
}

