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
4) Definire una cartella di lavoro, che chiameremo WORKSPACE d'ora in poi: una cartella "Codice" nella nostra home, oppure una cartella "code" sul desktop, creandola nel modo preferito (mkdir da Powershell, oppure direttamente da explorer col mouse). Standardizzeremo il funzionamento dei nostri script indipendentemente dalla posizione di questa cartella definendo a tal proposito una variabile d'ambiente. Aprire pertanto una Powershell in modalità utente standard e digitare
```
PS \>             rundll32 sysdm.cpl,EditEnvironmentVariables
```
5) Nella schermata che si apre, nella sezione superiore, creare una nuova variabile con nome WORKSPACE e come valore il path completo della nostra cartella di lavoro precedentemente stabilita
6) Chiudere la Powershell e riaprirla, sempre in modalità utente standard
```
PS \>             cd $env:WORKSPACE
PS Codice>        git clone https://github.com/Microsoft/vcpkg.git
PS Codice>        cd vcpkg
PS Codice\vcpkg>  .\bootstrap-vcpkg.bat 
```
7) Aprire Powershell in modalità amministratore e quindi digitare
```
PS \>             cd $env:WORKSPACE
PS Codice>        cd vcpkg
PS Codice\vcpkg>  .\vcpkg integrate install
```
8) Aprire Powershell in modalità utente standard e quindi digitare
```
PS \>             cd $env:WORKSPACE
PS Codice>        cd vcpkg
PS Codice\vcpkg>  .\vcpkg install fltk boost 
```
nb: per completare quest'ultimo passaggio bisogna accettare l'installazione di "CMake portable"


