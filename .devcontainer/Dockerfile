FROM ubuntu:24.04

ENV DEBIAN_FRONTEND=noninteractive

RUN apt-get update && apt-get install -y \
    build-essential \
    vim \
    git \
    cmake \
    curl \
    clangd \
    clang-format \
    && rm -rf /var/lib/apt/lists/*

RUN apt-get update && apt-get install -y \
    bison \
    flex 

WORKDIR /L

CMD ["/bin/bash"]