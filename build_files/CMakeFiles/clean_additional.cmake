# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "MinSizeRel")
  file(REMOVE_RECURSE
  "CMakeFiles/OOP_big_homework_autogen.dir/AutogenUsed.txt"
  "CMakeFiles/OOP_big_homework_autogen.dir/ParseCache.txt"
  "OOP_big_homework_autogen"
  )
endif()
