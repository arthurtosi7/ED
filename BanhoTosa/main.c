#include <stdio.h>
#include "BanhoTosa.h"

int main()
{
    BanhoTosa* loja = inicBanhoTosa ("Petz");
    Cachorro* iris = inicCachorro("Iris", BRAVO);
    Gato* branca = inicGato("Branca", BRAVO);
    cadastraCachorro (loja, iris);
    cadastraGato (loja, branca);
    //imprimeBanhoTosa (loja);
    //liberaBanhoTosa (loja);
}