# Trabalho de Sistemas Operacionais - RWLOCK

## Descrição 

Este é um programa em C que implementa o problema dos leitores e escritores usando threads e uma trava de leitura/escrita (rwlock). Ele permite o acesso concorrente de várias threads leitoras e escritoras a uma tabela compartilhada.

O programa cria uma trava de leitura/escrita (rwlock) e threads para leitores e escritores.
Os leitores obtêm a trava de leitura, acessam a tabela compartilhada e a liberam. Isso é feito em um loop infinito com um atraso de 1 segundo entre as iterações, em seguida os escritores fazem o mesmo porém com obtêm a trava de escrita, acessam a tabela compartilhada e a liberam, assim como os leitores isso também é feito em um loop infinito com um atraso de 1 segundo entre as iterações. Após a criação das threads, o programa espera que todas as threads terminem. Em seguida, a trava de leitura/escrita é liberada.

## Compilando e executando o código

Para compilar o programa basta abrir o terminal e digitar o seguinte comando: gcc -o leitores_escritores leitores_escritores.c -lpthread
Em seguida basta executar da seguinte maneira: ./leitores_escritores
