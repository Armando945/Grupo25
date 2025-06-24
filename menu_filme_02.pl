% inidio da magia     MISTER APG  " hello wolrd "
:- dynamic usuario/6.
:- dynamic filme/7.

inicio :-
    main.

% base de dados de usuarios
usuario('Fernanda', 22, [acao, drama], ['Nolan'], ['DiCaprio'], []).
usuario('Pedro', 16, [aventura, animacao], ['Spielberg'], ['Tom Hanks'], ['Toy Story']).
usuario('Ana',18,[comedia,drama],['Francis Coppola','Denis Villeneuve'],['Timothee Chalamet','Zendaya'],['VINGADORES: ULTIMATO']).
usuario('Maria',16,[comedia,animacao,fantasia],['Jon M. Chu'],['Ariana Grande','Cynthia Erivo'],['FORREST GUMP']).
usuario('Paiva',20,[acao,drama,romance],['Quentin Tarantino','Francis Coppola'],['Tim Robbins','Morgan Freeman'],['O CAVALEIRO DAS TREVAS']).
usuario('Telma',19,[comedia,drama,romance],['Francis Coppola'],['Timothee Chalamet','Zendaya'],['VINGADORES: ULTIMATO']).
usuario('Armando',30,[comedia,fc,aventura,fantasia,crime],['Francis Coppola','Peter Jackson','Anthony Russo','Joe Russo'],['Timothee Chalamet','Zendaya','Robert Downey Jr','Chris Evans'],['VINGADORES: ULTIMATO']).
usuario('Pedro',50,[comedia,drama,musical,guerra],['Francis Coppola','WB Picture','Robert Zemeckis'],['John Travolta','Samuel Jackson'],['A LISTA SCHINDLER','DUNA: PARTE 2']).

% base de dados  dos filmes
filme('Inception', [acao, ficcao], 2010, ['Nolan'], ['DiCaprio'], 8, 16).
filme('Toy Story', [animacao, aventura], 1995, ['John Lasseter'], ['Tom Hanks'], 9, 0).
filme('WICKED', [musical, fantasia,ficcao], 2024, ['Jon M. Chu'], ['Ariana Grande', 'Cynthia Erivo'], 7, 12).
filme('O PODEROSO CHEFAO',[crime,drama],1972,['Francis Coppola'],['Marlon Brando','Al Pacino','James Caan'],9,18).
filme('UM SONHO DE LIBERDADE',[drama],1994,['Frank Darabont'],['Tim Robbins','Morgan Freeman'],9,14).
filme('A LISTA SCHINDLER',[biografia,drama,guerra],1993,['Steven Spielberg'],['Liam Neeson','Ben Kingsley'],9,14).
filme('FORREST GUMP',[drama,romance],1994,['Robert Zemeckis'],['Tom Hanks','Robin Wright'],8,10).
filme('O REI LEAO',[animacao,aventura],1994,['Roger Allers','Rob Minkoff'],['James Earl Jones','Matthew Broderick'],8,0).
filme('O SENHOR DOS ANEIS: O RETORNO DO REI',[ficcao,aventura,fantasia],2003,['Peter Jackson'],['Elijah Wood','Viggo Mortensen'],9,14).
filme('PULP FICTION',[crime,drama],1994,['Quentin Tarantino'],['John Travolta','Samuel Jackson'],8,18).
filme('A VIDA E BELA',[comedia,drama],1997,['Roberto Benigni'],['Roberto Benigni','Nicoletta Braschi'],8,10).
filme('O CAVALEIRO DAS TREVAS',[acao,crime],2008,['Christopher Nolan'],['Christian Bale','Heath Ledger'],9,14).
filme('VINGADORES: ULTIMATO',[acao,aventura],2019,['Anthony Russo','Joe Russo'],['Robert Downey Jr','Chris Evans'],8,12).
filme('DUNA',[ficcao,aventura],2021,['Denis Villeneuve'],['Timothee Chalamet','Zendaya'],8,12).
filme('BARBIE',[comedia,fantasia],2023,['Greta Gerwig'],['Margot Robbie','Ryan Gosling'],7,0).
filme('OPPENHEIMER',[biografia,drama],2023,['Christopher Nolan'],['Cillian Murphy','Emily Blunt'],8,14).
filme('WICKED',[musical,fantasia],2024,['Jon M. Chu'],['Ariana Grande','Cynthia Erivo'],7,0).
filme('DUNA: PARTE 2',[ficcao,aventura,drama],2025,['WB Picture'],['Timothee Chalamet','Zendaya'],9,14).

% -----------------------------------------------------------------------------------------------------------------------------------------
% Predicado para recomendar filmes
recomendar_filme(NomeUsuario, Filme) :-
    usuario(NomeUsuario, Idade, GenerosPref, DiretoresPref, AtoresPref, JaAssistidos),
    filme(Filme, Generos, _, Diretores, Atores, AV, ClasseEtaria),
    AV >= 7,
    ClasseEtaria =< Idade,
    (
    interseccao(GenerosPref, Generos);
    interseccao(DiretoresPref, Diretores);
    interseccao(AtoresPref, Atores)
    ),
    \+ member(Filme, JaAssistidos).

% Verifica se ha intersecao ou ligacao entre duas listas
interseccao([H|_], L2) :- member(H, L2), !.
interseccao([_|T], L2) :- interseccao(T, L2).

