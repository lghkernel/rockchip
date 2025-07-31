FROM ubuntu:22.04

# Install dependencies
RUN apt-get update && apt-get install -y \
    build-essential \
    wget \
    unzip \
    cmake \
    git \
    vim \
    libssl-dev \
    libx264-dev \
    pkg-config \
    && rm -rf /var/lib/apt/lists/*

# Set working directory
WORKDIR /root

# Set colorful prompt (không cần source)
RUN echo "export PS1='\[\e[1;31m\]\u\[\e[0m\]@\h:\w\$ '" > /root/.bashrc

#docker build -t live555-env .
# docker run -it --rm -v $(pwd)/:/root/ live555-env bash