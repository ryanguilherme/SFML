CC = g++
CFLAGS = -c -Ilib
LFLAGS = -lsfml-graphics -lsfml-window -lsfml-system
OBJDIR = obj

# Lista dos arquivos fonte (.cpp) presentes na pasta src
SOURCES = $(wildcard src/*.cpp)
# Gera a lista dos arquivos objeto (.o) com base nos arquivos fonte
OBJECTS = $(patsubst src/%.cpp,$(OBJDIR)/%.o,$(SOURCES))

all: $(OBJDIR) sfml-app

$(OBJDIR):
	mkdir -p $(OBJDIR)

sfml-app: $(OBJECTS)
	$(CC) $(OBJECTS) -o sfml-app $(LFLAGS)

$(OBJDIR)/%.o: src/%.cpp
	$(CC) $(CFLAGS) $< -o $@

clean:
	rm -rf $(OBJDIR)/*.o sfml-app
