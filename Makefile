main: main.o 
	g++ -o $@ @flags $^ 

main.o: main.cpp
	g++ -c $^ @flags




.PHONY: clean wipe format
clean:
	ls | grep -E ".*\.o$\" | xargs -I{} rm {}
wipe: clean
	if [ -f main ]; then rm main; fi
format:
	clang-format -i main.cpp
	ls src/ | grep -E ".*\.((c|h)pp|h)$\" | xargs -I{} clang-format -i src/{}
	ls include/ | grep -E ".*\.((c|h)pp|h)$\" | xargs -I{} clang-format -i include/{}