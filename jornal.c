#include <stdio.h>
#include <stdlib.h>
#include "jornal.h"

noticia *cria_noticia() {
	noticia *tmp = (noticia *)malloc(sizeof(noticia));

	if (!tmp) {
		fprintf(stderr, "[-] Falha na alocação em cria_noticia()\n");

		return NULL;
	}

	tmp->prox = NULL;
	tmp->dias = 0;

	return tmp;
}

short dias_noticia(noticia *n) { return n->dias; }

short noticia_valida(noticia *n) { return dias_noticia(n) < 3 && dias_noticia(n) >= 0; }

void requisita(char *titulo, char *texto) {
	getchar();
	printf("\nDigite o título: ");
	fgets(titulo, TAM_TITULO, stdin);
	printf("Digite o texto: ");
	fgets(texto, TAM_TEXTO, stdin);
}

void cadastra_noticia(fila *f) {
	noticia *n = cria_noticia();
	requisita(n->titulo, n->texto);
        insere_fila(f, n);
}

void seleciona_noticias(fila *f, int *n_noticias) {
	int count = 0;
	
	if (!fila_vazia(f)) {
		noticia *aux = f->cbc;

		while (*n_noticias < 2 && count < tam_fila(f)) {
			if (noticia_valida(aux)) {
				printf("\n%s", aux->titulo);
				printf("%s", aux->texto);
				printf("\n==\n");
				(*n_noticias)++;

				if (aux->prox != NULL)
					aux = aux->prox;
			} else if (!noticia_valida(aux)) {
				if (aux->prox != NULL)
					aux = aux->prox;
			}

			count++;
		}

		aux = f->cbc;

		for (int i = 0; i < tam_fila(f); i++) {
			(aux->dias)++;
			
			if (aux->prox != NULL)
				aux = aux->prox;
		}
	}
}

void fechar_edicao(fila *f_breaking, fila *f_informe) {
	int n_noticias = 0;
	seleciona_noticias(f_breaking, &n_noticias);
	seleciona_noticias(f_informe, &n_noticias);

	if (n_noticias == 0)
		printf("\nEsta edição foi pulada por falta de notícias!\n");
}

fila *cria_fila() {
	fila *tmp = (fila *)malloc(sizeof(fila));

	if (!tmp) {
		fprintf(stderr, "[-] Falha na alocação da fila de notícias em cria_fila()\n");

		return NULL;
	}	

	tmp->cbc = NULL;
	tmp->cauda = NULL;
	tmp->tam = 0;

	return tmp;
}

int tam_fila(fila *f) { return f->tam; }

short fila_vazia(fila *f) { return tam_fila(f) == 0; }

void insere_fila(fila *f, noticia *n) {
	if (fila_vazia(f)) {
		f->cbc = n;
		f->cauda = n;
		(f->tam)++;

		return;
	}

	f->cauda->prox = n;
	f->cauda = n;
	(f->tam)++;
}

void remove_fila(fila *f) {
	if (fila_vazia(f)) {
		fprintf(stderr, "[-] Fila vazia. Impossível realizar remoção.\n");
	}

	if (tam_fila(f) == 1) {
		free(f->cbc);
		f->cbc = NULL;
		(f->tam)--;

		return;
	}

	noticia *aux = f->cbc;
	f->cbc = f->cbc->prox;
	free(aux);
	aux = NULL;
	(f->tam)--;
}

void libera_fila(fila *f) {
	while (!fila_vazia(f))
		remove_fila(f);

	free(f);
	f = NULL;
}
