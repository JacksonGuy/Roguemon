g++ -g -o game main.cpp \
	./src/*.cpp \
	./src/Items/*.cpp \
	./src/Effects/*.cpp \
	-lraylib -lGL -lm -lpthread -ldl -lrt -lX11
if [[ $? == 0 ]]; then
	./game
fi
