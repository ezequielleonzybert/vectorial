# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Release")
  file(REMOVE_RECURSE
  "CMakeFiles\\nose_autogen.dir\\AutogenUsed.txt"
  "CMakeFiles\\nose_autogen.dir\\ParseCache.txt"
  "nose_autogen"
  )
endif()
