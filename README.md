# Concordo


* [Compilação](#compilação)
* [Execução](#execução)
* [Testes](#testes)

## Compilação


Digite no terminal para compilar com cmake:
```console
mkdir build
cd build
cmake ..
cmake --build .
```


## Execução

Para executar o programa, dentro da pasta build digite o seguinte comando:
```console
./concordo
```

Após isso digite os comandos do concordo seguidos de ENTER.

## Testes

Ao invés de executar o programa digitando linha a linha, execute a sequência de testes presentes no arquivo comandos_teste.txt pelo seguinte comando ainda dentro da pasta build:
```console
./concordo < ../comandos_teste.txt
```

Você pode criar seus próprios casos de teste, basta especificar a rota onde está o arquivo especificado.
