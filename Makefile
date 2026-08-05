src_files = ./src/main.cpp ./src/Server.cpp ./src/Multiplexer.cpp
include_files = ./include/main.hpp ./include/Server.hpp ./include/Multiplexer.hpp

build: 
	g++ $(include_files) $(src_files) -pthread -Wall -o ./bin/chatappServer

clean:
	rm ./bin/chatappServer

run:
	./bin/chatappServer
