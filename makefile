# Variáveis do Makefile
CXX = g++
CXXFLAGS = -Wall -g
LDFLAGS=-L/usr/local/lib -lallegro `pkg-config --libs allegro-5 allegro_audio-5 allegro_dialog-5 allegro_image-5 allegro_memfile-5 allegro_primitives-5 allegro_acodec-5 allegro_color-5 allegro_font-5 allegro_main-5 allegro_physfs-5 allegro_ttf-5` 
INCLUDE=-I. -I/usr/include/allegro5
LIBS = -lallegro -lallegro_image -lallegro_font -lallegro_ttf

# Listas de arquivos
SRC_FILES = Main.cpp Pacman.cpp Pilula.cpp Labirinto.cpp CoordenadaTijolo.cpp
OBJ_FILES = $(SRC_FILES:.cpp=.o)
DEP_FILES = $(SRC_FILES:.cpp=.d)

# Regras de construção
all: game

game: $(OBJ_FILES)
	$(CXX) $(CXXFLAGS) -o $@ $^ $(LIBS)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

%.d: %.cpp
	$(CXX) $(CXXFLAGS) -MM $< -MT $(@:.d=.o) >$@

-include $(DEP_FILES)

# Regras de limpeza
clean:
	rm -f $(OBJ_FILES) $(DEP_FILES) game
