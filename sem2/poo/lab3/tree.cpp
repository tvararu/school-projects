#include <queue>
#include <algorithm>
using namespace std;

template <class T>
class Node {
private:
  T data;
  
  Node& set_data (const T &val) { data = val; return *this; }
  
public:
  Node () {}
  Node (const T &val) : data(val) {}
  ~Node () {}
  
  T get_data () { return data; }
  
  friend ostream& operator<< (ostream &out, Node x) {
    out << x.get_data();
    return out;
  }
  
  friend class Tree;
};

class Tree {
private:
  Node<Tag> head;
  Tree *child, *next, *parent;
  
  Tree* get_next() { return next; }
  Tree* get_child() { return child; }
  
  Tree& set_next(Tree &val) { next = &val; return *this; }
  Tree& set_child(Tree &val) { child = &val; return *this; }
  
  Tree& set_parent (Tree &val) { parent = &val; return *this; }
  
  // find the distance from the current Tree to its furthest parent
  int get_depth () {
    int depth = 0;
    
    Tree *conductor = this;
    while (conductor->parent) {
      ++depth;
      conductor = conductor->parent;
    }
    
    return depth;
  }
  
  string indent () {
    string ind = "";
    int depth = get_depth();
    
    for (int i = 0; i < depth; i++) {
      ind += "  ";
    }
    
    return ind;
  }
  
public:
  Tree () : child(0), next(0), parent(0) {}
  Tree (const Node<Tag> &val) : head(val), child(0), next(0), parent(0) {}
  ~Tree () {}
  
  Node<Tag> get_head () { return head; }
  Tree& set_head (const Node<Tag> &val) { head = val; return *this; }
  
  Tree* get_parent () { return parent; }
  
  Tree& operator+ (Tree &add) {
    add.set_parent(*this);
    if (!child) {
      set_child(add);
    } else {
      Tree *conductor = child;
      while (conductor->get_next()) { 
        conductor = conductor->get_next();
      }
      conductor->set_next(add);
    }
    
    return *this;
  }
  Tree& operator+= (Tree &add) { return *this + add; }
  
  // si aici merge un operator in functie de template
  friend ostream& operator<< (ostream &out, Tree x) {
    out << x.indent() << x.get_head().get_data().open_tag() << endl;
    
    if (x.get_child()) {
      out << *x.get_child();
      
      if (x.get_child()->next) {
        Tree *conductor = x.get_child()->next;
        out << *conductor;
        while (conductor->get_next()) {
          conductor = conductor->get_next();
          out << *conductor;
        }
      }
    }
    
    out << x.indent() << x.get_head().get_data().close_tag() << endl;
    
    return out;
  }
  
  // nu l-am facut sa citeasca si atribute pentru ca m-as fi complicat destul de mult
  friend istream& operator>> (istream &in, Tree &x) {
    string input; getline (in, input);
    input.erase(
      ::remove_if(
        input.begin(),
        input.end(), 
        ::isspace
      ),
      input.end()
    );
    
    string tagName(input.begin() + 1, input.end() - 1);
    x.set_head(Tag(tagName));
    cout << input << ": " << tagName << '\n';
    
    if (tagName[0] != '/') {
      cout << "opening tag\n";
      Tree& deeper = * new Tree;
      in >> deeper;
      if (deeper.get_head().get_data().get_name() == '/' + tagName) {
        cout << "finished:\n" << x;
      } else {
        cout << deeper.get_head().get_data().get_name() << " different from " << tagName << endl;
        x += deeper;
      }
    } else { 
      cout << "closing tag\n";
    }
    
    return in;
  }
  
  string bfs () {
    string result = "";
    
    queue<Tree*> coada;
    coada.push(this);
    
    while (!coada.empty()) {
      Tree *front = coada.front();
      result += front->get_head().get_data().get_name() + " ";
      coada.pop();
      
      if (front->get_child()) {
        coada.push(front->get_child());
      
        if (front->get_child()->get_next()) {
          Tree *conductor = front->get_child()->get_next();
          coada.push(conductor);
          while (conductor->get_next()) {
            conductor = conductor->get_next();
            coada.push(conductor);
          }
        }
      }
    }
    
    return result;
  }
  
  string dfs () {
    string result = "";
    result += get_head().get_data().get_name() + " ";
    
    if (get_child()) {
      result += get_child()->dfs();
    }
    
    if (get_next()) {
      Tree *conductor = get_next();
      result += conductor->dfs();
      while (conductor->get_next()) {
        conductor = conductor->get_next();
        result += conductor->dfs();
      }
    }
    
    return result;
  }
  
  int get_height (int depth = 1) {
    
    if (get_child()) {
      int result = get_child()->get_height(depth + 1);
      if (depth < result) depth = result;
    }
    
    if (get_next()) {
      Tree *conductor = get_next();
      int result = conductor->get_height(depth);
      if (depth < result) depth = result;
      while (conductor->get_next()) {
        conductor = conductor->get_next();
        result = conductor->get_height(depth);
        if (depth < result) depth = result;
      }
    }
    
    return depth;
  }
  
  vector<Node<Tag> > leaves () {
    vector<Node<Tag> > leaf;
    if (get_child()) {
      vector<Node<Tag> > result = get_child()->leaves();
      leaf.insert (leaf.end(), result.begin(), result.end());
    } else {
      leaf.push_back(get_head());
    }
    
    if (get_next()) {
      Tree *conductor = get_next();
      vector<Node<Tag> > result = conductor->leaves();
      leaf.insert (leaf.end(), result.begin(), result.end());
      while (conductor->get_next()) {
        conductor = conductor->get_next();
        vector<Node<Tag> > result = conductor->leaves();
        leaf.insert (leaf.end(), result.begin(), result.end());
      }
    }
    
    return leaf;
  }
};