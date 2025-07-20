FROM ubuntu:22.04

ENV DEBIAN_FRONTEND=noninteractive

# Dependence packages for buildroot, kernel, u-boot
RUN apt-get update && apt-get install -y \
    build-essential git wget unzip cpio rsync bc \
    python3 gawk flex bison texinfo libncurses5-dev \
    libssl-dev libelf-dev libtool automake cmake \
    pkg-config python3-distutils locales sudo \
    libudev-dev libusb-1.0-0-dev device-tree-compiler \
    u-boot-tools gcc-aarch64-linux-gnu nano \
    python3-pyelftools gcc-arm-linux-gnueabi \
    && apt-get clean

# User is not root for builder
RUN useradd -m rockchip && echo "rockchip ALL=(ALL) NOPASSWD:ALL" >> /etc/sudoers
RUN echo "export PS1='\[\e[1;31m\]\u\[\e[0m\]@\h:\w\$ '" >> /home/rockchip/.bashrc
RUN ln -sf /usr/bin/python3 /usr/bin/python

USER rockchip
WORKDIR /home/rockchip
