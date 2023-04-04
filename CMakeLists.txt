
cmake_minimum_required(VERSION 3.7...3.26)

add_subdirectory(external)

project(osmio-icd
        VERSION 0.1
        DESCRIPTION "A number of implementations of libosmio ICD's"
        LANGUAGES CXX)

add_subdirectory(platform)
