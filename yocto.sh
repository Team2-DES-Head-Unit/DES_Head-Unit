#!/bin/bash
if mountpoint -q /mnt/yocto; then
  sudo umount /mnt/yocto
fi

# Step 1: Create mount point and mount ext4 file
echo "Mounting ext4 file..."
sudo mkdir -p /mnt/yocto


EXT4_FILE=~/poky/HU/tmp/deploy/images/raspberrypi4-64/minam-image-raspberrypi4-64-20241009185903.rootfs.ext4
if [ ! -f "$EXT4_FILE" ]; then
  echo "Error: ext4 file not found!"
  exit 1
fi


sudo mount -o loop $EXT4_FILE /mnt/yocto


echo "Preparing rootfs directory..."
rm -rf ~/minam_rootfs && mkdir ~/minam_rootfs
sudo cp -a /mnt/yocto/* ~/minam_rootfs/
sudo chown -R $(whoami):$(whoami) ~/minam_rootfs
cd minam_rootfs


echo "Creating Dockerfile..."
cat <<EOF > Dockerfile
FROM scratch
COPY . /
CMD ["/bin/sh"]
EOF


echo "Building Docker image..."
if docker buildx build --platform linux/arm64 -t mechsoon/yoctotest -f Dockerfile .; then
  echo "Docker image built successfully!"
else
  echo "Docker build failed!"
  exit 1
fi


echo "Setting up QEMU..."
if docker run --rm --privileged multiarch/qemu-user-static --reset -p yes; then
  echo "QEMU setup successfully!"
else
  echo "QEMU setup failed!"
  exit 1
fi



echo "Running Docker container..."
docker run --platform linux/arm64 -it -v /tmp/.X11-unix:/tmp/.X11-unix -e DISPLAY=$DISPLAY mechsoon/yoctotest


