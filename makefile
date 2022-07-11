global_source_dir = ./src
control_source_dir = ${global_source_dir}/control
display_source_dir = ${global_source_dir}/display
solute_source_dir = ${global_source_dir}/solute

include_dir = ./include

bin_dir = ./bin#输出程序的的存放位置
object_dir = ./object#链接文件的存放位置

control_source = $(wildcard ${control_source_dir}/*.cpp)
display_source = $(wildcard ${display_source_dir}/*.cpp)
global_source = $(wildcard ${global_source_dir}/*.cpp)
solute_source = $(wildcard ${solute_source_dir}/*.cpp)
Source = $(wildcard ${control_source_dir}/*.cpp ${display_source_dir}/*.cpp ${global_source_dir}/*.cpp ${solute_source_dir}/*.cpp)

Include = $(wildcard ${include_dir}/*.h ${include_dir}/control/*.h ${include_dir}/display/*.h ${include_dir}/solute/*.h)

Objects  = $(patsubst %.cpp,${object_dir}/%.o,$(notdir ${Source}))

Library = ncurses
exec = ./bin/Klotski#可执行文件的名称
CFLAGS = --std=c++11 -O2
CC = g++

$(exec): $(Objects) $(Include)
	@echo "linking \033[32;1m $(notdir $@) \033[0;m from \033[30;1m $(notdir $(Objects)) \033[0;m..."
	@$(CC) $(Objects) -o $@ $(CFLAGS) -l $(Library)

$(object_dir)/%.o: $(control_source_dir)/%.cpp $(Include)
	@echo "compiling \033[30;1m $(notdir $@) \033[0;m from \033[35;1m $(notdir $<)  \033[0;m..."
	@$(CC) -c $< -o $@ --std=c++11 -O2

$(object_dir)/%.o: $(display_source_dir)/%.cpp $(Include)
	@echo "compiling \033[30;1m $(notdir $@) \033[0;m from \033[35;1m $(notdir $<) \033[0;m..."
	@$(CC) -c $< -o $@ --std=c++11 -O2 

$(object_dir)/%.o: $(global_source_dir)/%.cpp $(Include)
	@echo "compiling \033[30;1m $(notdir $@) \033[0;m from \033[35;1m $(notdir $<) \033[0;m..."
	@$(CC) -c $< -o $@ --std=c++11 -O2

$(object_dir)/%.o: $(solute_source_dir)/%.cpp $(Include)
	@echo "compiling \033[30;1m $(notdir $@) \033[0;m from \033[35;1m $(notdir $<) \033[0;m..."
	@$(CC) -c $< -o $@ --std=c++11 -O2

clean:
	@echo "clean \033[33;1m $(notdir $(exec)) \033[0;m and \033[30;1m $(notdir $(Objects)) \033[0;m" 
	@rm -r $(Objects) $(exec)

rebuild: clean $(exec)

explain:
	@echo "Source file: \033[35;1m${notdir $(Source)}\033[0;m"
	@echo "Include file: ${notdir $(Include)}"
	@echo "Object file: \033[30;1m${notdir $(Objects)}\033[0;m"
	@echo "exec: \033[33;1m${notdir $(exec)}\033[0;m"

.PHONY:clean rebuild explain
