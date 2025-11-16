<div align="center"><img src="/assets/img/radix.png" alt="Radix Logo"></div>

# Radix

Kyklos è un programma a riga di comando, scritto in C++, per approssimare la radice quadrata di un numero.

## Come funziona

Per approssimare la radice quadrata di un numero, Radix implementa il seguente approccio:

1. **Metodo Babilonese**: Viene calcolata una stima iniziale della radice quadrata del numero dato in input, facendola convergere sempre di più al suo valore reale
2. **Stabilità numerica**: Ad ogni iterazione si tiene traccia di un numero massimo di iterazioni consentite e di una precisione decimale da raggiungere entrambi forniti in input dall'utente, per minimizzare il tempo di esecuzione e gli errori di arrotondamento

## Guida all'utilizzo

### Prerequisiti

Per utilizzare Radix è necessario scaricare [Git](https://git-scm.com/downloads), un C++ toolchain (`g++` o `clang++` e `make`) su [Windows](https://code.visualstudio.com/docs/cpp/config-mingw), [MacOS](https://code.visualstudio.com/docs/cpp/config-clang-mac) o una distribuzione [GNU/Linux](https://code.visualstudio.com/docs/cpp/config-linux).

### Download

1. Apri il terminale e clona la repository: `git clone https://github.com/lambda21830/Radix.git`
2. Vai nella repository clonata: `cd Radix`
3. Compila ed esegui il programma: `make run`
