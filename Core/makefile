Sources = $(wildcard *.cpp)#源文件名称
Headers = $(wildcard *.h)#头文件名称
Objects = $(Sources:%.cpp=%.o)
Library = ncurses
exec = Klotski#可执行文件的名称

$(exec): $(Objects)
	clang++ $^ -o $@ --std=c++11 -O2 

$(Objects): %.o: %.cpp $(Headers)
	clang++ -c $< -o $@ --std=c++11 -O2 

clean: 
	rm *.o $(exec)

rebuild: clean $(exec)

explain:
	@echo "Headers: $(Headers)"
	@echo "Sources: $(Sources)"
	@echo "Objects: $(Objects)"
	@echo "exec: $(exec)"

.PHONY:clean rebuild explain
