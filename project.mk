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

OBJECTS							+= $(patsubst $(SRC_DIR)/%, $(OBJ_DIR)/%.o, $(wildcard $(SRC_DIR)/*.c))
OBJECTS							+= $(patsubst $(DEVICE_SRC_DIR)/%, $(OBJ_DIR)/%.o, $(wildcard $(DEVICE_SRC_DIR)/*.c))

# ------------------- Флаги архитектуры ---------------------------------------------
ARCH_FLAGS						+= -mcpu=cortex-m3
ARCH_FLAGS						+= -march=armv7-m
ARCH_FLAGS						+= -mthumb
ARCH_FLAGS						+= -mlittle-endian
ARCH_FLAGS						+= -msoft-float

# ------------------- Флаги компиляции ---------------------------------------------

# ------------------- Каталоги поиска заголовочных файлов ---------------------------------------------

# ------------------- Флаги компановщика ---------------------------------------------

# ------------------- Библиотеки компановщика ---------------------------------------------
LD_LIBS							+= --specs=nano.specs
ifeq ($(DEBUG_BUILD), true)
LD_LIBS							+= --specs=rdimon.specs
else
LD_LIBS							+= --specs=nosys.specs
endif

# ------------------- Правила сборки ------------------------------------------------

default: $(TARGET_ELF)

clean:
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

$(TARGET_ELF): $(OBJECTS) $(DEST_DIR) $(MAP_DIR)
	$(LD) -o $@ $(OBJECTS) $(ARCH_FLAGS) $(LD_FLAGS) $(LD_DEFS) $(LD_LIBS)

$(OBJ_DIR)/%.o: $(SRC_DIR)/% $(OBJ_DIR)
	$(CC) -c $< -o $@ $(ARCH_FLAGS) $(C_FLAGS) $(C_INCLUDES) $(C_DEFS)

include $(wildcard $(OBJ_DIR)/*.d)
