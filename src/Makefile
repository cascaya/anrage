CONFDIR=$(shell php -i |grep 'for additional .ini files'| sed -e"s/.*=> //g";)


ifdef STRFLIP
strflip: STRFLIP/strflip.Makefile
	$(MAKE) -C STRFLIP  -f strflip.Makefile CONFDIR=$(CONFDIR);
endif

ifdef COUNTRY
country: COUNTRY/country.Makefile
	$(MAKE) -C COUNTRY  -f country.Makefile CONFDIR=$(CONFDIR);
endif
