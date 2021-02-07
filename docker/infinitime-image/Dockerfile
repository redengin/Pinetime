FROM debian:stable-slim

# install the minimal necessary distro packages
ARG DEBIAN_FRONTEND=noninteractive
RUN apt-get update -qq \
 && apt-get install -y \
      # needed to decompress the toolchain
      bzip2 \
      # needed to support CMake
      make git \
 && rm -rf /var/cache/apt/* /var/lib/apt/lists/*;

# RUN pip3 install adafruit-nrfutil

# install latest CMake
RUN  apt install -y \
       make
ARG  CMAKE_VERSION=3.17.2
ADD  https://github.com/Kitware/CMake/releases/download/v${CMAKE_VERSION}/cmake-${CMAKE_VERSION}-Linux-x86_64.sh  /tmp/cmake-install.sh
RUN  yes | sh /tmp/cmake-install.sh --skip-license --prefix=/
RUN  rm /tmp/cmake-install.sh

# install the toolchain
ARG TOOLCHAIN_TARBALL=https://developer.arm.com/-/media/Files/downloads/gnu-rm/9-2020q2/gcc-arm-none-eabi-9-2020-q2-update-x86_64-linux.tar.bz2?revision=05382cca-1721-44e1-ae19-1e7c3dc96118&la=en&hash=D7C9D18FCA2DD9F894FD9F3C3DC9228498FA281A
ADD $TOOLCHAIN_TARBALL /tmp/toolchain.tbz
RUN \
    tar xf /tmp/toolchain.tbz -C /opt/ \
 && rm /tmp/toolchain.tbz
ENV PATH="${PATH}:/opt/gcc-arm-none-eabi-9-2020-q2-update/bin/"

# provide the CMake hook
ADD Makefile /opt/
CMD make -f /opt/Makefile