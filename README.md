# Debian Instructions

Install Build Tools
```bash
sudo apt update

sudo apt install \
    build-essential \
    git \
    cmake \
    ninja-build \
    pkg-config
```
Build and Install SDL3
```bash
cd ~/src

git clone https://github.com/libsdl-org/SDL
cd SDL

cmake -S . -B build
cmake --build build

sudo cmake --install build
```
Update Shared Library Cache
```bash
sudo ldconfig
```
Build and Run Pong
```bash
gcc -Wall -Wextra -Wpedantic -fmax-errors=5 \
    src/*.c \
    -o pong \
    -lSDL3

./pong
```
