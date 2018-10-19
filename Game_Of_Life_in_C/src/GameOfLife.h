#define MATRIXSIZE 20
typedef enum {alive, dead} Cell;
void printLife(Cell cellp[MATRIXSIZE][MATRIXSIZE]);
void Live(Cell current_generation[MATRIXSIZE][MATRIXSIZE], Cell future_generation[MATRIXSIZE][MATRIXSIZE]);

