GTKWAVE:= which gtkwave
TARGET := build/alu
CXX := g++
LD := $(CXX) 
C_FLAGS := -I${HOME}/.local/include -c -O0 -g3 -Wall
LD_OPTIONS = -L${HOME}/.local/lib -DSC_CPLUSPLUS=201703L -std=c++17 -o $(TARGET)
LIBS :=  -lsystemc
C_SOURCES = $(shell ls *.cc)
C_OBJS := $(patsubst %.cc, %.o, $(C_SOURCES))

%.o:%.cc
	@echo 'Building file: $(@F)'
	@echo '--------------------'
	@echo 'Invoking: GNU CPP Compiler'
	echo $(C_FLAGS)
	$(CXX) $(C_FLAGS) -DSC_CPLUSPLUS=201703L -std=c++17 $< -o $@
	@echo 'Finished building: $(@F)'
	@echo ' '

all:$(TARGET) 

$(TARGET): $(C_OBJS)
	@echo 'building binary $(@F)'
	$(LD) $(LD_OPTIONS) $(C_OBJS) $(LIBS)

prerequisites: 
ifneq ('$(GTKWAVE)', "/usr/bin/gtkwave")
	@echo $(GTKWAVE)
	@echo 'installing gtkwave, please be patient'
	sudo apt-get install -y gtkwave
endif

test:$(TARGET)
	./$(TARGET) 
	gtkwave -c 4 vcd_trace.vcd

clean:
	rm -f $(TARGET) *.o vcd_trace.vcd
.PHONY: $(TARGET)
