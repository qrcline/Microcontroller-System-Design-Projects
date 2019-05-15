# THIS FILE IS AUTOMATICALLY GENERATED
# Project: D:\GIT\Microcontroller System Design Projects\HW6- MotorControll\MotorControll.cydsn\MotorControll.cyprj
# Date: Tue, 14 May 2019 06:15:19 GMT
#set_units -time ns
create_clock -name {CapSense_ModClk(FFB)} -period 10625 -waveform {0 5312.5} [list [get_pins {ClockBlock/ff_div_6}]]
create_clock -name {CapSense_SnsClk(FFB)} -period 10625 -waveform {0 5312.5} [list [get_pins {ClockBlock/ff_div_5}]]
create_clock -name {Clock_2(FFB)} -period 1000 -waveform {0 500} [list [get_pins {ClockBlock/ff_div_8}] [get_pins {ClockBlock/ff_div_9}] [get_pins {ClockBlock/ff_div_10}] [get_pins {ClockBlock/ff_div_11}]]
create_clock -name {CyRouted1} -period 41.666666666666664 -waveform {0 20.8333333333333} [list [get_pins {ClockBlock/dsi_in_0}]]
create_clock -name {CyILO} -period 31250 -waveform {0 15625} [list [get_pins {ClockBlock/ilo}]]
create_clock -name {CyLFClk} -period 31250 -waveform {0 15625} [list [get_pins {ClockBlock/lfclk}]]
create_clock -name {CyIMO} -period 41.666666666666664 -waveform {0 20.8333333333333} [list [get_pins {ClockBlock/imo}]]
create_clock -name {CyHFClk} -period 41.666666666666664 -waveform {0 20.8333333333333} [list [get_pins {ClockBlock/hfclk}]]
create_clock -name {CySysClk} -period 41.666666666666664 -waveform {0 20.8333333333333} [list [get_pins {ClockBlock/sysclk}]]
create_generated_clock -name {CapSense_ModClk} -source [get_pins {ClockBlock/hfclk}] -edges {1 255 511} [list]
create_generated_clock -name {CapSense_SnsClk} -source [get_pins {ClockBlock/hfclk}] -edges {1 255 511} [list]
create_generated_clock -name {SPIM_IntClock} -source [get_pins {ClockBlock/hfclk}] -edges {1 13 25} [list [get_pins {ClockBlock/udb_div_0}]]
create_generated_clock -name {Clock_2} -source [get_pins {ClockBlock/hfclk}] -edges {1 25 49} [list]

set_false_path -from [get_pins {__ONE__/q}]

# Component constraints for D:\GIT\Microcontroller System Design Projects\HW6- MotorControll\MotorControll.cydsn\TopDesign\TopDesign.cysch
# Project: D:\GIT\Microcontroller System Design Projects\HW6- MotorControll\MotorControll.cydsn\MotorControll.cyprj
# Date: Tue, 14 May 2019 06:15:16 GMT
