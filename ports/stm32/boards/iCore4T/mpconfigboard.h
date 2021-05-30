#define MICROPY_HW_BOARD_NAME       "iCore4T"
#define MICROPY_HW_MCU_NAME         "STM32H743"
#define MICROPY_HW_ENABLE_RTC       (1)
#define MICROPY_HW_ENABLE_RNG       (1)
#define MICROPY_HW_ENABLE_ADC       (1)
#define MICROPY_HW_ENABLE_DAC       (1)
#define MICROPY_HW_HAS_SWITCH       (1)
#define MICROPY_HW_HAS_FLASH        (1)
#define MICROPY_HW_ENABLE_USB       (1)
#define MICROPY_HW_ENABLE_SDCARD    (1)
//#define MICROPY_HW_ENABLE_INTERNAL_FLASH_STORAGE (0)

#define MICROPY_BOARD_EARLY_INIT    iCore4T_board_early_init
void iCore4T_board_early_init(void);

// The board has an 25MHz HSE, the following gives 480MHz CPU speed
#define MICROPY_HW_CLK_PLLM (5)
#define MICROPY_HW_CLK_PLLN (192)
#define MICROPY_HW_CLK_PLLP (2)
#define MICROPY_HW_CLK_PLLQ (24)
#define MICROPY_HW_CLK_PLLR (2)

#define MICROPY_HW_CLK_PLL3M (5)
#define MICROPY_HW_CLK_PLL3N (192)
#define MICROPY_HW_CLK_PLL3P (2)
#define MICROPY_HW_CLK_PLL3Q (20)
#define MICROPY_HW_CLK_PLL3R (12)

// 4 wait states
#define MICROPY_HW_FLASH_LATENCY    FLASH_LATENCY_4

// I2C busses I2C1 to 24LC04(0x50), LM75A(0X90) and AXP152(0x40 0x30?)
#define MICROPY_HW_I2C1_SCL         (pin_B8)
#define MICROPY_HW_I2C1_SDA         (pin_B7)
// I2C3 to goldfinger
#define MICROPY_HW_I2C3_SCL         (pin_H7)
#define MICROPY_HW_I2C3_SDA         (pin_H8)

// SPI1 ExtBoard EXT_ARM_IO
#define MICROPY_HW_SPI1_NSS         (pin_A15)
#define MICROPY_HW_SPI1_SCK         (pin_B3)
#define MICROPY_HW_SPI1_MISO        (pin_G9)
#define MICROPY_HW_SPI1_MOSI        (pin_D7)

// SPI4 to FPGA
#define MICROPY_HW_SPI4_NSS         (pin_E4)
#define MICROPY_HW_SPI4_SCK         (pin_E2)
#define MICROPY_HW_SPI4_MISO        (pin_E5)
#define MICROPY_HW_SPI4_MOSI        (pin_E6)

// UART config
#define MICROPY_HW_UART1_TX         (pin_A9)
#define MICROPY_HW_UART1_RX         (pin_B15)
#define MICROPY_HW_UART2_TX         (pin_D5)
#define MICROPY_HW_UART2_RX         (pin_D6)

#define MICROPY_HW_UART_REPL        PYB_UART_2
#define MICROPY_HW_UART_REPL_BAUD   115200

// FDCAN bus
#define MICROPY_HW_CAN1_NAME  "FDCAN1"
#define MICROPY_HW_CAN1_TX    (pin_B9)
#define MICROPY_HW_CAN1_RX    (pin_H14)

// USRSW is pulled low. Pressing the button makes the input go high.
#define MICROPY_HW_USRSW_PIN        (pin_H7)
#define MICROPY_HW_USRSW_PULL       (GPIO_NOPULL)
#define MICROPY_HW_USRSW_EXTI_MODE  (GPIO_MODE_IT_FALLING)
#define MICROPY_HW_USRSW_PRESSED    (0)

// LEDs
#define MICROPY_HW_LED1             (pin_A10)    // ARM_LED
#define MICROPY_HW_LED_ON(pin)      (mp_hal_pin_low(pin))
#define MICROPY_HW_LED_OFF(pin)     (mp_hal_pin_high(pin))

