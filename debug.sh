#!/bin/sh
avrdude -p m64   -c dragon_jtag -b 460800  -U flash:w:$1.hex

sleep 2s

avarice -C -g -j usb -B 2MHz  :4242 &

ddd --debugger "avr-gdb -x gdb.conf"
exit 0

