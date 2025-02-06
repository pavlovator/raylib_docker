# raylib_docker
An Ubuntu 24.04 Docker image preconfigured with Raylib and C++ examples.
## Build and Run docker container
```
docker build -t raylib .
run_raylib_container.sh
```
## Build example
```
cd examples/basic_window
mkdir build
cmake ..
make
```
