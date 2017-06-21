## Ubuntu On Windows
Si suggerisce di utilizzare Bash on Ubuntu on Windows solo a partire dalla build 15063 (Creators Update).  
1) Se non è già installato nel sistema, installare [chocolatey](http://chocolatey.org)
2) Se nel sistema Windows non è già presente un server X, installarlo con questa procedura: aprire Powershell in modalità amministratore e quindi digitare
```
PS \>  cinst -y vcxsrv 
```
3) Se non ancora abilitato, attivare UoW seguendo la [guida ufficiale](https://msdn.microsoft.com/it-it/commandline/wsl/install_guide)
4) Seguire la guida per Ubuntu



## Ubuntu
Aprire un terminale bash e digitare  
```
$  sudo apt-get update
$  sudo apt-get install g++ gnuplot cmake make libfltk1.3-dev freeglut3-dev libboost-all-dev git imagemagick
```


## macOS
1) Installare gli XCode Command Line Tools, se non già installati, digitando su un terminale il seguente comando:
```
$  xcode-select --install
```
2) Se non ancora installato, installare Homebrew secondo la guida presente sulla [homepage](https://brew.sh/index_it.html).  
3) Aprire infine un terminale e digitare  
```
$  brew update
$  brew install gnuplot cmake make fltk boost git
$  brew install imagemagick --with-x11
```


## Windows (7+)
1) Installare/aggiornare Visual Studio: se si usa Visual Studio 2015, assicurarsi di averlo aggiornato almeno alla versione Update 3. Se va installato da zero, si consiglia [Visual Studio 2017 Community](http://visualstudio.com).  
2) Se non installato, installare [chocolatey](http://chocolatey.org)
3) Se non avete gnuplot e un client git installati, aprire Powershell in modalità amministratore e quindi digitare
```
PS \>             cinst -y gnuplot git cmake pscx powershell
```
4) Riavviare il PC se richiesto da chocolatey
5) Definire una cartella di lavoro, che chiameremo WORKSPACE d'ora in poi: una cartella "Codice" nella nostra home, oppure una cartella "code" sul desktop, creandola nel modo preferito (mkdir da Powershell, oppure direttamente da explorer col mouse). Standardizzeremo il funzionamento dei nostri script indipendentemente dalla posizione di questa cartella definendo a tal proposito una variabile d'ambiente. Aprire pertanto una Powershell in modalità utente standard e digitare
```
PS \>             rundll32 sysdm.cpl,EditEnvironmentVariables
```
6) Nella schermata che si apre, nella sezione superiore, creare una nuova variabile con nome WORKSPACE e come valore il path completo della nostra cartella di lavoro precedentemente stabilita. Aggiungere inoltre alla variabile "Path" il seguente percorso (assicurandosi di essere separati con un `;` da eventuali altri record presenti):
```
%PROGRAMFILES%/CMake/bin;
```
7) Se vcpkg non è installato, eseguire la procedura seguente, altrimenti saltare direttamente al punto 9. Chiudere la Powershell e riaprirla, sempre in modalità utente standard
```
PS \>             cd $env:WORKSPACE
PS Codice>        git clone https://github.com/Microsoft/vcpkg.git
PS Codice>        cd vcpkg
PS Codice\vcpkg>  .\bootstrap-vcpkg.bat 
```
8) Aprire Powershell in modalità amministratore e quindi digitare
```
PS \>             cd $env:WORKSPACE
PS Codice>        cd vcpkg
PS Codice\vcpkg>  .\vcpkg integrate install
```
9) Aprire Powershell in modalità utente standard e quindi digitare
```
PS \>             cd $env:WORKSPACE
PS Codice>        cd vcpkg
PS Codice\vcpkg>  .\vcpkg install fltk fltk:x86-windows-static boost boost:x86-windows-static freeglut freeglut:x86-windows-static opengl opengl:x86-windows-static
```
10) Aprire un editor di testo qualsiasi (anche notepad.exe va bene!) e incollare il seguente testo:

**Visual Studio 2015, Windows 32 bit**
```
Import-Module Pscx
Invoke-BatchFile "${env:PROGRAMFILES}\Microsoft Visual Studio 14.0\VC\vcvarsall.bat" x86
```
**Visual Studio 2015, Windows 64 bit**
```
Import-Module Pscx
Invoke-BatchFile "${env:PROGRAMFILES(x86)}\Microsoft Visual Studio 14.0\VC\vcvarsall.bat" x64
```
**Visual Studio 2017, Windows 32 bit**
```
Import-Module Pscx
Invoke-BatchFile "${env:PROGRAMFILES}\Microsoft Visual Studio\2017\Community\VC\Auxiliary\Build\vcvarsall.bat" x86
```
**Visual Studio 2017, Windows 64 bit**
```
Import-Module Pscx
Invoke-BatchFile "${env:PROGRAMFILES(x86)}\Microsoft Visual Studio\2017\Community\VC\Auxiliary\Build\vcvarsall.bat" x64
```
e salvarlo nella cartella Documenti\WindowsPowerShell del proprio utente con nome `Microsoft.PowerShell_profile.ps1`


