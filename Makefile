_printf:
	sudo apt install gcc && sudo apt install binutils;
	sudo mkdir -p /usr/local/include/;
        sudo cp main.h /usr/local/include/;
        gcc -c *.c;
        sudo mkdir -p /usr/local/lib/;
        sudo ar -rcs /usr/local/lib/lib_printf.a *.o;
        rm *.o;
        sudo mkdir -p /usr/local/man/man3/;
        sudo cp ./_printf.3 /usr/local/man/man3/;
        sudo gzip /usr/local/man/man3/_printf.3;
        sudo mandb;
        echo "Successful... All Done.";
