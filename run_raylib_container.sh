#!/bin/bash

# Ensure the script is executable
# chmod +x run_raylib_container.sh

# Container image name
IMAGE_NAME="raylib"
CONTAINER_NAME="raylib-container"

# Build the image if not already built
echo "Building Docker image '$IMAGE_NAME'..."
docker build -t $IMAGE_NAME .

# Allow Docker to access X11 for GUI rendering
xhost +local:docker

# Run the container
docker run -it \
  --rm \
  --name $CONTAINER_NAME \
  --env DISPLAY=$DISPLAY \
  --volume /tmp/.X11-unix:/tmp/.X11-unix \
  --volume "$(pwd)":/workspace \
  --workdir /workspace \
  $IMAGE_NAME bash
