cd live555 && make clean && ./genMakefiles linux && make -j$(nproc) && make install

cd ~/rtspserver/ && mkdir -p build/ && cd build/ && cmake .. && make install

cd ~/test && mkdir -p build/ && cd build/ && cmake .. && make