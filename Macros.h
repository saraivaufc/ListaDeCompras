#ifndef MACROS_H
#define MACROS_H

#include <QString>

#define CONTACORRENTE "empty"
#define ICON_COMPRA ":imagens/icones/icon.png"
#define ICON_COMIDA ":imagens/icones/comida.png"
#define ICON_UTENSILIO ":imagens/icones/utensilio.png"
#define ICON_LIMPEZA ":imagens/icones/limpeza.png"


#define DIR_JSON "data"

enum ClasseDeProduto{LIMPESA=1, COMIDA, UTENSILIOS};


#define classeToString(c) c == LIMPESA ? "LIMPESA":\
    c == COMIDA ? "COMIDA":\
    "UTENSILIOS"
#define stringToClasse(c) c == "LIMPESA" ? LIMPESA:\
    c == "COMIDA" ? COMIDA:\
    UTENSILIOS

#define classeToIcon(c) c == COMIDA ? ICON_COMIDA:\
      c == LIMPESA ? ICON_LIMPEZA:\
      ICON_UTENSILIO


#endif // MACROS_H
