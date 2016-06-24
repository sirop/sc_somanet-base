/**
 * @file flash_service.h
 * @author Synapticon GmbH <support@synapticon.com>
 */

#pragma once

#include <flash.h>

interface FlashDataInterface {
    int get_configurations(int type, unsigned char buffer[], unsigned &n_bytes);
    int set_configurations(int type, unsigned char data[n_bytes], unsigned n_bytes);
};

interface FlashBootInterface {
    int read(char data[], unsigned nbytes,  unsigned char image_num);
    int write(char data[], unsigned nbytes);
    int prepare_boot_partition(unsigned image_size);
    int erase_upgrade_image(void);
    int validate_flashing(void);
};

enum configuration_type {
    MOTCTRL_CONFIG
};

void flash_service(fl_SPIPorts &SPI,
                   interface FlashBootInterface server ?i_boot,
                   interface FlashDataInterface server (&?i_data)[n_data], unsigned n_data);
