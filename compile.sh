g++ -o game main.cpp ./src/*.cpp -lraylib -lGL -lm -lpthread -ldl -lrt -lX11
if [[ $? == 0 ]]; then
	./game
fi
