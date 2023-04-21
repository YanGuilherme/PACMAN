# Variáveis do Makefile
CXX = g++
CXXFLAGS = -Wall -g
LIBS = -lallegro -lallegro_image -lallegro_font -lallegro_ttf

# Listas de arquivos
SRC_FILES = Main.cpp Coordenada.cpp Labirinto.cpp Pacman.cpp ListaCoordenadas.cpp
OBJ_FILES = $(SRC_FILES:.cpp=.o)
DEP_FILES = $(SRC_FILES:.cpp=.d)

# Regras de construção
all:game

game:$(OBJ_FILES)
	$(CXX) $(CXXFLAGS) -o $@ $^ $(LIBS)

%.o:%.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

%.d:%.cpp
	$(CXX) $(CXXFLAGS) -MM $< -MT $(@:.d=.o) >$@

-include $(DEP_FILES)

# Regras de limpeza
clean:
	rm -f $(OBJ_FILES) $(DEP_FILES) game
