// http://www3.telus.net/public/robark/

#include <FL/Fl.H>
#include <FL/Fl_Window.H>
#include <FL/Fl_Button.H>   // useremo anche un bottone!


using namespace std;


// Callback (funzione richiamata) eseguita alla pressione del bottone.
// La firma della funzione è (Fl_Widget*, void*), a noi non serve il secondo argomento
// quindi lo lasciamo vuoto
void button_callback(Fl_Widget * o, void *) {
  Fl_Button* b = (Fl_Button*)o;   //Con questa linea facciamo un *cast* del puntatore a widget generico in un puntatore di tipo Fl_Button.
                                   //In questo caso particolare e' superfluo perche' i metodi che useremo (label(), resize(), redraw()) su "b" sono tutti metodi membri della classe base widget

  b->label("Good job");            //Il redraw non e' necessario perche' label() e value() sono gli unici membri di widget che chiamano redraw() automaticamente
  b->resize(10, 150, 140, 30);        //redraw() necessario
  b->redraw();                     //redraw() eseguito!
}



int main() {
  const std::string titolo_finestra = "Finestra";

  // La creazione dei widget in questo esempio avviene con i costruttori.
  Fl_Window finestra(300, 200, titolo_finestra.c_str());
  finestra.begin();
  Fl_Button but(10, 150, 70, 30, "Click me");
  finestra.end();

  // imposto la funzione che viene eseguita quando premo sul bottone
  but.callback(button_callback);

  // Porto tutto a schermo ed attendo l'utente per uscire (ESC o chiudi finestra)
  finestra.show();
  Fl::run();

  // chiusura
  return 0;
}

