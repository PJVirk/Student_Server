# Student Information Server
Server that can store any information about a student such as major, email, name, and so on. 

To compile do:
g++ -std=c++17 -Werror -Wall client.cpp Major.cpp -o client.out
g++ -std=c++17 -Werror -Wall server.cpp server.cpp -o server.out
Then to run use two terminals one with client.out and one with server.out

DOES NOT WORK ON APPLE SILICON
Some issues with jsonrpccpp and Apple Silicon lead to compliation issues