//SDCard
#define MICROPY_HW_SDCARD_CK                (pin_C12)
#define MICROPY_HW_SDCARD_CMD               (pin_D2)
#define MICROPY_HW_SDCARD_D0                (pin_C8)
#define MICROPY_HW_SDCARD_D1                (pin_C9)
#define MICROPY_HW_SDCARD_D2                (pin_C10)
#define MICROPY_HW_SDCARD_D3                (pin_C11)

// #define MICROPY_HW_USB_FS              (1)
#define MICROPY_HW_USB_HS           (1)
#define MICROPY_HW_USB_HS_ULPI_NXT  (pin_H4)
#define MICROPY_HW_USB_HS_ULPI_DIR  (pin_I11)

// Ethernet via RMII
// #define MICROPY_HW_ETH_MDC          (pin_C1)
// #define MICROPY_HW_ETH_MDIO         (pin_A2)
// #define MICROPY_HW_ETH_RMII_REF_CLK (pin_A1)
// #define MICROPY_HW_ETH_RMII_CRS_DV  (pin_A7)
// #define MICROPY_HW_ETH_RMII_RXD0    (pin_C4)
// #define MICROPY_HW_ETH_RMII_RXD1    (pin_C5)
// #define MICROPY_HW_ETH_RMII_TX_EN   (pin_G11)
// #define MICROPY_HW_ETH_RMII_TXD0    (pin_G13)
// #define MICROPY_HW_ETH_RMII_TXD1    (pin_G14)

#define LAN_RXERR                   (pin_C14)
#define LAN_nRST                    (pin_C15)
/*
#define MICROPY_HW_SPIFLASH_ENABLE_CACHE (1)


// QUADSPI flash W25Q64BVSIG
#define MICROPY_HW_QSPIFLASH_SIZE_BITS_LOG2 (29)
#define MICROPY_HW_QSPIFLASH_CS     (pin_B6)
#define MICROPY_HW_QSPIFLASH_SCK    (pin_B2)
#define MICROPY_HW_QSPIFLASH_IO0    (pin_D11)
#define MICROPY_HW_QSPIFLASH_IO1    (pin_D12)
#define MICROPY_HW_QSPIFLASH_IO2    (pin_F7)
#define MICROPY_HW_QSPIFLASH_IO3    (pin_D13)


#define MICROPY_HW_BDEV_IOCTL(op, arg) ( \
     (op) == BDEV_IOCTL_NUM_BLOCKS ? (1 << MICROPY_HW_QSPIFLASH_SIZE_BITS_LOG2 / 8 / FLASH_BLOCK_SIZE) : \
     (op) == BDEV_IOCTL_INIT ? spi_bdev_ioctl(&spi_bdev, (op), (uint32_t)&spiflash_config) : \
     spi_bdev_ioctl(&spi_bdev, (op), (arg)) \
 )
#define MICROPY_HW_BDEV_READBLOCKS(dest, bl, n) spi_bdev_readblocks(&spi_bdev, (dest), (bl), (n))
#define MICROPY_HW_BDEV_WRITEBLOCKS(src, bl, n) spi_bdev_writeblocks(&spi_bdev, (src), (bl), (n))
#define MICROPY_HW_BDEV_SPIFLASH_EXTENDED (&spi_bdev) // for extended block protocol
*/


//SDRAM W98256G6JB
// #define MICROPY_HW_SDRAM_SIZE  (256 / 8 * 1024 * 1024) 
// #define MICROPY_HW_SDRAM_STARTUP_TEST             (1)
// #define MICROPY_HW_SDRAM_CAS_LATENCY        3
// #define MICROPY_HW_SDRAM_WRITE_PROTECTION   (0)
// #define MICROPY_HW_SDRAM_COLUMN_BITS_NUM    9
// #define MICROPY_HW_SDRAM_ROW_BITS_NUM       13
// #define MICROPY_HW_SDRAM_MEM_BUS_WIDTH      16
// #define MICROPY_HW_SDRAM_INTERN_BANKS_NUM   4
// #define MICROPY_HW_SDRAM_RPIPE_DELAY        1
// #define MICROPY_HW_SDRAM_CLOCK_PERIOD       2
// #define MICROPY_HW_SDRAM_RBURST             1
// #define MICROPY_HW_SDRAM_BURST_LENGTH       1
// #define MICROPY_HEAP_START  ((sdram_valid) ? sdram_start() : &_heap_start)
// #define MICROPY_HEAP_END    ((sdram_valid) ? sdram_end() : &_heap_end)

