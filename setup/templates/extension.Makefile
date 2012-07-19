all: ini.o

ini.o: make.o
	touch %%module-low%%.ini; 
	echo extension=%%module-low%%.so > %%module-low%%.ini; 
	install -D -m644 %%module-low%%.ini $(DESTDIR)/$(CONFDDIR)%%module-low%%.ini; 
	phpize --clean;
	rm %%module-low%%.ini;

make.o: configure.o
	make;
	make all install INSTALL_ROOT=$(DESTDIR);

configure.o: phpize.o
	./configure  --enable-%%module-low%%;

phpize.o: config.m4 %%module-low%%.c php_%%module-low%%.h 
	phpize;
