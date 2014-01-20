all:
	mkdir build; mkdir bin; cd build; mkdir main; cd main; cmake ../../src; make; mv Solve ../../bin
test:
	mkdir build; mkdir bin; cd build; mkdir test; cd test; cmake ../..; make; mv runTests ../../bin 

clean:
	rm -rf build bin CMakeFiles
