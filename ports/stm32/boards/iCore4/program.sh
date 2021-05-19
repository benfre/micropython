sudo openocd -f openocd_stm32f7.cfg -c "jlink_flash ../../build-iCore4/firmware0.bin 0x08000000 ../../build-iCore4/firmware1.bin 0x08020000"

