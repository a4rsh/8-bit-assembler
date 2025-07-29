#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void assemble(char* inputName, char* outputName);
char* parseOperation(char* op, char* reg, char* arg2);
char* parseReg(char reg);


int main(int argc, char** argv)
{
  if (argc < 3) {
    printf("Usage: %s [input] [output]\n", argv[0]);
    return 0;
  }

  assemble(argv[1], argv[2]);

  return 0;
}

void assemble(char* inputName, char* outputName) {
  FILE* f_in = fopen(inputName, "r");
  FILE* f_out = fopen(outputName, "w");

char line[16];
while (fgets(line, sizeof(line), f_in)) {

  while (strlen(line) > 0 && (line[strlen(line) - 1] == '\n' || line[strlen(line) - 1] == '\r')) {
    line[strlen(line) - 1] = 0;
}


  char* op = strtok(line, " \t");
  char* reg = strtok(NULL, " \t");
  char* arg2 = strtok(NULL, " \t");

  if (!op) {
    continue;
  }

  char* out = parseOperation(op, reg, arg2);

  if (out != NULL) {
 
    fprintf(f_out, "%s\n", out);
    free(out);
  } else {
    fprintf(stderr, "Error: could not parse line: %s\n", line);
    break;
  }
}
}

char* parseOperation(char* op, char* reg, char* arg2) {

  char* out = malloc(sizeof(char) * 9);
  out[0] = '\0';
  
  if (!strcmp(op, "WLO")) {

    strcat(out, "000");

    char* r = parseReg(*reg);
    if (r == NULL) {
      return NULL;
    }

    strcat(out, r + 1);
    strcat(out, arg2);

  } else if (!strcmp(op, "WUP")) {

    strcat(out, "001");

    char* r = parseReg(*reg);
    if (r == NULL) {
      return NULL;
    }

    strcat(out, r + 1);
    strcat(out, arg2);

  } else if (!strcmp(op, "HALT")) {

    strcat(out, "11111111");

  }  else if (!strcmp(op, "JMP")) {

      strcat(out, "1100");

      char* r = parseReg(*reg);
      if (r == NULL) {
        return NULL;
      }

      strcat(out, r);
      strcat(out, r);

    } else {
    if (!strcmp(op, "SAVE")) {
      strcat(out, "0111");
    } else if (!strcmp(op, "MOVE")) {
      strcat(out, "0100");
    } else if (!strcmp(op, "LOAD")) {
      strcat(out, "0110"); 
    } else if (!strcmp(op, "ADD")) {
      strcat(out, "1000");
    } else if (!strcmp(op, "SUB")) {
      strcat(out, "1001");
    } else if (!strcmp(op, "AND")) {
      strcat(out, "1010");
    } else if (!strcmp(op, "XOR")) {
      strcat(out, "1011");
    } else if (!strcmp(op, "JEQ")) {
      strcat(out, "1101");
    } else {
      return NULL;
    }

    char* r1 = parseReg(*reg);
    char* r2 = parseReg(*arg2);

    if (r1 == NULL || r2 == NULL) {
      return NULL;
    }

    strcat(out, r1);
    strcat(out, r2);

  }
  return out;
}

char* parseReg(char reg) {
  switch (reg) {
    case 'A': return "00";
    case 'B': return "01";
    case 'C': return "10";
    case 'D': return "11";
    default:  return NULL;
  }
}
