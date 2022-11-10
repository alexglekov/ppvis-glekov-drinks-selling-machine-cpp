cmake_minimum_required(VERSION 3.20.3 FATAL_ERROR)

project(drink_machine)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(exec
../../base/abstract/Orderable.h
../../base/config/Settings.h
../../base/drink_selling_machine/DrinkSellingMachine.h
../../base/drink_selling_machine/machine_elements/PreReadyGoodsStorage.h
../../base/drink_selling_machine/machine_elements/IngredientStorage.h
../../base/drink_selling_machine/machine_elements/IngredientOperator.h
../../base/drink_selling_machine/machine_elements/Storage.h
../../base/drink_selling_machine/goods/Ingredient.h
../../base/drink_selling_machine/goods/Drinks.h
../../base/drink_selling_machine/goods/Item.h
../../base/client/Client.h
../../base/ClientQueueMachineHandler.h
../../base/abstract/Orderable.cpp
../../base/drink_selling_machine/DrinkSellingMachine.cpp
../../base/drink_selling_machine/machine_elements/IngredientOperator.cpp
../../base/drink_selling_machine/machine_elements/IngredientStorage.cpp
../../base/drink_selling_machine/machine_elements/Storage.cpp
../../base/drink_selling_machine/machine_elements/PreReadyGoodsStorage.cpp
../../base/drink_selling_machine/goods/Drinks.cpp
../../base/drink_selling_machine/goods/Item.cpp
../../base/drink_selling_machine/goods/Ingredient.cpp
../../base/client/Client.cpp
./DrinkSellingMachine.h
./DrinkSellingMachine.cpp
./Handler.h
./Handler.cpp
./main.cpp)
