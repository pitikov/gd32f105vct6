PROJECT_NAME				:= $(shell basename $(PWD))

FLASH_SIZE					:= 256K
RAM_SIZE					:= 96K

STACK_SIZE					:= 2048
HEAP_SIZE					:= 2048

HXTAL_VALUE					:= 25000000
LXTAL_VALUE					:= 32768

DEBUG_DEVICE				:= jlink
DEBUG_INTERFACE				:= jtag

DEBUG_BUILD					:= true

include project.mk
