#include<iostream>
#include<fstream>
#include<iomanip>

using namespace std;


//Same concept as HTML lab but with pointer
// Use classes for JSON and CSV
//Do not forget to pointer cleanup

struct CountyInfo
{
  string name;
  double infections;
};

class CoronaData
{
  protected:
    CountyInfo data[5];
  public:
    CoronaData()
  {
    // hard-coded data. Could load from any source.
    data[0].name = "Los Angeles";
    data[0].infections = 255000;
    data[1].name = "Riverside";
    data[1].infections = 55766;
    data[2].name = "Orange";
    data[2].infections = 52166;
    data[3].name = "San Bernardino";
    data[3].infections = 50709;
    data[4].name = "San Diego";
    data[4].infections = 42950;
  }
  //Create a virtual function
  virtual void save_to_file(string filename) = 0;
};

//CoronaDataJson class inherited from CoronaData

class CoronaDataJson: public CoronaData {

  public:

    void save_to_file(string filename) {

      //opening output file

      ofstream out(filename.c_str());

      out << setprecision(4) << fixed;

      out << "{" << endl;

      out << " \"data\" : [" << endl;

      //looping and writing name and infection of all 5 objects on the array

      for (int i = 0; i < 5; i++) {

        out << "    { \"name\" : \"" << data[i].name << "\", \"infections\" : \"" << data[i].infections << "\" }," << endl;

      }

      out << " ]" << endl;

      out << "}" << endl;

      out.close();

    }

};

//CoronaDataCsv class inherited from CoronaData

class CoronaDataCsv: public CoronaData {

  public:

    void save_to_file(string filename) {

      ofstream out(filename.c_str());

      out << setprecision(4) << fixed;

      out << "County, Infections" << endl;

      //same concept as the JSON but different format

      for (int i = 0; i < 5; i++) {

        out << "\"" << data[i].name << "\", " << data[i].infections << endl;

      }

      out.close();

    }

};

//a global function to save data of a CoronaData object (it could be CoronaDataJson

//or CoronaDataCsv) to a file

void save(CoronaData * cd, string filename)

{

  cd -> save_to_file(filename);

  cout << "File is ready." << endl;

}

int main() {

  CoronaData * cd = NULL;

  // code to prompt the user for format type
  char input;

  cout << "Choose output format (j = JSON, c = CSV): ";


  cin >> input;

  // User chose JSON format

  if (input == 'j')
  {
    cd = new CoronaDataJson();

    save(cd, "corona.json");

  } else if (input == 'c') {

    cd = new CoronaDataCsv();

    save(cd, "corona.csv");

  }

  //Pointer cleanup

  if (cd != NULL) {

    delete cd;

  }

  return 0;

}

