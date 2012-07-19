CONFDIR=$(shell php -i |grep 'for additional .ini files'| sed -e"s/.*=> //g";)

all: strflip 

strflip: STRFLIP/strflip.Makefile
	$(MAKE) -C STRFLIP  -f strflip.Makefile CONFDIR=$(CONFDIR); 
