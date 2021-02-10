#include <iostream>

// std namespace dalys, dėl lengvesnės sintaksės
using std::cout;
using std::cin;
using std::endl;
using std::string;

//funkcija, kuri nustato pasisveikinimą pagal vardą
string check_greeting(string name)
{
  return (name[name.length() - 1] == 'a') ? "Sveika, " : "Sveikas, ";
}

//funkcija, kuri patikrina ar įvestas rėmelio plotis yra skaičius
int validate_width(string entered_offset)
{
  for(int i = 0; i<entered_offset.length(); i++) if(!std::isdigit(entered_offset[i])) return -1;
  return std::stoi(entered_offset);
}

int main() {

  // vardo įvedimas
  string name;
  cout<<"Enter your name: ";
  cin>>name;

  string greeting = check_greeting(name);
  cout<<"\n////////////////////////////////\n"<<endl;

  //rėmelio pločio nustatymas
  int width;
  do
  {
    string temp_input;
    cout<<"Enter the desired width\nbeween boarders and the greeting (can't be less than 0): ";
    cin>>temp_input;
    width = validate_width(temp_input);
  }while(width < 0);

  cout<<"\n////////////////////////////////\n"<<endl;

  //eilučių ilgis: * + width + pasisveikinimas + vardas + ! + width + "*"
  int row_length = 3 + greeting.length() + name.length() + width*2;

  // eilučių masyvas susideda iš trijų būtinų eilučių ir 2 tarpų tarp pasisveikinimo ir rėmelio galų
  int array_size = 3 + (width*2);
  string rows[array_size];

  //ciklas, kuris užpildo masyvą tam tikromis eilutėmis
  string space(width, ' ');
  for(int i = 0; i<array_size; i++)
  {
    //pirma ir paskutinė eilutės
    if(i == 0 || i == array_size-1) rows[i] = string(row_length, '*');
    //vidurinė eilutė
    else if (i == array_size/2) rows[i] = "*" + space + greeting + name + "!" + space + "*";
    else //visos kitos
    {
      rows[i] = string(row_length, ' ');
      rows[i][0] = '*';
      rows[i][row_length-1] = '*'; 
    }
    
    //printinimas
    cout<<rows[i]<<endl;
  }
} 