all: ini.o

ini.o: make.o
	touch country.ini; 
	echo extension=country.so > country.ini; 
	install -D -m644 country.ini $(DESTDIR)/$(CONFDIR)/country.ini; 
	phpize --clean;
	rm country.ini;

make.o: configure.o
	make;
	make all install INSTALL_ROOT=$(DESTDIR);

configure.o: phpize.o
	./configure  --enable-country;

phpize.o: config.m4 country.c php_country.h 
	phpize;
