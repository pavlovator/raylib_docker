# Use Ubuntu 24.04 as the base image
FROM ubuntu:24.04

# Set the working directory to /tmp
WORKDIR /tmp

# Install dependencies and build-essential for compilers
RUN apt-get update && apt-get install -y \
    libasound2-dev \
    libx11-dev \
    libxrandr-dev \
    libxi-dev \
    libgl1-mesa-dev \
    libglu1-mesa-dev \
    libxcursor-dev \
    libxinerama-dev \
    libwayland-dev \
    libxkbcommon-dev \
    cmake \
    git \
    tar \
    vim \
    build-essential \
    && apt-get clean

# Clone the raylib repository
RUN git clone https://github.com/raysan5/raylib.git raylib

# Build and install raylib
WORKDIR /tmp/raylib
RUN mkdir build && cd build \
    && cmake -DBUILD_SHARED_LIBS=ON .. \
    && make \
    && make install \
    && ldconfig

# Clean up the git folder
RUN rm -rf /tmp/raylib

# Set the image name as raylib
LABEL name="raylib"

# Set the default command (optional)
CMD ["bash"]
