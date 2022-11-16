GCC = g++
src = data_structure.o preprocess.o judge.o output.o main.o
target = equivalence.exe
$(target):$(src)
	$(GCC) $^ -o $(target)

%.o:%.cpp
	$(GCC) -c $< -o $@

.PHONY: clean
clean: 
	rm $(src) -f