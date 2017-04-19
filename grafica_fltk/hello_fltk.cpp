//http://fltk.org/doc-1.3/basics.html

// Tutti i programmi che usano le librerie FLTK devono includere <FL/Fl.H>. 
// In aggiunta, ogni codice deve includere l'header file corrispondente a ciascuna classe FLTK usata (finestre, bottoni, ...). 
// Mostriamo qui un semplice programma introduttivo, un "Hello, World!", che utilizza le librerie FLTK per creare una finestra.


#include <FL/Fl.H>            // Obbligatorio primo #include per usare le FLTK
#include <FL/Fl_Window.H>     // Header incluso per poter usare la classe Fl_Window (una finestra)
#include <FL/Fl_Box.H>        // Header incluso per poter usare la classe Fl_Box (un riquadro)

#include <string>

int main(int argc, char **argv) {
  const std::string hw_s = "Hello, World!";
  // Creazione oggetti base (widgets), sempre identificati come Fl_nomewidget
  // La creazione avviene *solo* con il metodo *new*
  // In FLTK il punto in alto a sinistra della finestra e` l'origine (x=0, y=0) e le unita` sono in pixel
  // Fl_Widget(x, y, width, height, label)
  // La label deve essere in uno static storage (es: const char*, oppure definita "a mano" hardcoded nel codice) perche' FLTK non ne fa una copia, ne prende solo il puntatore.
  Fl_Window *window = new Fl_Window(340,180);              // creiamo una finestra di dimensioni 340x180
  Fl_Box *box = new Fl_Box(20,40,300,100,hw_s.c_str());    // creiamo un riquadro, dando il punto iniziale e le dimensioni, contenente la stringa "Hello, World!". Esso appartiene alla finestra "window" automaticamente

  // Impostazione stile
  box->box(FL_UP_BOX);                  // tipo di box (uscente dalla finestra)
  box->labelfont(FL_BOLD+FL_ITALIC);    // font (grassetto+corsivo)
  box->labelsize(36);                   // dimensione font
  box->labeltype(FL_SHADOW_LABEL);      // stile testo (ombreggiato)

  // Porto tutto a schermo ed attendo l'utente per uscire (ESC o chiudi finestra)
  window->end();                 // significa che non abbiamo altri oggetti da disegnare dentro "window"
  window->show(argc, argv);      // mostra la finestra
  Fl::run();                     // loop principale di attesa interazione utente

  // Chiusura
  return 0;
}
