
Grupo nº 24
Integrantes:
- Armando Paulo Gomes
- Makenda Figueredo
- Olimpo Paiva
- Telma Domingos




Relatório do Projeto:


 Meu Filme Ideal
Disciplina: Estruturas Discretas
Projeto Prático de Programação Lógica

Introdução

Neste projeto, aplicamos conceitos fundamentais de programação lógica - como fatos, regras evariáveis - para construir um sistema interativo de recomendação de filmes.

 O objetivo foi simularum sistema capaz de interpretar as preferências de diferentes utilizadores e gerar sugestõespersonalizadas.

Objetivo do Projeto

Desenvolver um sistema de recomendação inteligente que, com base nas preferências individuaisdos utilizadores, sugira filmes adequados utilizando lógica declarativa e estruturação deconhecimento em Prolog.

Etapas do Projeto1.

 Construção da Base de ConhecimentoIncluímos um conjunto de 15 filmes distintos, com os seguintes atributos:

- Título- Gêneros (um ou mais)
- Ano de lançamento
- Diretor
- Atores principais
- Avaliação (escala de 1 a 10)
- Classificação etária (opcional)
Exemplo:filme('A Origem', ['ficção', 'ação'], 2010, 'Christopher Nolan', ['Leonardo DiCaprio'], 9, 14).2.

 Regras e Funcionamento do Sistema

O sistema utiliza regras em Prolog para realizar a correspondência entre os gostos dos usuários eos atributos dos filmes.

Por exemplo, os predicados são definidos dinamicamente com:
:- dynamic usuario/6.
:- dynamic filme/7.

O predicado principal `main` ativa a recomendação baseada em critérios como:
- Gêneros preferidos
- Diretores favoritos
- Atores favoritos
- Filmes já assistidos (para evitar repetições)As sugestões são feitas utilizando cláusulas como `recomendar/2`, que avalia correspondênciasentre os atributos dos filmes e as preferências armazenadas de cada usuário.

3. Exemplos de Consultas

Exemplo 1: Cadastro de um usuáriousuario('Ana', 18, [comedia, drama], ['Greta Gerwig'], ['Emma Watson'], []).
Exemplo 2: Consulta de recomendação?- recomendar('Ana', Filmes).Filmes = ['Lady Bird', 'Adoráveis Mulheres'].

Esse mecanismo permite personalizar as sugestões com base no histórico e nos gostos de cadautilizador.

Dificuldades Enfrentadas e SoluçõesDurante o desenvolvimento do projeto, surgiram algumas dificuldades importantes:

1. **Entendimento da Sintaxe de Prolog**: A curva de aprendizado inicial da linguagem Prolog foi desafiadora, especialmente por não utilizar estruturas tradicionais de outras linguagens.
 *Solução:* Estudo aprofundado dos conceitos de fatos, regras e consultas, com exemplospráticos.

2. **Criação de Regras de Recomendação**: Formular regras que capturassem preferências múltiplas (diretor, ator, gênero) exigiu bastanteteste e refatoração. *Solução:* Implementação modular das regras e uso do predicado `member/2` para simplificarverificações.

3. **Evitar Recomendações de Filmes Já Vistos**: A verificação correta da lista de filmes assistidos causava conflitos de lógica. 
*Solução:* Uso adequado de `\+ member(Filme, Vistos)` para garantir a exclusão correta.

Essas dificuldades foram superadas com estudo e prática, e contribuíram para o aprendizadosignificativo sobre lógica declarativa.


Conclusão

Este projeto demonstrou, na prática, como a linguagem Prolog pode ser utilizada na construção desistemas inteligentes. 
Através da definição de fatos e regras, foi possível implementar um sistemade recomendação de filmes adaptado às preferências individuais dos usuários.
Além de reforçar osconceitos de lógica de programação, o trabalho proporcionou uma experiência valiosa namodelagem declarativa do conhecimento.