% ------------------------------------------
% Marcar filme como assistido
marcar_como_assistido(NomeUsuario, Filme) :-
    usuario(NomeUsuario, Idade, Generos, Diretores, Atores, JaAssistidos),
    \+ member(Filme, JaAssistidos),
    retract(usuario(NomeUsuario, Idade, Generos, Diretores, Atores, JaAssistidos)),
    assertz(usuario(NomeUsuario, Idade, Generos, Diretores, Atores, [Filme|JaAssistidos])).

% ------------------------------------------
% Adicionar usuário
adicionar_usuario :-
       write('======================================================================'), nl,
       write('Nome: '), flush_output, read(Nome),
       write('Idade: '), flush_output, read(Idade),
       write('Generos preferidos (ex: [acao, drama]): '), flush_output, read(Generos),
       write('Diretores preferidos (ex: [Nolan]): '), flush_output, read(Diretores),
       write('Atores preferidos (ex: [DiCaprio]): '), flush_output, read(Atores),
       assert(usuario(Nome, Idade, Generos, Diretores, Atores, [])),
       write('======================================================================'), nl,
       write('Usuário adicionado com sucesso!'), nl.

% Adicionar filme
adicionar_filme :- 
    write('===================================================================='), nl,
    write('Nome do filme: '), flush_output, read(Nome),
    write('Gêneros (ex: [acao, drama]): '), flush_output, read(Generos),
    write('Ano de lancamento: '), flush_output, read(Ano),
    write('Diretores  ex: [Nolan] : '), flush_output, read(Diretores),
    write('Atores ex: [DiCaprio] : '), flush_output, read(Atores),
    write('Avaliação  0 a 10 : '), flush_output, read(AV),
    write('Classificação etária : '), flush_output, read(ClasseEtaria),
    assert(filme(Nome, Generos, Ano, Diretores, Atores, AV, ClasseEtaria)),
    write('======================================================================'), nl,
    write('Filme adicionado com sucesso!'), nl.

% ------------------------------------------
%  para Mostrar catalogo de filmes que estao na base de dados filme
mostrar_catalogo :-
    write('--- Catálogo de Filmes ---'), nl,
    forall(filme(Filme, Generos, Ano, Diretores, Atores, AV, ClasseEtaria),
           (write('============================================================'), nl,
            write('  Filme: '), write(Filme), nl,
            write('  Gêneros: '), write(Generos), nl,
            write('  Ano: '), write(Ano), nl,
            write('  Diretores: '), write(Diretores), nl,
            write('  Atores: '), write(Atores), nl,
            write('  Avaliação: '), write(AV), nl,
            write('  Classificação etária: '), write(ClasseEtaria), nl,
            write('============================================================'), nl,
            nl)).

% ------------------------------------------
% Recomendar filmes
recomendar_para_usuario :-
    write('Nome do usuário: '), flush_output, read(Nome),
    (   usuario(Nome,_,_,_,_,_)
    ->  findall(F, recomendar_filme(Nome, F), Lista),
        (Lista = [] ->
            write('Nenhum filme recomendado.'), nl;
            write('Filmes recomendados: '), nl,
            print_lista(Lista),
            write('Você assistiu algum desses filmes? '),nl,
            write('degita [sim] ou [nao] *_* : '), flush_output, read(Resp),
            (Resp == sim ->
                write('Qual filme você assistiu? '), flush_output, read(FilmeAssistido),
                (member(FilmeAssistido, Lista) ->
                    marcar_como_assistido(Nome, FilmeAssistido),
                    write('Filme marcado como assistido! +_+ '), nl;
                    write('Filme não está na lista recomendada.  @_@'), nl);
                      true) ); 
                      write('Usuário não encontrado  ! *_* '), nl).

% para mostrar uma lista  um item por linha
print_lista([]).
print_lista([H|T]) :- write(' - '), write(H), nl, print_lista(T).


%Listar usuario 
% ------------------------------------------
 listar_usuario :- 
        
    write('--- Lista de Usuários ---'), nl,
    forall(usuario(Nome, Idade, Generos, Diretores, Atores, Assistidos),
        (    write('============================================================='), nl,
            write('Nome: '), write(Nome), nl,
            write('  Idade: '), write(Idade), nl,
            write('  Gêneros preferidos: '), write(Generos), nl,
            write('  Diretores preferidos: '), write(Diretores), nl,
            write('  Atores preferidos: '), write(Atores), nl,
            write('  Já assistidos: '), write(Assistidos), nl,
            write('============================================================='), nl,
            nl
        )
    ).

% Menu principal
main :-
    repeat,nl,
    write('============ MENU PRINCIPAL =======================#'), nl,
    write('[1] MOSTRAR CATALOGO DE FILMES     |??????|       |'), nl,
    write('[2] ADICIONAR USUARIOS ________    | ^_^  |       |'), nl,
    write('[3] ADICIONAR FILME    |  APG |  # |______|       |'), nl,
    write('[4] RECOMENDAR FILMES  |  OP  |   \\/| $ |\\        |'), nl,
    write('[5] LISTAR USUARIOS    |  TD  |     |   | \\       |'),nl,
    write('[6] Sair               |  MF  |     / ^ \\  @      |'), nl,
    write('===================================================#'), nl,
    write('Escolha uma opção: '), flush_output, read(OP),
    executar(OP),
    (OP == 6), !.

executar(1) :- mostrar_catalogo.
executar(2) :- adicionar_usuario.
executar(3) :- adicionar_filme.
executar(4) :- recomendar_para_usuario.
executar(5) :- listar_usuario.
executar(6) :- write('Saindo...  *_* '), nl.
executar(_) :- write('Opção inválida!'), nl.

