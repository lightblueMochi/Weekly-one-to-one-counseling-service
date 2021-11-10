compile: main.cpp 
	 g++  main.cpp -o project


run: project
	 ./project


clean: project
	 rm project