// #define MICROPY_HW_SDRAM_TIMING_TMRD        (2)
// #define MICROPY_HW_SDRAM_TIMING_TXSR        (7)
// #define MICROPY_HW_SDRAM_TIMING_TRAS        (4)
// #define MICROPY_HW_SDRAM_TIMING_TRC         (7)
// #define MICROPY_HW_SDRAM_TIMING_TWR         (2)
// #define MICROPY_HW_SDRAM_TIMING_TRP         (2)
// #define MICROPY_HW_SDRAM_TIMING_TRCD        (2)
// #define MICROPY_HW_SDRAM_REFRESH_RATE       (64) // ms
// #define MICROPY_HW_SDRAM_AUTOREFRESH_NUM    (8)

//FMC for SDRAM

// #define MICROPY_HW_FMC_SDCKE0   (pin_H2)
// #define MICROPY_HW_FMC_SDNE0    (pin_H3)
// #define MICROPY_HW_FMC_SDCLK    (pin_G8)
// #define MICROPY_HW_FMC_SDNCAS   (pin_G15)
// #define MICROPY_HW_FMC_SDNRAS   (pin_F11)
// #define MICROPY_HW_FMC_SDNWE    (pin_H5)
// #define MICROPY_HW_FMC_BA0      (pin_G4)
// #define MICROPY_HW_FMC_BA1      (pin_G5)
// #define MICROPY_HW_FMC_NBL0     (pin_E0)
// #define MICROPY_HW_FMC_NBL1     (pin_E1)
// #define MICROPY_HW_FMC_A0       (pin_F0)
// #define MICROPY_HW_FMC_A1       (pin_F1)
// #define MICROPY_HW_FMC_A2       (pin_F2)
// #define MICROPY_HW_FMC_A3       (pin_F3)
// #define MICROPY_HW_FMC_A4       (pin_F4)
// #define MICROPY_HW_FMC_A5       (pin_F5)
// #define MICROPY_HW_FMC_A6       (pin_F12)
// #define MICROPY_HW_FMC_A7       (pin_F13)
// #define MICROPY_HW_FMC_A8       (pin_F14)
// #define MICROPY_HW_FMC_A9       (pin_F15)
// #define MICROPY_HW_FMC_A10      (pin_G0)
// #define MICROPY_HW_FMC_A11      (pin_G1)
// #define MICROPY_HW_FMC_A12      (pin_G2)
// #define MICROPY_HW_FMC_D0       (pin_D14)
// #define MICROPY_HW_FMC_D1       (pin_D15)
// #define MICROPY_HW_FMC_D2       (pin_D0)
// #define MICROPY_HW_FMC_D3       (pin_D1)
// #define MICROPY_HW_FMC_D4       (pin_E7)
// #define MICROPY_HW_FMC_D5       (pin_E8)
// #define MICROPY_HW_FMC_D6       (pin_E9)
// #define MICROPY_HW_FMC_D7       (pin_E10)
// #define MICROPY_HW_FMC_D8       (pin_E11)
// #define MICROPY_HW_FMC_D9       (pin_E12)
// #define MICROPY_HW_FMC_D10      (pin_E13)
// #define MICROPY_HW_FMC_D11      (pin_E14)
// #define MICROPY_HW_FMC_D12      (pin_E15)
// #define MICROPY_HW_FMC_D13      (pin_D8)
// #define MICROPY_HW_FMC_D14      (pin_D9)
// #define MICROPY_HW_FMC_D15      (pin_D10)
