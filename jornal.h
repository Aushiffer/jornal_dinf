#ifndef JORNAL_H
#define JORNAL_H

#define TAM_TITULO 33
#define TAM_TEXTO 513

// Notícia
typedef struct Noticia {
	struct Noticia *prox;
	char titulo[TAM_TITULO];
	char texto[TAM_TEXTO];
	short dias;
} noticia;

// Fila
typedef struct Fila {
	noticia *cbc;
	noticia *cauda;
	int tam;
} fila;

// Cria um espaço na memória para uma notícia
noticia *cria_noticia();

// Cria uma fila que armazena notícias
fila *cria_fila();

// Retorna quantos dias a notícia tem
short dias_noticia(noticia *n);

// Retorna o valor lógico para: dias_noticia(n) < 3 && dias_noticia(n) > 0
short noticia_valida(noticia *n);

// Requisita o título e o texto para a notícia
void requisita(char *titulo, char *texto);

// Cadastra uma notícia em uma fila
void cadastra_noticia(fila *f);

// Seleciona as notícias a serem exibidas
void seleciona_noticias(fila *f, int *n_noticias);

// Fecha a edição do dia, selecionando as notícias a serem exibidas com seleciona_noticias()
void fechar_edicao(fila *f_breaking, fila *f_informe);

// Retorna o tamanho da fila
int tam_fila(fila *f);

// Retorna o valor lógico para: tam_fila(f) == 0
short fila_vazia(fila *f);

// Insere uma notícia na cauda dafila
void insere_fila(fila *f, noticia *n);

// Remove uma notícia da cabeça da fila
void remove_fila(fila *f);

// Libera as notícias da fila e o espaço alocado à ela
void libera_fila(fila *f);

#endif // JORNAL_H
