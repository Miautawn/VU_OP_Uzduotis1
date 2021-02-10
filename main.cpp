#include <iostream>

// std namespace dalys, dėl lengvesnės sintaksės
using std::cout;
using std::cin;
using std::endl;
using std::string;

//function that determines the greeting depending on the name
string greeting_check(string name)
{
  return (name[name.length() - 1] == 'a') ? "Sveika, " : "Sveikas, ";
}

int main() {

  // vardo įvedimas
  string name;
  cout<<"Enter your name: ";
  cin>>name;

  string greeting = greeting_check(name);

  //eilučių ilgis: *_ + pasisveikinimas + vardas + ! + _*
  int row_length = 5 + greeting.length() + name.length();

  //veiksmai su eilutėmis
  string row_1 (row_length, '*');
  //padarome, kad antroje ir ketvirtoje eilutėse būtų po '*' iš galų 
  string row_2 (row_length, ' ');
  row_2[0] = '*';
  row_2[row_length-1] = '*';
  //padarome, kad antroje ir ketvirtoje eilutėse būtų po '*' iš galų 
  string row_3 = "* " + greeting + name + "!" + " *";
  string row_4 = row_2;
  string row_5 = row_1; 
 
  //išvedimas
  cout<<row_1<<endl;
  cout<<row_2<<endl;
  cout<<row_3<<endl;
  cout<<row_4<<endl;
  cout<<row_5<<endl;

}
