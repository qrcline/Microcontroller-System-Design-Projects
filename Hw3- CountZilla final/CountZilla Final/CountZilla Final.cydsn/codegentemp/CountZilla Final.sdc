# THIS FILE IS AUTOMATICALLY GENERATED
# Project: D:\GIT\Microcontroller System Design Projects\Hw3- CountZilla final\CountZilla Final\CountZilla Final.cydsn\CountZilla Final.cyprj
# Date: Tue, 16 Apr 2019 00:23:42 GMT
#set_units -time ns
create_clock -name {CyRouted1} -period 41.666666666666664 -waveform {0 20.8333333333333} [list [get_pins {ClockBlock/dsi_in_0}]]
create_clock -name {CyILO} -period 31250 -waveform {0 15625} [list [get_pins {ClockBlock/ilo}]]
create_clock -name {CyLFClk} -period 31250 -waveform {0 15625} [list [get_pins {ClockBlock/lfclk}]]
create_clock -name {CyIMO} -period 41.666666666666664 -waveform {0 20.8333333333333} [list [get_pins {ClockBlock/imo}]]
create_clock -name {CyHFClk} -period 41.666666666666664 -waveform {0 20.8333333333333} [list [get_pins {ClockBlock/hfclk}]]
create_clock -name {CySysClk} -period 41.666666666666664 -waveform {0 20.8333333333333} [list [get_pins {ClockBlock/sysclk}]]
create_generated_clock -name {GLCD_SPIM_UDB_IntClock} -source [get_pins {ClockBlock/hfclk}] -edges {1 3 5} [list [get_pins {ClockBlock/udb_div_0}]]


# Component constraints for D:\GIT\Microcontroller System Design Projects\Hw3- CountZilla final\CountZilla Final\CountZilla Final.cydsn\TopDesign\TopDesign.cysch
# Project: D:\GIT\Microcontroller System Design Projects\Hw3- CountZilla final\CountZilla Final\CountZilla Final.cydsn\CountZilla Final.cyprj
# Date: Tue, 16 Apr 2019 00:23:39 GMT
