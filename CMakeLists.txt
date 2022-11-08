cmake_minimum_required(VERSION 3.20.3 FATAL_ERROR)

project(drink_machine)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(exec
src/Client.cpp
src/drinks.cpp
src/IngredientOperator.cpp
src/ClientQueueMachineHandler.cpp
src/Item.cpp
src/DrinkSellingMachine.cpp
src/IngredientStorage.cpp
src/Storage.cpp
src/Ingredient.cpp
src/PreReadyGoodsStorage.cpp
src/Orderable.cpp
src/main.cpp
src/Ingredient.h
src/Drinks.h
src/Client.h
src/PreReadyGoodsStorage.h
src/DrinkSellingMachine.h
src/Settings.h
src/Item.h
src/IngredientStorage.h
src/IngredientOperator.h
src/Storage.h
src/Orderable.h
src/ClientQueueMachineHandler.h)
