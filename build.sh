#! /bin/bash

if [ ! -d "build" ]; then
	mkdir build
fi

cmake -B build
make -C build clean
make -C build
