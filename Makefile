CC    = zcc
FLAGS = +primo -O2 -Cc"-Wall" -lgenmath_ixiy -create-app -Cz"-t ptp -n Rakt}ros"

SOURCEDIR = src
DATADIR   = src/data
BINARY    = raktaros.ptp
WAV       = raktaros.wav

SRC     := $(wildcard $(SOURCEDIR)/*.c)
DATASRC := $(wildcard $(DATADIR)/*.c)

.PHONY: all clean docker wav $(BINARY)

all: $(BINARY)

$(BINARY):
	$(CC) $(FLAGS) $(SRC) $(DATASRC) -o $(BINARY) 

docker:
	docker run --rm --mount type=bind,src=.,dst=/src --workdir /src z88dk/z88dk:latest make

wav: $(BINARY)
	ptp2wav $(BINARY) $(WAV)

clean:
	rm -rf $(BINARY) $(WAV)
