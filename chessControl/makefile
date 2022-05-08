Sources = $(wildcard *.cpp)#源文件名称
Headers = $(wildcard *.h)#头文件名称
Objects = $(Sources:%.cpp=%.o)
exec = testRun#可执行文件的名称

$(exec): $(Objects)
	$(CXX) $^ -o $@ 

$(Objects): %.o: %.cpp $(Headers)
	$(CXX) -c $< -o $@ -I $(Headers)

clean: 
	rm *.o $(exec)

rebuild: clean $(exec)

explain:
	@echo "Headers: $(Headers)"
	@echo "Sources: $(Sources)"
	@echo "Objects: $(Objects)"
	@echo "exec: $(exec)"

.PHONY:clean rebuild explain
