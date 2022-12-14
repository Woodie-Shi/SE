CC = g++
src = data_structure.o preprocess.o judge.o output.o main.o
target = equivalence.exe
$(target):$(src)
	$(CC) $^ -o $(target)

%.o:%.cpp
	$(CC) -c $< -o $@

.PHONY: clean
clean: 
	rm $(src) -f
