/*
 * Tarefa 2
 * Discutir o emprego da ferramenta debug no processo
 * de criação de uma aplicação que apresenta, numa
 * janela de 320 px de largura, imagens de 60 x 80 px
 * de acordo com duas variáveis globais: h para a
 * quantidade de imagens horizontais e v para a quan-
 * tidade de imagens verticais, tratando devidamente
 * as restrições de h e de v em relação ao tamanho da
 * janela.
 */
int h, v;

void setup() {
  size(320, 320);
  h = width / 60; //<>//
  v = height / 80;
  for(int i = 0; i < h; i++)
    for(int j = 0; j < v; j++)
      rect(i * 60, j * 80, 60, 80);
}