#!/bin/bash

# Limpa o diretório antes de compilar
make clean

# Chama o comando make para compilar o programa
make

# Verifica se a compilação foi bem-sucedida
if [ $? -eq 0 ]; then
  
  echo -e "A compilação foi concluída com sucesso.\nDigite ./game para jogar!"
else
  echo "A compilação falhou. Verifique os erros."
fi
