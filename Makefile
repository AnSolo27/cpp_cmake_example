.PHONY: all build build-container cmake format format-linux flash-stlink flash-jlink format-container shell image build-container clean clean-image clean-all
############################### Native Makefile ###############################

PROJECT_NAME ?= sample-cpp
BUILD_DIR ?= build
BUILD_TYPE ?= Debug
PLATFORM = $(if $(OS),$(OS),$(shell uname -s))

ifeq ($(PLATFORM),Windows_NT)
    BUILD_SYSTEM ?= MinGW Makefiles
    OUTPUT_EXT ?= .exe
else
	OUTPUT_EXT ?=
    ifeq ($(PLATFORM),Linux)
        BUILD_SYSTEM ?= Unix Makefiles
    else
        @echo "Unsuported platform"
        exit 1
    endif
endif

all: build

build: cmake
	$(MAKE) -C $(BUILD_DIR) --no-print-directory

cmake: $(BUILD_DIR)/Makefile

$(BUILD_DIR)/Makefile: CMakeLists.txt
	cmake \
		-G "$(BUILD_SYSTEM)" \
		-B$(BUILD_DIR) \
		-DPROJECT_NAME=$(PROJECT_NAME) \
		-DCMAKE_BUILD_TYPE=$(BUILD_TYPE) \
		-DCMAKE_EXPORT_COMPILE_COMMANDS=true

run:
	@echo "Start program"
	@echo "#############"
	build/$(PROJECT_NAME)$(OUTPUT_EXT)

clean:
	rm -rf $(BUILD_DIR)
