# THIS FILE IS AUTOMATICALLY GENERATED
# Project: D:\GIT\Microcontroller System Design Projects\HW5-MiniScope\MiniScope.cydsn\MiniScope.cyprj
# Date: Mon, 06 May 2019 21:56:15 GMT
#set_units -time ns
create_clock -name {ADCInput_intClock(FFB)} -period 166.66666666666666 -waveform {0 83.3333333333333} [list [get_pins {ClockBlock/ff_div_7}]]
create_clock -name {Clock_1(FFB)} -period 1000000 -waveform {0 500000} [list [get_pins {ClockBlock/ff_div_8}]]
create_clock -name {CyRouted1} -period 41.666666666666664 -waveform {0 20.8333333333333} [list [get_pins {ClockBlock/dsi_in_0}]]
create_clock -name {CyILO} -period 31250 -waveform {0 15625} [list [get_pins {ClockBlock/ilo}]]
create_clock -name {CyLFClk} -period 31250 -waveform {0 15625} [list [get_pins {ClockBlock/lfclk}]]
create_clock -name {CyIMO} -period 41.666666666666664 -waveform {0 20.8333333333333} [list [get_pins {ClockBlock/imo}]]
create_clock -name {CyHFClk} -period 41.666666666666664 -waveform {0 20.8333333333333} [list [get_pins {ClockBlock/hfclk}]]
create_clock -name {CySysClk} -period 41.666666666666664 -waveform {0 20.8333333333333} [list [get_pins {ClockBlock/sysclk}]]
create_generated_clock -name {GLCD_SPIM_UDB_IntClock} -source [get_pins {ClockBlock/hfclk}] -edges {1 3 5} [list [get_pins {ClockBlock/udb_div_0}]]
create_generated_clock -name {ADCInput_intClock} -source [get_pins {ClockBlock/hfclk}] -edges {1 5 9} [list]
create_generated_clock -name {Clock_1} -source [get_pins {ClockBlock/hfclk}] -edges {1 24001 48001} [list]


# Component constraints for D:\GIT\Microcontroller System Design Projects\HW5-MiniScope\MiniScope.cydsn\TopDesign\TopDesign.cysch
# Project: D:\GIT\Microcontroller System Design Projects\HW5-MiniScope\MiniScope.cydsn\MiniScope.cyprj
# Date: Mon, 06 May 2019 21:56:11 GMT