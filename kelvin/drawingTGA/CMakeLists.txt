# Copy from https://mrlvsb.github.io/upr-skripta/c/automatizace_prekladu.html
cmake_minimum_required(VERSION 3.4)

# Název projektu
project(drawingTGA)

# Přidání přepínačů překladače
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -fsanitize=address -Wall -Wextra -pedantic")

# Vytvoření programu s názvem `hra`
# Program se bude skládat ze dvou zadaných zdrojových souborů (jednotek překladu)
add_executable(drawingTGA main.c)
