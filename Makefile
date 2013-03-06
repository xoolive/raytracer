GCC        = gcc
MACHINE   := $(shell uname -op | sed 's/[/\ ]/-/g')
CFLAGS     = -Iinclude -Wall
SDL_CFLAGS = `sdl-config --cflags`
SDL_LIBS   = `sdl-config --libs`
LIBUTIL    = lib/libutil-$(MACHINE).a
LIBIMGSDL  = lib/libimgsdl-$(MACHINE).a
LIBS       = # $(LIBUTIL) $(LIBIMGSDL) $(SDL_LIBS)

EXEC       = raytracer
EXEC_NOTE  = test_note

# Mettre ici le nom de tous les fichiers à compiler (sans oublier src/ devant
# *chaque* objet)
SOURCES    = # src/geometry.c par exemple
OBJECTS    = $(patsubst src/%.c, bin/%.o, $(SOURCES))

# Rajouter ici le nom des objets contenant les fichiers à *tester* (sans oublier
# bin/ devant *chaque* objet .o)
TESTS_NOTE = tests/tests_notes.c # bin/geometry.o par exemple
TESTS_SDL  = tests/tests_imgsdl.c $(LIBIMGSDL)
# Vous pouvez rajouter ici d'autres variables contenant les objets nécessaires
# aux tests que vous écrirez
# TESTS_AUTRE = ...

all: $(EXEC)

compile: $(EXEC) $(TESTS)

$(EXEC): bin/$(OBJECTS)
	$(GCC) $(CFLAGS) -o bin/$(EXEC) $(OBJECTS) $(LIBS)

$(EXEC_NOTE): $(TESTS_NOTE)
	$(GCC) -Iinclude -o bin/$(EXEC_NOTE) $(TESTS_NOTE)

tests: $(EXEC_NOTE)
	./bin/$(EXEC_NOTE)
	# Rajoutez ici vos autres tests

tests_sdl: $(TESTS_SDL)
	$(GCC) $(CFLAGS) $(SDL_CFLAGS) -o bin/tests_sdl $(TESTS_SDL) $(SDL_LIBS)
	./bin/tests_sdl foo

run: all
	./bin/$(EXEC) scenes/cubes.scn

clean:
	@rm ./bin/*

lib/lib%-$(MACHINE).a: bin/%.o
	ar rc $@ $<

bin/%.o: src/%.c
	$(GCC) $(CFLAGS) -c $< -o $@


