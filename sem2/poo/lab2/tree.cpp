#include <queue>
using namespace std;

// aici ar fi mers de minune un template
class Node {
private:
  Tag data;
  
  Node& set_data (const Tag &data) { this->data = data; return *this; }
  
public:
  Node (const Tag &val) : data(val) {}
  ~Node () {}
  
  Tag get_data () { return data; }
  
  friend ostream& operator<< (ostream &out, Node x) {
    out << x.get_data();
    return out;
  }
  
  friend class Tree;
};

class Tree {
private:
  Node head;
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
    int depth = this->get_depth();
    
    for (int i = 0; i < depth; i++) {
      ind += "  ";
    }
    
    return ind;
  }
  
public:
  Tree (const Node &val) : head(val), child(0), next(0), parent(0) {}
  ~Tree () {}
  
  Node get_head () { return head; }
  Tree& set_head (const Node &val) { head = val; return *this; }
  
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
  // friend istream& operator>> (istream &in, Tree &x) {
  //   
  // }
  
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
    result += this->get_head().get_data().get_name() + " ";
    
    if (this->get_child()) {
      result += this->get_child()->dfs();
    }
    
    if (this->get_next()) {
      Tree *conductor = this->get_next();
      result += conductor->dfs();
      while (conductor->get_next()) {
        conductor = conductor->get_next();
        result += conductor->dfs();
      }
    }
    
    return result;
  }
  
  int get_height (int depth = 1) {
    
    if (this->get_child()) {
      int result = this->get_child()->get_height(depth + 1);
      if (depth < result) depth = result;
    }
    
    if (this->get_next()) {
      Tree *conductor = this->get_next();
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
};