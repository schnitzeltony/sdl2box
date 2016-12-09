# SDL libraries and cflags
LDFLAGS:=	$(shell sdl2-config --libs)
CFLAGS:=	$(shell sdl2-config --cflags)

all:
	$(CC) $(CFLAGS) -o sdl2box sdl2box.c $(LDFLAGS)
