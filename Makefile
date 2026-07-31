src_files = ./src/main.cpp ./src/Server.cpp
include_files = ./include/main.hpp ./include/Server.hpp

compile: 
	g++ $(include_files) $(src_files) -pthread -Wall -o ./bin/chatappServer

clean:
	rm ./bin/chatappServer

run:
	./bin/chatappServer
