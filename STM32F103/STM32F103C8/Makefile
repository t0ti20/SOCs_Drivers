##################################################
# *  FILE DESCRIPTION
#########################
# *  Author:  Khaled El-Sayed (@t0ti20)
# *  Created:  05.02.2023
# *  File:  Makefile
# *  Module:  Global
# *  Description:  Make File For Auto Generation
##################################################
#Select Name Of Application
Application=STM32F103C8
#Build Directory
Build=./Build
#Compiler Name
CC=arm-none-eabi-
#Compiler Flags
CFLAGS = -gdwarf-4 -mcpu=cortex-m3 -mthumb -O0 -g
#Asseember Flags
AFLAGS=  -gdwarf-4
#Linker Flags
LFLAGS= -gdwarf-4 -O0 --std=gnu99 -mthumb -mcpu=cortex-m3 --specs=nosys.specs -g
#External Include Directories
INCS=
# INCS+=-I /usr/lib/arm-none-eabi/include
#External Liberaries
LIBS=
# LIBS+=-L /usr/lib/arm-none-eabi/lib
# LIBS+=-L /usr/lib/arm-none-eabi/newlib
##################################################
################### Variables ####################
##################################################
SRC=$(shell find $(SOURCEDIR) -name '*.c')
SRS=$(shell find $(SOURCEDIR) -name '*.s')
SRL=$(shell find $(SOURCEDIR) -name '*.ld')
INCS+=$(shell find $(SOURCEDIR) -name '*.h' -exec dirname {} \; | uniq | sed 's/^/-I /')
OBJ=$(SRC:.c=.o) $(SRS:.s=.o)	
##################################################
################# Main Methouds ##################
##################################################
.PHONY: clean
all: $(Application).hex $(Application).bin
	@echo "========== Build Finished ========="
#*******************************************************************
#*******************************************************************
#Compile And Assimble C Files Files
%.o:%.c
	@$(CC)gcc $(CFLAGS) -c $< $(INCS) -o $(Build)/$(notdir $@)
#*******************************************************************
#*******************************************************************
#Assimble Assimply Files
%.o:%.s
	@$(CC)as $(AFLAGS) $< -o $(Build)/$(notdir $@)
#*******************************************************************
#*******************************************************************
#Link All Files And Generate ELF File
$(Application).elf: $(OBJ)
	@$(CC)gcc $(Build)/*.o $(INCS) $(LFLAGS) -T $(SRL) $(LIBS) -o $(Build)/$@ 
#*******************************************************************
#*******************************************************************
#Generate Hex File
$(Application).hex: $(Application).elf
	@$(CC)objcopy -O ihex $(Build)/$< $(Build)/$@ 
	@cp $(Build)/$(Application).elf $(Build)/$(Application).axf 
#*******************************************************************
#*******************************************************************
#Generate Binary File
$(Application).bin: $(Application).elf
	@$(CC)objcopy -O binary $(Build)/$< $(Build)/$@ 
#*******************************************************************
#*******************************************************************
#Clean All Files
.PHONY: clean
clean: 
	@rm -f -r $(Build)/*
	@echo "========= Cleaning Finished ========"
#*******************************************************************
#*******************************************************************
#Flash On Board
.PHONY: flash
flash: all
	@sudo chmod -R 777 /dev/bus/usb/
	@st-flash write $(Build)/$(Application).bin 0x08000000 > /dev/null 2>&1
	@echo "========= Flashing Finished ======="
#*******************************************************************
#*******************************************************************
#Erase The Flash 
.PHONY: erase
erase:
	@sudo chmod -R 777 /dev/
	@st-flash erase > /dev/null 2>&1
	@echo "========= Erasing Finished ========"
#*******************************************************************
#*******************************************************************
# Read The Flash 
FLASH_Address = 0x08000000
.PHONY: read do_read
read:
	@PAGE_NUMBER=$(word 2,$(MAKECMDGOALS)) SIZE_PAGES=$(word 3,$(MAKECMDGOALS)) make -C . do_read
do_read:
	@st-flash read ./Build/FLASH.bin $$(printf "0x%08x" $$(( $(FLASH_Address) + ($$PAGE_NUMBER * 1024) ))) $$(($$SIZE_PAGES * 1024))
	@sudo chmod -R 777 ./Build/
	@echo "========= Reading Finished ========"
#*******************************************************************
#*******************************************************************