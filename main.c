#include <stdio.h>
#include "jornal.h"

int main() {
	fila *f_breaking = cria_fila();
	fila *f_informe = cria_fila();
	int select;

	do {
		int define_tipo;
		printf("\n- (1) Cadastrar notícia\n");
		printf("- (2) Fechar edição\n");
		printf("- (3) Sair\n");
		scanf("%d", &select);

		if (select == 1) {
			printf("\nDefina o tipo da notícia: ");
			scanf("%d", &define_tipo);

			if (define_tipo == 0)
				cadastra_noticia(f_breaking);
			else if (define_tipo == 1)
				cadastra_noticia(f_informe);
			else
				fprintf(stderr, "\n[-] Erro: entrada inválida. Nenhuma notícia foi cadastrada.\n");
		} else if (select == 2) {
			printf("\n================================================\n");
			fechar_edicao(f_breaking, f_informe);
			printf("\n================================================\n");
		}
	} while (select < 3 && select > 0);

	printf("\nSaindo...\n");
	libera_fila(f_breaking);
	libera_fila(f_informe);

	return 0;
}
