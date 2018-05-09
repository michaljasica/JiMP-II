
project(academiaserializer)

set(HEDEAR_FILES Serialization.h)
set(SOURCE_FILES Serialization.cpp)

add_library(libacademiaserializer STATIC ${SOURCE_FILES})
target_include_directories(libacademiaserializer PUBLIC .)

add_executable(academiaserializer ${SOURCE_FILES} main.cpp)

target_link_libraries(academiaserializer libacademiaserializer)