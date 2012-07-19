all: ini.o 

ini.o: make.o
	touch strflip.ini; 
	echo extension=strflip.so > strflip.ini; 
	install -D -m644 strflip.ini $(DESTDIR)/$(CONFDIR)/strflip.ini;
	phpize --clean; 
	rm strflip.ini;

make.o: configure.o
	make; 
	make all install INSTALL_ROOT=$(DESTDIR);

configure.o: phpize.o
	./configure --enable-strflip;

phpize.o: config.m4 strflip.c php_strflip.h 
	phpize;
