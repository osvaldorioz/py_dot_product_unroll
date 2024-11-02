cmake_minimum_required(VERSION 3.10)

project(dot_product_unroll)
set(CMAKE_CXX_STANDARD 11)
set(PYBIND11_PYTHON_VERSION 3.10)
set(CMAKE_CXX_FLAGS "-O2 -Wall -shared -std=c++20 -fPIC")

find_package(pybind11 REQUIRED)

pybind11_add_module(${PROJECT_NAME} dot_product_unroll.cpp)

target_compile_definitions(${PROJECT_NAME} PRIVATE VERSION_INFO=${EXAMPLE_VERSION_INFO})
target_include_directories(${PROJECT_NAME} PRIVATE ${PYBIND11_INCLUDE_DIRS})
#target_link_libraries(${PROJECT_NAME} PRIVATE Eigen3::Eigen)
#g++ -O3 -Wall -shared -std=c++17 -fPIC $(python3 -m pybind11 --includes) pysuma.cpp -o suma$(python3-config --extension-suffix)
#g++ -O2 -Wall -shared -std=c++20 -fPIC `python3.10 -m pybind11 --includes` dot_product_unroll.cpp -o dot_product_unroll`python3-config --extension-suffix` -I/path/to/eigen

# add the executable
# add_executable(${PROJECT_NAME} main.cpp)
# target_include_directories( ${PROJECT_NAME} PRIVATE)
# target_link_libraries(${PROJECT_NAME} PRIVATE Eigen3::Eigen)
