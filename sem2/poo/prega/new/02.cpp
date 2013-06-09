#include <iostream> 
#include <typeinfo> 
using namespace std;

struct PolyBase { 
	virtual ~PolyBase() {} 
	};
	
struct PolyDer : PolyBase { 
	PolyDer() {} 
	};
	
struct NonPolyBase {};

struct NonPolyDer : NonPolyBase {
	NonPolyDer() {} 
}; 

int main() { 
	
	// Test polymorphic Types false
	//const PolyDer pd;
	const PolyBase *ppb;
	ppb = new PolyDer();
	//const PolyBase* ppb = &pd;
	cout << typeid(ppb).name() << endl;
	cout << typeid(*ppb).name() << endl;
	//cout << boolalpha << (typeid(*ppb) == typeid(pd)) << endl; 
	cout << (typeid(PolyDer) == typeid(const PolyDer))<< endl;
	
	 // Test non-polymorphic Types
	const NonPolyDer npd;
	const NonPolyBase* nppb = &npd;
	cout << typeid(nppb).name() << endl;
	cout << typeid(*nppb).name() << endl;
	cout << (typeid(*nppb) == typeid(npd)) << endl;

	// Test a built-in type
	int *i;
	cout << typeid(i).name() << endl;
} 