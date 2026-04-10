#include <stdio.h>
#include <string.h>
#include <ctype.h>

// Função para descriptografar
void descriptografar(char texto[], int chave) {
for (int i = 0; texto[i] != '\0'; i++) {

if (isalpha(texto[i])) {
char base;

if (islower(texto[i]))
base = 'a';
else
base = 'A';

texto[i] = (texto[i] - base - chave + 26) % 26 + base;
}
}
}

// Função simples para ver se parece correto
int verificar(char texto[]) {
int pontos = 0;

if (strstr(texto, "a")) pontos++;
if (strstr(texto, "e")) pontos++;
if (strstr(texto, "o")) pontos++;
if (strstr(texto, "the")) pontos += 2;
if (strstr(texto, "de")) pontos += 2;

return pontos;
}

// Função principal de descoberta
void descobrir(char texto[]) {
char copia[200];
char melhor[200];
int melhor_pontos = -1;
int melhor_chave = 0;

for (int chave = 1; chave <= 25; chave++) {

strcpy(copia, texto);

descriptografar(copia, chave);

int pontos = verificar(copia);

printf("Chave %d: %s", chave, copia);

if (pontos > melhor_pontos) {
melhor_pontos = pontos;
melhor_chave = chave;
strcpy(melhor, copia);
}
}

printf("\n=== MELHOR RESULTADO ===\n");
printf("Chave: %d\n", melhor_chave);
printf("Mensagem: %s\n", melhor);
}

int main() {
char mensagem[200];

printf("Digite a mensagem cifrada: ");
fgets(mensagem, sizeof(mensagem), stdin);

descobrir(mensagem);

return 0;
}
