# Partial Persistence

## Relatório

A implementação da ordenação agora está funcionando devidamente, permitindo a inserção de elementos em uma ordem arbitrária e mantendo
a ordem crescente na lista.

Não consegui implementar de maneira 100% correta a funcionalidade. Após alguns testes,
percebi a inserção (até onde testei) está funcionando perfeitamente juntamente com a função de sucessor.

O problema conhecido está relacionado a remoção. Remover o elemento da cauda ou da raíz, está funcionando ok (até onde testei), porém quando um elemento intermediário é removido, **as vezes** ele acaba causando
alguns problemas na inserção. Acredito que seja algum ponteiro de _backref_ desatualizado que esteja causando esse problema.

## Instruções
Download:

```sh
    git clone https://github.com/luizok/Partial-Persistence.git
```

Build:

```sh
    gcc *.c -o <outfile_name>
```

Run:

```sh
    ./<outfile_name> <filename>
```
