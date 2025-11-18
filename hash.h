#define HASH_H

#define TAM_USERNAME 50
#define TAM_SENHA 50

typedef struct usuario {
    char username[TAM_USERNAME];
    unsigned long hashSenha;
    struct usuario *prox;
} Usuario;

typedef struct {
    int tamanho;
    Usuario **tabela;
} Hash;

// Funções Hash
unsigned long valorString(const char *str);
int chaveDivisao(unsigned long chave, int tamanho);
unsigned long hashSenha(const char *senha);

// Funções da Tabela
Hash* criaHash(int tamanho);
Usuario* buscaHash(Hash *h, const char *username);
int insereHash(Hash *h, const char *username, const char *senha);
int removeHash(Hash *h, const char *username);
void imprimeHash(Hash *h);
void liberaHash(Hash *h);

// Funções do Sistema de Login
void cadastrarUsuario(Hash *h);
void loginUsuario(Hash *h);
void removerUsuario(Hash *h);

