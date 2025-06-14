# Relatório de Escalonamento de Tarefas - Atividade 04

## Informações Gerais

- disciplina: **SO** [Sistemas Operacionais](https://github.com/sistemas-operacionais/)
- professor: [Leonardo A. Minora](https://github.com/leonardo-minora)
- aluno: [Nadson Santos Nascimento](https://github.com/nadsuus)
- Data: 12/06/2025

## Sumário

1. [Pré-requisitos](#parte-1-pré-requisitos-para-a-tarefa)
2. [Código Inicial](#parte-2-código-inicial)
3. [Análise de Desempenho](#parte-3-análise-de-desempenho)
4. [Tarefas do Aluno](#parte-4-tarefas-do-aluno)
5. [Conceitos Ensinados](#parte-5-conceitos-ensinados)

---

## Parte 1: Pré-requisitos para a tarefa

* Docker instalado e serviço em execução
* Imagem Fedora pré-configurada via Dockerfile

## Parte 2: Código Inicial

![Código Inicial](imagens/codigo_inicial.png.png)
![Código Inicial1](imagens/codigo_inicial1.png.png)
![Código Inicial2](imagens/codigo_inicial2.png.png)

## Parte 3: Análise de Desempenho

### 3.1 Monitoramento de CPU

![Monitoramento CPU - htop](imagens/monitoramento_cpu1.png)
![Monitoramento CPU - top](imagens/monitoramento_cpu_top.png)

### 3.2 Tempos de Execução

![Tempo de Execução](imagens/tempo_execucao.png)

### 3.2 Tempos de Execução

![Resultado perf stat](imagens/perf_stat.png)

## Parte 4: Tarefas do Aluno

* Modificações realizadas: adicionar threads e ajustar cálculo

*Insira prints das saídas após modificações:*

![Saída CPU-bound modificada e Saída I/O-bound modificada](imagens/saida_cpu_modificada.png)

* Resultados do `perf stat`:

![Resultado perf stat](imagens/perf_stat.png)

## Parte 5: Conceitos Ensinados

* **CPU-bound vs I/O-bound:** diferenciação de uso de CPU vs espera em I/O
* **Escalonamento no Linux:** como o kernel prioriza threads
* **Monitoramento:** uso de `top`, `time` e `perf`
