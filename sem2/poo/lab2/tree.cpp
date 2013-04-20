using namespace std;

// initial l-am implementat cu template si era mai fain
class Node {
private:
  Tag data;
  
  Node& set_data (const Tag &data) { this->data = data; return *this; }
  
public:
  Node (const Tag &val) : data(val) {}
  ~Node () {}
  
  Tag get_data () { return data; }
  
  friend ostream& operator<< (ostream &out, Node x) { // TODO: const Node &x
    out << x.get_data();
    return out;
  }
  
  friend class Tree;
};

class Tree {
private:
  Node head;
  Tree *child, *next;
  
  Tree* get_next() { return next; }
  Tree& set_next(Tree &val) { next = &val; return *this; }
  
  void add_child (Tree &add) {
    if (!child) {
      child = &add;
    } else {
      Tree *conductor = child;
      while (conductor->get_next()) { conductor = conductor->get_next(); }
      conductor->set_next(add);
    }
  }
  
public:
  Tree (const Node &val) : head(val), child(0), next(0) {}
  ~Tree () {}
  
  Node get_head () { return head; }
  Tree& set_head (const Node &val) { head = val; return *this; }
  
  Tree& operator+ (Tree add) { add_child (add); return *this; }
  Tree& operator+= (Tree add) { add_child (add); return *this; }
  
  friend ostream& operator<< (ostream &out, Tree x) { // TODO: const Tree &x
    out << x.get_head() << endl;
    
    if (x.child) {
      out << *x.child << endl;
      
      if (x.child->next) {
        Tree *conductor = x.child->next;
        out << *conductor << endl;
        while (conductor->get_next()) {
          out << *conductor << endl;
          conductor = conductor->get_next();
        }
      }
    }
    
    return out;
  }
};