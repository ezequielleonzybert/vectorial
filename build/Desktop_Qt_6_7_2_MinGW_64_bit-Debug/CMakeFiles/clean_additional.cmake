# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "CMakeFiles\\vectorial_autogen.dir\\AutogenUsed.txt"
  "CMakeFiles\\vectorial_autogen.dir\\ParseCache.txt"
  "vectorial_autogen"
  )
endif()
