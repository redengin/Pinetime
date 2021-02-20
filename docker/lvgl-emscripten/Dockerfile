FROM debian:stable-slim

# install the minimal necessary distro packages
ARG DEBIAN_FRONTEND=noninteractive
RUN apt update -qq \
 && apt install -y \
    libsdl2-dev \
    git \
    cmake \
    make \
 && rm -rf /var/cache/apt/* /var/lib/apt/lists/*;

# install emscripten-core
RUN \
    cd /opt/ \
 && git clone --depth 1 https://github.com/emscripten-core/emsdk.git \
 && cd emsdk \
 && ./emsdk install latest \
 && ./emsdk activate latest \
 # allow non-root access to cache files
 && chmod -R a+rw /opt/emsdk/upstream/emscripten/cache/

# set the environment per emsdk_env.sh
ENV PATH=$PATH:/opt/emsdk
ENV PATH=$PATH:/opt/emsdk/upstream/emscripten
ENV PATH=$PATH:/opt/emsdk/node/14.15.5_64bit/bin
ENV EMSDK=/opt/emsdk
ENV EM_CONFIG=/opt/emsdk/.emscripten
ENV EM_CACHE=/opt/emsdk/upstream/emscripten/cache
ENV EMSDK_NODE=/opt/emsdk/node/14.15.5_64bit/bin/node

# add lvgl emscripten library
RUN \
    cd /opt/ \
 && git clone --recursive --depth 1 --shallow-submodules https://github.com/littlevgl/emscripten.git

# fake a build to pull in libSDL2.a
RUN \
    cd /tmp \
 && touch dummy.c \
 && emcc -s USE_SDL=2 dummy.c \
 && rm dummy.c
