#include <stdio.h>
#include <stdbool.h>

struct processo_t {
    int id;
    int tempo_execucao;
    bool finalizado;
} processo_t;


struct processo_t inicializar_processo(int id, int tempo_execucao) {
    struct processo_t ret;
    ret.id = id;
    ret.tempo_execucao = tempo_execucao;
    ret.finalizado = false;
    return ret;
}


void mostrar_processo(struct processo_t* p) {
    printf(
    "Processo id=%d | tempo_execucao=%d | finalizado=%d\n",
    p->id,
    p->tempo_execucao,
    p->finalizado
    );
}

void roundrobin(struct processo_t processos[], int quantidadeProcessos, int quantum) {
    int finalizados = 0;
    while (finalizados < quantidadeProcessos) {
        for (int i = 0; i < quantidadeProcessos; i++) {
            if (processos[i].finalizado) {
                continue;
            }

            int tempo_decorrido;
            if (processos[i].tempo_execucao < quantum) {
                tempo_decorrido = processos[i].tempo_execucao;
            } else {
                tempo_decorrido = quantum;
            }

            processos[i].tempo_execucao -= tempo_decorrido;
            printf("Executando processo id=%d | tempo restante=%d\n",
                processos[i].id, processos[i].tempo_execucao);

            if (processos[i].tempo_execucao == 0) {
                processos[i].finalizado = true;
                finalizados++;
                printf("Processo id=%d finalizado", processos[i].id);
            }
        }
    }
}
int main() {
    struct processo_t processos[8];
    int quantum = 3;
    processos[0] = inicializar_processo(0, 5);
    processos[1] = inicializar_processo(1, 7);
    processos[2] = inicializar_processo(2, 4);
    processos[3] = inicializar_processo(3, 12);
    processos[4] = inicializar_processo(4, 6);
    processos[5] = inicializar_processo(5, 2);
    processos[6] = inicializar_processo(6, 7);
    processos[7] = inicializar_processo(7, 1);

    for (int i = 0; i < 8; i++) {
        mostrar_processo(&processos[i]);
    }
    roundrobin(processos, 8, quantum);
    return 0;
}