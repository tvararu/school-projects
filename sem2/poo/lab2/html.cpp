using namespace std;

class Property {
private:
  string name, value;
  
  Property (string _name = "class", string _value = "") {
    name = _name;
    value = _value;
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
  bool plain;

  Tag set_name (const string &val) { name = val; return *this; }
  
public:
  Tag () : name("div"), plain(0) {}
  Tag (const string &name, bool plain = 0) : name(name), plain(plain) {}
  
  Tag& attr (const string &name, string value = "") {
    assert (name != "");
    prop.push_back (
      Property (name, value)
    );
    
    return *this;
  }
  
  string get_name () { return name; }
  
  bool is_plain () { return plain; }
  
  string open_tag () {
    if (is_plain()) return name;
    
    string str = "<" + name;
    for (typeof(prop.begin()) it = prop.begin(); it != prop.end(); it++) {
      str += " " + it->to_s();
    }
    
    return str + ">";
  }
  
  string close_tag () { 
    if (is_plain()) return "";
    
    return "</" + name + ">";
  }
  
  friend ostream& operator<< (ostream &out, Tag x) {
    out << x.get_name();
    return out;
  }
};