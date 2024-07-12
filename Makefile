BUILD_DIR= ./build
SRC= src/main.cpp src/Server.cpp src/ThreadPool.cpp 
LIB= -I ./lib/libevent/include 
LINK= -L./lib/libevent/lib -levent -lspdlog -lfmt
G++FLAGS= -pthread
BUILD= -o $(BUILD_DIR)/test

.PHONY:server clean run 
server:
	g++ $(SRC) $(LIB) $(LINK) $(BUILD) 

clean:
	rm $(BUILD_DIR)/server && rm $(BUILD_DIR)/client && rm $(BUILD_DIR)/test

run:
	./build/test