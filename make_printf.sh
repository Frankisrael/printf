#!/bin/bash
echo "Attempting to install dependencies...";
sudo apt install gcc && sudo apt install binutils;
echo "Dependencies installed.";
echo "Trying to create standard header directory...";
sudo mkdir -p /usr/local/include/;
echo "Done.";
echo "Copying header file...";
sudo cp main.h /usr/local/include/;
echo "Done.";
echo "Generating object file...";
gcc -c *.c;
echo "Done.";
echo "Trying to create lib directory...";
sudo mkdir -p /usr/local/lib/;
echo "Done.";
echo "Generating static lib...";
sudo ar -rcs /usr/local/lib/lib_printf.a *.o;
echo "Done.";
rm *.o;
echo "Adding manpage...";
sudo mkdir -p /usr/local/man/man3/;
sudo cp ./_printf.3 /usr/local/man/man3/;
sudo gzip /usr/local/man/man3/_printf.3;
sudo mandb;
echo "Done."
echo "Successful... All Done."
