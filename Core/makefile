Sources = $(wildcard *.cpp)#源文件名称
Headers = $(wildcard *.h)#头文件名称
Objects = $(Sources:%.cpp=%.o)
exec = Kilotski#可执行文件的名称

$(exec): $(Objects)
	$(CXX) $^ -o $@	--std=c++11 

$(Objects): %.o: %.cpp $(Headers)
	$(CXX) -c $< -o $@ --std=c++11 

clean: 
	rm *.o $(exec)

rebuild: clean $(exec)

explain:
	@echo "Headers: $(Headers)"
	@echo "Sources: $(Sources)"
	@echo "Objects: $(Objects)"
	@echo "exec: $(exec)"

.PHONY:clean rebuild explain
