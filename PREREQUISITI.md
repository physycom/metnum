## Ubuntu (incluso Ubuntu On Windows)
Aprire un terminale bash e digitare  
```
$  sudo apt-get install g++ gnuplot cmake make libfltk1.3-dev libboost-all-dev git
```


## macOS
1) Installare gli XCode Command Line Tools, se non già installati, digitando su un terminale il seguente comando:
```
$  xcode-select --install
```
2) Installare Homebrew secondo la guida presente sulla [homepage](https://brew.sh/index_it.html).  
3) Aprire infine un terminale e digitare  
```
$  brew install gnuplot cmake make fltk boost git
```

## Windows (7+)
1) Installare [Visual Studio 2017 Community](http://visualstudio.com).  
2) Installare [chocolatey](http://chocolatey.org)
3) Aprire Powershell in modalità amministratore e quindi digitare
```
PS \>  cinst -y gnuplot git 
```
4) Aprire Powershell in modalità utente standard, andare in una cartella dove lavoreremo (che chiameremo `Codice`) e digitare
```
PS Codice>        git clone https://github.com/Microsoft/vcpkg.git
PS Codice>        cd vcpkg
PS Codice\vcpkg>  .\scripts\bootstrap.ps1 
```
5) Aprire Powershell in modalità amministratore, andare nella cartella `Codice` e quindi digitare
```
PS Codice>        cd vcpkg
PS Codice\vcpkg>  .\vcpkg integrate install
```
6) Aprire Powershell in modalità utente standard, andare nella cartella `Codice` e quindi digitare
```
PS Codice>        cd vcpkg
PS Codice\vcpkg>  .\vcpkg install fltk boost 
Accettare l'installazione di CMake 3.8 rc1
```
7) Aggiungere la versione portable di CMake 3.8 rc1 appena scaricata da vcpkg al path dell'utente, così da poterlo utilizzare globalmente nel terminale



