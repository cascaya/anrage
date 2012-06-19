all: ini.o

ini.o: make.o
	touch %%module-low%%.ini; \
	echo extension=%%module-low%%.so > %%module-low%%.ini; \
	install -D -m644 %%module-low%%.ini /etc/php/conf.d/%%module-low%%.ini; \
	phpize --clean; \
	rm %%module-low%%.ini;

make.o: configure.o
	make; \
	make install; \

configure.o: phpize.o
	./configure --prefix=/usr --enable-%%module-low%%

phpize.o: config.m4 %%module-low%%.c php_%%module-low%%.h 
	phpize
