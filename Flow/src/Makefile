## Flags
CC=g++
CFLAGS=-pedantic -Wall -Wextra -O2
ifeq ($(OS), Windows_NT)
STD=-std=c++11
else
STD=-std=c++0x
endif
OBJFILES=Main.o Parameters.o DirectoryReader.o Flows.o FlowsIP.o FlowsPort.o \
FlowProcessor.o FlowProcessorIP.o FlowProcessorPort.o

.PHONY: all clean run pack
	
## Choosing target (Windows vs. Linux)
ifeq ($(OS), Windows_NT)    
    all: ..\bin\flow.exe	
    ..\bin\flow.exe: ${OBJFILES}
	${CC} ${STD} ${CFLAGS} $^ -o $@	
else
    all: ../bin/flow ${OBJFILES}   	
    ../bin/flow: $(OBJFILES)
	$(CC) ${STD} $(CFLAGS) $^ -o $@
endif

## Build dependencies
Main.o: Main.cpp FlowProcessor.h FlowProcessorIP.h FlowProcessorPort.h FlowsIP.h \
	FlowsPort.h Parameters.h Exceptions.h DirectoryReader.h
	${CC} ${STD} ${CFLAGS} -c $< -o $@

Parameters.o: Parameters.cpp Parameters.h Exceptions.h
	${CC} ${STD} ${CFLAGS} -c $< -o $@
	
DirectoryReader.o: DirectoryReader.cpp DirectoryReader.h
	${CC} ${STD} ${CFLAGS} -c $< -o $@

Flows.o: Flows.cpp Flows.h
	${CC} ${STD} ${CFLAGS} -c $< -o $@
	
FlowsIP.o: FlowsIP.cpp FlowsIP.h Flows.h IP.h
	${CC} ${STD} ${CFLAGS} -c $< -o $@
	
FlowsPort.o: FlowsPort.cpp FlowsPort.h Flows.h
	${CC} ${STD} ${CFLAGS} -c $< -o $@
	
FlowProcessor.o: FlowProcessor.cpp FlowProcessor.h
	${CC} ${STD} ${CFLAGS} -c $< -o $@
	
FlowProcessorIP.o: FlowProcessorIP.cpp FlowProcessorIP.h FlowsIP.h
	${CC} ${STD} ${CFLAGS} -c $< -o $@
	
FlowProcessorPort.o: FlowProcessorPort.cpp FlowProcessorPort.h FlowsPort.h
	${CC} ${STD} ${CFLAGS} -c $< -o $@

## Target specific make options
ifeq ($(OS), Windows_NT)    
    run:
	.\Flow.exe	
	
    clean:
	del *.o
else
    run:
	./Flow
	
    clean:
	rm *.o *~

    pack:
	tar -czf ../xbedna45.tar.gz --exclude=Flow-project --exclude=.gitignore ../src ../doc/*.pdf ../bin
endif
	
