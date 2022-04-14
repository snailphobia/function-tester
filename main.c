#include "utils.h"

extern volatile int16_t _sgn;
extern clock_t _clk;
extern volatile void* wff;
extern volatile int16_t _t_idx;

void kill_thr() {
    pthread_t* t_id = (pthread_t*)wff;
    _sgn = pthread_kill(t_id[1], 2);
}

int32_t main(int32_t argc, char* argv[]) {
    _clk = clock();
    FILE * out = fopen("out_rep.txt", "w+");

    if (!out)
        exit(1);
    
    
    // code goes here
    signal(SIGSEGV, kill_thr);
    extern volatile try1();
    extern volatile try2();
    extern volatile main1();

    pthread_t* t_id = calloc(1000, sizeof(pthread_t));
        wff = t_id;
    
    for (int i = 0; i < 3; i++) {
            _t_idx = i;
        pthread_create(&(t_id[_t_idx]), NULL, try1, NULL);
    }
    
    printf("operation took %f seconds to complete . . .\n", (double)(((clock() - _clk) / CLOCKS_PER_SEC)));
    free(t_id);

    fclose(out);
    return 0x0;
}