all: ini.o

ini.o: make.o
	touch strflip.ini; \
	echo extension=strflip.so > strflip.ini; \
	install -D -m644 strflip.ini /etc/php/conf.d/strflip.ini; \
	phpize --clean;

make.o: configure.o
	make; \
	make install; \

configure.o: phpize.o
	./configure --prefix=/usr --enable-strflip

phpize.o: config.m4 strflip.c php_strflip.h 
	phpize
