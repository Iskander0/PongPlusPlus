# PongPlusPlus
Simple pong clone I made using Raylib and C++.

How to compile on Linux (If you have raylib setup) :
`g++ main.cpp -Ofast -lraylib -lGL -lm -lpthread -ldl -lrt -lX11`

How to setup Raylib

Step 1 : https://github.com/raysan5/raylib/wiki/Working-on-GNU-Linux#install-required-tools.
Step 2 : https://github.com/raysan5/raylib/wiki/Working-on-GNU-Linux#install-required-libraries.
Step 3 : https://github.com/raysan5/raylib/wiki/Working-on-GNU-Linux#build-raylib-using-make.

For step 3 I recommend going with `make PLATFORM=PLATFORM_DESKTOP` and `sudo make install` to install the static version! 
