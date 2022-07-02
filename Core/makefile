global_source_dir = ./src
control_source_dir = ${global_source_dir}/control
display_source_dir = ${global_source_dir}/display

include_dir = ./include

bin_dir = ./bin#输出程序的的存放位置
object_dir = ./object#链接文件的存放位置

control_source = $(wildcard ${control_source_dir}/*.cpp)
display_source = $(wildcard ${display_source_dir}/*.cpp)
global_source = $(wildcard ${global_source_dir}/*.cpp)
Source = $(wildcard ${control_source_dir}/*.cpp ${display_source_dir}/*.cpp ${global_source_dir}/*.cpp)

Include = $(wildcard ${include_dir}/*.h ${include_dir}/control/*.h ${include_dir}/display/*.h)

Objects  = $(patsubst %.cpp,${object_dir}/%.o,$(notdir ${Source}))

Library = ncurses
exec = ./bin/Klotski#可执行文件的名称
CFLAGS = --std=c++11 -O2
CC = g++

$(exec): $(Objects) $(Include)
	$(CC) $(Objects) -o $@ $(CFLAGS) -l $(Library)

$(object_dir)/%.o: $(control_source_dir)/%.cpp $(Include)
	@echo "compiling... $(object_dir)/%.o from $(control_dir)/%.cpp"
	$(CC) -c $< -o $@ --std=c++11 -O2

$(object_dir)/%.o: $(display_source_dir)/%.cpp $(Include)
	@echo "compiling... $(object_dir)/%.o from $(control_dir)/%.cpp"
	$(CC) -c $< -o $@ --std=c++11 -O2 -l $(Library)

$(object_dir)/%.o: $(global_source_dir)/%.cpp $(Include)
	@echo "compiling... $(object_dir)/%.o from $(control_dir)/%.cpp"
	$(CC) -c $< -o $@ --std=c++11 -O2 -l $(Library)

clean: 
	rm -r $(Objects) $(exec)

rebuild: clean $(exec)

explain:
	@echo "Source file: ${notdir $(Source)}"
	@echo "Include file: ${notdir $(Include)}"
	@echo "Object file: ${notdir $(Objects)}"
	@echo "exec: ${notdir $(exec)}"

.PHONY:clean rebuild explain
