CC = g++
CFLAGS = -std=c++11 -Wall
TARGET = app.exe

ifdef DEBUG
	CFLAGS += -g
endif

BUILD_DIR = ./.build
SRC_DIR = ./src
INCLUDE_DIR = ./inc


${BUILD_DIR}/${TARGET}: ${BUILD_DIR}/main.o ${BUILD_DIR}/Matrix.o ${BUILD_DIR}/Functions.o ${BUILD_DIR}/TerminalFunctions.o ${BUILD_DIR}/Commands.o
	${CC} ${CFLAGS} ${BUILD_DIR}/*.o -o ${TARGET}

${BUILD_DIR}/Matrix.o: ${SRC_DIR}/Matrix.cpp ${INCLUDE_DIR}/Matrix.hpp
	${CC} ${CFLAGS} -I ${INCLUDE_DIR} -c ${SRC_DIR}/Matrix.cpp -o ${BUILD_DIR}/Matrix.o

${BUILD_DIR}/Functions.o: ${SRC_DIR}/Functions.cpp ${INCLUDE_DIR}/Functions.hpp
	${CC} ${CFLAGS} -I ${INCLUDE_DIR} -c ${SRC_DIR}/Functions.cpp -o ${BUILD_DIR}/Functions.o

${BUILD_DIR}/TerminalFunctions.o: ${SRC_DIR}/TerminalFunctions.cpp ${INCLUDE_DIR}/TerminalFunctions.hpp
	${CC} ${CFLAGS} -I ${INCLUDE_DIR} -c ${SRC_DIR}/TerminalFunctions.cpp -o ${BUILD_DIR}/TerminalFunctions.o

${BUILD_DIR}/Commands.o: ${SRC_DIR}/Commands.cpp ${INCLUDE_DIR}/Commands.hpp
	${CC} ${CFLAGS} -I ${INCLUDE_DIR} -c ${SRC_DIR}/Commands.cpp -o ${BUILD_DIR}/Commands.o

${BUILD_DIR}/main.o: ${SRC_DIR}/main.cpp ${INCLUDE_DIR}/Commands.hpp
	${CC} ${CFLAGS} -I ${INCLUDE_DIR} -c ${SRC_DIR}/main.cpp -o ${BUILD_DIR}/main.o

clean:
	rm ${BUILD_DIR}/*