FIXPATH = $1
RM = rm -f
MD := mkdir -p

CXX = gcc
CXXFLAGS := -Wall -Wextra -g
LFLAGS = 

MAIN := main
OUTPUT := ../bin
SRC := .
INCLUDE := .
LIB := ../bin
CUR_DIR_NAME := $(notdir $(shell pwd))
OBJ := ../obj/$(CUR_DIR_NAME)

OUTPUTMAIN := $(call FIXPATH, $(OUTPUT)/$(MAIN))

SOURCEDIRS := $(shell find $(SRC) -type d)
INCLUDEDIRS := $(shell find $(INCLUDE) -type d)
LIBDIRS := $(shell find $(LIB) -name "*.so")

INCLUDES := $(patsubst %, -I%, $(INCLUDEDIRS:%/=%))
SOURCES := $(wildcard $(patsubst %, %/*.c, $(SOURCEDIRS)))
LIBS := $(LIBDIRS)
OBJECTS := $(patsubst $(SRC)/%, $(OBJ)/%, $(SOURCES:.c=.o))

OBJDIRS := $(dir $(OBJECTS))

all:$(OUTPUT) $(OBJDIRS) $(MAIN)
	@echo excuting "all" complete.

$(OUTPUT):
	$(MD) $(OUTPUT)

$(OBJ)/%:
	$(MD) $@

$(MAIN): $(OBJECTS)
	$(CXX) -o $(OUTPUTMAIN) $(CXXFLAGS) $(LFLAGS) $(INCLUDES) $(LIBS) $(OBJECTS)

$(OBJ)/%.o: $(SRC)/%.c
	$(CXX) -o $@ -c $< $(CXXFLAGS) $(INCLUDES)

.PHONY: clean
clean:
	find $(OBJ) -name "*.o" | xargs rm -rf
	rm -rf $(OUTPUTMAIN)

.PHONY: test
test:
	@echo "FIXPATH:$(FIXPATH)"
	@echo "MAIN:$(MAIN)"
	@echo "OUTPUTMAIN:$(OUTPUTMAIN)"
	@echo CXX: $(CXX)
	@echo CXXFLAGS:$(CXXFLAGS)
	@echo LFLAGS:$(LFLAGS)
	@echo OUTPUT:$(OUTPUT)
	@echo SRC:$(SRC)
	@echo INCLUDE:$(INCLUDE)
	@echo LIB:$(LIB)
	@echo CUR_DIR_NAME:$(CUR_DIR_NAME)
	@echo "OBJ:$(OBJ)"
	@echo "SOURCEDIRS:$(SOURCEDIRS)"
	@echo "INCLUDEDIRS:$(INCLUDEDIRS)"
	@echo "LIBDIRS:$(LIBDIRS)"
	@echo "INCLUDES:$(INCLUDES)"
	@echo "SOURCES:$(SOURCES)"
	@echo "LIBS:$(LIBS)"
	@echo "OBJECTS:$(OBJECTS)"
	@echo "OBJDIRS:$(OBJDIRS)"
