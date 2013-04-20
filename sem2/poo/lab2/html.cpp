using namespace std;

class Property {
private:
  string name, value;
  
  Property (string name = "class", string value = "") {
    this->name = name;
    this->value = value;
  }
  
  string to_s () {
    if (value.empty()) {
      return name;
    } else {
      return name + "=\"" + value + '\"';
    }
  }
  
  friend class Tag;
};

class Tag {
private:
  string name;
  vector<Property> prop;
  
public:
  Tag (string name = "div") {
    assert (name != "");
    this->name = name;
  }
  
  Tag& attr (const string &name, string value = "") {
    assert (name != "");
    prop.push_back (
      Property (name, value)
    );
    
    return *this;
  }
  
  string open_tag () {
    string str = "<" + name;
    for (typeof(prop.begin()) it = prop.begin(); it != prop.end(); it++) {
      str += " " + it->to_s();
    }
    
    return str + ">";
  }
  
  string close_tag () { return "</" + name + ">"; }
  
  friend ostream& operator<< (ostream &out, const Tag &x) {
    out << x.name;
    return out;
  }
};