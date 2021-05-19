#include "py/mphal.h"

void iCore4_board_early_init(void) {
    //Reset LAN
    mp_hal_pin_output(LAN_reset);
    mp_hal_pin_low(LAN_reset);
    mp_hal_delay_ms(50);
    mp_hal_pin_high(LAN_reset);
    mp_hal_delay_ms(50);
}
