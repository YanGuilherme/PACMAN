# Variáveis do Makefile
CXX = g++
CXXFLAGS = -Wall -g
LIBS = -lallegro -lallegro_image -lallegro_font -lallegro_ttf

# Listas de arquivos
SRC_FILES = Main.cpp Coordenada.cpp Labirinto.cpp Personagem.cpp Pacman.cpp ListaCoordenadas.cpp Fantasma.cpp
OBJ_FILES = $(SRC_FILES:.cpp=.o)

# Regras de construção
all: game

game: $(OBJ_FILES)
	$(CXX) $(CXXFLAGS) -o $@ $^ $(LIBS)

%.o:%.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@


# Regras de limpeza
clean:
	rm -f $(OBJ_FILES) $(DEP_FILES) game
