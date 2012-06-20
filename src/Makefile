CONFDDIR = $(shell php -i |grep 'for additional .ini files'| sed -e"s/.*=> //g";)


all: strflip 

strflip: STRFLIP/strflip.Makefile
	cd STRFLIP; \
	make CONFDDIR=$(CONFDDIR) -f strflip.Makefile; \
	cd ..
