src_files = ./src/main.cpp ./src/Server.cpp ./src/Multiplexer.cpp ./src/CommandQueue.cpp
include_files = ./include/main.hpp ./include/Server.hpp ./include/Multiplexer.hpp ./include/Command.hpp ./include/CommandQueue.hpp

build: 
	g++ $(include_files) $(src_files) -pthread -lssl -lcrypto -Wall -o ./bin/chatappServer

clean:
	rm ./bin/chatappServer

run:
	./bin/chatappServer
