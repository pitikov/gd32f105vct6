# ------------------ Инструменты BINUTILS и используемые комманды Unix ----------------

BINUTILS						:= arm-none-eabi-

CC								:= $(BINUTILS)gcc
LD								:= $(BINUTILS)gcc
OBJCOPY							:= $(BINUTILS)objcopy
OBJDUMP							:= $(BINUTILS)objdump

RM								:= rm -rf
MKDIR							:= mkdir -p -m 0764
ECHO							:= @echo

GDB								:= gdb-multiarch -tui
OPENOCD							:= openocd -f interface/$(DEBUG_DEVICE).cfg -c 'interface select $(DEBUG_INTERFACE)' -f target/stm32f1x.cfg

# ------------------- Каталоги проекта ------------------------------------------------
BUILD_DIR						?= ./build
OBJ_DIR							:= $(BUILD_DIR)/.obj
DEST_DIR						:= $(BUILD_DIR)/target
MAP_DIR							:= $(BUILD_DIR)/map

# ------------------- Каталоги прокета ------------------------------------------------

SRC_DIR							:= ./src
CMSIS_DIR						:= ./CMSIS
CORE_DIR						:= $(CMSIS_DIR)/Core
CORE_INC_DIR					:= $(CORE_DIR)/Include
CORE_SRC_DIR					:= $(CORE_INC_DIR:Include=Source)
DEVICE_DIR						:= ./GD32F105
DEVICE_INC_DIR					:= $(DEVICE_DIR)/Include
DEVICE_SRC_DIR					:= $(DEVICE_INC_DIR:Include=Source)
DEVICE_CFG_DIR					:= $(DEVICE_INC_DIR:Include=Config)

# ------------------- Именование целей сборки ----------------------------------------
TARGET_ELF						:= $(DEST_DIR)/$(PROJECT_NAME).elf
TARGET_BIN						:= $(TARGET_ELF:.elf=.bin)
TARGET_MAP						:= $(MAP_DIR)/$(PROJECT_NAME).map
TARGET_OBJDUMP					:= $(TARGET_MAP:.map=.objdump)
LD_SCRIPT						:= $(DEVICE_CFG_DIR)/gd32f105_gcc.ld

OBJECTS							+= $(patsubst $(SRC_DIR)/%, $(OBJ_DIR)/%.o, $(wildcard $(SRC_DIR)/*.c))
OBJECTS							+= $(patsubst $(DEVICE_SRC_DIR)/%, $(OBJ_DIR)/%.o, $(wildcard $(DEVICE_SRC_DIR)/*.c))

# ------------------- Флаги архитектуры ---------------------------------------------
ARCH_FLAGS						+= -mcpu=cortex-m3
ARCH_FLAGS						+= -march=armv7-m
ARCH_FLAGS						+= -mthumb
ARCH_FLAGS						+= -mlittle-endian
ARCH_FLAGS						+= -msoft-float

# ------------------- Флаги компиляции ----------------------------------------------
C_FLAGS							+= -MD
C_FLAGS							+= -Wall
C_FLAGS							+= -Wpedantic

ifeq ($(DEBUG_BUILD), true)
C_FLAGS							+= -Og
C_FLAGS							+= -g
C_FLAGS							+= -ggdb
C_FLAGS							+= -gdwarf-5
else
C_FLAGS							+= -O2
endif
# ------------------- Макросы компилятора -------------------------------------------
CDEF							+= __HXTAL_VALUE=$(HXTAL_VALUE)
CDEF							+= __LXTAL_VALUE=$(LXTAL_VALUE)

C_DEFS							+= $(foreach d,$(CDEF),-D$d)

# ------------------- Каталоги поиска заголовочных файлов ---------------------------
INCDIRS							+= $(SRC_DIR)
INCDIRS							+= $(CORE_INC_DIR)
INCDIRS							+= $(DEVICE_INC_DIR)

C_INCLUDES						+= $(foreach i,$(INCDIRS),-I$i)

# ------------------- Флаги компановщика --------------------------------------------
LD_FLAGS						+= -Wl,-Map=$(TARGET_MAP)
LD_FLAGS						+= -Wl,--script=$(LD_SCRIPT)
LD_FLAGS						+= -Wl,--print-memory-usage

# ------------------- Макросы компановщика ------------------------------------------
LD_DEFS							+= -Wl,--defsym=__ROM_BASE=0x08000000
LD_DEFS							+= -Wl,--defsym=__ROM_SIZE=$(FLASH_SIZE)
LD_DEFS							+= -Wl,--defsym=__RAM_BASE=0x20000000
LD_DEFS							+= -Wl,--defsym=__RAM_SIZE=$(RAM_SIZE)
LD_DEFS							+= -Wl,--defsym=__HEAP_SIZE=$(HEAP_SIZE)
LD_DEFS							+= -Wl,--defsym=__STACK_SIZE=$(HEAP_SIZE)
LD_DEFS							+= -Wl,--defsym=_start=main_venir

# ------------------- Библиотеки компановщика ---------------------------------------
LD_LIBS							+= --specs=nano.specs
ifeq ($(DEBUG_BUILD), true)
LD_LIBS							+= --specs=rdimon.specs
else
LD_LIBS							+= --specs=nosys.specs
endif

LIBS							+= g m gcc c

LD_LIBS							+= -Wl,--start-group
LD_LIBS							+= $(foreach l,$(LIBS),-l$l)
LD_LIBS							+= -Wl,--end-group

# ------------------- Правила сборки ------------------------------------------------

default: $(TARGET_ELF)

clean:
	$(ECHO) Очистка проекта $(PROJECT_NAME)
	$(RM) $(BUILD_DIR)

objdump: $(TARGET_OBJDUMP)

erase:
	$(ECHO) Цель не готова

flash: $(TARGET_BIN)
	$(ECHO) Цель не готова

openocd:
	$(ECHO) Цель не готова

gdb: $(TARGET_ELF)
	$(ECHO) Цель не готова

$(DEST_DIR):
	$(MKDIR) $@

$(MAP_DIR):
	$(MKDIR) $@

$(OBJ_DIR):
	$(MKDIR) $@

$(TARGET_BIN): $(TARGET_ELF)
	$(OBJCOPY) -Obinary $< $@

$(TARGET_ELF): $(OBJECTS) $(DEST_DIR) $(MAP_DIR)
	$(LD) -o $@ $(OBJECTS) $(ARCH_FLAGS) $(LD_FLAGS) $(LD_DEFS) $(LD_LIBS)

$(OBJ_DIR)/%.o: $(SRC_DIR)/% $(OBJ_DIR)
	$(CC) -c $< -o $@ $(ARCH_FLAGS) $(C_FLAGS) $(C_INCLUDES) $(C_DEFS)

$(OBJ_DIR)/%.o: $(DEVICE_SRC_DIR)/% $(OBJ_DIR)
	$(CC) -c $< -o $@ $(ARCH_FLAGS) $(C_FLAGS) $(C_INCLUDES) $(C_DEFS)

$(TARGET_OBJDUMP): $(TARGET_ELF) $(MAP_DIR)
	$(OBJDUMP) -xds $< > $@

include $(wildcard $(OBJ_DIR)/*.d)

.SILENT: $(OBJ_DIR)
.SILENT: $(DEST_DIR)
.SILENT: $(MAP_DIR)
.SILENT: clean