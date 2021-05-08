# Aprendendo
Teste
Introdução
O objetivo de disponibilizar publicamente esse arquivo é auxiliar no desempenho e aprendizado dos alunos.
Este arquivo contém funções aplicadas a matrizes referente ao conteúdo dos 3 primeiros capítulos do livro de Algebra Linear do Boldrini. 
O arquivo ainda está em desenvolvimento e pretende-se incluir até o capítulo 4. Assim abrangendo escalonamento e resolução de sistemas lineares.
Críticas, sugestões ou observações podem ser enviadas no email: victorcalisto42@gmail.com ou por whatsapp.

Orientações de uso:
Para usar o arquivo matriz.h deve salvá-lo na mesma pasta que o programa que você está criando. E incluí-lo no seu programa entre aspas.
Exemplo:
#include “matriz.h”
Declare a matriz com a própria palavra matriz. em seguida coloque o nome que deseja dar a matriz.
Exemplo:
matriz MatrizDosCoeficientes;
Uma vez declarada, é necessário dimensionar a matriz, mas você pode fazer isso quando for mais conveniente. Para dimensionar pasta colocar a palavra dimensionar
Exemplo:
MatrizDosCoeficientes.dimensionar(5,6);
Assim como foi para dimensionar as demais funções também estão no verbo infinitivo.
Também como no exemplo anterior deve-se usar depois de um ponto e antes de um parêntese.
exemplo:
matriz1.transpor();
matriz1.imprimir();
Funções que envolvem operações entre matrizes, como: soma, multiplicação, subtração...São usadas,de fato, como funções (os outros são tecnicamente métodos).
Exemplo:
matriz1=somar(matriz2,matriz3);
matriz1=multiplicar(matriz2,matriz3);

Resumo:
Sempre use os comandos no infinitivo, não se esqueça de incluir o arquivo matriz.h ou dimensionar a matriz declarada.

Dica:
Um bom aplicativo para compilar em c++ é o Cxxdroid.
Link: https://play.google.com/store/apps/details?id=ru.iiec.cxxdroid
