g++ -Wall -g -c src/CacheBlock.cpp -o obj/CacheBlock.o -I ./include/
g++ -Wall -g -c src/Cache.cpp -o obj/Cache.o -I ./include/
g++ -Wall -g -c src/main.cpp -o obj/main.o -I ./include/
g++ -Wall -g -c src/MainMemory.cpp -o obj/MainMemory.o -I ./include/
g++ -Wall -g -c src/Utils.cpp -o obj/Utils.o -I ./include/
g++ -Wall -g -o ./bin/tp03.out  ./obj/CacheBlock.o  ./obj/Cache.o  ./obj/main.o  ./obj/MainMemory.o  ./obj/Utils.o
./bin/tp03.out < "$1"