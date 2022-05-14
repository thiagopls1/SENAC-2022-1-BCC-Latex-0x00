#include <stdio.h>
#include <stdlib.h>

void generateMultTable(int);

int main(int argc, char *argv[]) {
    int base;

    if (argc == 2){
        base = atoi(argv[1]);
    }
    else{
        base = 2;
    } 
    generateMultTable(base);

    exit(EXIT_SUCCESS);
}

void generateMultTable(int base) {
    const char *archive = "tabela.tex";

    FILE * fp = fopen(archive,"wt");
    if (fp == NULL)
        return;

    fprintf(fp,"\\begin{table}[h]\n");
    fprintf(fp,"\\begin{tabular}{|rcrcr|}\n");

    fprintf(fp,"\\hline\n");

    for (int i=0; i<=10; i++) {
        fprintf(fp, "%3d & $\\times$ & %3d & $=$ & %3d\\\\\n", i, base, i*base);
    }

    fprintf(fp,"\\hline\n");

    fprintf(fp,"\\end{tabular}\n");
    fprintf(fp,"\\end{table}\n");

    fclose(fp);
}

