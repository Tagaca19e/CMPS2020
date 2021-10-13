#include <iostream>
#include <fstream>


using namespace std;

class ConfigFileError: public exception {
  public: const char * what() const
  throw () {
    return "Configuration file is badly formed";
  }
};

class ConfigFileMissingKey: public ConfigFileError {
  public: const char * what() const
  throw () {
    return "Missing key";
  }
};

class ConfigFileBadKey: public ConfigFileError {
  public: const char * what() const
  throw () {
    return "Bad key specification";
  }
};

class ConfigFileMissingSeparator: public ConfigFileError {
  public: const char * what() const
  throw () {
    return "Missing separator";
  }
};

class ConfigFile {
  private:

    bool contains_separator(string line, char sep = '=') {
      bool containsSep = false;
      for (int i = 0; i < line.length(); i++) {
        if (line[i] == sep) {
          containsSep = true;
          break;
        }
      }
      return containsSep;
    }


  bool is_name_valid(string name) {
    bool check = false;
    char undr ='_';
  //This will check for a letter or underscore
    if ( isalpha(name[0]) || name[0] == undr )
      check = true;

    return check;
  }

  bool is_comment(string line) {
    bool comment = false;

    if (line[0] == ';')
      comment = true;

    return comment;
  }

  bool is_missing_key(string line) {
    bool missingKey = false;

    if (line[0] == '=')
      missingKey = true;

    return missingKey;
  }

  public:

    bool load(string filename) {
      string line;

      ifstream in;
      in.open("config.ini");

      if (in.is_open()) {
        while (!in.eof()) {
          if (getline(in, line)) {
            //Checking if the first line is empty or not and it is not a comment so we can check it
            if (line != "" && !is_comment(line)) {
              if (!is_name_valid(line))
                throw ConfigFileBadKey();

              else  if (!contains_separator(line))
                throw ConfigFileMissingSeparator();

              else if (is_missing_key(line))
                throw ConfigFileMissingKey();
            }
          }
        }
      }
      return true;
    }
};
int main() {
  ConfigFile config;

  try {
    if (config.load("config.ini"))
      cout << "Config file verified" << endl;

  } catch (ConfigFileMissingKey & ex) {
    cerr << ex.what() << endl;
  } catch (ConfigFileBadKey & fbk) {
    cerr << fbk.what() << endl;
  } catch (ConfigFileMissingSeparator & fms) {
    cerr << fms.what() << endl;
  } catch (ConfigFileError & fe){
    cerr << fe.what() << endl;
  } catch (...) {

    cerr << "Unknown Error" << endl;
  }

  return 0;
}